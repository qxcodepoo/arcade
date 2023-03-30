#pragma once

#include <iostream>
#include <sstream>
#include <memory>
#include <optional>

#include <array>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace fn {

//[[pipe]]
/**
 * @brief Functor para criação de funções Pipeline.
 * 
 * PIPE é um functor, ou seja, uma struct que após instanciada, funciona como uma função.
 * Ela é construída passando uma função que recebe um único parâmetro qualquer.
 * O PIPE então guarda essa função para que possa ser executada em pipeline ou invocada diretamente.
 * 
 * @param fn função a ser guardada
 * 
 * @warning 5 | PIPE([](int x){return x * 2;}) | WRITE(); // 10
 * @note https://github.com/senapk/cppaux/#pipe
 */
template<typename FUNCTION> 
struct PIPE
//[[pipe]]]
{
    FUNCTION fn;
    PIPE(FUNCTION fn) : fn(fn) {}

    PIPE& operator()() { 
        return *this; 
    }

    template<typename DATA>
    auto operator()(DATA data) { 
        return fn(data); 
    }

    template<typename DATA>
    friend auto operator|(DATA data, PIPE<FUNCTION> PIPE) {
        return PIPE(data);
    }
};

//-------------------------------------------------
template<typename PRINTABLE>
std::string tostr(PRINTABLE data, std::string cfmt = ""); 

struct __STRAUX {
    template <typename ...Args>
    static std::string cformat(const std::string& format, Args && ...args) 
    {
        auto size = std::snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args)...);
        std::string output(size + 1, '\0');
        std::sprintf(&output[0], format.c_str(), std::forward<Args>(args)...);
        if (output.back() == '\0') 
            output.pop_back();
        return output;
    }

    static std::string embrace(std::string data, std::string brackets) 
    {
        auto prefix = brackets.size() > 0 ? std::string {brackets[0]} : "";
        auto suffix = brackets.size() > 1 ? std::string {brackets[1]} : "";
        return prefix + data + suffix;
    }

    template <typename CONTAINER>
    static std::string join(std::string fmt, CONTAINER container, std::string separator = ", ", std::string brackets = "[]")
    {
        std::ostringstream ss;
        for (auto it = container.begin(); it != container.end(); ++it) {
            ss << (it == container.begin() ? "" : separator) << tostr(*it, fmt);
        }
        auto output = ss.str();
        return __STRAUX::embrace(output, brackets);
    }

    template <typename... Ts>
    static std::string join(std::string fmt, std::tuple<Ts...> const &theTuple, std::string separator = ", ", std::string brackets = "()")
    {
        std::stringstream ss;
        std::apply( [&](Ts const &...tupleArgs) {
                std::size_t n{0};
                ((ss << tostr(tupleArgs, fmt) << (++n != sizeof...(Ts) ? separator : "")), ...);
            }, theTuple);
        return __STRAUX::embrace(ss.str(), brackets);
    }

    template<typename A, typename B>
    static std::string join(std::string fmt, std::pair<A, B> pair, std::string separator = ", ", std::string brackets = "()")
    {
        auto output = tostr(pair.first, fmt) + separator + tostr(pair.second, fmt);
        return __STRAUX::embrace(output, brackets);
    }
};

//-------------------------------------------------

//[[join]]
/**
 * Transforma um container, par ou tupla em string, separando os elementos
 * pelo separador e envolvendo com os brakets.
 *
 * Se os elementos não forem strings, eles serão transformados em string utilizando
 * a função tostr.
 * 
 * @param container Container a ser transformado em string
 * @param separator Separador entre os elementos
 * @param brakets   Brakets que envolvem a string
 * @return string com os elementos concatenados
 * 
 * @warning join(std::vector<int>{1,2,3}, " ", "{}") | WRITE(); // "{1 2 3}"
 * 
 * @note https://github.com/senapk/cppaux#join
 */
template <typename CONTAINER>
std::string join(CONTAINER container, std::string separator = "", std::string brakets = "")
//[[join]]
{
    return __STRAUX().join("", container, separator, brakets);
}

/**
 * container | JOIN(separator, brakets)
 * 
 * @param container Container a ser transformado em string
 * @param separator (opcional) Separador entre os elementos
 * @param brakets   (opcional) Brakets que envolvem a string
 * @return string com os elementos concatenados
 * 
 * @warning join(std::vector<int>{1,2,3}, " ", "{}") | WRITE(); // "{1 2 3}"
 * 
 * @note https://github.com/senapk/cppaux#join
 */
