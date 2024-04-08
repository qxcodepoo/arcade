#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <array>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <memory>

namespace fn {

using str_view = std::string_view;

//--------------------------------------------------------
//-------------------- ALIGN -------------- --------------
//--------------------------------------------------------

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
        //search for : char in format, if exists and is followed by a char, then use that char as padding, and remove both from string
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

    Align(str_view format) {
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

//--------------------------------------------------------
//-------------------- CFMT  -----------------------------
//--------------------------------------------------------

class CFMT {

    //transformation using sprintf
    template <typename T>
    static std::string c_transform(const T& data, const str_view& format) {
        std::string fmt(format);
        auto size = std::snprintf(nullptr, 0, fmt.c_str(), data);
        std::string output(size + 1, '\0');
        std::sprintf(&output[0], fmt.c_str(), data);
        if (output.back() == '\0') 
            output.pop_back();
        return output;
    }

    //conversion to string using stringstream
    template <typename T>
    static std::string sstream_transform(const T& data) {
        std::stringstream ss;
        ss << data;
        return ss.str();
    }


    template <typename T>
    static std::string process(const T& data, const str_view& format) 
    {
        if (format == "%s" || format == "") {
            return sstream_transform(data);
        }
        if (format.size() > 0 && format.find("%s") != std::string::npos) {//formatting a non string with %s
            return process(sstream_transform(data), format);
        }
        return c_transform(data, format);
    }

    //validate if the format is correct for a string
    static std::string process(const std::string& data, const str_view& format) 
    {
        return process(data.c_str(), format);
    }
    
    //validate if the format is correct for a const char *
    //write specialization for const char *
    static std::string process(const char* const& data, const str_view& format) 
    {
        if (format == "%s" || format == "") {
            return data;
        }
        return CFMT::c_transform(data, format);
    };

    
public:

    template <typename T>
    static std::string format(const T& data, const str_view& format) 
    {
        Align align(format);
        std::string filtered = align.get_filtered_format();
        return align.align_text(process(data, filtered));
    }
};

//--------------------------------------------------------
//-------------------- TOSTR PROTOTYPE -------------------
//--------------------------------------------------------

template <typename T> std::string tostr(const T& t     , const str_view& format = "");

//--------------------------------------------------------
//-------------------- JOIN  -----------------------------
//--------------------------------------------------------

namespace hide {
template <typename CONTAINER> 
std::string __join(const CONTAINER& container, const str_view& separator, const str_view& cfmt) 
{ 
    std::stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it == container.begin() ? "" : separator);
        ss << tostr(*it, cfmt);
    }
    return ss.str();
}

template <typename... Ts>
std::string __join(std::tuple<Ts...> const &the_tuple, const str_view& separator, const str_view& cfmt)
{
    std::stringstream ss;
    std::apply( [&](Ts const &...tuple_args) {
            std::size_t n{0};
            ((ss << tostr(tuple_args, cfmt) << (++n != sizeof...(Ts) ? separator : "")), ...);
        }, the_tuple);
    return ss.str();
}

template <typename T1, typename T2>
std::string __join(const std::pair<T1, T2>& the_pair, const str_view& separator, const str_view& cfmt)
{
    std::stringstream ss;
    ss << tostr(the_pair.first, cfmt) << separator << tostr(the_pair.second, cfmt);
    return ss.str();
}
}
//__guide join
//[[join]]
/**
 * @note #### `join(T container, str separator = "", str cfmt = "") -> str`
 * @note #### `T container| JOIN(str separator = "", str cfmt = "") -> str`
 * 
 * @note - Transforma um container, par ou tupla em string.
 * @note - Se os elementos não forem strings, eles serão transformados pela função `tostr`.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser transformado em string.
 * @note `param: separator` Separador entre os elementos.
 * @note `param: cfmt` String de formatação.
 * @note `return` String com os elementos concatenados.
 * 
 * @note  #### Exemplos
 * @note `join(vector<int>{1, 2, 3}, " ") | WRITE(); // "1 2 3"`
 * @note `vector<int>{1, 2, 3} | JOIN("=") | WRITE(); // "1=2=3"`
 * @note `vector<int>{1, 2, 3} | JOIN("=", "%02d") | WRITE(); // "01=02=03"`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/cppaux#join
 */
template <typename T>
std::string join(const T& container, const str_view& separator = "", const str_view& cfmt = "") 
//[[join]]
{
    return hide::__join(container, separator, cfmt);
}

