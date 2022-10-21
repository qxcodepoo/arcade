#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <aux.hpp>


using namespace aux;

int main() {
    Chain chain;
    Param ui;
    Account acc(0);

    auto INT = STR2<int>();

    chain["show"]     = [&]() { std::cout << acc.str() << std::endl; };
    chain["init"]     = [&]() { acc = Account(INT(ui[1])); };
    chain["deposit"]  = [&]() {   acc.deposit(INT(ui[1])); };
    chain["withdraw"] = [&]() {  acc.withdraw(INT(ui[1])); };
    chain["fee"]      = [&]() {       acc.fee(INT(ui[1])); };
    chain["reverse"]  = [&]() { ui | DROP(1) | MAP(INT) | FOREACH([&](int index) { acc.reverse(index); }); };
    chain["extract"]  = [&]() { acc.getManager().getExtract(INT(ui[1])) | JOIN("\n") | PRINT(); };

    execute(chain, ui);
}
