#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import sys
import io
import argparse
import tempfile
import subprocess
from shutil import rmtree
from typing import Dict, List, Tuple, Union, Optional  # , Any, Callable
import configparser
from subprocess import PIPE


class Defaults:
    EMPTY = "__EMPTY__"
    SYMBOLS = {
        "category": ["cat:", "©"],
        "tag": ["#", "tag:"],
        "date": ["date:", "ð"],
        "author": ["author:", "æ"],
        "subtitle": ["sub:", "ß"]
    }


class Util:
    # join the many strings in the list using join
    @staticmethod
    def join(path_list: List[str]) -> str:
        path_list = [os.path.normpath(x) for x in path_list]
        path = ""
        for x in path_list:
            path = os.path.join(path, x)
        return os.path.normpath(path)

    @staticmethod
    def key_filter(key: str) -> str:
        key = key.replace("_", " ")
        words = key.split(" ")

        try:
            _index = int(words[0])
            del words[0]
        except ValueError:
            pass
        return " ".join(words).strip()

    # generate a relative path from source to destination
    @staticmethod
    def get_directions(source: str, destination: str) -> str:
        source = os.path.normpath(source)
        destination = os.path.normcase(destination)
        source_list = source.split(os.sep)
        destin_list = destination.split(os.sep)
        while source_list[0] == destin_list[0]:  # erasing commom path
            del source_list[0]
            del destin_list[0]

        return Util.join(["../" * (len(source_list) - 1)] + destin_list)

    # returns a tuple with two strings
    # the first  is the directory
    # the second is the filename
    @staticmethod
    def split_path(path: str) -> Tuple[str, str]:
        path = os.path.normpath(path)
        vet: List[str] = path.split(os.path.sep)
        if len(vet) == 1:
            return ".", path
        return Util.join(vet[0:-1]), vet[-1]

    @staticmethod
    def create_dirs_if_needed(path: str) -> None:
        root, file = Util.split_path(path)
        if not os.path.isdir(root):
            os.makedirs(root)

    # generate md link for the text
    @staticmethod
    def get_md_link(title: Union[None, str]) -> str:
        if title is None:
            return ""
        title = title.lstrip(" #").rstrip()
        title = title.lower()
        out = ''
        for c in title:
            if c == ' ' or c == '-':
                out += '-'
            elif c == '_':
                out += '_'
            elif c.isalnum():
                out += c
        return out

    @staticmethod
    def only_hashtags(x: str) -> bool:
        return len(x) == x.count("#") and len(x) > 0

    # return two lists
    # the first  with the words that        start with str p
    # the second with the words that do not start with char p
    @staticmethod
    def split_list(word_list: List[str], prefix: List[str]) -> Tuple[List[str], List[str]]:
        inside_list = []
        for p in prefix:
            inside_list += [x[(len(p)):] for x in word_list if x.startswith(p)]
            word_list = [x for x in word_list if not x.startswith(p)]
        return inside_list, word_list


class TOC:
    tag_begin = r"<!--TOC_BEGIN-->"
    tag_end = r"<!--TOC_END-->"
    regex = tag_begin + r"(.*)" + tag_end

    @staticmethod
    def get_level(line: str) -> int:
        return len(line.split(" ")[0])

    @staticmethod
    def get_content(line: str) -> str:
        return " ".join(line.split(" ")[1:])

    @staticmethod
    def remove_code_blocks(content):
        regex = r"^```.*?```\n"
        return re.sub(regex, "", content, 0, re.MULTILINE | re.DOTALL)

    @staticmethod
    def search_old_toc(readme_content):
        found = re.search(TOC.regex, readme_content, re.MULTILINE | re.DOTALL)
        if found:
            return True, found[1]
        return False, ""


    @staticmethod
    def merge_toc(readme_content, toc):
        subst = TOC.tag_begin + "\\n" + toc + "\\n" + TOC.tag_end
        merged_content = re.sub(TOC.regex, subst, readme_content, 0, re.MULTILINE | re.DOTALL)
        return merged_content

    @staticmethod
    def make_toc(file_content):
        content = TOC.remove_code_blocks(file_content)

        lines = content.split("\n")
        disable_tag = "[]()"
        lines = [line for line in lines if Util.only_hashtags(line.split(" ")[0]) and line.find(disable_tag) == -1]

        min_level = 1
        toc_lines = []
        for line in lines:
            level = (TOC.get_level(line) - 1) - min_level
            if level < 0:
                continue
            text = "    " * level + "- [" + TOC.get_content(line) + "](#" + Util.get_md_link(line) + ")"
            toc_lines.append(text)
        toc_text = "\n".join(toc_lines) + "\n"
        return toc_text

    @staticmethod
    def add_toc(path):
        if os.path.isfile(path):
            with open(path) as f:
                file_content = f.read()
        else:
            print("Warning: File", path, "not found")
            return()

        toc_text = TOC.make_toc(file_content)
        found, _text = TOC.search_old_toc(file_content)
        if found:
            merged_content = TOC.merge_toc(file_content, toc_text)
            if file_content != merged_content:
                print("Toc updated in", path)
                with open(path, "w") as f:
                    f.write(merged_content)
        else:
            print("Create an entry with the text:")
            print(TOC.tag_begin)
            print(TOC.tag_end)
            print("in the file", path)
            print("Use '[]()' string in the lines that you want to hide in toc")