//class
struct JOIN {
    str_view delimiter;
    str_view cfmt;

//__guide join
/**
 * @note #### `join(T container, str separator = "", str cfmt = "") -> str`
 * @note #### `T container| JOIN(str separator = "", str cfmt = "") -> str`
 * 
 * @note - Transforma um container, par ou tupla em string.
 * @note - Se os elementos não forem strings, eles serão transformados pela função `tostr`.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser transformado em string.
 * @note `param: separator` Separador entre os elementos.
 * @note `param: cfmt` String de formatação.
 * @note `return` String com os elementos concatenados.
 * 
 * @note  #### Exemplos
 * @note `join(vector<int>{1, 2, 3}, " ") | WRITE(); // "1 2 3"`
 * @note `vector<int>{1, 2, 3} | JOIN("=") | WRITE(); // "1=2=3"`
 * @note `vector<int>{1, 2, 3} | JOIN("=", "%02d") | WRITE(); // "01=02=03"`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/cppaux#join
 */
    JOIN(const str_view& delimiter = "", const str_view& cfmt = "") : delimiter(delimiter), cfmt(cfmt) {}
    template <typename CONTAINER> std::string operator()(const CONTAINER& v) const { return join(v, delimiter, cfmt); }
    template <typename T> friend std::string operator|(const T& v, const JOIN& obj) { return obj(v); }
};

//--------------------------------------------------------
//-------------------- TOSTR -----------------------------
//--------------------------------------------------------

namespace hide {
template <typename T>             inline std::string __tostr(const T& t                      , const str_view& format) { return CFMT::format(t, format); }
                                  inline std::string __tostr(int i                           , const str_view& format) { return CFMT::format(i, format); }
                                  inline std::string __tostr(bool b                          , const str_view& format) { (void) format; return b ? "true" : "false"; }
                                  inline std::string __tostr(const char* s                   , const str_view& format) { return CFMT::format(s, format); }
                                  inline std::string __tostr(const std::string& s            , const str_view& format) { return CFMT::format(s, format); }
                                  inline std::string __tostr(const str_view& s               , const str_view& format) { return CFMT::format(s, format); }
template <typename A, typename B> inline std::string __tostr(const std::pair<A,B>& p         , const str_view& format) { return "(" + tostr(p.first, format) + ", " + tostr(p.second, format) + ")"; }
template <typename T>             inline std::string __tostr(const std::list<T>& t           , const str_view& format) { return "[" + join(t, ", ", format) + "]"; }
template <typename T>             inline std::string __tostr(const std::vector<T>& t         , const str_view& format) { return "[" + join(t, ", ", format) + "]"; }
template <typename ...Ts>         inline std::string __tostr(const std::tuple<Ts...>& t      , const str_view& format) { return "(" + join(t, ", ", format) + ")"; }
template <typename T, size_t N>   inline std::string __tostr(const std::array<T, N>& t       , const str_view& format) { return "[" + join(t, ", ", format) + "]"; }
template <typename T>             inline std::string __tostr(const std::set<T>& t            , const str_view& format) { return "{" + join(t, ", ", format) + "}"; }
template <typename K, typename T> inline std::string __tostr(const std::map<K,T>& t          , const str_view& format) { return "{" + join(t, ", ", format) + "}"; }
template <typename T>             inline std::string __tostr(const std::unordered_set<T>& t  , const str_view& format) { return "{" + join(t, ", ", format) + "}"; }
template <typename K, typename T> inline std::string __tostr(const std::unordered_map<K,T>& t, const str_view& format) { return "{" + join(t, ", ", format) + "}"; }
template <typename T>             inline std::string __tostr(const std::shared_ptr<T>& t     , const str_view& format) { return t == nullptr ? "null" : tostr(*t, format); }

}

//__guide tostr
//[[tostr]]
/**
 * @note #### `tostr(T data, str cfmt = "") -> str`
 * @note #### `T data| TOSTR(str cfmt = "") -> str`
 * @note - Converte o dado passado em string.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser convertido.
 * @note `param: cfmt` Parâmetro de formatação no modo printf.
 * @note `return` String com o dado convertido.
 * 
 * @note #### Funcionamento para tipos primitivos
 * @note - Converte o dado em string.
 * @note - Se `cfmt` for passado, o dado será formatado usando o modelo do `printf`.
 * @note `tostr(1.2) | WRITE(); // "1.2"`
 * @note `tostr(1.2, "%.4f") | WRITE(); // "1.2000"`
 * 
 * @note #### Funcionamento para containers
 * @note - Elementos são impressos usando vírgulas como separador.
 * @note `vector`, `list` e `array` são impressos entre colchetes. 
 * @note `map` e `set` são impressos entre chaves. 
 * @note `pair` e `tuple` são impressos entre parênteses.
 * @note - O parâmetro de formatação é aplicado em todos os elementos do container recursivamente.
 * @note `tostr(list<int>{1,2,3}, "%02d") | WRITE(); //[01, 02, 03]`
 * 
 * @note #### Formatação personalizada
 * @note - Veja a função `join`.
 * @note `std::vector<int> vet {1, 2, 3};`
 * @note `join(vet, " - ", "%02d") | WRITE(); // "01 - 02 - 03"`
 * 
 * @note #### Funcionamento para tipos do usuário
 * @note - Basta implementar a função de saída
 * @note `ostream& operador <<(ostream& os, TIPO tipo)`.
 * 
 * @note  #### Exemplos
 * @note `tostr(std::list<int>{1,2,3}, "%02d") | WRITE(); //[01, 02, 03]`
 * @note `std::pair<int, int>(2, 1) | TOSTR() | WRITE(); //(2, 1)`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/cppaux#tostr
 */