inline auto JOIN(std::string separator = "", std::string brakets = "") {
    return PIPE([separator, brakets](auto container) {
        return join(container, separator, brakets);
    });
};

//-------------------------------------------------

template <typename DATA>
struct __TOSTR{
    std::string apply(DATA data, std::string fmt = "") {
        if (fmt == "") {
            std::ostringstream ss;
            ss << data;
            return ss.str();
        } else {
            return __STRAUX::cformat(fmt, data);
        }
    }
};

//specialization for bool
template <>
struct __TOSTR<bool> {
    std::string apply(bool t, std::string fmt = "") {
        (void) fmt;
        return t ? "true" : "false";
    }
};

//specialization for string
template <>
struct __TOSTR<std::string> {
    std::string apply(std::string v, std::string fmt = "") {
        if (fmt.size() > 0) {
            static std::string dummy;
            dummy = v;
            return __STRAUX::cformat(fmt, v.c_str());
        }
        return v;
    }
};

//specialization for pair
template <typename A, typename B>
struct __TOSTR<std::pair<A, B>> {
    std::string apply(std::pair<A, B> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "()");
    }
};

//specialization for tuple
template <typename... Ts>
struct __TOSTR<std::tuple<Ts...>> {
    std::string apply(std::tuple<Ts...> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "()");
    }
};

//specialization for vector
template <typename T>
struct __TOSTR<std::vector<T>> {
    std::string apply(std::vector<T> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "[]");
    }
};

//specialization for list
template <typename T>
struct __TOSTR<std::list<T>> {
    std::string apply(std::list<T> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "[]");
    }
};

//specialization for array
template <typename T, std::size_t N>
struct __TOSTR<std::array<T, N>> {
    std::string apply(std::array<T, N> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "[]");
    }
};

//specialization for set
template <typename T>
struct __TOSTR<std::set<T>> {
    std::string apply(std::set<T> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "{}");
    }
};

//specialization for map
template <typename A, typename B>
struct __TOSTR<std::map<A, B>> {
    std::string apply(std::map<A, B> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "{}");
    }
};

//specialization for unordered_map
template <typename A, typename B>
struct __TOSTR<std::unordered_map<A, B>> {
    std::string apply(std::unordered_map<A, B> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "{}");
    }
};

//specialization for unordered_set
template <typename T>
struct __TOSTR<std::unordered_set<T>> {
    std::string apply(std::unordered_set<T> t, std::string fmt = "") {
        return __STRAUX::join(fmt, t, ", ", "{}");
    }
};

//specialization for shared_ptr
template <typename T>
struct __TOSTR<std::shared_ptr<T>> {
    std::string apply(std::shared_ptr<T> t, std::string fmt = "") {
        return t ? __TOSTR<T>().apply(*t, fmt) : "null";
    }
};

//specialization for optional
template <typename T>
struct __TOSTR<std::optional<T>> {
    std::string apply(std::optional<T> t, std::string fmt = "") {
        return t ? __TOSTR<T>().apply(*t, fmt) : "null";
    }
};

//[[tostr]]
/**
 * Converte o dado passado em string.
 * 
 * Se passado o parâmetro de formatação cfmt, o dado será formatado usando o modelo do printf.
 * Se o dado for um container, o formato será aplicado em todos os elementos
 * do container recursivamente.
 * 
 * vectors, lists e arrays são impressos entre colchetes.
 * maps e sets são impressos entre chaves.
 * pairs e tuples são impressos entre parênteses.
 * shared_ptr e optional são impressos como o valor contido ou null.
 * 
 * Para classe do usuário ser impressa, ela deve sobrecarregar o ostream& operador <<.
 * 
 * @param data Dado a ser convertido
 * @param cfmt (opcional) Parâmetro de formatação no modo printf
 * @return String com o dado convertido
 * 
 * @warning tostr(std::list<int>{1,2,3}, "%02d") | WRITE();
 * 
 * @note https://github.com/senapk/cppaux#tostr
 */
template<typename PRINTABLE>
std::string tostr(PRINTABLE data, std::string cfmt)
//[[tostr]]
{
    return __TOSTR<PRINTABLE>().apply(data, cfmt);
}


