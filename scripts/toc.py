#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import sys
from enum import Enum
from typing import List, Tuple, Any, Optional, Union
import os
import re
import shutil
import argparse
import subprocess
import tempfile
import io
from subprocess import PIPE

class TOC:
    @staticmethod
    def only_hashtags(x: str) -> bool:
        return len(x) == x.count("#") and len(x) > 0

    @staticmethod
    # generate md link for the text
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
    def merge_toc(readme_content, toc, tag_begin, tag_end):
        regex = tag_begin + r"(.*)" + tag_end
        found = re.search(regex, readme_content, re.MULTILINE | re.DOTALL)
        subst = tag_begin + "\\n" + toc + "\\n" + tag_end
        if found:
            merged_content = re.sub(regex, subst, readme_content, 0, re.MULTILINE | re.DOTALL)
            return True, merged_content
        else:
            return False, ""

    @staticmethod
    def make_toc(file_content):
        content = TOC.remove_code_blocks(file_content)

        lines = content.split("\n")
        disable_tag = "[]()"
        lines = [line for line in lines if TOC.only_hashtags(line.split(" ")[0]) and line.find(disable_tag) == -1]

        min_level = 1
        toc_lines = []
        for line in lines:
            level = (TOC.get_level(line) - 1) - min_level
            if level < 0:
                continue
            text = "    " * level + "- [" + TOC.get_content(line) + "](#" + TOC.get_md_link(line) + ")"
            toc_lines.append(text)
        toc_text = "\n".join(toc_lines) + "\n"
        return toc_text

    @staticmethod
    def add_toc(path):
        with open(path) as f:
            file_content = f.read()

        toc_text = TOC.make_toc(file_content)
        tag_begin = r"<!--TOC_BEGIN-->"
        tag_end = r"<!--TOC_END-->"
        result, merged_content = TOC.merge_toc(file_content, toc_text, tag_begin, tag_end)

        if result:
            if file_content != merged_content:
                print("toc updated")
                with open(path, "w") as f:
                    f.write(merged_content)
        else:
            print("Create an entry with the text:")
            print(tag_begin)
            print(tag_end)
            print("in your file.")
            print("Use '[]()' string in the lines that you want to hide in toc")

def main():
    path = ""
    if len(sys.argv) == 1:
        if os.path.isfile("Readme.md"):
            path = "Readme.md"
    else: 
        path = sys.argv[1]
    
    if path == "":
        print("use toc.py file.md")
        exit(1)
        
    TOC.add_toc(path)

main()

