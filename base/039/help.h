#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

template <class T>
T to(std::string data); //int value = to<int>("43");

template <class T> //cout com o endl
void print(T data); 

std::vector<int> to_vet(std::string data); //vector<int> vet = to_vet("[1,2,3]");
std::vector<std::string> split(std::string content, char sep = ' '); //quebra uma linha em um vetor de palavras
std::string fmt(std::vector<int> data); //formata vetor como [2,3,4,5]
std::string fmt(bool value); //retorna bool como "true" ou "false"
std::string fmt(double value); //retorna com duas casas decimais;


//--------------------------------------

std::vector<std::string> split(std::string content, char sep) {
    std::stringstream ss(content);
    std::string token;
    std::vector<std::string> vet;
    while(std::getline(ss, token, sep))
        vet.push_back(token);
    return vet;
}

template <class T>
T to(std::string data) {
    T value;
    std::istringstream(data) >> value;
    return value;
}

std::vector<int> to_vet(std::string data) {
    auto vet_str = split(data.substr(1, data.size() - 2), ',');
    std::vector<int> vet;
    for (auto token : vet_str)
        vet.push_back(to<int>(token));
    return vet;
}

std::string fmt(std::vector<int> data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? "," : "") << *it;
    ss << "]";
    return ss.str();
}

std::string fmt(bool value) {
    return value ? "true" : "false";
}

std::string fmt(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << value;
    return ss.str();
}

template <class T>
void print(T data) {
    std::cout << data << '\n';
} 