class Config:
    @staticmethod
    def get_default_cfg():
        return ""

    @staticmethod
    def load_cfg(config_file):
        if not os.path.isfile(config_file):
            print("  fail: create a " + config_file + "like in https://github.com/senapk/indexer")
            exit(1)
        config = configparser.ConfigParser()
        config.read(config_file)
        return config


class Meta:
    def __init__(self, content: str = "", symbols: Dict[str, str] = None):
        if symbols is None:
            symbols = Defaults.SYMBOLS

        self.fulltitle = ""
        self.symbols = symbols
        self.md_level = Defaults.EMPTY
        self.title = ""
        self.subtitle = Defaults.EMPTY
        self.tags = []
        self.categories = []
        self.authors = []
        self.date = ""

        self.payload = ""
        self.cover = None

        self.parse_content(content)

    def parse_content(self, content: str):
        symbols = self.symbols
        lines = content.split('\n')

        self.payload = "" if len(lines) == 1 else "\n".join(lines[1:])
        self.cover = self.__get_cover()

        self.fulltitle = lines[0]
        words = self.fulltitle.split(" ")
        if Util.only_hashtags(words[0]):
            self.md_level = words[0]
            del words[0]

        words = [x for x in words if not Util.only_hashtags(x)]
        self.tags, words = Util.split_list(words, symbols["tag"])
        self.categories, words = Util.split_list(words, symbols["category"])
        self.authors, words = Util.split_list(words, symbols["author"])
        self.date, words = Util.split_list(words, symbols["date"])

        parts = []
        for symbol in symbols["subtitle"]:
            parts = " ".join(words).split(symbol)
            if len(parts) != 1:
                break

        self.title = parts[0].strip()
        self.subtitle = Defaults.EMPTY if len(parts) == 1 else parts[1].strip()

        self.date = Defaults.EMPTY if len(self.date) == 0 else self.date[0]

        if len(self.categories) == 0:
            self.categories.append(Defaults.EMPTY)
        if len(self.tags) == 0:
            self.tags.append(Defaults.EMPTY)
        if len(self.authors) == 0:
            self.authors.append(Defaults.EMPTY)

    def __get_cover(self):
        regex = r"!\[(.*?)\]\(([^:]*?)\)"
        match = re.search(regex, self.payload)
        if match:
            return os.path.normpath(match.group(2))  # cover.jpg
        return None

    def assemble(self, sequence="lTdctas"):
        symbols = self.symbols
        out = []

        for s in sequence:
            if s == 'T':
                if self.title:
                    out += [self.title]
            if s == 'l':
                if self.md_level != Defaults.EMPTY:
                    out += [self.md_level]
            if s == 'd':
                if self.date != Defaults.EMPTY:
                    out += [symbols["date"][0] + self.date]
            if s == 'c':
                for cat in self.categories:
                    if cat != Defaults.EMPTY:
                        out += [symbols["category"][0] + cat]
            if s == 's':
                if self.subtitle != Defaults.EMPTY:
                    out += [symbols['subtitle'][0] + " " + self.subtitle]
            if s == 't':
                for tag in self.tags:
                    if tag != Defaults.EMPTY:
                        out += [symbols["tag"][0] + tag]
            if s == 'a':
                for author in self.authors:
                    if author != Defaults.EMPTY:
                        out += [symbols["author"][0] + author]
        return " ".join(out)

    def meta_str(self):
        out = ("l[" + self.md_level + "] ") if self.md_level != Defaults.EMPTY else ""
        out += "T[" + self.title + "]"
        out += (" s[" + self.subtitle + "]") if self.subtitle != Defaults.EMPTY else ""
        out += (" c[" + ",".join(self.categories) + "]") if self.categories[0] != Defaults.EMPTY else ""
        out += (" t[" + ",".join(self.tags) + "]") if self.tags[0] != Defaults.EMPTY else ""
        out += (" a[" + ",".join(self.authors) + "]") if self.authors[0] != Defaults.EMPTY else ""
        out += (" d[" + self.date + "]") if self.date != Defaults.EMPTY else ""
        return out

    def __str__(self):
        return self.meta_str()