template <typename T> std::string tostr(const T& data     , const str_view& cfmt) 
//[[tostr]]
{ 
    return hide::__tostr(data, cfmt); 
}

//class
struct TOSTR {
    str_view cfmt;

//__guide tostr
/**
 * @note #### `tostr(T data, str cfmt = "") -> str`
 * @note #### `T data| TOSTR(str cfmt = "") -> str`
 * @note - Converte o dado passado em string.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser convertido.
 * @note `param: cfmt` Parâmetro de formatação no modo printf.
 * @note `return` String com o dado convertido.
 * 
 * @note #### Funcionamento para tipos primitivos
 * @note - Converte o dado em string.
 * @note - Se `cfmt` for passado, o dado será formatado usando o modelo do `printf`.
 * @note `tostr(1.2) | WRITE(); // "1.2"`
 * @note `tostr(1.2, "%.4f") | WRITE(); // "1.2000"`
 * 
 * @note #### Funcionamento para containers
 * @note - Elementos são impressos usando vírgulas como separador.
 * @note `vector`, `list` e `array` são impressos entre colchetes. 
 * @note `map` e `set` são impressos entre chaves. 
 * @note `pair` e `tuple` são impressos entre parênteses.
 * @note - O parâmetro de formatação é aplicado em todos os elementos do container recursivamente.
 * @note `tostr(list<int>{1,2,3}, "%02d") | WRITE(); //[01, 02, 03]`
 * 
 * @note #### Formatação personalizada
 * @note - Veja a função `join`.
 * @note `std::vector<int> vet {1, 2, 3};`
 * @note `join(vet, " - ", "%02d") | WRITE(); // "01 - 02 - 03"`
 * 
 * @note #### Funcionamento para tipos do usuário
 * @note - Basta implementar a função de saída
 * @note `ostream& operador <<(ostream& os, TIPO tipo)`.
 * 
 * @note  #### Exemplos
 * @note `tostr(std::list<int>{1,2,3}, "%02d") | WRITE(); //[01, 02, 03]`
 * @note `std::pair<int, int>(2, 1) | TOSTR() | WRITE(); //(2, 1)`
 * 
 * @note  #### Mais exemplos em https://github.com/senapk/cppaux#tostr
 */
    TOSTR(const str_view& cfmt = "") : cfmt(cfmt) {}

    template <typename T> std::string operator()(const T& t) const { return tostr(t, cfmt); }
    template <typename T> friend std::string operator|(const T& v, const TOSTR& obj) { return obj(v); }
};

//--------------------------------------------------------
//-------------------- FORMAT ----------------------------
//--------------------------------------------------------

//class
template<typename... Args> 
class FORMAT 
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
                ((result.push_back(tostr(tupleArgs, controls.at(++i)))), ...);
            }, this->args
        );

        return result;
    }

    //transforma {{ em \a e }} em \b
    std::string preprocess(std::string data) {
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

    std::pair<std::vector<std::string>, std::vector<std::string>> extract(std::string data)
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

public:

//__guide format
/**
 * @note #### `format(str fmt, Args ...args ) -> str`
 * @note #### `str fmt| FORMAT(Args ...args ) -> str`
 * 
 * @note - Formata uma string com base nos argumentos passados 
 * @note - Utilizando um modelo de chaves para posicionar os argumentos.
 * @note - Se dentro da chave, houver um string de formatação, o dado será formatado com base nela.
 * @note - Não primitivos são formatados de acordo com a função `tostr`
 * 
 * @note #### Parâmetros
 * @note `param: fmt` O texto com os {} para substituir pelos argumentos.
 * @note `param: args` Os argumentos a serem substituídos.
 * @note `return` O texto formatado.
 * 
 * @note #### Exemplos
 * @note `format("O {} é {%0.2f}.", "pi", 3.141592653) | WRITE(); //o pi e 3.14.`
 * @note `"O {} é {%0.2f}." | FORMAT("pi", 3.141592653) | WRITE(); //o pi e 3.14.`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#format
 * 
 */
    FORMAT(Args ...args): args(std::forward<Args>(args)...){}

    std::string operator()(std::string fmt)
    {
        auto [texts, controls] = extract(fmt);
        try {
            auto vars = tuple_to_vector_str(controls);
            
            if(vars.size() < texts.size() - 1) {
                throw std::out_of_range("");
            }
            std::stringstream ss;
            for (size_t i = 0; i < vars.size(); i++)
                ss << texts[i] << vars[i];
            ss << texts.back(); //ultimo texto
            return ss.str();
        } catch (std::out_of_range& e) {
            std::cout << "fail: verifique a quantidade de parâmetros passado para string: " << fmt << '\n';
            exit(1);
        }
    }

    friend std::string operator|(std::string fmt, FORMAT<Args...> obj) { return obj(fmt); }
};


