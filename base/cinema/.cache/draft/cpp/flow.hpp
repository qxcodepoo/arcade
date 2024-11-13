//--------------------------------------------------------
// BIBLIOTECA HEADER ONLY PARA C++ 
//     MANIPULAÇÃO DE TEXTO
//         Text, Format, Write, Parse, Unpack, Split, Join
//     E PROGRAMAÇÃO FUNCIONAL
//         Map, Filter, Slice, Enumerate, Zip, ZipWith, Foreach
//     E ESTRUTURA PARA CRIAR E MANIPULAR PIPES
//         Pipe, Chain
//     EM MODO FUNÇÃO E MODO PIPELINE
//--------------------------------------------------------
//  VERSÃO 2.0.0
//  https://github.com/senapk/flow
//--------------------------------------------------------

#pragma once
#include <iostream>
#include <sstream>

#ifndef FLOW
#include <vector>
#include <list>
#include <array>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#endif


namespace fw {


//-------------------- PIPE -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

template <typename FN_ONE>
class Pipe {
    FN_ONE fn;
public:
    Pipe(FN_ONE fn): fn(fn) {}
    template <typename T>        auto operator()(T data) const            { return fn(data); }
    template <typename T> friend auto operator| (T data, const Pipe& obj) { return obj(data); }
};

//-------------------- CHAIN -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

// class to store a chain of functions and apply them in sequence
// to a given data when operator () is called

template<typename... Args>
class Chain {
    std::tuple<Args...> args;
public:
    Chain(Args ...args): args(std::forward<Args>(args)...){}
    template <typename T>
    auto operator()(const T& data) const {
        return std::apply([&data](auto&&... fns) { return (fns(data), ...); }, args);
    }
    template <typename T> 
    friend auto operator| (const T& data, Chain obj) { return obj(data); }
};


//-------------------- INPUT -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[input]]
/**
 * @note #### `input(istream source = std::cin) -> str`
 * 
 * @note - Extrai uma linha inteira e retorna como string.
 * @note - O padrão é o std::cin, mas pode ser um fluxo ou arquivo.
 * @note - Se não houver mais linhas, lança uma exceção.
 * 
 * @note #### Parâmetros
 * @note `param: source` Origem da linha.
 * @note `return` Linha lida.
 * @note `throws: std::runtime_error` Caso não haja mais linhas.
 * 
 * @note #### Exemplos
 * @note `auto line = input();`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#input
 */
inline std::string input(std::istream & is = std::cin)
//[[input]]
{
    std::string line;
    if (std::getline(is, line))
        return line;
    throw std::runtime_error("input empty");
}

struct Input {
/**
 * @note #### `input(istream source = std::cin) -> str`
 * 
 * @note - Extrai uma linha inteira e retorna como string.
 * @note - O padrão é o std::cin, mas pode ser um fluxo ou arquivo.
 * @note - Se não houver mais linhas, lança uma exceção.
 * 
 * @note #### Parâmetros
 * @note `param: source` Origem da linha.
 * @note `return` Linha lida.
 * @note `throws: std::runtime_error` Caso não haja mais linhas.
 * 
 * @note #### Exemplos
 * @note `auto line = input();`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#input
 */
    Input() {}
    std::string        operator()(std::istream& is = std::cin) const { return input(is); }
    friend std::string operator| (std::istream& is, const Input& obj) { return obj(is); }
};

//-------------------- RANGE -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

// [[range]]
/**
 * @note #### `range(int init, int end, int step = 1) -> vector<int>`
 * 
 * @note - Gera um vetor de inteiros de init até end, mas não incluindo end, com passo step.
 * 
 * @note #### Parâmetros
 * @note `param: init` início.
 * @note `param: end` limite superior.
 * @note `param: step` passo do incremento.
 * @note `return` vetor de inteiros.
 * 
 * @note #### Exemplos
 * @note `range(0, 10) | Join() | Write(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
 * @note `range(0, 10, 2) | Join() | Write(); // [0, 2, 4, 6, 8]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#range
 */
inline std::vector<int> range(int init, int end, int step = 1)
//[[range]]
{
    if (step == 0)
        throw std::runtime_error("step cannot be zero");
    std::vector<int> aux;
    if (step > 0) {
        for (int i = init; i < end; i += step) {
            aux.push_back(i);
        }
    } else {
        for (int i = init; i > end; i += step) {
            aux.push_back(i);
        }
    }
    return aux;
}

/**
 * @note #### `range(int end) -> vector<int>`
 * 
 * @note - Gera um vetor de inteiros de 0 até end, mas não incluindo end, com passo 1.
 * 
 * @note #### Parâmetros
 * @note `param: end` limite superior.
 * @note `return` vetor de inteiros.
 * 
 * @note #### Exemplos
 * @note `range(10) | Join() | Write(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#range
 */
inline std::vector<int> range(int end)
{
    return range(0, end, 1);
}

struct Range {
/**
 * @note #### `range(int end) -> vector<int>`
 * 
 * @note - Gera um vetor de inteiros de 0 até end, mas não incluindo end, com passo 1.
 * 
 * @note #### Parâmetros
 * @note `param: end` limite superior.
 * @note `return` vetor de inteiros.
 * 
 * @note #### Exemplos
 * @note `range(10) | Join() | Write(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#range
 */
    Range() : init(0), step(1) {};

    std::vector<int> operator()(int end) const {
        return range(init, end, step);
    }

    friend std::vector<int> operator|(int end, const Range& obj) {
        return obj(end);
    }

    int init {0};
    int end {0};
    int step {0};
};

//-------------------- TEXT HEADER  ----------------------
//--------------------------------------------------------
//--------------------------------------------------------

template <typename T>
inline std::string text(const T& data, const std::string& cfmt = "");

//-------------------- JOIN  -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

namespace hide {
    template <typename CONTAINER, typename FN> 
    std::string __join(const CONTAINER& container, const std::string& separator, FN fn) 
    { 
        std::stringstream ss;
        for (auto it = container.begin(); it != container.end(); ++it) {
            ss << (it == container.begin() ? "" : separator);
            ss << fn(*it);
        }
        return ss.str();
    }

    template <typename FN>
    std::string __join(const char * data, const std::string& separator, FN fn) 
    { 
        (void) separator;
        return fn(data);
    }

    template <typename... Ts, typename FN>
    std::string __join(std::tuple<Ts...> const &the_tuple, const std::string& separator, FN fn)
    {
        std::stringstream ss;
        std::apply( [&](Ts const &...tuple_args) {
                std::size_t n{0};
                ((ss << fn(tuple_args) << (++n != sizeof...(Ts) ? separator : "")), ...);
            }, the_tuple);
        return ss.str();
    }