class Item(Meta):
    def __init__(self, path: str = "", content: str = "", symbols: Dict[str, str] = None):
        if symbols is None:
            symbols = Defaults.SYMBOLS
        Meta.__init__(self, content, symbols)
        self.path_full = os.path.normpath(path)  # arcade/base/000/Readme.md
        self.base = os.sep.join(self.path_full.split(os.sep)[:-2])  # arcade/base
        self.base = "." if self.base == "" else self.base
        self.hook = path.split(os.sep)[-2]  # 000
        self.filename = path.split(os.sep)[-1]  # Readme.md

    def check_cover(self):
        if not os.path.isfile(Util.join([self.base, self.hook, self.cover])):
            raise FileNotFoundError("  error: cover image not found in ", self.path_full)

    def __str__(self):
        return self.base + ":" + self.hook + ":" + self.filename


class ItemRepository:
    def __init__(self, base: str):
        self.base = os.path.normpath(base)
        self.__test_exists()
        self.itens: List[Item] = []

    def __test_exists(self):
        if not os.path.isdir(self.base):
            print("  error: base dir is missing")
            exit(1)

    def load(self):
        for (root, _dirs, files) in os.walk(self.base, topdown=True):
            folder = root.split(os.sep)[-1]
            if folder.startswith("_") or folder.startswith("."):
                continue
            if root.count(os.sep) - self.base.count(os.sep) != 1:  # one level only
                continue
            files = [x for x in files if x.endswith(".md")]
            for file in files:
                if file.startswith("_") or file.startswith(">"):
                    continue
                path = Util.join([root, file])
                self.itens.append(FileItem.load_from_file(path))
        return self.itens


class FileItem:
    @staticmethod
    def load_from_file(path: str) -> Item:
        with open(path, "r") as f:
            return Item(path, f.read())

    @staticmethod
    def write_from_item(item: Item):
        with open(item.path_full, "w") as f:
            f.write(item.fulltitle.strip() + "\n")
            f.write(item.payload)

    @staticmethod
    def has_changes(source: str, derivated: str):
        if not os.path.isfile(derivated):
            return True
        return os.path.getctime(source) > os.path.getctime(derivated)