//__guide format
//[[format]]
/**
 * @note #### `format(str fmt, Args ...args ) -> str`
 * @note #### `str fmt| FORMAT(Args ...args ) -> str`
 * 
 * @note - Formata uma string com base nos argumentos passados 
 * @note - Utilizando um modelo de chaves para posicionar os argumentos.
 * @note - Se dentro da chave, houver um string de formatação, o dado será formatado com base nela.
 * @note - Não primitivos são formatados de acordo com a função `tostr`
 * 
 * @note #### Parâmetros
 * @note `param: fmt` O texto com os {} para substituir pelos argumentos.
 * @note `param: args` Os argumentos a serem substituídos.
 * @note `return` O texto formatado.
 * 
 * @note #### Exemplos
 * @note `format("O {} é {%0.2f}.", "pi", 3.141592653) | WRITE(); //o pi e 3.14.`
 * @note `"O {} é {%0.2f}." | FORMAT("pi", 3.141592653) | WRITE(); //o pi e 3.14.`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#format
 * 
 */
template<typename... Args> 
std::string format(std::string fmt, Args ...args) 
//[[format]]
{
    return FORMAT<Args...>(args...)(fmt); 
}


//--------------------------------------------------------
//-------------------- PRINT------------------------------
//--------------------------------------------------------

//__guide print
//[[print]]
/**
 * @note #### `print(str fmt, Args ...args) -> str`
 * 
 * @note - Invoca a função `format` e imprime o resultado na tela.
 * @note - As quebras de linha precisam ser inseridas explicitamente.
 * 
 * @note #### Parâmetros
 * @note `param: fmt` O texto com os {} para substituir pelos argumentos.
 * @note `param: args` Os argumentos a serem substituídos.
 * @note `return` O texto que foi impresso.
 * 
 * @note #### Exemplos
 * @note `print("O {} é {%0.2f}.\n", "pi", 3.141592653); //o pi e 3.14.`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#print
 * 
 */
template<typename... Args> std::string print(std::string fmt, Args ...args)
//[[print]]
{ 
    auto result = FORMAT<Args...>(args...)(fmt);
    std::cout << result;
    return result;
}
//class
template<typename... Args> 
struct PRINT {
    std::tuple<Args...> args;

//__guide print
/**
 * @note #### `print(str fmt, Args ...args) -> str`
 * 
 * @note - Invoca a função `format` e imprime o resultado na tela.
 * @note - As quebras de linha precisam ser inseridas explicitamente.
 * 
 * @note #### Parâmetros
 * @note `param: fmt` O texto com os {} para substituir pelos argumentos.
 * @note `param: args` Os argumentos a serem substituídos.
 * @note `return` O texto que foi impresso.
 * 
 * @note #### Exemplos
 * @note `print("O {} é {%0.2f}.\n", "pi", 3.141592653); //o pi e 3.14.`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#print
 * 
 */
    PRINT(Args ...args): args(std::forward<Args>(args)...) { }
    std::string operator()(std::string fmt) { return print(fmt, args); }
    friend std::string operator|(std::string fmt, PRINT<Args...> obj) { return obj(fmt); }
};

//--------------------------------------------------------
//-------------------- WRITE -----------------------------
//--------------------------------------------------------

//__guide write
//[[write]]
/**
 * @note #### `write(T data, str end = "\n") -> T`
 * @note #### `T data| WRITE(str end = "\n") -> T`
 * 
 * @note - Envia o dado para o `std::cout` quebrando a linha.
 * @note - Se o dado não for uma `string`, será convertido pela função `tostr`.
 * @note - O modo pipe é `| WRITE()`.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser transformado e impresso.
 * @note `param: end` (opcional) String a ser inserida no final da linha.
 * @note `return` O dado original recebido.
 * 
 * @note #### Exemplos
 * @note `write(vector<int> {1, 2, 3}); // [1, 2, 3]`
 * @note `vector<int> {1, 2, 3} | WRITE(); // [1, 2, 3]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#write
 */
template <typename PRINTABLE> const PRINTABLE& write(const PRINTABLE& data, str_view end = "\n") 
//[[write]]
{
    std::cout << tostr(data) << end;
    return data;
}

//class
struct WRITE {
    str_view end;

//__guide write
/**
 * @note #### `write(T data, str end = "\n") -> T`
 * @note #### `T data| WRITE(str end = "\n") -> T`
 * 
 * @note - Envia o dado para o `std::cout` quebrando a linha.
 * @note - Se o dado não for uma `string`, será convertido pela função `tostr`.
 * @note - O modo pipe é `| WRITE()`.
 * 
 * @note #### Parâmetros
 * @note `param: data` Dado a ser transformado e impresso.
 * @note `param: end` (opcional) String a ser inserida no final da linha.
 * @note `return` O dado original recebido.
 * 
 * @note #### Exemplos
 * @note `write(vector<int> {1, 2, 3}); // [1, 2, 3]`
 * @note `vector<int> {1, 2, 3} | WRITE(); // [1, 2, 3]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#write
 */
    WRITE(str_view end = "\n"): end(end) { }