/**
 * DATA | TOSTR(cfmt)
 * 
 * @param data Dado a ser convertido
 * @param cfmt (opcional) Parâmetro de formatação no modo printf
 * @return String com o dado convertido
 * 
 * @warning tostr(std::list<int>{1,2,3}, "%02d") | WRITE();
 * 
 * @note https://github.com/senapk/cppaux#tostr
 */
inline auto TOSTR(std::string cfmt = "") {
    return PIPE([cfmt](auto data) {
        return tostr(data, cfmt);
    });
};


//-------------------------------------------------

//[[fnt]]
/**
 * Encurtador de função lambda para um único parâmetro e uma única operação a ser retornada.
 * O primeiro parâmetro é o nome da variável a ser utilizada, o segundo é a operação a ser realizada.
 * 
 * @param x Nome da variável
 * @param fx Operação a ser realizada
 * @return Função lambda
 * 
 * @note https://github.com/senapk/cppaux#fnt
 */
#define FNT(x, fx)                  [] (auto x) { return fx; }
//[[fnt]]

// Encurtador de função lambda para dois parâmetros e uma única operação a ser retornada.
#define FNT2(x, y, fxy)             [] (auto x, auto y) { return fxy; }

//-------------------------------------------------
class __SLICE {
    int begin;
    int end;
    bool from_begin {false};
    bool to_end {false};

    template<typename CONTAINER>
    static auto new_vec_from(CONTAINER container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<decltype(fn(*container.begin()))> aux;
        return aux;
    }

    template <typename K, typename T>
    static auto new_vec_from(std::map<K, T> container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<std::pair<decltype(fn(container.begin()->first)), decltype(fn(container.begin()->second))>> aux;
        return aux;
    }

    template <typename K, typename T>
    static auto new_vec_from(std::unordered_map<K, T> container) {
        auto fn = [](auto x) {return x;}; 
        std::vector<std::pair<decltype(fn(container.begin()->first)), decltype(fn(container.begin()->second))>> aux;
        return aux;
    }

public:
    __SLICE(int begin = 0) {
        this->from_begin = begin == 0;
        this->begin = begin;
        this->to_end = true;
    }
    __SLICE(int begin, int end) {
        this->begin = begin;
        this->end = end;
        this->from_begin = false;
        this->to_end = false;
    }

