#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <functional>


namespace aux {

    using Chain = std::map<std::string, std::function<void()>>;
    using Param = std::vector<std::string>;

    enum EXEC_MODE {ASYNC, SYNC};

    std::vector<std::string> __split(const std::string& line, char delimiter) {
        std::istringstream is(line);
        std::vector<std::string> output;
        std::string token;
        while(std::getline(is, token, delimiter))
            output.push_back(token);
        return output;
    };

    void __action(Chain& chain, Param& param, aux::EXEC_MODE mode) {
        while(true) {
            std::string line{}, cmd{};
            if (mode == SYNC)
                std::cout << "$";
            std::getline(std::cin, line);
            std::stringstream ss(line);
            ss >> cmd;
            param = __split(line, ' ');
            if (mode == ASYNC)
                std::cout << "$" << line << '\n';
            if (cmd == "end") {
                break;
            } else if (chain.count(cmd) != 0) {
                try {
                    chain[cmd]();
                } catch (std::string& e) {
                    std::cout << e << '\n';
                }
            } else {
                std::cout << "fail: command not found\n";
            }
        }
    }

    void execute(Chain& chain, Param& param) {
        __action(chain, param, SYNC);
    }

    void evaluate(Chain& chain, Param& param) {
        __action(chain, param, ASYNC);
    }

    template <class T>
    T str2(std::string data) {
        T value;
        std::stringstream ss(data);
        
        if(ss >> value)
            return value;
        std::cout << "conversão de dados inválida\n"; 
        return value;
    }
}