class Sorter:
    @staticmethod
    def test_key(item: Item, key: str):
        if not hasattr(item, key):
            print("    fail: Item doesn't have the key", key)
            print("    The options are ", ["title", "hook", "categories/cat", "tags/tag", "authors", "date"])
            exit(1)

    @staticmethod
    def fix_key_name(key: str):
        key = key.lower()
        if key == "cat":
            return "categories"
        if key == "tag":
            return "tags"
        if key == "title":
            return "fulltitle"
        return key

    @staticmethod
    def normalize_keys(keys: str) -> Tuple[str, str]:
        keys_list = [x.strip() for x in keys.split(",")]
        if len(keys_list) == 1:
            keys_list.append("title")
        elif len(keys_list) > 2:
            keys_list = keys_list[:2]
        keys_list = [Sorter.fix_key_name(x) for x in keys_list]
        return keys_list[0], keys_list[1]

    @staticmethod
    def sorted_by_key(itens: List[Item], keys: str, reverse: bool = False) -> List[Item]:
        primary_key, secondary_key = Sorter.normalize_keys(keys)

        if len(itens) == 0:
            return []
        Sorter.test_key(itens[0], primary_key)
        Sorter.test_key(itens[0], secondary_key)

        if type(getattr(itens[0], primary_key)) is list:
            return sorted(itens, key=lambda x: (getattr(x, primary_key)[0], getattr(x, secondary_key)), reverse=reverse)
        return sorted(itens, key=lambda x: (getattr(x, primary_key), getattr(x, secondary_key)), reverse=reverse)

    @staticmethod
    def group_by(itens: List[Item], group_by: str, sort_by: str = "fulltitle", reverse_sort: bool = False) -> \
            List[Union[str, List[Item]]]:
        tree = {}
        if len(itens) > 0:
            group_by = Sorter.fix_key_name(group_by)
            Sorter.test_key(itens[0], group_by)
        for item in itens:
            data = getattr(item, group_by)
            if data is None:
                data = []
            elif not type(data) is list:
                data = [data]

            if len(data) == 0:
                if Defaults.EMPTY not in tree:
                    tree[Defaults.EMPTY] = []
                tree[Defaults.EMPTY].append(item)
            else:
                for elem in data:  # inserting the elem in all tags or categories
                    if elem not in tree:
                        tree[elem] = []
                    tree[elem].append(item)
        output: List[Union[str, List[Item]]] = []

        for key in tree.keys():  # sorting the lists
            sorted_list = Sorter.sorted_by_key(tree[key], sort_by)
            output.append([key, sorted_list])
        output.sort(key=lambda x: x[0], reverse=reverse_sort)  # sorting the keys
        return output


class Board:
    @staticmethod
    def make_entry(item: Item, board_file: str) -> Tuple[str, str]:
        return "[](" + Util.get_directions(board_file, item.path_full) + ')', item.fulltitle

    @staticmethod
    def extract_path_and_fulltitle(line: str, board_path: str):
        parts = line.split(":")
        file_path = parts[0].strip()[3:-1]  # removing []( )
        fulltitle = ":".join(parts[1:]).strip()

        # change path relative to board to a path relative to base
        board_dir = Util.split_path(board_path)[0]
        path = Util.join([board_dir, file_path])
        return path, fulltitle

    @staticmethod
    def update_itens(itens: List[Item]):
        for item in itens:
            FileItem.write_from_item(item)

    @staticmethod
    def check_itens_for_update(board_content: str, board_path: str, itens: List[Item]):
        names_list = [x for x in board_content.split("\n") if x != ""]  # cleaning the empty lines
        itens_for_update = []
        for line in names_list:
            path, fulltitle = Board.extract_path_and_fulltitle(line, board_path)
            search = [item for item in itens if item.path_full == path]
            if len(search) == 0:
                print("  warning: file", path, "not found!")
            else:
                if search[0].fulltitle != fulltitle:
                    search[0].fulltitle = fulltitle
                    itens_for_update.append(search[0])
        return itens_for_update

    @staticmethod
    def generate(itens: List[Item], board_file: str, sort_by: str, reverse_sort: bool = False) -> str:
        sorted_list = Sorter.sorted_by_key(itens, sort_by, reverse_sort)
        # Util.create_dirs_if_needed(board_file)

        output = io.StringIO()
        pair_list: List[Tuple[str, str]] = []
        for item in sorted_list:
            pair_list.append(Board.make_entry(item, board_file))

        max_len_path = max([len(x[0]) for x in pair_list])

        for path, fulltitle in pair_list:
            output.write(path.ljust(max_len_path) + " : " + fulltitle + "\n")

        return output.getvalue()


class IndexConfig:
    def __init__(self, path, sort_by, group_by, toc, hook, reverse, key_filter):
        self.path = path
        self.sort_by = sort_by
        self.group_by = group_by
        self.insert_toc = toc
        self.insert_hook = hook
        self.reverse_sort = reverse
        self.key_filter = key_filter


