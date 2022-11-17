#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>


double operator+(std::string text); //converte de string para double colocando um + na frente da string
std::vector<std::string> load_args(); //pega a linha e quebra em vetor de palavras
std::vector<std::string> split(std::string line, char delimiter); //quebra em vetor de palavras
template <class T> std::string join(T container, std::string sep); //junta os objetos usando o separador

int main() {
    Account acc(0);
    while (true) {
        auto args = load_args();
        auto cmd = args[0];
        std::cout << "$" << join(args, " ") << "\n";

        if      (cmd == "end")      { break;                               }
        else if (cmd == "show")     { std::cout << acc.str() << '\n'; }
        else if (cmd == "init")     { acc = Account(+args.at(1));          }
        else if (cmd == "deposit")  {   acc.deposit(+args.at(1));          }
        else if (cmd == "withdraw") {  acc.withdraw(+args.at(1));          }
        else if (cmd == "fee")      {       acc.fee(+args.at(1));          }
        else if (cmd == "reverse")  { 
            for(size_t i = 1; i < args.size(); i++)
                acc.reverse(+args.at(i));
        }
        else if (cmd == "extract")  { 
            auto operations = acc.getManager().getExtract(+args.at(1));
            std::cout << join(operations, "\n") << '\n'; 
        }
        else                        { 
            std::cout << "fail: invalid command\n";                                         
        }
    }
}

double operator+(std::string text) {
    std::stringstream ss(text);
    double value {};
    if (ss >> value)
        return value;
    std::cout << "fail: (" << text << ") is not a number\n";
    return 0.0;
}

std::vector<std::string> load_args() { 
    std::string line;
    std::getline(std::cin, line);
    return split(line, ' ');
}

std::vector<std::string> split(std::string line, char delimiter) {
    std::stringstream ss(line);
    std::vector<std::string> result;
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}

template <class T> std::string join(T container, std::string sep) { 
    std::stringstream ss;
    for (auto item : container)
        ss << sep << item;
    return ss.str().substr(sep.size());
}