    template <typename PRINTABLE>        const PRINTABLE& operator()(const PRINTABLE& data           ) { return write(data, end); }
    template <typename PRINTABLE> friend const PRINTABLE& operator| (const PRINTABLE& data, WRITE obj) { return obj(data); }
};

//--------------------------------------------------------
//-------------------- SLICE -----------------------------
//--------------------------------------------------------

class SLICE {
public:
//__guide slice1
/**
 * @note #### `slice(CONTAINER<T> container, int begin = 0) -> vector<T>`
 * @note #### `CONTAINER<T> container| SLICE(int begin = 0) -> vector<T>`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript. 
 * @note - Se não passado nenhum parâmetro, copia todos os elementos. 
 * @note - Os índices podem ser negativos para contar a partir final.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` (opcional) índice inicial.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1) | WRITE(); // [2, 3, 4, 5]`
 * @note `slice(vet, -2) | WRITE(); // [4, 5]`
 * @note `vet | SLICE(1) | WRITE(); // [2, 3, 4, 5]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#slice
 */
    SLICE(int begin = 0) {
        this->from_begin = begin == 0;
        this->begin = begin;
        this->to_end = true;
    }

//__guide slice2
/**
 * @note #### `slice(CONTAINER<T> container, int begin, int end) -> vector<T>`
 * @note #### `CONTAINER<T> container| SLICE(int begin, int end) -> vector<T>`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript. 
 * @note - Os índices podem ser negativos para indicar que a contagem deve ser feita a partir do final.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` índice inicial.
 * @note `param: end` índice final.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1, -1) | WRITE(); // [2, 3, 4]`
 * @note `vet| SLICE(1, -1) | WRITE(); // [2, 3, 4]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#slice
 */
    SLICE(int begin, int end) {
        this->begin = begin;
        this->end = end;
        this->from_begin = false;
        this->to_end = false;
    }
    template<typename CONTAINER>
    auto operator()(const CONTAINER& container) const {
        auto aux = SLICE::new_vec_from(container);
        
        //empty container
        if (!this->from_begin && !this->to_end && (this->begin == this->end)) {
            return aux;
        }

        //full container
        if (this->from_begin && this->to_end) {
            std::copy(container.begin(), container.end(), std::back_inserter(aux));
            return aux;
        }

        int size = container.size();
        int begin = 0;
        int end = size;
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

        std::copy(std::next(container.begin(), begin), std::next(container.begin(), end), std::back_inserter(aux));
        return aux;
    }
    
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const SLICE& obj) { return obj(container); }

private:
    int begin;
    int end;
    bool from_begin {false};
    bool to_end {false};

    template<typename CONTAINER>
    static auto new_vec_from(const CONTAINER& container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<decltype(fn(*container.begin()))> aux;
        return aux;
    }

    template <typename K, typename T>
    static auto new_vec_from(const std::map<K, T>& container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<std::pair<decltype(fn(container.begin()->first)), decltype(fn(container.begin()->second))>> aux;
        return aux;
    }

    template <typename K, typename T>
    static auto new_vec_from(const std::unordered_map<K, T>& container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<std::pair<decltype(fn(container.begin()->first)), decltype(fn(container.begin()->second))>> aux;
        return aux;
    }
};

//__guide slice1
//[[slice]]
/**
 * @note #### `slice(CONTAINER<T> container, int begin = 0) -> vector<T>`
 * @note #### `CONTAINER<T> container| SLICE(int begin = 0) -> vector<T>`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript. 
 * @note - Se não passado nenhum parâmetro, copia todos os elementos. 
 * @note - Os índices podem ser negativos para contar a partir final.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` (opcional) índice inicial.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1) | WRITE(); // [2, 3, 4, 5]`
 * @note `slice(vet, -2) | WRITE(); // [4, 5]`
 * @note `vet | SLICE(1) | WRITE(); // [2, 3, 4, 5]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#slice
 */
template<typename CONTAINER>
auto slice(const CONTAINER& container, int begin = 0)
//[[slice]]
{
    return SLICE(begin)(container);
}

//__guide slice2
/**
 * @note #### `slice(CONTAINER<T> container, int begin, int end) -> vector<T>`
 * @note #### `CONTAINER<T> container| SLICE(int begin, int end) -> vector<T>`
 * 
 * @note - Fatia um container retornando um `vector` com os elementos copiados.
 * @note - Funciona como a função `slice` do Python ou do Javascript. 
 * @note - Os índices podem ser negativos para indicar que a contagem deve ser feita a partir do final.
 * 
 * @note #### Parâmetros
 * @note `param: container` container a ser fatiado.
 * @note `param: begin` índice inicial.
 * @note `param: end` índice final.
 * @note `return` vector com os elementos copiados.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3, 4, 5};`
 * @note `slice(vet, 1, -1) | WRITE(); // [2, 3, 4]`
 * @note `vet| SLICE(1, -1) | WRITE(); // [2, 3, 4]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#slice
 */