class Index:
    @staticmethod
    # bool: generate_indices
    # bool: parse key to 01_Titulo_Coisado -> Titulo Coisado
    # bool: add hook
    def generate(itens: List[Item], param: IndexConfig, order: str) -> str:
        groups = Sorter.group_by(itens, param.group_by, param.sort_by, param.reverse_sort)
        output = io.StringIO()
        output.write("\n## Links\n")

        # gerando indices
        if param.insert_toc:
            for key, _item_list in groups:
                key = Util.key_filter(key) if param.key_filter else key
                link = Util.get_md_link(key)
                output.write("- [" + key + "](#" + link + ")\n")

        for key, item_list in groups:
            key = Util.key_filter(key) if param.key_filter else key
            output.write("\n## " + key + "\n\n")

            def calc_entry(item: Item) -> str:
                item_path = item.path_full + "#" + Util.get_md_link(item.fulltitle)
                prefix = ("@" + item.hook + " ") if param.insert_hook else ""
                entry = "- [" + prefix + item.title.strip() + "](" + Util.get_directions(param.path, item_path) + ")"
                return entry

            for item in item_list:
                entry = calc_entry(item)
                if item.subtitle != Defaults.EMPTY:
                    entry += " [" + item.subtitle + "]"
                output.write(entry + "\n")
        return output.getvalue()


class Links:
    @staticmethod
    def generate(itens: List[Item], links_dir: str):
        rmtree(links_dir, ignore_errors=True)
        os.mkdir(links_dir)
        for item in itens:
            path = os.path.join(links_dir, item.title.strip() + ".md")
            with open(path, "w") as f:
                link = Util.get_directions(path, item.path_full)
                f.write("[LINK](" + link + ")\n")


class HTML:
    """
    generate a html page from infile
    if remote_server not null, all reference to images begining with __
    will be updates to full url
    """

    @staticmethod
    def _generate_html(title: str, content: str, enable_latex: bool) -> str:
        temp_dir = tempfile.TemporaryDirectory()
        outfile = os.path.join(temp_dir.name, "out.html")
        infile = os.path.join(temp_dir.name, "in.md")
        with open(infile, "w") as f:
            f.write(content)

        fulltitle = title.replace('!', '\\!').replace('?', '\\?')
        cmd = ["pandoc", infile, '--metadata', 'pagetitle=' + fulltitle, '-s', '-o', outfile]
        if enable_latex:
            cmd.append("--mathjax")
        try:
            p = subprocess.Popen(cmd, stdout=PIPE, stderr=PIPE, universal_newlines=True)
            stdout, stderr = p.communicate()
            if stdout != "" or stderr != "":
                print(stdout)
                print(stderr)
            with open(outfile) as f:
                return f.read()
        except Exception as e:
            print("Erro no comando pandoc:", e)
            exit(1)

    @staticmethod
    def insert_remote_url(content: str, remote_url: str) -> str:
        regex = r"\[(.*)\]\((\s*)([^:\s]*)(\s*)\)"
        subst = "[\\1](" + remote_url + "\\3)"
        result = re.sub(regex, subst, content, 0, re.MULTILINE)
        return result

    @staticmethod
    #  remote_master is something like https://raw.githubusercontent.com/qxcodefup/arcade/master
    def generate(base: str, itens: List[Item], insert_hook: bool, enable_latex: bool, remote_master_url: str, rebuild_all: bool, output: str):
        for item in itens:
            hook = ("@" + item.hook) if insert_hook else ""

            payload = item.payload
            if remote_master_url != "":
                remote_hook = remote_master_url.rstrip("/") + "/" + base + "/" + item.hook + "/"
                payload = HTML.insert_remote_url(payload, remote_hook)

            md_content = "## " + hook + "\n" + item.fulltitle + "\n" + payload
            title = " ".join([hook, item.title])

            output_file = Util.join([item.base, item.hook, output])

            if FileItem.has_changes(item.path_full, output_file) or rebuild_all:
                print("  regenerating html for hook", item.hook)
                html_content = HTML._generate_html(title, md_content, enable_latex)
                with open(output_file, "w") as f:
                    f.write(html_content)


class VPL:
    @staticmethod
    def _generate_cases(infiles: List[str], outfile):
        cmd = ["tk", "build", '-f', outfile]
        for infile in infiles:
            if os.path.isfile(infile):
                cmd.append(infile)
        # cmd.append("-q")
        try:
            p = subprocess.Popen(cmd, stdout=PIPE, stderr=PIPE, universal_newlines=True)
            stdout, stderr = p.communicate()
            if stdout != "" or stderr != "":
                print(stdout)
                print(stderr)
        except Exception as e:
            print("Erro no comando th:", e)
            exit(1)

    @staticmethod
    def generate(itens: List[Item], rebuild_all: bool, output: str):
        for item in itens:
            output_file = Util.join([item.base, item.hook, output])
            extra_tests = Util.join([item.base, item.hook, "t.tio"])

            to_rebuild = False
            to_rebuild = to_rebuild or FileItem.has_changes(item.path_full, output_file)
            if os.path.isfile(extra_tests):
                to_rebuild = to_rebuild or FileItem.has_changes(extra_tests, output_file)
            if to_rebuild or rebuild_all:
                print("  regenerating .vpl for hook", item.hook)
                input_files = [item.path_full, extra_tests]
                VPL._generate_cases(input_files, output_file)