    template<typename CONTAINER>
    auto operator()(CONTAINER container) {
        auto aux = __SLICE::new_vec_from(container);
        
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
};

//[[slice]]
/**
 * Fatia um container de begin até o fim retornando um vector com os elementos copiados.
 * O funcionamento é equivalente à função slice do Python ou do Javascript. Se não passado
 * nenhum parâmetro, copia todos os elementos.
 * 
 * @param container Container a ser fatiado
 * @param begin (opcional) Índice inicial
 * @return Vector com os elementos copiados
 * 
 * @warning std::vector<int>{1, 2, 3, 4, 5} | SLICE(1)  | WRITE(); // [2, 3, 4, 5]
 * 
 * @note https://github.com/senapk/cppaux#slice
*/
template<typename CONTAINER>
auto slice(CONTAINER container, int begin = 0)
//[[slice]]
{
    return __SLICE(begin)(container);
}


/**
 * container | SLICE(begin)
 * 
 * @param container Container a ser fatiado
 * @param begin (opcional) Índice inicial
 * @return Vector com os elementos copiados
 * 
 * @warning std::vector<int>{1, 2, 3, 4, 5} | SLICE(1)  | WRITE(); // [2, 3, 4, 5]
 * 
 * @note https://github.com/senapk/cppaux#slice
*/
inline auto SLICE(int begin = 0)
{
    return PIPE([begin](auto container) {
        return __SLICE(begin)(container);
    });
};

/**
 * Fatia um container de begin até o fim retornando um vector com os elementos copiados.
 * O funcionamento é equivalente à função slice do Python ou do Javascript. Se não passado
 * nenhum parâmetro, copia todos os elementos.
 * 
 * @param container Container a ser fatiado
 * @param begin Índice inicial
 * @param end Índice final
 * @return Vector com os elementos copiados
 * 
 * @warning std::vector<int>{1, 2, 3, 4, 5} | SLICE(1, -1)  | WRITE(); // [2, 3, 4]
 * 
 * @note https://github.com/senapk/cppaux#slice
*/
template<typename CONTAINER>
auto slice(CONTAINER container, int begin, int end)
{
    return __SLICE(begin, end)(container);
}

/**
 * container | SLICE(begin, end)
 * 
 * @param container Container a ser fatiado
 * @param begin Índice inicial
 * @param end Índice final
 * @return Vector com os elementos copiados
 * 
 * @warning std::vector<int>{1, 2, 3, 4, 5} | SLICE(1, -1)  | WRITE(); // [2, 3, 4]
 * 
 * @note https://github.com/senapk/cppaux#slice
*/
inline auto SLICE(int begin, int end)
{
    return PIPE([begin, end](auto container) {
        return __SLICE(begin, end)(container);
    });
};

// -------------------------------------------------
//[[map]]
/**
 * Retorna um vetor com o resultado da aplicação da função fn para cada elemento do container
 * 
 * @param container Container a ser mapeado
 * @param fn Função a ser aplicada em cada elemento do container
 * @return Vector com os elementos resultantes da aplicação da função
 * 
 * @note https://github.com/senapk/cppaux#map
 */
template<typename CONTAINER, typename FUNCTION>
auto map(CONTAINER container, FUNCTION fn)
//[[map]]
{
    std::vector<decltype(fn(*container.begin()))> aux;
    //std::transform(container.begin(), container.end(), std::back_inserter(aux), fn);
    for (auto& item : container) {
        aux.push_back(fn(item));
    }
    return aux;
}

/**
 * container | MAP(fn)
 * 
 * @param container Container a ser mapeado
 * @param fn Função a ser aplicada em cada elemento do container
 * @return Vector com os elementos resultantes da aplicação da função
 * 
 * @note https://github.com/senapk/cppaux#map
 */
template <typename FUNCTION>
auto MAP(FUNCTION fn) {
    return PIPE([fn](auto container) {
        return map(container, fn);
    });
};

//-------------------------------------------------

//[[filter]]
/**
 * Retorna um vetor com os elementos do container que satisfazem a função predicado fn
 * @param container Container a ser filtrado
 * @param fn Função predicado
 * @return Vector com os elementos que satisfazem a função predicado
 * 
 * @note https://github.com/senapk/cppaux#filter
 */
template<typename CONTAINER, typename FUNCTION>
auto filter(CONTAINER container, FUNCTION fn)
//[[filter]]
{
    auto aux = slice(container, 0, 0);
    for(auto& x : container) {
        if(fn(x))
            aux.push_back(x);
    }
    return aux;
}

/**
 * container | FILTER(fn)
 * 
 * @param container Container a ser filtrado
 * @param fn Função predicado
 * @return Vector com os elementos que satisfazem a função predicado
 * 
 * @note https://github.com/senapk/cppaux#filter
 */
template <typename FUNCTION>
auto FILTER(FUNCTION fn)
{
    return PIPE([fn](auto container) {
        return filter(container, fn);
    });
};

//-------------------------------------------------

//[[strto]]
/**
 * Transforma de string para o tipo solicitado utilizando o operador de extração de stream.
 * Dispara uma exceção caso a conversão não seja possível.
 * 
 * @param value String a ser convertida
 * @tparam READABLE Tipo a ser convertido
 * @return Valor convertido
 * @throws std::runtime_error Caso a conversão não seja possível
 * 
 * @note https://github.com/senapk/cppaux#strto
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

/**
 * value | STRTO<READABLE>()
 * 
 * @param value String a ser convertida
 * @tparam READABLE Tipo a ser convertido
 * @return Valor convertido
 * @throws std::runtime_error Caso a conversão não seja possível
 * 
 * @note https://github.com/senapk/cppaux#strto
 * 
*/
template <typename READABLE>
auto STRTO() {
    return PIPE([](std::string value) {
        return strto<READABLE>(value);
    });
};

//-------------------------------------------------

//[[number]]
/**
 * Transforma de string para double utilizando a função strto.
 * 
 * @param value String a ser convertida
 * @return Valor convertido para double
 * @throws std::runtime_error Caso a conversão não seja possível
 * 
 * @note https://github.com/senapk/cppaux#number
 * 
*/
inline double number(std::string value)
//[[number]]
{
    return strto<double>(value);
}

/**
 * value | NUMBER()
 * 
 * @param value String a ser convertida
 * @return Valor convertido para double
 * @throws std::runtime_error Caso a conversão não seja possível
 * 
 * @note https://github.com/senapk/cppaux#number
 * 
*/
inline auto NUMBER() {
    return PIPE([](std::string value) {
        return number(value);
    });
};

//-------------------------------------------------
template <typename... Types>
struct __UNPACK {
    char delimiter;
    __UNPACK(char delimiter) : delimiter(delimiter) {}