template<typename CONTAINER>
auto slice(CONTAINER container, int begin, int end)
{
    return SLICE(begin, end)(container);
}

//--------------------------------------------------------
//-------------------- MAP   -----------------------------
//--------------------------------------------------------

//__guide map
//[[map]]
/**
 * @note #### `map(CONTAINER<T> container, FUNCTION fn) -> vector<fn(T)>`
 * @note #### `CONTAINER<T> container| MAP(FUNCTION fn) -> vector<fn(T)>`
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
 * @note `map(vet, [](int x) {return x * x;}) | WRITE(); // [1, 4, 9]`
 * @note `vet| MAP([](int x) {return x * x;}) | WRITE(); // [1, 4, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#map
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
struct MAP {
    FUNCTION fn;
//__guide map
/**
 * @note #### `map(CONTAINER<T> container, FUNCTION fn) -> vector<fn(T)>`
 * @note #### `CONTAINER<T> container| MAP(FUNCTION fn) -> vector<fn(T)>`
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
 * @note `map(vet, [](int x) {return x * x;}) | WRITE(); // [1, 4, 9]`
 * @note `vet| MAP([](int x) {return x * x;}) | WRITE(); // [1, 4, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#map
 */
    MAP(FUNCTION fn) : fn(fn) {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return map(container, fn); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const MAP& map) { return map(container); }
};

//--------------------------------------------------------
//-------------------- FILTER ----------------------------
//--------------------------------------------------------