class Runner:
    @staticmethod
    def simple_run(cmd_list: List[str], input_data: str = "") -> str:
        p = subprocess.Popen(cmd_list, stdout=PIPE, stdin=PIPE, stderr=PIPE, universal_newlines=True)
        stdout, stderr = p.communicate(input=input_data)
        if p.returncode != 0:
            print(stderr)
            exit(1)
        return stdout


class Base:
    @staticmethod
    def find_files(base: str) -> List[str]:
        file_text = Runner.simple_run(["find", base, "-name", "Readme.md"])
        return [line for line in file_text.split("\n") if line != ""]

    @staticmethod
    def load_headers(file_list: List[str]) -> List[str]:
        headers = Runner.simple_run(["xargs", "-n", "1", "head", "-n", "1"], "\n".join(file_list))
        return headers.split("\n")

    @staticmethod
    def extract_hook_from_path(path: str, base: str):
        return path[len(base) + 1:-10]  # remove base and Readme.md

    @staticmethod
    def load_hook_header_from_base(base) -> List[Tuple[str, str]]:
        file_list = Base.find_files(base)
        header_list = Base.load_headers(file_list)
        hook_list = [Base.extract_hook_from_path(item, base) for item in file_list]  # remove base and Readme.md
        return list(zip(hook_list, header_list))


class Manual:
    @staticmethod
    def load_lines(path) -> List[str]:
        if os.path.isfile(path):
            with open(path) as f:
                return f.read().split("\n")
        else:
            with open(path, "w"):
                pass
        print("Warning: File", path, "not found, creating empty file")
        return []

    @staticmethod
    def search_hook(line: str) -> Optional[str]:
        parts = line.split("@")
        if len(parts) == 1:
            return None
        return parts[1].split("]")[0].split(" ")[0].split(")")[0]  # extracting token

    @staticmethod
    def calc_prefix(line: str):
        cont = 0
        for c in line:
            if c == ' ':
                cont += 1
            else:
                break
        return cont

    @staticmethod
    def refactor_line(line: str, hook: str, header: str, base: str, hide: bool, root: bool):
        prefix = Manual.calc_prefix(line)
        words = header.split(" ")
        tags = [word for word in words if word.startswith("#") and len(word) != word.count('#')]
        title = " ".join([word for word in words if not word.startswith("#")])
        line = ' ' * prefix + '- ['
        if not hide:
            line += '@' + hook + ' '
        line += title
        if root:
            line += '](' + Util.join([base, hook]) + ') '
        else:
            line += '](' + Util.join([base, hook, 'Readme.md']) + ') '

        extra = []
        if hide:
            extra.append('@' + hook)
        if len(tags) > 0:
            extra += tags
        if len(extra) > 0:
            line += " [](" + " ".join(extra) + ")"
        return line

    @staticmethod
    def find_header(hook_header_list: List[Tuple[Optional[str], Optional[str]]], hook: Optional[str]) -> Optional[str]:
        header = []
        if hook:
            header = [header for _hook, header in hook_header_list if _hook == hook]
        if len(header) == 0:
            return None
        else:
            return header[0]

    @staticmethod
    def load_line_hook_header_from_readme(line_list: List[str],
                                          hook_header_base: List[Tuple[Optional[str], Optional[str]]]) -> \
            List[Tuple[str, Optional[str], Optional[str]]]:
        hook_list = [Manual.search_hook(line) for line in line_list]
        header_list = [Manual.find_header(hook_header_base, hook) for hook in hook_list]
        return list(zip(line_list, hook_list, header_list))

    @staticmethod
    def generate_new_list(line_hook_header_readme, base, hide, root) -> List[str]:
        new_line_list = []
        for line, hook, header in line_hook_header_readme:
            if hook is None or header is None:
                new_line_list.append(line)
            else:
                new_line_list.append(Manual.refactor_line(line, hook, header, base, hide, root))
        return new_line_list

    @staticmethod
    def update_readme(line_list, new_line_list, path):
        if line_list != new_line_list:
            print("Updating", path)
            with open(path, "w") as f:
                f.write("\n".join(new_line_list))

    @staticmethod
    def find_not_used_hooks(line_hook_header_readme, hook_header_base, base, hide, show, root):
        hooks_readme = [item[1] for item in line_hook_header_readme]
        missing_hook_header = [pair for pair in hook_header_base if pair[0] not in hooks_readme]
        if show and len(missing_hook_header) > 0:
            print('Warning: There are entries not used:')
            for hook, header in missing_hook_header:
                print(Manual.refactor_line("", hook, header, base, hide, root))

    @staticmethod
    def find_not_found_hooks(line_hook_header_readme):
        line_list = [line for line, hook, _header in line_hook_header_readme if hook is not None and _header is None]
        if len(line_list) > 0:
            print("Warning: There are entries not found:")
            for line in line_list:
                print(line)

    @staticmethod
    def indexer(hook_header_base, base, path, hide, show, root):
        line_list = Manual.load_lines(path)
        line_hook_header_readme = list(Manual.load_line_hook_header_from_readme(line_list, hook_header_base))
        new_line_list = Manual.generate_new_list(line_hook_header_readme, base, hide, root)
        Manual.update_readme(line_list, new_line_list, path)
        Manual.find_not_used_hooks(line_hook_header_readme, hook_header_base, base, hide, show, root)
        Manual.find_not_found_hooks(line_hook_header_readme)