    template <typename T1, typename T2, typename FN>
    std::string __join(const std::pair<T1, T2>& the_pair, const std::string& separator, FN fn)
    {
        std::stringstream ss;
        ss << fn(the_pair.first) << separator << fn(the_pair.second);
        return ss.str();
    }
}

//[[join]]
/**
 * @note #### `join(T container, str separator = ", ", str cfmt = "") -> str`
 * @note #### `T container| Join(str separator = ", ", str cfmt = "") -> str`
 * 
 * @note - Transforma um container, par ou tupla em string.
 * @note - Se os elementos não forem strings, eles serão transformados pela função `text`.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser transformado em string.
 * @note `param: separtor` demilitador utilizado para juntar os elementos.
 * @note `param: cfmt` fortação a ser aplicada em cada elemento do container.
 * @note `return` String com os elementos concatenados.
 * 
 * @note  #### Exemplos
 * @note `join(vector<int>{1, 2, 3}, " ") | Write(); // "1 2 3"`
 * @note `vector<int>{1, 2, 3} | Join("=") | Write(); // "1=2=3"`
 * @note `vector<int>{1, 2, 3} | Join("; ") | Text("[{}]") | Write(); // "[1; 2; 3]"`
 * @note `vector<int>{1, 2, 3} | Join("; ", "%02d") | Text("[{}]") | Write(); // "[01; 02; 03]"`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/flow#join
 */
template <typename T>
std::string join(const T& container, const std::string& separator = ", ", const std::string& cfmt = "")
//[[join]]
{
    return hide::__join(container, separator, [&](auto x) { return text(x, cfmt);});  //debug
}

struct Join {
    std::string separator;
    std::string cfmt;

/**
 * @note #### `join(T container, str separator = ", ", str cfmt = "") -> str`
 * @note #### `T container| Join(str separator = ", ", str cfmt = "") -> str`
 * 
 * @note - Transforma um container, par ou tupla em string.
 * @note - Se os elementos não forem strings, eles serão transformados pela função `text`.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser transformado em string.
 * @note `param: separtor` demilitador utilizado para juntar os elementos.
 * @note `param: cfmt` fortação a ser aplicada em cada elemento do container.
 * @note `return` String com os elementos concatenados.
 * 
 * @note  #### Exemplos
 * @note `join(vector<int>{1, 2, 3}, " ") | Write(); // "1 2 3"`
 * @note `vector<int>{1, 2, 3} | Join("=") | Write(); // "1=2=3"`
 * @note `vector<int>{1, 2, 3} | Join("; ") | Text("[{}]") | Write(); // "[1; 2; 3]"`
 * @note `vector<int>{1, 2, 3} | Join("; ", "%02d") | Text("[{}]") | Write(); // "[01; 02; 03]"`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/flow#join
 */
    Join(const std::string& separator = ", ", const std::string& cfmt = "") : separator(separator), cfmt(cfmt) {}
    template <typename CONTAINER> std::string operator()(const CONTAINER& v) const { return join(v, separator, cfmt); }
    template <typename T> friend std::string operator|(const T& v, const Join& obj) { return obj(v); }
};

//-------------------- TEXT ------------------------------
//--------------------------------------------------------
//--------------------------------------------------------
namespace hide {
class Braces {
    public:
        //transforma {{ em \a e }} em \b
    static std::string preprocess(std::string data) {
        std::string result1;
        data.push_back('_');
        for (int i = 0; i < (int) data.size() - 1; i++) {
            if (data[i] == '{' && data[i + 1] == '{') {
                result1.push_back('\a');
                i++;
            } else {
                result1.push_back(data[i]);
            }
        }
        std::string result2;
        for (int i = result1.size() - 1; i >= 0; i--) {
            if (result1[i] == '}' && result1[i - 1] == '}') {
                result2.push_back('\b');
                i--;
            } else {
                result2.push_back(result1[i]);
            }
        }
        std::string final_result;
        for (int i = result2.size() - 1; i >= 0; i--) {
            final_result.push_back(result2[i]);
        }
        return final_result;
    }

    static std::pair<std::vector<std::string>, std::vector<std::string>> extract(std::string data)
    {
        data = preprocess(data);
        std::vector<std::string> texts = {""};
        std::vector<std::string> ctrls = {""};
        auto* destiny = &texts;

        for (char c : data) {
            if (c == '{') 
            {
                texts.push_back("");
                destiny = &ctrls;
            }
            else if (c == '}') 
            {
                ctrls.push_back("");
                destiny = &texts;
            }
            else
            {
                if (c == '\a') {
                    c = '{';
                } else if (c == '\b') {
                    c = '}';
                }
                destiny->back().append(std::string(1,c));
            }
        }
        while (texts.size() > ctrls.size())
            ctrls.push_back("");
        return {texts, ctrls};
    }

    static std::string combine(const std::vector<std::string>& texts, const std::vector<std::string>& vars) {
        if(vars.size() < texts.size() - 1) {
            throw std::out_of_range("");
        }
        std::stringstream ss;
        for (size_t i = 0; i < vars.size(); i++)
            ss << texts[i] << vars[i];
        ss << texts.back(); //ultimo texto
        return ss.str();
    }
};

class Align {
    char align_mode { 0 }; //< > or ^, default is center
    int  align_size { 0 }; //size of the field
    char pad_char   { ' ' }; //char used to pad the field
    std::string format { "" }; //filtered format string

    bool extract_align() {
        std::string align_str_size;

        size_t i {0}, j {0};
        for (i = 0; i < format.size(); ++i) {
            if (format[i] == '<' || format[i] == '>' || format[i] == '^') { //achei o alinhamento
                this->align_mode = format[i];

                for (j = i + 1; j < format.size(); ++j) { //extraindo o tamanho do alinhamento
                    if (format[j] >= '0' && format[j] <= '9') {
                        align_str_size += format[j];
                    } else { // terminou o tamanho
                        break;
                    }
                }
                if (align_str_size.empty()) {
                    this->align_size = 0;
                    std::cout << "fail: format symbol `" << format[i] << "` must be followed by a size\n";
                    exit(1);
                }
                this->align_size = std::stoi(align_str_size);
                this->format.erase(i, j - i);
                return true;
            }
        }
        return false;
    }

    void extract_pad() {
        // search for : char in format, if exists and is followed by a char, 
        // then use that char as padding, and remove both from string
        auto pos = this->format.find(':');
        if (pos != std::string::npos) {
            if (pos + 1 < format.size()) {
                this->pad_char = format[pos + 1];
                this->format.erase(pos, 2);
            } else {
                std::cout << "fail: format symbol `:` must be followed by a padding char\n";
                exit(1);
            }
        }
    }
public:

    Align(const std::string& format) {
        this->format = format;
        this->extract_pad();
        this->extract_align();
    }

    std::string align_text(const std::string& str) {
        int len = str.length();
        if(this->align_mode == 0 || this->align_size < len) { 
            return str; 
        }
        int diff = this->align_size - len;
        
        //default is center
        int padleft = diff/2;
        int padright = diff - padleft;
        if(this->align_mode == '>') {
            padleft = diff;
            padright = 0;
        }
        else if(this->align_mode == '<') {
            padleft = 0;
            padright = diff;
        }
        return std::string(padleft, this->pad_char) + str + std::string(padright, this->pad_char);
    }

