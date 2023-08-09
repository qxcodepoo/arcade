
#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include <algorithm>

class Player {
private:
    int label;     // índice do player   
    int pos;       // posição dele no tabuleiro
    bool free;

public:
    Player(int label) { return {}; }

    int getLabel() { return {}; }

    int getPos() { return {}; }

    void setPos(int pos) { return {}; }

    void setFree(bool free) { return {}; }

    bool isFree() { return {}; }
    std::string toString() {
        std::string status = (this->free ? "free" : "not free");
        return fn::format("Player {} at {} is {}", label, pos, status); 
    }
};

class Board {
private:
    std::vector<int> trapList; // posição das armadilhas
    bool running;   // se o jogo acabou
    int size;   // tamanho do tabuleiro
    std::vector<Player> players; // lista de jogadores

public:
    Board(int nPlayers, int size) { return {}; }

    void addTrap(int pos) { return {}; }

    void rollDice(int value) { return {}; }


    std::string toString() {
        std::stringstream ss;
        for (auto p : this->players) {
            auto line = std::string(this->size, '.');
            line[p.getPos()] = p.getLabel() + '0';
            ss << "player" << p.getLabel() << ": " << line << std::endl;
        }
        auto traps = std::string(this->size, '.');
        for (auto t : this->trapList)
            traps[t] = 'x';
        ss << "traps__: " << traps;
        return ss.str();
    }
};

int main() {
    Board board(0, 0);

    while(true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line);

        if      (args[0] == "end"    ) { break;                                 }
        else if (args[0] == "init"   ) { board = Board(+args[1], +args[2]);     }
        else if (args[0] == "addTrap") { board.addTrap(+args[1]);               }
        else if (args[0] == "roll"   ) { board.rollDice(+args[1]);              }
        else if (args[0] == "show"   ) { fn::write(board.toString());           }
        else                           { fn::write("fail: command not found");  }

    }
}