class Actions:
    @staticmethod
    def manual(base: str, file: str, hide_key: bool, show: bool, root: bool):
        hook_header_base = Base.load_hook_header_from_base(base)
        Manual.indexer(hook_header_base, base, file, hide_key, show, root)
        TOC.add_toc(file)

    @staticmethod
    def auto(base: str, path, sort_by, group_by, toc, hook, reverse, filter, order):
        itens = ItemRepository(base).load()
        print("Generating index")
        index_param = IndexConfig(path, sort_by, group_by, toc, hook, reverse, filter)
        index = Index.generate(itens, index_param, order)
        with open(index_param.path, "w") as f:
            f.write(index)

    @staticmethod
    def board(base, path, set_mode, sort_by, reverse_sort):
        itens = ItemRepository(base).load()

        if set_mode:
            print("Updating names using board")
            with open(path) as f:
                marked = Board.check_itens_for_update(f.read(), path, itens)
                Board.update_itens(marked)
            itens = ItemRepository(base).load()

        print("Generating board")
        board = Board.generate(itens, path, sort_by, reverse_sort)
        with open(path, "w") as f:
            f.write(board)

    @staticmethod
    def links(base, path):
        print("Generating links")
        itens = ItemRepository(base).load()
        Links.generate(itens, path)

    @staticmethod
    def html(base, remote, index, latex, rebuild, output):
        print("Generating htmls")
        itens = ItemRepository(base).load()
        itens = sorted(itens, key=lambda x: x.hook)
        HTML.generate(base, itens, index, latex, remote, rebuild, output)

    @staticmethod
    def vpl(base, rebuild, output):
        print("Generating vpl")
        itens = ItemRepository(base).load()
        itens = sorted(itens, key=lambda x: x.hook)
        VPL.generate(itens, rebuild, output)

    @staticmethod
    def update():
        tdir = tempfile.mkdtemp()
        installer = os.path.join(tdir, "installer.sh")
        cmd = ["wget", "https://raw.githubusercontent.com/senapk/indexer/master/install.sh", "-O", installer]
        data = Runner.simple_run(cmd)
        print(data)
        cmd = ["sh", installer]
        out = Runner.simple_run(cmd)
        print(out)
        return 0