    template<typename Head, typename... Tail>
    std::tuple<Head, Tail...> tuple_read_impl(std::istream& is, char delimiter) {
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

    std::tuple<Types...> operator()(std::string content) {
        std::stringstream ss(content);
        return tuple_read_impl<Types...>(ss, this->delimiter);
    }
};

//[[unpack]]
/**
 * Transforma de string para tupla dados os tipos de cada elemento e o char separador.
 * 
 * @tparam TS... Tipos a serem extraídos
 * @param value String a ser convertida
 * @param delimiter Caractere separador entre os elementos
 * @return Tupla com os elementos convertidos
 * 
 * @warning unpack<int, double, std::string>("1:2.4:uva", ':') | WRITE(); // (1, 2.4, "uva")
 * 
 * @note https://github.com/senapk/cppaux#unpack
 * 
 */
template <typename... TS>
std::tuple<TS...> unpack(const std::string& line, char delimiter)
//[[unpack]]
{
    return __UNPACK<TS...>(delimiter)(line);
}


/**
 * value | UNPACK<TS...>(delimiter)
 * 
 * @tparam TS... Tipos a serem extraídos
 * @param value String a ser convertida
 * @param delimiter Caractere separador entre os elementos
 * @return Tupla com os elementos convertidos
 * 
 * @warning "1:2.4:uva" | UNPACK<int, double, std::string>(':') | WRITE(); // (1, 2.4, "uva")
 * 
 * @note https://github.com/senapk/cppaux#unpack
 * 
 */
template <typename... TS>
auto UNPACK(char delimiter) {
    return PIPE([delimiter](std::string line) {
        return __UNPACK<TS...>(delimiter)(line);
    });
};

//-------------------------------------------------

//[[zip]]
/**
 * Une dois containers em um vetor de pares limitado ao menor tamanho dos dois containers.
 * 
 * @param container_a primeiro container
 * @param container_b segundo container
 * @return Vetor de pares
 * 
 * @warning zip(vector<int>{1, 2, 3}, string("pterodactilo")) | WRITE(); //[(1, p), (2, t), (3, e)]
 * 
 * @note https://github.com/senapk/cppaux#zip
 */
template<typename CONTAINER_A, typename CONTAINER_B>
auto zip(CONTAINER_A A, CONTAINER_B B)
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

/**
 * container_a | ZIP(container_b)
 * 
 * @param container_a primeiro container
 * @param container_b segundo container
 * @return Vetor de pares
 * 
 * @warning vector<int>{1, 2, 3} | ZIP(string("pterodactilo")) | WRITE(); //[(1, p), (2, t), (3, e)]
 * 
 * @note https://github.com/senapk/cppaux#zip
 * 
 */
template<typename CONTAINER_B>
auto ZIP(CONTAINER_B B) {
    return PIPE([B](auto A) {
        return zip(A, B);
    });
};

//-------------------------------------------------

//[[zipwith]]
/**
 * Une dois containers em um único container limitado ao menor tamanho dos dois containers
 * colocando o resultado da função fnjoin em cada par no container de saída.
 * 
 * @param container_a primeiro container
 * @param container_b segundo container
 * @return Vetor com os resultados
 * 
 * @warning zipwith(range(10), "pterodactilo"s, FNT2(x, y, tostr(x) + y)) | WRITE(); // ["0p", "1t", "2e", "3r", "4o", "5d", "6a", "7c", "8t", "9i"]
 * @note https://github.com/senapk/cppaux#zipwith
 * 
 */
template<typename CONTAINER_A, typename CONTAINER_B, typename FNJOIN>
auto zipwith(CONTAINER_A A, CONTAINER_B B, FNJOIN fnjoin)
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

/**
 * container_a | ZIPWITH(container_b, fnjoin)
 * 
 * @param container_a primeiro container
 * @param container_b segundo container
 * @return Vetor com os resultados
 * 
 * @warning range(10) | ZIPWITH("pterodactilo"s, FNT2(x, y, tostr(x) + y)) | WRITE(); // ["0p", "1t", "2e", "3r", "4o", "5d", "6a", "7c", "8t", "9i"]
 * 
 * @note https://github.com/senapk/cppaux#zipwith
 * 
 */
template<typename CONTAINER_B, typename FNJOIN>
auto ZIPWITH(CONTAINER_B B, FNJOIN fnjoin) {
    return PIPE([B, fnjoin](auto A) {
        return zipwith(A, B, fnjoin);
    });
};

//-------------------------------------------------

template<typename... Args>
class __FORMAT 
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
                ((result.push_back(TOSTR(controls[++i])(tupleArgs))), ...);
            }, this->args
        );
        return result;
    }

    std::pair<std::vector<std::string>, std::vector<std::string>> extract(std::string data)
    {
        data.append("_");
        auto lim = data.size() - 1;
        std::vector<std::string> texts = {""};
        std::vector<std::string> ctrls = {""};
        auto* destiny = &texts;

        for (size_t i = 0; i < lim;) {
            char c = data[i];
            if ((c == '{' && data[i + 1] == '{') || (c == '}' && data[i + 1] == '}'))
            {
                destiny->back().append(std::string(1, c));
                i += 2;
            }
            else if (c == '{') 
            {
                texts.push_back("");
                destiny = &ctrls;
                i++;
            }
            else if (c == '}') 
            {
                ctrls.push_back("");
                destiny = &texts;
                i++;
            }
            else
            {
                destiny->back().append(std::string(1,c));
                i++;
            }
        }
        while (texts.size() > ctrls.size())
            ctrls.push_back("");
        return {texts, ctrls};
    }

