#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

int main() {
    Pig pig(0);
    while (true) {
        try {
            auto line = fn::input();
            auto args = fn::split(line, ' ');
            fn::write("$" + line);

            if      (args[0] == "end" ) { break; } 
            else if (args[0] == "init") { pig = Pig(+args[1]); }
            else if (args[0] == "addCoin") {
                switch((int) +args[1]) {
                    case  10: pig.addValuable(std::make_shared<Coin>(Coin::C10 )); break;
                    case  25: pig.addValuable(std::make_shared<Coin>(Coin::C25 )); break;
                    case  50: pig.addValuable(std::make_shared<Coin>(Coin::C50 )); break;
                    case 100: pig.addValuable(std::make_shared<Coin>(Coin::C100)); break;
                }
            }
            else if (args[0] == "addItem") {
                pig.addValuable(std::make_shared<Item>(args[1], +args[2], (int) +args[3]));
            }
            else if (args[0] == "break"       ) { pig.breakPig();                               }
            else if (args[0] == "extractCoins") { fn::write(pig.extractCoins());                }
            else if (args[0] == "extractItems") { fn::write(pig.extractItems());                }
            else if (args[0] == "show"        ) { fn::write(pig);                               }
            else                                { fn::write("fail: invalid command");           }
        } catch (std::string s) {
            fn::write(s);
        }
    }

}