class Main:
    @staticmethod
    def manual(args):
        Actions.manual(args.base, args.path, args.dindex, not args.dshow, args.root)

    @staticmethod
    def auto(args):
        Actions.auto(args.base, args.path, args.sort_by, args.group_by, not args.dtoc, not args.dindex, args.reverse, not args.dfilter, args.order)

    @staticmethod
    def board(args):
        Actions.board(args.base, args.path, args.set, args.sort_by, args.reverse)

    @staticmethod
    def links(args):
        Actions.links(args.base, args.path)

    @staticmethod
    def html(args):
        Actions.html(args.base, args.remote, not args.dindex, not args.dlatex, args.rebuild, args.output)

    @staticmethod
    def vpl(args):
        Actions.vpl(args.base, args.rebuild, args.output)

    @staticmethod
    def update(args):
        Actions.update()

    @staticmethod
    def main():
        parent_base = argparse.ArgumentParser(add_help=False)
        parent_base.add_argument('--base', '-b', type=str, default="base", help="path to dir with the questions")

        parser = argparse.ArgumentParser(prog='indexer')
        subparsers = parser.add_subparsers(title='sub commands', help='help for sub commands.')

        parser_m = subparsers.add_parser('manual', parents=[parent_base], help='create manual sorted index.')
        parser_m.add_argument('path', type=str, help="source file do load and rewrite")
        parser_m.add_argument('--dindex', action='store_true', help="disable index key")
        parser_m.add_argument('--dshow', action='store_true', help="disable show missing indexes")
        parser_m.add_argument('--root', action='store_true', help="link send to folder instead file")
        parser_m.set_defaults(func=Main.manual)

        parser_a = subparsers.add_parser('auto', parents=[parent_base], help='create auto sorted index.')
        parser_a.add_argument('path', type=str, help="source file do load and rewrite")
        parser_a.add_argument('--group_by', '-g', type=str, default='tag', help="group by: fulltitle, tille, tag, cat. Default: tag")
        parser_a.add_argument('--sort_by', '-s', type=str, default='title', help="sort by: fulltitle, tille, tag, cat. Default: title")
        parser_a.add_argument('--dtoc', action='store_true', help="disable toc")
        parser_a.add_argument('--dindex', action='store_true', help="disabe insert index")
        parser_a.add_argument('--dfilter', action='store_true', help="disable filter key")
        parser_a.add_argument('--order', type=str, help="tag sequence to use")
        parser_a.add_argument('--reverse', action='store_true', help="reverse sort")
        parser_a.set_defaults(func=Main.auto)

        parser_b = subparsers.add_parser('board', parents=[parent_base], help='get or set the board.')
        parser_b.add_argument('--path', '-p', type=str, default='board.md', help="source board file")
        parser_b.add_argument('--sort_by', type=str, default='title',
                              help="sort by: fulltitle, tille, tag, cat. Default: title")
        parser_b.add_argument('--set', '-s', action='store_true', help="set board instead get")
        parser_b.add_argument('--reverse', action='store_true', help="reverse sort")
        parser_b.set_defaults(func=Main.board)


        parser_l = subparsers.add_parser('links', parents=[parent_base], help='generate links for questions.')
        parser_l.add_argument('--path', '-p', type=str, default='.links', help="links dir")
        parser_l.set_defaults(func=Main.links)

        parser_h = subparsers.add_parser('html', parents=[parent_base], help='generate html for questions')
        parser_h.add_argument('--output', '-o', type=str, default=".html", help="name of output file")
        parser_h.add_argument('--remote', '-r', type=str, default="", help="root remote path")
        parser_h.add_argument('--dindex', action='store_true', help="disable insert index in name")
        parser_h.add_argument('--dlatex', action='store_true', help="disable latex rendering")
        parser_h.add_argument('--rebuild', action='store_true', help="force rebuild all")
        parser_h.set_defaults(func=Main.html)

        parser_v = subparsers.add_parser('vpl', parents=[parent_base], help='generate vpl for questions')
        parser_v.add_argument('--output', '-o', type=str, default=".vpl", help="name of output file")
        parser_v.add_argument('--rebuild', action='store_true', help="force rebuild all")
        parser_v.set_defaults(func=Main.vpl)

        parser_u = subparsers.add_parser('update', parents=[parent_base], help='update indexer')
        parser_u.set_defaults(func=Main.update)

        args = parser.parse_args()

        if len(sys.argv) == 1:
            print("choose one subcommand")
        else:
            try:
                args.func(args)
            except ValueError as e:
                print(str(e) + '\n')




if __name__ == '__main__':
    Main.main()