public:

    __FORMAT(Args ...args): args(std::forward<Args>(args)...)
    {
    }

    std::string operator()(std::string fmt)
    {
        auto [texts, controls] = extract(fmt);
        auto vars = tuple_to_vector_str(controls);
        while(vars.size() < texts.size())
            vars.push_back("");
        return __STRAUX().join("", texts | ZIPWITH(vars, [](auto x, auto y) { return x + y;}), "", ""); 
    }
};

//[[format]]
/**
 * Formata uma string com base nos argumentos passados utilizando um modelo de chaves para posicionar os argumentos.
 * Se dentro da chave, houver um string de formatação, o dado será formatado com base nela.
 * Não primitivos são formatados de acordo com a função TOSTR
 * 
 * @param fmt O texto com os {} para substituir pelos argumentos
 * @param Args Os argumentos a serem substituídos
 * @return O texto formatado
 * 
 * @warning format("O {} é {0.2f} e o {} é {0.2f}", "pi", 3.141592653, "e", 2.7182818);
 * @note https://github.com/senapk/cppaux#format
 * 
 */
template<typename... Args>
std::string format(std::string fmt, Args ...args)
//[[format]]
{
    return __FORMAT<Args...>(args...)(fmt);
}

/**
 * texto | FORMAT(arg1, arg2, ...)
 * 
 * @param fmt O texto com os {} para substituir pelos argumentos
 * @param Args Os argumentos a serem substituídos
 * @return O texto formatado
 * 
 * @warning "O {} é {0.2f} e o {} é {0.2f}" | FORMAT("pi", 3.141592653, "e", 2.7182818);
 * 
 * @note https://github.com/senapk/cppaux#format
 */
template<typename... Args>
auto FORMAT(Args ...args) {
    return PIPE([args...](std::string fmt) {
        return __FORMAT<Args...>(args...)(fmt);
    });
};

//-------------------------------------------------

// [[range]]
/**
 * @brief Gera um vetor de inteiros de init até end, mas não incluindo end, com passo step.
 * 
 * @param init início
 * @param end limite superior
 * @param step passo do incremento
 * @return vetor de inteiros
 * 
 * @warning range(0, 10, 2) | WRITE(); // [0, 2, 4, 6, 8]
 * 
 * @note https://github.com/senapk/cppaux#range
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
 * inicio | RANGE(end, step)
 * 
 * @param init início
 * @param end limite superior
 * @param step passo do incremento
 * @return vetor de inteiros
 * 
 * @warning 0 | RANGE(10, 2) | WRITE(); // [0, 2, 4, 6, 8]
 * 
 * @note https://github.com/senapk/cppaux#range
*/
inline auto RANGE(int end, int step = 1) {
    return PIPE([end, step](int init) {
        return range(init, end, step);
    });
};