    const std::string& get_filtered_format() {
        return this->format;
    }
    int get_align_size() {
        return this->align_size;
    }
    char get_pad_char() {
        return this->pad_char;
    }
    char get_align_mode() {
        return this->align_mode;
    }
};
}

class Text {

    template <typename T>
    static inline std::string ss_transform(const T& data) {
        std::ostringstream ss;
        ss << data;
        return ss.str();
    }

    template <typename... Ts>
    static inline std::string cformat(const std::string &fmt, Ts... vs) {
        auto __format = [](const std::string &fmt, auto... vs) {
            char b;
            size_t required = std::snprintf(&b, 0, fmt.c_str(), vs...) + 1;
            char bytes[required];
            std::snprintf(bytes, required, fmt.c_str(), vs...);
            return std::string(bytes);
        };
        return __format(fmt, [&vs](){
            if constexpr (std::is_same_v<std::string, Ts>) {
                return vs.c_str();
            } else {
                return vs;
            }
        }()...);
    }

    template <typename T>
    static inline std::string process(const T& data, const std::string& cfmt) {
        hide::Align align(cfmt);
        std::string filtered = align.get_filtered_format();

        if (filtered == "") {
            return align.align_text(ss_transform(data));
        }
        if (filtered.find(" ") != std::string::npos) {
            std::cout << "fail: cfmt não pode conter espaços ou %\n";
            exit(1);
        }
        return align.align_text(cformat(filtered, data));
    }

    template <typename A, typename B>
    static inline std::string process(const std::pair<A, B>& pair, const std::string& cfmt) {
        return join(pair, ", ", cfmt) | Text("({})");
    }