//__guide filter
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
 * @note `filter(vet, [](int x) {return x % 2 == 0;}) | WRITE(); // [2]`
 * @note `vet| FILTER([](int x) {return x % 2 == 0;}) | WRITE(); // [2]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#filter
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
struct FILTER {
    FUNCTION fn;

//__guide filter
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
 * @note `filter(vet, [](int x) {return x % 2 == 0;}) | WRITE(); // [2]`
 * @note `vet| FILTER([](int x) {return x % 2 == 0;}) | WRITE(); // [2]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#filter
 * 
 */
    FILTER(FUNCTION fn) : fn(fn) {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return filter(container, fn); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const FILTER& obj) { return obj(container); }
};

//--------------------------------------------------------
//-------------------- RANGE -----------------------------
//--------------------------------------------------------

//__guide range2
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
 * @note `range(0, 10) | WRITE(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
 * @note `range(0, 10, 2) | WRITE(); // [0, 2, 4, 6, 8]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#range
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

//__guide range1
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
 * @note `range(10) | WRITE(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#range
 */
inline std::vector<int> range(int end) {
    return range(0, end, 1);
}

struct RANGE {
    RANGE() : init(0), step(1) {};

    std::vector<int> operator()(int end) const {
        return range(init, end, step);
    }

    friend std::vector<int> operator|(int end, const RANGE& obj) {
        return obj(end);
    }

    int init {0};
    int end {0};
    int step {0};
};

//--------------------------------------------------------
//-------------------- ENUMERATE -------------------------
//--------------------------------------------------------

//__guide enumerate
//[[enumerate]]
/**
 * @note #### `enumerate(CONTAINER<T> container) -> vector<pair<int, T>>`
 * @note #### `CONTAINER<T> container|ENUMERATE()-> vector<pair<int, T>>`
 * 
 * @note - Retorna um vetor de pares com os indices seguidos dos elementos originais do vetor.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser enumerado.
 * @note `return` Vector com os pares.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `enumerate(vet) | WRITE(); // [(0, 1), (1, 2), (2, 3)]`
 * @note `vet|ENUMERATE()| WRITE(); // [(0, 1), (1, 2), (2, 3)]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#enumerate
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

struct ENUMERATE {
//__guide enumerate
/**
 * @note #### `enumerate(CONTAINER<T> container) -> vector<pair<int, T>>`
 * @note #### `CONTAINER<T> container|ENUMERATE()-> vector<pair<int, T>>`
 * 
 * @note - Retorna um vetor de pares com os indices seguidos dos elementos originais do vetor.
 * 
 * @note #### Parâmetros
 * @note `param: container` Container a ser enumerado.
 * @note `return` Vector com os pares.
 * 
 * @note #### Exemplos
 * @note `vector<int> vet {1, 2, 3};`
 * @note `enumerate(vet) | WRITE(); // [(0, 1), (1, 2), (2, 3)]`
 * @note `vet|ENUMERATE()| WRITE(); // [(0, 1), (1, 2), (2, 3)]`
 * 
 * @note #### Veja  mais exemplos em https://github.com/senapk/cppaux#enumerate
 */
    ENUMERATE() {};
    template<typename CONTAINER> auto operator()(const CONTAINER& container) const { return enumerate(container); }
    template<typename CONTAINER> friend auto operator|(const CONTAINER& container, const ENUMERATE& obj) { return obj(container); }
};



//--------------------------------------------------------
//-------------------- STRTO -----------------------------
//--------------------------------------------------------

//__guide strto
//[[strto]]
/**
 * @note #### `strto<READABLE>(str value) -> READABLE`
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
 * @note `strto<int>("1") | WRITE(); // 1`
 * @note `strto<double>("1.2") | WRITE(); // 1.2`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#strto
 * 
*/
template <typename READABLE>
READABLE strto(std::string value)
//[[strto]]
{
    std::istringstream iss(value);
    READABLE aux;
    if (iss >> aux) {
        return aux;
    }
    throw std::runtime_error("strto: invalid conversion from " + value);
}

template <typename READABLE>
struct STRTO {
//__guide strto
/**
 * @note #### `strto<READABLE>(str value) -> READABLE`
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
 * @note `strto<int>("1") | WRITE(); // 1`
 * @note `strto<double>("1.2") | WRITE(); // 1.2`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#strto
 * 
*/
    STRTO(){};
    READABLE operator()(std::string value) const { return strto<READABLE>(value); }
    friend READABLE operator|(std::string value, const STRTO& obj) { return obj(value); }
};

//--------------------------------------------------------
//-------------------- NUMBER ----------------------------
//--------------------------------------------------------

//__guide number
//[[number]]
/**
 * @note #### `number(str value) -> double`
 * 
 * @note - Transforma de string para double utilizando a função strto.
 * 
 * @note #### Parâmetros
 * @note `param: value` String a ser convertida.
 * @note `return` Valor convertido para double.
 * @note `throws: std::runtime_error` Caso a conversão não seja possível.
 * 
 * @note #### Exemplos
 * @note `number("1.23") | WRITE(); // 1.23`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#number
 * 
*/
inline double number(std::string value)
//[[number]]
{
    return strto<double>(value);
}

struct NUMBER {
//__guide number
/**
 * @note #### `number(str value) -> double`
 * 
 * @note - Transforma de string para double utilizando a função strto.
 * 
 * @note #### Parâmetros
 * @note `param: value` String a ser convertida.
 * @note `return` Valor convertido para double.
 * @note `throws: std::runtime_error` Caso a conversão não seja possível.
 * 
 * @note #### Exemplos
 * @note `number("1.23") | WRITE(); // 1.23`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#number
 * 
*/
    NUMBER(){}
    double operator()(std::string value) const { return number(value); }
    friend double operator|(std::string value, const NUMBER& obj) { return obj(value); }
};

//--------------------------------------------------------
//-------------------- UNPACK -----------------------------
//--------------------------------------------------------

template <typename... Types>
struct UNPACK {
    char delimiter;

//__guide unpack
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
 * @note unpack<int, double, std::string>("1:2.4:uva", ':') | WRITE(); // (1, 2.4, "uva") 
 * @note "1:2.4:uva"| UNPACK<int, double, std::string>(':') | WRITE(); // (1, 2.4, "uva")
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#unpack
 * 
 */
    UNPACK(char delimiter) : delimiter(delimiter) {}

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
    
    friend std::tuple<Types...> operator|(std::string content, const UNPACK& obj) {
        return obj(content);
    }
};

//__guide unpack
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
 * @note unpack<int, double, std::string>("1:2.4:uva", ':') | WRITE(); // (1, 2.4, "uva") 
 * @note "1:2.4:uva"| UNPACK<int, double, std::string>(':') | WRITE(); // (1, 2.4, "uva")
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#unpack
 * 
 */
template <typename... TS>
std::tuple<TS...> unpack(const std::string& line, char delimiter)
//[[unpack]]
{
    return UNPACK<TS...>(delimiter)(line);
}


//--------------------------------------------------------
//-------------------- ZIP   -----------------------------
//--------------------------------------------------------

//__guide zip
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
 * @note `zip(vector<int>{1, 2, 3}, string("pterodactilo")) | WRITE(); //[(1, p), (2, t), (3, e)]`
 * @note `vector<int>{1, 2, 3}| ZIP(string("pterodactilo")) | WRITE(); //[(1, p), (2, t), (3, e)]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#zip
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
struct ZIP {
    CONTAINER_B container_b;

//__guide zip
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
 * @note `zip(vector<int>{1, 2, 3}, string("pterodactilo")) | WRITE(); //[(1, p), (2, t), (3, e)]`
 * @note `vector<int>{1, 2, 3}| ZIP(string("pterodactilo")) | WRITE(); //[(1, p), (2, t), (3, e)]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#zip
 */
    ZIP(const CONTAINER_B& container_b) : container_b(container_b) {}

    template<typename CONTAINER_A>
    auto operator()(const CONTAINER_A& container_a) const { return zip(container_a, container_b); }
    template<typename CONTAINER_A>
    friend auto operator|(const CONTAINER_A& container_a, const ZIP& obj) { return obj(container_a); }
};

//--------------------------------------------------------
//-------------------- ZIPWITH ---------------------------
//--------------------------------------------------------

//__guide zipwith
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
 * @note `auto concat = [](auto x, auto y) { return tostr(x) + y; };`
 * @note `zipwith(vector<int>{1, 2, 3}, string("pterodactilo"), concat) | WRITE(); // ["1p", "2t", "3e"]`
 * @note `zipwith(range(10), "pterodactilo"s, concat) | WRITE(); // ["0p", "1t", "2e", "3r", "4o", "5d", "6a", "7c", "8t", "9i"]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#zipwith
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
struct ZIPWITH {
    CONTAINER_B container_b;
    FNJOIN fnjoin;

//__guide zipwith
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
 * @note `auto concat = [](auto x, auto y) { return tostr(x) + y; };`
 * @note `zipwith(vector<int>{1, 2, 3}, string("pterodactilo"), concat) | WRITE(); // ["1p", "2t", "3e"]`
 * @note `zipwith(range(10), "pterodactilo"s, concat) | WRITE(); // ["0p", "1t", "2e", "3r", "4o", "5d", "6a", "7c", "8t", "9i"]`
 * 
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#zipwith
 * 
 */
    ZIPWITH(const CONTAINER_B& container_b, FNJOIN fnjoin) : container_b(container_b), fnjoin(fnjoin) {}

    template<typename CONTAINER_A>        auto operator()(const CONTAINER_A& container_a) const { return zipwith(container_a, container_b, fnjoin); }
    template<typename CONTAINER_A> friend auto operator| (const CONTAINER_A& container_a, const ZIPWITH& obj) { return obj(container_a); }
};