/**
 * @brief Gera um vetor de inteiros de 0 até end, mas não incluindo end, com passo step
 * 
 * @param end limite superior
 * @param step passo do incremento
 * @return vetor de inteiros
 * 
 * @warning range(10) | WRITE(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * @note https://github.com/senapk/cppaux#range
*/
inline std::vector<int> range(int end) {
    return range(0, end, 1);
}

/**
 * @brief Gera um vetor de inteiros de 0 até end, mas não incluindo end, com passo step
 * 
 * @param end limite superior
 * @param step passo do incremento
 * @return vetor de inteiros
 * 
 * @warning 10 | RANGE() | WRITE(); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 * 
 * @note https://github.com/senapk/cppaux#range
*/
inline auto RANGE() {
    return PIPE([](int end) {
        return range(0, end, 1);
    });
};

//-------------------------------------------------

//[[write]]
/**
 * Tranforma um dado em string utilizando a função tostr e envia para o std::cout quebrando a linha.
 * 
 * @param data Dado a ser transformado em string
 * @param end (opcional) String de finalização
 * @return Dado original
 * 
 * @warning write(std::vector<int> {1, 2, 3}); // [1, 2, 3]
 * 
 * @note https://github.com/senapk/cppaux#write
 */
template <typename PRINTABLE>
PRINTABLE write(PRINTABLE data, std::string end = "\n") 
//[[write]]
{
    std::cout << tostr(data) << end;
    return data;
}

/**
 * data | WRITE(end)
 * 
 * @param data Dado a ser transformado em string
 * @param end (opcional) String de finalização
 * @return Dado original
 * 
 * @warning std::vector<int> {1, 2, 3} | WRITE(); // [1, 2, 3]
 * 
 * @note https://github.com/senapk/cppaux#write
 */
inline auto WRITE(std::string end = "\n") {
    return PIPE([end](auto data) {
        return write(data, end);
    });
}

//-------------------------------------------------

//[[split]]
/**
 * Transforma uma string em um vetor de strings, separando pelo delimitador
 * 
 * @param content String a ser separada
 * @param delimiter (opcional) Caractere delimitador
 * @return Vetor de strings
 * 
 * @warning split("a,b,c", ',') | WRITE(); // [a, b, c]
 * 
 * @note https://github.com/senapk/cppaux#split
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

/**
 * content | SPLIT(delimiter)
 * 
 * @param content String a ser separada
 * @param delimiter (opcional) Caractere delimitador
 * @return Vetor de strings
 * 
 * @warning "a,b,c" | SPLIT(',') | WRITE(); // [a, b, c]
 * 
 * @note https://github.com/senapk/cppaux#split
 */
inline auto SPLIT(char delimiter = ' ') {
    return PIPE([delimiter](std::string content) {
        return split(content, delimiter);
    });
};

//[[input]]
/**
 * Extrai uma linha inteira e retorna como string
 * O padrão é o std::cin, mas pode ser um fluxo ou arquivo
 * Se não houver mais linhas, lança uma exceção
 * 
 * @param source (opcional) de onde ler a linha
 * @return linha lida
 * 
 * @warning auto line = input();
 * 
 * @note https://github.com/senapk/cppaux#input
 */
inline std::string input(std::istream & is = std::cin)
//[[input]]
{
    std::string line;
    if (std::getline(is, line))
        return line;
    throw std::runtime_error("input empty");
}

/**
 * Extrai uma linha inteira e retorna como string
 * O padrão é o std::cin, mas pode ser um fluxo ou arquivo
 * Se não houver mais linhas, lança uma exceção
 * 
 * @param source (opcional) de onde ler a linha
 * @return linha lida
 * 
 * @warning auto line = std::cin | INPUT(); // lê uma linha do std::cin
 * 
 * @note https://github.com/senapk/cppaux#input
 */
struct INPUT {
    friend std::string operator|(std::istream& is, INPUT) {
        return input(is);
    }
};

} // namespace fn

using namespace std::string_literals;

// Transforma uma string em um double utilizando a função STRTO
inline double operator+(std::string text) {
    return fn::strto<double>(text);
}