    template <typename... Ts>
    static inline std::string process(const std::tuple<Ts...>& tuple, const std::string& cfmt) {
        return join(tuple, ", ", cfmt) | Text("({})");
    }


#ifndef FLOW
    template <typename PRINTABLE> 
    static inline std::string process(const std::vector<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("[{}]");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::list<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("[{}]");
    }
    template <typename PRINTABLE, size_t S> 
    static inline std::string process(const std::array<PRINTABLE, S>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("[{}]");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::set<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
    template <typename PRINTABLE> 
    static inline std::string process(const std::unordered_set<PRINTABLE>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
    template <typename A, typename B> 
    static inline std::string process(const std::map<A, B>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
    template <typename A, typename B>
    static inline std::string process(const std::unordered_map<A, B>& container, const std::string& cfmt) {
        return join(container, ", ", cfmt) | Text("{{{}}}");
    }
#endif

private:

    std::string cfmt;

public:

/**
 * @note #### `text(T data,  str cfmt = "") -> str`
 * @note #### `T data | Text(str cfmt = "") -> str`
 * @note - Converte o dado passado em string.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser convertido.
 * @note `param: cfmt`: parâmetro de formatação tal qual printf como "%.2f"
 * @note `param: cfmt`: modo de formatação usando braces para substituição "antes {%2f} depois"
 * @note `return` String com o dado convertido.
 * 
 * @note #### Funcionamento para tipos primitivos
 * @note - Converte o dado em string.
 * @note - Se `cfmt` for passado, o dado será formatado usando o modelo do `printf`.
 * @note - Se não tiver `cfmt`, o dado será convertido diretamente para string usando operator<<
 * @note `text(1.2) | Write(); // "1.2"
 * @note `text(1.2, "%.4f") | Write(); // "1.2000"
 * @note `1.2 | Text("%.4f") | Write(); // "1.2000"
 * @note `text(1.2, "%.4f") | Write(); // "1.2000"`
 * 
 * @note #### Utilizando {} como placeholder
 * @note - O {} pode ser utilizado como o local onde a variável será inserida.
 * @note - O conteúdo do {} será formatado de acordo com o `cfmt`.
 * @note "domingo" | Text("Hoje é {}.") | Write(); // "Hoje é domingo."
 * @note 3.1415 | Text("O valor de pi é {%.2f}.") | Write(); // "O valor de pi é 3.14."
 * 
 * @note #### Funcionamento para pair e tuple
 * @note - Para pair e tuple, o texto é gerado com os elementos separados por vírgula.
 * @note `text(std::pair<int, int>(2, 1)) | Write(); // "(2, 1)"`
 * 
 * @note #### Padding e alinhamento
 * @note - O alinhamento pode ser feito com <, > ou ^.
 * @note - O tamanho do campo pode ser definido com um número.
 * @note - O padding pode ser feito com qualquer caractere e definido pelo símbolo :.
 * @note `text(1.2, "<10:_") | Write(); // "1.2_______"`
 * @note `text(1.2, ">10:_") | Write(); // "_______1.2"`
 * @note `text(1.2, "^10:_") | Write(); // "___1.2____"`
 * @note `text(1.2, "<10:0") | Write(); // "1.20000000"`
 * @note `"amigo" | Text("Meu {^10:0}.") | Write(); // "Meu 00amigo000."`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/flow#text
 */
    Text(std::string cfmt = ""): cfmt(cfmt) { }
    
    template <typename T>
    std::string operator()(const T& data) const {
        if (cfmt.find("{") == std::string::npos) {
            return process(data, cfmt);
        }
        auto [texts, controls] = hide::Braces::extract(cfmt);
        try {
            auto result = process(data, controls.at(0));
            return hide::Braces::combine(texts, {result});
        } catch (std::out_of_range& e) {
            std::cout << "fail: verifique a quantidade de parâmetros passado para string: " << cfmt << '\n';
            exit(1);
        }
    }

    template <typename T>
    friend std::string operator|(const T& v, const Text& obj) { return obj(v); }
};

//[[text]]
/**
 * @note #### `text(T data,  str cfmt = "") -> str`
 * @note #### `T data | Text(str cfmt = "") -> str`
 * @note - Converte o dado passado em string.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser convertido.
 * @note `param: cfmt`: parâmetro de formatação tal qual printf como "%.2f"
 * @note `param: cfmt`: modo de formatação usando braces para substituição "antes {%2f} depois"
 * @note `return` String com o dado convertido.
 * 
 * @note #### Funcionamento para tipos primitivos
 * @note - Converte o dado em string.
 * @note - Se `cfmt` for passado, o dado será formatado usando o modelo do `printf`.
 * @note - Se não tiver `cfmt`, o dado será convertido diretamente para string usando operator<<
 * @note `text(1.2) | Write(); // "1.2"
 * @note `text(1.2, "%.4f") | Write(); // "1.2000"
 * @note `1.2 | Text("%.4f") | Write(); // "1.2000"
 * @note `text(1.2, "%.4f") | Write(); // "1.2000"`
 * 
 * @note #### Utilizando {} como placeholder
 * @note - O {} pode ser utilizado como o local onde a variável será inserida.
 * @note - O conteúdo do {} será formatado de acordo com o `cfmt`.
 * @note "domingo" | Text("Hoje é {}.") | Write(); // "Hoje é domingo."
 * @note 3.1415 | Text("O valor de pi é {%.2f}.") | Write(); // "O valor de pi é 3.14."
 * 
 * @note #### Funcionamento para pair e tuple
 * @note - Para pair e tuple, o texto é gerado com os elementos separados por vírgula.
 * @note `text(std::pair<int, int>(2, 1)) | Write(); // "(2, 1)"`
 * 
 * @note #### Padding e alinhamento
 * @note - O alinhamento pode ser feito com <, > ou ^.
 * @note - O tamanho do campo pode ser definido com um número.
 * @note - O padding pode ser feito com qualquer caractere e definido pelo símbolo :.
 * @note `text(1.2, "<10:_") | Write(); // "1.2_______"`
 * @note `text(1.2, ">10:_") | Write(); // "_______1.2"`
 * @note `text(1.2, "^10:_") | Write(); // "___1.2____"`
 * @note `text(1.2, "<10:0") | Write(); // "1.20000000"`
 * @note `"amigo" | Text("Meu {^10:0}.") | Write(); // "Meu 00amigo000."`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/flow#text
 */
template <typename T>
inline std::string text(const T& data, const std::string& cfmt)
//[[text]]
{
    return Text(cfmt)(data);
}

//-------------------- FORMAT ----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

template<typename... Args>
class Format 
{
    std::tuple<Args...> args;

    std::vector<std::string> tuple_to_vector_str(const std::vector<std::string>& controls)
    {
        std::vector<std::string> result;
        std::apply
        (
            [&result, &controls](Args const&... tupleArgs)
            {
                int i = -1;
                ((result.push_back(text(tupleArgs, controls.at(++i)))), ...);
            }, this->args
        );

        return result;
    }
public:

/**
 * @note #### `format(str fmt, Args ...args ) -> str`
 * @note #### `str fmt| FORMAT(Args ...args ) -> str`
 * 
 * @note - Formata uma string com base nos argumentos passados.
 * @note - A função `text` é chamada para cada argumento {}
 * @note - Utilizando um modelo de chaves para posicionar os argumentos.
 * @note - Se dentro da chave, houver um string de formatação, o dado será formatado com base nela.
 * @note - Não primitivos são formatados de acordo com a função `text`
 * 
 * @note #### Parâmetros
 * @note `param: fmt` O texto com os {} para substituir pelos argumentos.
 * @note `param: args` Os argumentos a serem substituídos.
 * @note `return` O texto formatado.
 * 
 * @note #### Exemplos
 * @note `format("O {} é {%0.2f}.", "pi", 3.141592653) | Write(); //o pi e 3.14.`
 * @note `"O {} é {%0.2f}." | Format("pi", 3.141592653) | Write(); //o pi e 3.14.`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#format
 * 
 */
    Format(Args ...args): args(std::forward<Args>(args)...){}

    std::string operator()(std::string fmt)
    {
        auto [texts, controls] = hide::Braces::extract(fmt);
        try {
            auto vars = tuple_to_vector_str(controls);
            return hide::Braces::combine(texts, vars);
        } catch (std::out_of_range& e) {
            std::cout << "fail: verifique a quantidade de parâmetros passado para string: " << fmt << '\n';
            exit(1);
        }
    }

    friend std::string operator|(std::string fmt, Format<Args...> obj) { return obj(fmt); }
};

//[[format]]
/**
 * @note #### `format(str fmt, Args ...args ) -> str`
 * @note #### `str fmt| FORMAT(Args ...args ) -> str`
 * 
 * @note - Formata uma string com base nos argumentos passados.
 * @note - A função `text` é chamada para cada argumento {}
 * @note - Utilizando um modelo de chaves para posicionar os argumentos.
 * @note - Se dentro da chave, houver um string de formatação, o dado será formatado com base nela.
 * @note - Não primitivos são formatados de acordo com a função `text`
 * 
 * @note #### Parâmetros
 * @note `param: fmt` O texto com os {} para substituir pelos argumentos.
 * @note `param: args` Os argumentos a serem substituídos.
 * @note `return` O texto formatado.
 * 
 * @note #### Exemplos
 * @note `format("O {} é {%0.2f}.", "pi", 3.141592653) | Write(); //o pi e 3.14.`
 * @note `"O {} é {%0.2f}." | Format("pi", 3.141592653) | Write(); //o pi e 3.14.`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#format
 * 
 */
template<typename... Args>
std::string format(std::string fmt, Args ...args) 
//[[format]]
{
    return Format<Args...>(args...)(fmt); 
}

//-------------------- Write -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

struct Write {
    std::string end;

    template <typename PRINTABLE> 
    const PRINTABLE& process(const PRINTABLE& data, std::string end) {
        std::cout << text(data) << end;
        return data;
    }


/**
 * @note #### `write(T data, str end = "\n") -> T`
 * @note #### `T data| Write(str end = "\n") -> T`
 * 
 * @note - Envia o dado para o `std::cout` quebrando a linha.
 * @note - Se o dado não for uma `string`, será convertido pela função `text`.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser transformado e impresso.
 * @note `param: end` (opcional) String a ser inserida no final da linha.
 * @note `return` O dado original recebido.
 * 
 * @note #### Exemplos
 * @note `vector<int> {1, 2, 3} | Join() | Write(); // [1, 2, 3]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#write
 */
    Write(std::string end = "\n"): end(end) { }
    template <typename PRINTABLE>        const PRINTABLE& operator()(const PRINTABLE& data           ) { return process(data, end); }
    template <typename PRINTABLE> friend const PRINTABLE& operator| (const PRINTABLE& data, Write obj) { return obj(data); }
};

//[[write]]
/**
 * @note #### `write(T data, str end = "\n") -> T`
 * @note #### `T data| Write(str end = "\n") -> T`
 * 
 * @note - Envia o dado para o `std::cout` quebrando a linha.
 * @note - Se o dado não for uma `string`, será convertido pela função `text`.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser transformado e impresso.
 * @note `param: end` (opcional) String a ser inserida no final da linha.
 * @note `return` O dado original recebido.
 * 
 * @note #### Exemplos
 * @note `vector<int> {1, 2, 3} | Join() | Write(); // [1, 2, 3]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#write
 */
template <typename PRINTABLE> 
const PRINTABLE& write(const PRINTABLE& data, std::string end = "\n") 
//[[write]]
{
    data | Write(end);
    return data;
}

//-------------------- Map   -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[map]]
/**
 * @note #### `map(CONTAINER<T> container, FUNCTION fn) -> vector<fn(T)>`
 * @note #### `CONTAINER<T> container| Map(FUNCTION fn) -> vector<fn(T)>`
 * 
 * @note - Retorna um vetor com o resultado da aplicação da função fn para cada elemento do container.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser mapeado.
 * @note `param: fn` Função a ser aplicada em cada elemento do container.
 * @note `return` Vector com os elementos resultantes da aplicação da função.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `map(vet, [](int x) {return x * x;}) | Join() | Write(); // [1, 4, 9]`
 * @note `vet| Map([](int x) {return x * x;}) | Join() | Write(); // [1, 4, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#map
 */
template<typename CONTAINER, typename FUNCTION>
auto map(const CONTAINER& container, FUNCTION fn)
//[[map]]
{
    std::vector<decltype(fn(*container.begin()))> aux;
    for (const auto& item : container)
        aux.push_back(fn(item));
    return aux;
}

template <typename FUNCTION>
struct Map {
    FUNCTION fn;
/**
 * @note #### `map(CONTAINER<T> container, FUNCTION fn) -> vector<fn(T)>`
 * @note #### `CONTAINER<T> container| Map(FUNCTION fn) -> vector<fn(T)>`
 * 
 * @note - Retorna um vetor com o resultado da aplicação da função fn para cada elemento do container.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser mapeado.
 * @note `param: fn` Função a ser aplicada em cada elemento do container.
 * @note `return` Vector com os elementos resultantes da aplicação da função.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `map(vet, [](int x) {return x * x;}) | Join() | Write(); // [1, 4, 9]`
 * @note `vet| Map([](int x) {return x * x;}) | Join() | Write(); // [1, 4, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#map
 */
    Map(FUNCTION fn) : fn(fn) {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return map(container, fn); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Map& obj) { return obj(container); }
};

//-------------------- Split -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[split]]
/**
 * @note #### `split(str content, char delimiter = " ") -> vector<str>`
 * @note #### `str content| Split(char delimiter = " ") -> vector<str>`
 * 
 * @note - Transforma uma string em um vetor de strings, separando pelo delimitador.
 * 
 * @note #### Parâmetros
 * @note `param: content` String a ser separada.
 * @note `param: delimiter` (opcional) Caractere delimitador.
 * @note `return` Vetor de strings.
 *
 * @note #### Exemplos
 * @note `split("a,b,c", ",") | Join() | Write(); // [a, b, c]`
 * @note `"a,b,c"| Split(",") | Join() | Write(); // [a, b, c]`
 * @note `"a, b, c"| Split(", ") | Join() | Write(); // [a, b, c]`
 * @note `split("a b c") | Join() | Write(); // [a, b, c]`
 * @note `"a b c"|Split()| Join() | Write(); // [a, b, c]`
 *  
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#split
 */
inline std::vector<std::string> split(std::string content, std::string delimiter = " ")
//[[split]]
{
    std::vector<std::string> aux;
    size_t pos = 0;
    while ((pos = content.find(delimiter)) != std::string::npos) {
        std::string token = content.substr(0, pos);
        aux.push_back(token);
        content.erase(0, pos + delimiter.length());
    }
    aux.push_back(content);
    return aux;
}

struct Split {
    std::string delimiter;
/**
 * @note #### `split(str content, char delimiter = " ") -> vector<str>`
 * @note #### `str content| Split(char delimiter = " ") -> vector<str>`
 * 
 * @note - Transforma uma string em um vetor de strings, separando pelo delimitador.
 * 
 * @note #### Parâmetros
 * @note `param: content` String a ser separada.
 * @note `param: delimiter` (opcional) Caractere delimitador.
 * @note `return` Vetor de strings.
 *
 * @note #### Exemplos
 * @note `split("a,b,c", ",") | Join() | Write(); // [a, b, c]`
 * @note `"a,b,c"| Split(",") | Join() | Write(); // [a, b, c]`
 * @note `"a, b, c"| Split(", ") | Join() | Write(); // [a, b, c]`
 * @note `split("a b c") | Join() | Write(); // [a, b, c]`
 * @note `"a b c"|Split()| Join() | Write(); // [a, b, c]`
 *  
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#split
 */
    Split(std::string delimiter = " ") : delimiter(delimiter) {}

    std::vector<std::string>        operator()(std::string content) const { return split(content, delimiter); }
    friend std::vector<std::string> operator| (std::string content, const Split& obj) { return obj(content); }
};

//--------------------------------------------------------
//-------------------- Slice -----------------------------
//--------------------------------------------------------

class Slice {

    template<typename CONTAINER>
    static auto new_vec_from(const CONTAINER& container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<decltype(fn(*container.begin()))> aux;
        return aux;
    }

    template<typename CONTAINER>
    std::pair<int, int> calc_limits(const CONTAINER& container) const {
        int size = container.size();
        int begin = 0;
        int end = size;
        if (!this->from_begin && !this->to_end && (this->begin == this->end)) {
            return {0, 0};
        }
        if (!this->from_begin) {
            begin = this->begin;
            if (begin < 0)
                begin = size + begin;
            begin = std::min(begin, size);
        }
        if (!this->to_end) {
            end = this->end;
            if (end < 0)
                end = size + end;
            end = std::min(end, size);
        }
        return {begin, end};
    }

    template<typename CONTAINER>
    auto process(const CONTAINER& container) const {
        auto [begin, end] = calc_limits(container);
        auto aux = Slice::new_vec_from(container);
        auto it = container.begin();
        std::advance(it, begin);
        for (int i = begin; i < end; i++) {
            aux.push_back(*it);
            it++;
        }
        return aux;
    }

    std::string process(const std::string& container) const {
        auto [begin, end] = calc_limits(container);
        std::string aux;
        for (int i = begin; i < end; i++) {
            aux.push_back(container[i]);
        }
        return aux;
    }

    std::string process(const char * container) const {
        return process(std::string(container));
    }


public:

/**
 * @note #### `slice(CONTAINER<T> container, int begin = 0) -> vector<T>`
 * @note #### `slice(      string container, int begin = 0) -> string`

 * @note #### `CONTAINER<T> container| Slice(int begin = 0) -> vector<T>`
 * @note #### `      string container| Slice(int begin = 0) -> string`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript.
 * @note - Se não passado nenhum parâmetro, copia todos os elementos.
 * @note - Os índices podem ser negativos para contar a partir final.
 * @note - Se o container for uma string, retorna uma string.
 * @note - Se o container for qualquer outro como vetor, set, map, list, array, retorna um vetor.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` (opcional) índice inicial.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1)  | Join() | Write(); // [2, 3, 4, 5]`
 * @note `slice(vet, -2) | Join() | Write(); // [4, 5]`
 * @note `vet | Slice(1) | Join() | Write(); // [2, 3, 4, 5]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#slice
 */
    Slice(int begin = 0) {
        this->from_begin = begin == 0;
        this->begin = begin;
        this->to_end = true;
    }



/**
 * @note #### `slice(CONTAINER<T> container, int begin, int end) -> vector<T>`
 * @note #### `CONTAINER<T> container| Slice(int begin, int end) -> vector<T>`
 * @note #### `slice(string container, int begin, int end) -> string`
 * @note #### `string container| Slice(int begin, int end) -> string`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript. 
 * @note - Os índices podem ser negativos para indicar que a contagem deve ser feita a partir do final.
 * @note - Se o container for uma string, retorna uma string.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` índice inicial.
 * @note `param: end` índice final.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1, -1) | Join() | Write(); // [2, 3, 4]`
 * @note `vet| Slice(1, -1) | Join() | Write(); // [2, 3, 4]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#slice
 */
    Slice(int begin, int end) {
        this->begin = begin;
        this->end = end;
        this->from_begin = false;
        this->to_end = false;
    }

    template<typename CONTAINER>
    auto operator()(const CONTAINER& container) const {
        return process(container);
    }
    
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Slice& obj) { return obj(container); }

private:
    int begin;
    int end;
    bool from_begin {false};
    bool to_end {false};
};

//[[slice1]]

/**
 * @note #### `slice(CONTAINER<T> container, int begin = 0) -> vector<T>`
 * @note #### `slice(      string container, int begin = 0) -> string`

 * @note #### `CONTAINER<T> container| Slice(int begin = 0) -> vector<T>`
 * @note #### `      string container| Slice(int begin = 0) -> string`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript.
 * @note - Se não passado nenhum parâmetro, copia todos os elementos.
 * @note - Os índices podem ser negativos para contar a partir final.
 * @note - Se o container for uma string, retorna uma string.
 * @note - Se o container for qualquer outro como vetor, set, map, list, array, retorna um vetor.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` (opcional) índice inicial.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1)  | Join() | Write(); // [2, 3, 4, 5]`
 * @note `slice(vet, -2) | Join() | Write(); // [4, 5]`
 * @note `vet | Slice(1) | Join() | Write(); // [2, 3, 4, 5]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#slice
 */
template<typename CONTAINER>
auto slice(const CONTAINER& container, int begin = 0)
//[[slice1]]
{
    return Slice(begin)(container);
}



/**
 * @note #### `slice(CONTAINER<T> container, int begin, int end) -> vector<T>`
 * @note #### `CONTAINER<T> container| Slice(int begin, int end) -> vector<T>`
 * @note #### `slice(string container, int begin, int end) -> string`
 * @note #### `string container| Slice(int begin, int end) -> string`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript. 
 * @note - Os índices podem ser negativos para indicar que a contagem deve ser feita a partir do final.
 * @note - Se o container for uma string, retorna uma string.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` índice inicial.
 * @note `param: end` índice final.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1, -1) | Join() | Write(); // [2, 3, 4]`
 * @note `vet| Slice(1, -1) | Join() | Write(); // [2, 3, 4]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#slice
 */
template<typename CONTAINER>
auto slice(CONTAINER container, int begin, int end)
{
    return Slice(begin, end)(container);
}

//-------------------- FILTER ----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[filter]]
/**
 * @note #### `filter(CONTAINER<T> container, FUNCTION fn) -> vector<T>`
 * @note #### `CONTAINER<T> container| FILTER(FUNCTION fn) -> vector<T>`
 * 
 * @note - Retorna um vetor com os elementos do container que satisfazem a função predicado fn.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser filtrado.
 * @note `param: fn` Função predicado.
 * @note `return` Vector com os elementos que satisfazem a função predicado.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `filter(vet, [](int x) {return x % 2 == 0;}) | Join() | Write(); // [2]`
 * @note `vet| Filter([](int x) {return x % 2 == 0;}) | Join() | Write(); // [2]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#filter
 * 
 */
template<typename CONTAINER, typename FUNCTION>
auto filter(const CONTAINER& container, FUNCTION fn)
//[[filter]]
{
    auto aux = slice(container, 0, 0);
    for(const auto& x : container) {
        if(fn(x))
            aux.push_back(x);
    }
    return aux;
}

template <typename FUNCTION>
struct Filter {
    FUNCTION fn;

/**
 * @note #### `filter(CONTAINER<T> container, FUNCTION fn) -> vector<T>`
 * @note #### `CONTAINER<T> container| FILTER(FUNCTION fn) -> vector<T>`
 * 
 * @note - Retorna um vetor com os elementos do container que satisfazem a função predicado fn.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser filtrado.
 * @note `param: fn` Função predicado.
 * @note `return` Vector com os elementos que satisfazem a função predicado.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `filter(vet, [](int x) {return x % 2 == 0;}) | Join() | Write(); // [2]`
 * @note `vet| Filter([](int x) {return x % 2 == 0;}) | Join() | Write(); // [2]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#filter
 * 
 */
    Filter(FUNCTION fn) : fn(fn) {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return filter(container, fn); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Filter& obj) { return obj(container); }
};

//-------------------- Enumerate -------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[enumerate]]

/**
 * @note #### `enumerate(CONTAINER<T> container) -> vector<pair<int, T>>`
 * @note #### `CONTAINER<T> container|Enumerate()-> vector<pair<int, T>>`
 * 
 * @note - Retorna um vetor de pares com os indices seguidos dos elementos originais do vetor.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser enumerado.
 * @note `return` Vector com os pares.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `enumerate(vet) | Join() | Write(); // [(0, 1), (1, 2), (2, 3)]`
 * @note `vet|Enumerate()| Join() | Write(); // [(0, 1), (1, 2), (2, 3)]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#enumerate
 */
template<typename CONTAINER>
auto enumerate(const CONTAINER& container)
//[[enumerate]]
{
    auto fn = [](auto x) {return x;}; 
    std::vector<std::pair<int, decltype(fn(*container.begin()))>> aux;
    int i = 0;
    for (const auto& item : container) {
        aux.push_back(std::make_pair(i, item));
        i++;
    }
    return aux;
}

struct Enumerate {

/**
 * @note #### `enumerate(CONTAINER<T> container) -> vector<pair<int, T>>`
 * @note #### `CONTAINER<T> container|Enumerate()-> vector<pair<int, T>>`
 * 
 * @note - Retorna um vetor de pares com os indices seguidos dos elementos originais do vetor.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser enumerado.
 * @note `return` Vector com os pares.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `enumerate(vet) | Join() | Write(); // [(0, 1), (1, 2), (2, 3)]`
 * @note `vet|Enumerate()| Join() | Write(); // [(0, 1), (1, 2), (2, 3)]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/flow#enumerate
 */
    Enumerate() {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return enumerate(container); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const Enumerate& obj) { return obj(container); }
};

//-------------------- PARSE -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[parse]]
/**
 * @note #### `parse<READABLE>(str value) -> READABLE`
 * @note #### `str value|STRTO<READABLE>()-> READABLE`
 * 
 * @note - Transforma de string para o tipo solicitado utilizando o operador de extração de stream.
 * @note - Dispara uma exceção caso a conversão não seja possível.
 * 
 * @note #### Parâmetros
 * @note `param: READABLE` Tipo a ser convertido.
 * @note `param: value` String a ser convertida.
 * @note `return` Valor convertido.
 * @note `throws: std::runtime_error` Caso a conversão não seja possível.
 * 
 * @note #### Exemplos
 * @note `parse<int>("1") | Write(); // 1`
 * @note `parse<double>("1.2") | Write(); // 1.2`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#parse
 * 
*/
template <typename READABLE>
READABLE parse(std::string value)
//[[parse]]
{
    std::istringstream iss(value);
    READABLE aux;
    if (iss >> aux) {
        return aux;
    }
    throw std::runtime_error("parse: invalid conversion from " + value);
}

template <typename READABLE>
struct Parse {
/**
 * @note #### `parse<READABLE>(str value) -> READABLE`
 * @note #### `str value|STRTO<READABLE>()-> READABLE`
 * 
 * @note - Transforma de string para o tipo solicitado utilizando o operador de extração de stream.
 * @note - Dispara uma exceção caso a conversão não seja possível.
 * 
 * @note #### Parâmetros
 * @note `param: READABLE` Tipo a ser convertido.
 * @note `param: value` String a ser convertida.
 * @note `return` Valor convertido.
 * @note `throws: std::runtime_error` Caso a conversão não seja possível.
 * 
 * @note #### Exemplos
 * @note `parse<int>("1") | Write(); // 1`
 * @note `parse<double>("1.2") | Write(); // 1.2`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#parse
 * 
*/
    Parse(){};
    READABLE operator()(std::string value) const { return parse<READABLE>(value); }
    friend READABLE operator|(std::string value, const Parse& obj) { return obj(value); }
};

//-------------------- UNPACK -----------------------------
//---------------------------------------------------------
//---------------------------------------------------------

template <typename... Types>
struct Unpack {
    char delimiter;

/**
 * @note #### `unpack<...TS>(str value, char delimiter) -> tuple<TS...>`
 * @note #### `str value| UNPACK<...TS>(char delimiter) -> tuple<TS...>`
 * 
 * @note - Transforma de string para tupla dados os tipos de cada elemento e o char separador.
 * 
 * @note #### Parâmetros
 * @note `param: TS...` Tipos a serem extraídos.
 * @note `param: value` String a ser convertida.
 * @note `param: delimiter` Caractere separador entre os elementos.
 * @note `return` Tupla com os elementos convertidos.
 * 
 * @note #### Exemplos
 * @note unpack<int, double, std::string>("1:2.4:uva", ':') | Write(); // (1, 2.4, "uva") 
 * @note "1:2.4:uva"| UNPACK<int, double, std::string>(':') | Write(); // (1, 2.4, "uva")
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#unpack
 * 
 */
    Unpack(char delimiter) : delimiter(delimiter) {}

    template<typename Head, typename... Tail>
    std::tuple<Head, Tail...> tuple_read_impl(std::istream& is, char delimiter) const {
        Head val;
        std::string token;
        std::getline(is, token, delimiter);
        std::stringstream ss_token(token);
        ss_token >> val;
        if constexpr (sizeof...(Tail) == 0) // this was the last tuple value
            return std::tuple{val};
        else
            return std::tuple_cat(std::tuple{val}, tuple_read_impl<Tail...>(is, delimiter));
    }

    std::tuple<Types...> operator()(std::string content) const {
        std::stringstream ss(content);
        return tuple_read_impl<Types...>(ss, this->delimiter);
    }
    
    friend std::tuple<Types...> operator|(std::string content, const Unpack& obj) {
        return obj(content);
    }
};

//[[unpack]]
/**
 * @note #### `unpack<...TS>(str value, char delimiter) -> tuple<TS...>`
 * @note #### `str value| UNPACK<...TS>(char delimiter) -> tuple<TS...>`
 * 
 * @note - Transforma de string para tupla dados os tipos de cada elemento e o char separador.
 * 
 * @note #### Parâmetros
 * @note `param: TS...` Tipos a serem extraídos.
 * @note `param: value` String a ser convertida.
 * @note `param: delimiter` Caractere separador entre os elementos.
 * @note `return` Tupla com os elementos convertidos.
 * 
 * @note #### Exemplos
 * @note unpack<int, double, std::string>("1:2.4:uva", ':') | Write(); // (1, 2.4, "uva") 
 * @note "1:2.4:uva"| UNPACK<int, double, std::string>(':') | Write(); // (1, 2.4, "uva")
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#unpack
 * 
 */
template <typename... TS>
std::tuple<TS...> unpack(const std::string& line, char delimiter)
//[[unpack]]
{
    return Unpack<TS...>(delimiter)(line);
}


//-------------------- ZIP   -----------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[zip]]
/**
 * @note #### `zip(CONTAINER_A<T> container_a, CONTAINER_B<K> container_b) -> vector<pair<T, K>>`
 * @note #### `CONTAINER_A<T> container_a| ZIP(CONTAINER_B<K> container_b) -> vector<pair<T, K>>`
 * 
 * @note - Une dois containers em um vetor de pares limitado ao menor tamanho dos dois containers.
 * 
 * @note #### Parâmetros
 * @note `param: container_a` Primeiro container.
 * @note `param: container_b` Segundo container.
 * @note `return` Vetor de pares.
 * 
 * @note #### Exemplos
 * @note `zip(vector<int>{1, 2, 3}, string("pterodactilo")) | Join() | Write(); //[(1, p), (2, t), (3, e)]`
 * @note `vector<int>{1, 2, 3}| ZIP(string("pterodactilo")) | Join() | Write(); //[(1, p), (2, t), (3, e)]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#zip
 */
template<typename CONTAINER_A, typename CONTAINER_B>
auto zip(const CONTAINER_A& A, const CONTAINER_B& B)
//[[zip]]
{
    auto fn = [](auto x) { return x; };
    using type_a = decltype(fn(*A.begin()));
    using type_b = decltype(fn(*B.begin()));
    std::vector<std::pair<type_a, type_b>> aux;

    auto ita = A.begin();
    auto itb = B.begin();
    while(ita != A.end() &&  itb != B.end()) {
        aux.push_back({*ita, *itb});
        ita++;
        itb++;
    }
    return aux;
};

template <typename CONTAINER_B>
struct Zip {
    CONTAINER_B container_b;

/**
 * @note #### `zip(CONTAINER_A<T> container_a, CONTAINER_B<K> container_b) -> vector<pair<T, K>>`
 * @note #### `CONTAINER_A<T> container_a| ZIP(CONTAINER_B<K> container_b) -> vector<pair<T, K>>`
 * 
 * @note - Une dois containers em um vetor de pares limitado ao menor tamanho dos dois containers.
 * 
 * @note #### Parâmetros
 * @note `param: container_a` Primeiro container.
 * @note `param: container_b` Segundo container.
 * @note `return` Vetor de pares.
 * 
 * @note #### Exemplos
 * @note `zip(vector<int>{1, 2, 3}, string("pterodactilo")) | Join() | Write(); //[(1, p), (2, t), (3, e)]`
 * @note `vector<int>{1, 2, 3}| ZIP(string("pterodactilo")) | Join() | Write(); //[(1, p), (2, t), (3, e)]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#zip
 */
    Zip(const CONTAINER_B& container_b) : container_b(container_b) {}

    template<typename CONTAINER_A>
    auto operator()(const CONTAINER_A& container_a) const { return zip(container_a, container_b); }
    template<typename CONTAINER_A>
    friend auto operator|(const CONTAINER_A& container_a, const Zip& obj) { return obj(container_a); }
};

//-------------------- ZIPWITH ---------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[zipwith]]
/**
 * @note #### `zipwith(CONTAINER<T> container_a, CONTAINER<K> container_b, FUNCTION fnjoin) -> vector<fnjoin(T, K)>`
 * @note #### `CONTAINER<T> container_a| ZIPWITH(CONTAINER<K> container_b, FUNCTION fnjoin) -> vector<fnjoin(T, K)>`
 * 
 * @note - Une dois containers através da aplicação da função fnjoin em cada par limitado ao menor tamanho dos dois containers.
 * 
 * @note #### Parâmetros
 * @note `param: container_a` Primeiro container.
 * @note `param: container_b` Segundo container.
 * @note `param: fnjoin` Função a ser aplicada em cada par.
 * @note `return` Vetor com os resultados.
 * 
 * @note #### Exemplos
 * @note `auto concat = [](auto x, auto y) { return text(x) + y; };`
 * @note `zipwith(vector<int>{1, 2, 3}, string("pterodactilo"), concat) | Join() | Write(); // ["1p", "2t", "3e"]`
 * @note `zipwith(range(10), "pterodactilo"s, concat) | Join() | Write(); // ["0p", "1t", "2e", "3r", "4o", "5d", "6a", "7c", "8t", "9i"]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#zipwith
 * 
 */
template<typename CONTAINER_A, typename CONTAINER_B, typename FNJOIN>
auto zipwith(const CONTAINER_A& A, const CONTAINER_B& B, FNJOIN fnjoin)
//[[zipwith]]
{
    auto idcopy = [](auto x) { return x; };
    using type_out = decltype( fnjoin( idcopy(*A.begin()), idcopy(*B.begin()) ));
    std::vector<type_out> aux;

    auto ita = A.begin();
    auto itb = B.begin();
    while(ita != A.end() &&  itb != B.end()) {
        aux.push_back(fnjoin(*ita, *itb));
        ita++;
        itb++;
    }
    return aux;
};


template<typename CONTAINER_B, typename FNJOIN>
struct ZipWith {
    CONTAINER_B container_b;
    FNJOIN fnjoin;

/**
 * @note #### `zipwith(CONTAINER<T> container_a, CONTAINER<K> container_b, FUNCTION fnjoin) -> vector<fnjoin(T, K)>`
 * @note #### `CONTAINER<T> container_a| ZIPWITH(CONTAINER<K> container_b, FUNCTION fnjoin) -> vector<fnjoin(T, K)>`
 * 
 * @note - Une dois containers através da aplicação da função fnjoin em cada par limitado ao menor tamanho dos dois containers.
 * 
 * @note #### Parâmetros
 * @note `param: container_a` Primeiro container.
 * @note `param: container_b` Segundo container.
 * @note `param: fnjoin` Função a ser aplicada em cada par.
 * @note `return` Vetor com os resultados.
 * 
 * @note #### Exemplos
 * @note `auto concat = [](auto x, auto y) { return text(x) + y; };`
 * @note `zipwith(vector<int>{1, 2, 3}, string("pterodactilo"), concat) | Join() | Write(); // ["1p", "2t", "3e"]`
 * @note `zipwith(range(10), "pterodactilo"s, concat) | Join() | Write(); // ["0p", "1t", "2e", "3r", "4o", "5d", "6a", "7c", "8t", "9i"]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#zipwith
 * 
 */
    ZipWith(const CONTAINER_B& container_b, FNJOIN fnjoin) : container_b(container_b), fnjoin(fnjoin) {}

    template<typename CONTAINER_A>        auto operator()(const CONTAINER_A& container_a) const { return zipwith(container_a, container_b, fnjoin); }
    template<typename CONTAINER_A> friend auto operator| (const CONTAINER_A& container_a, const ZipWith& obj) { return obj(container_a); }
};

//-------------------- FOREACH ---------------------------
//--------------------------------------------------------
//--------------------------------------------------------

//[[foreach]]
/**
 * @note #### `foreach(CONTAINER container, FUNCTION fn) -> void`
 * @note #### `CONTAINER container| Foreach(FUNCTION fn) -> void`
 * 
 * @note - Aplica a função fn em cada elemento do container.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser iterado.
 * @note `param: fn` Função a ser aplicada em cada elemento.
 * 
 * @note #### Exemplos
 * std::vector<int>{1, 2, 3, 4} | Foreach([&](int x) { std::cout << x; });
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#zipwith
 */
template <typename CONTAINER, typename FN>
void foreach(const CONTAINER& container, FN fn)
//[[foreach]]
{
    for (const auto& item : container) {
        fn(item);
    }
}

template <typename FN>
struct Foreach {
    FN fn;

/**
 * @note #### `foreach(CONTAINER container, FUNCTION fn) -> void`
 * @note #### `CONTAINER container| Foreach(FUNCTION fn) -> void`
 * 
 * @note - Aplica a função fn em cada elemento do container.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser iterado.
 * @note `param: fn` Função a ser aplicada em cada elemento.
 * 
 * @note #### Exemplos
 * std::vector<int>{1, 2, 3, 4} | Foreach([&](int x) { std::cout << x; });
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/flow#zipwith
 */
    Foreach(FN fn) : fn(fn) {}

    template<typename CONTAINER> void operator()(const CONTAINER& container) const { foreach(container, fn); }
    template<typename CONTAINER> friend void operator|(const CONTAINER& container, const Foreach& obj) { obj(container); }
};
} // namespace fw

using namespace std::string_literals;


//[[operator+]]
/**
 * @note #### `+str -> double`
 * 
 * @note - Transforma de string para double utilizando a função number.
 * 
 * @note #### Parâmetros
 * @note `param: str` String a ser convertida.
 * @note `return` Valor convertido para double.
 * 
 * @note #### Exemplos
 * @note `+"1.23"s | Write(); // 1.23`
 * 
*/
inline double operator+(std::string text)
//[[operator+]]

{
    return fw::parse<double>(text);
}

#define EXTRA
#include <algorithm>

namespace fw {
#ifdef EXTRA

inline auto Sort() {
    return fw::Pipe([](auto container) {
        std::sort(container.begin(), container.end());
        return container;
    });
};

template <typename T>
inline auto Find(const T& value) {
    return fw::Pipe([value](auto container) {
        return std::find(container.begin(), container.end(), value);
    });
};

} // namespace fw
#endif