//--------------------------------------------------------
//-------------------- SPLIT -----------------------------
//--------------------------------------------------------

//__guide split
//[[split]]
/**
 * @note #### `split(str content, char delimiter = ' ') -> vector<str>`
 * @note #### `str content| SPLIT(char delimiter = ' ') -> vector<str>`
 * 
 * @note - Transforma uma string em um vetor de strings, separando pelo delimitador.
 * 
 * @note #### Parâmetros
 * @note `param: content` String a ser separada.
 * @note `param: delimiter` (opcional) Caractere delimitador.
 * @note `return` Vetor de strings.
 *
 * @note #### Exemplos
 * @note `split("a,b,c", ',') | WRITE(); // [a, b, c]`
 * @note `"a,b,c"| SPLIT(',') | WRITE(); // [a, b, c]`
 * @note `split("a b c") | WRITE(); // [a, b, c]`
 * @note `"a b c"|SPLIT()| WRITE(); // [a, b, c]`
 *  
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#split
 */
inline std::vector<std::string> split(std::string content, char delimiter = ' ')
//[[split]]
{
    std::vector<std::string> aux;
    std::string token;
    std::istringstream tokenStream(content);
    while (std::getline(tokenStream, token, delimiter))
        aux.push_back(token);
    return aux;
}

struct SPLIT {
    char delimiter;

//__guide split
/**
 * @note #### `split(str content, char delimiter = ' ') -> vector<str>`
 * @note #### `str content| SPLIT(char delimiter = ' ') -> vector<str>`
 * 
 * @note - Transforma uma string em um vetor de strings, separando pelo delimitador.
 * 
 * @note #### Parâmetros
 * @note `param: content` String a ser separada.
 * @note `param: delimiter` (opcional) Caractere delimitador.
 * @note `return` Vetor de strings.
 *
 * @note #### Exemplos
 * @note `split("a,b,c", ',') | WRITE(); // [a, b, c]`
 * @note `"a,b,c"| SPLIT(',') | WRITE(); // [a, b, c]`
 * @note `split("a b c") | WRITE(); // [a, b, c]`
 * @note `"a b c"|SPLIT()| WRITE(); // [a, b, c]`
 *  
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#split
 */
    SPLIT(char delimiter = ' ') : delimiter(delimiter) {}

    std::vector<std::string>        operator()(std::string content) const { return split(content, delimiter); }
    friend std::vector<std::string> operator| (std::string content, const SPLIT& obj) { return obj(content); }
};

//--------------------------------------------------------
//-------------------- INPUT -----------------------------
//--------------------------------------------------------

//__guide input
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
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#input
 */
inline std::string input(std::istream & is = std::cin)
//[[input]]
{
    std::string line;
    if (std::getline(is, line))
        return line;
    throw std::runtime_error("input empty");
}

struct INPUT {
//__guide input
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
 * @note #### Veja mais exemplos em https://github.com/senapk/cppaux#input
 */
    INPUT() {}

    std::string        operator()(std::istream& is = std::cin) const { return input(is); }
    friend std::string operator| (std::istream& is, const INPUT& obj) { return obj(is); }
};

} // namespace fn

using namespace std::string_literals;

//__guide operator+
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
 * @note `+"1.23"s | WRITE(); // 1.23`
 * 
*/
inline double operator+(std::string text) {
    return fn::number(text);
}
