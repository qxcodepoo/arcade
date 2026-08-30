#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// @DROP
#include <algorithm>
class Player {
private:
    int label;     // índice do player   
    int pos;       // posição dele no tabuleiro
    bool free;

public:
    Player(int label) {
        this->label = label;
        this->free = true;
        this->pos = 0;
    }

    int getLabel() {
        return this->label;
    }

    int getPos() {
        return this->pos;
    }

    void setPos(int pos) {
        this->pos = pos;
    }

    void setFree(bool free) {
        this->free = free;
    }

    bool isFree() {
        return this->free;
    }

    std::string str() {
        std::string status = (this->free ? "free" : "not free");
        stringstream ss;
        ss << "Player " << this->label << " at " << this->pos << " is " << status;
        return ss.str();
    }
};


class Board {
private:
    std::vector<int> trapList; // posição das armadilhas
    bool running;   // se o jogo acabou
    int size;   // tamanho do tabuleiro
    std::vector<Player> players; // lista de jogadores

public:
    Board(int nPlayers = 0, int size = 0) {
        this->size = size + 1;
        this->trapList = {};
        this->running = true;
        for (int i = 1; i <= nPlayers; i++) {
            this->players.push_back(Player(i));
        }
    }

    void addTrap(int pos) {
        this->trapList.push_back(pos);
    }

    void rollDice(int value) {
        if (!this->running) {
            cout << "game is over" << endl;
            return;
        }

        int finish = this->size - 1;
        Player player = this->players.front();
        this->players.erase(this->players.begin());

        if (!player.isFree()) {
            if (value % 2 == 0) {
                player.setFree(true);
                cout << "player" << player.getLabel() << " se libertou" << endl;
            } else {
                cout << "player" << player.getLabel() << " continua preso" << endl;
            }
        } else if (player.getPos() + value >= finish) {
            cout << "player" << player.getLabel() << " ganhou" << endl;
            player.setPos(finish);
            this->running = false;
        } else {
            player.setPos(player.getPos() + value);
            cout << "player" << player.getLabel() << " andou para " << player.getPos() << endl;
            if (std::find(this->trapList.begin(), this->trapList.end(), player.getPos()) != this->trapList.end()) {
                player.setFree(false);
                cout << "player" << player.getLabel() << " caiu em uma armadilha" << endl;
            }
        }
        this->players.push_back(player);
    }

    std::string str() {
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
// @KEEP
int main() {
    // @DROP
    Board board;
    // @KEEP

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            // @COM
            int nPlayers, size;
            ss >> nPlayers >> size;
            board = Board(nPlayers, size);
        } else if (cmd == "addTrap") {
            // @COM
            int pos;
            ss >> pos;
            board.addTrap(pos);
        } else if (cmd == "roll") {
            // @COM
            int value;
            ss >> value;
            // @DROP
            board.rollDice(value);
        } else if (cmd == "show") {
            // @DROP
            cout << board.str() << endl;
        } else {
            cout << "fail: command not found" << endl;
        }

    }
}
