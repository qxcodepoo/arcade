#include <iostream>
#include <memory> //shared_ptr
#include <sstream> //stringstream
#include <utility> //exchange
using namespace std;
// @DROP

class Person {
    string name; //atributo
    int age;
public:
    Person(string name = "", int age = 0) {
        this->name = name;
        this->age = age;
    }

    Person(int age) : Person("", age) {
    }

    int getAge() const {
        return age;
    }
    string getName() const {
        return name;
    }
    string str() const {
        return (stringstream() << name << ":" << age).str();
    }
};

class Motorcycle {
    shared_ptr<Person> person {nullptr}; //agregação
    int time {0};
    int power {1};

public:
    Motorcycle(int power = 1): power {power} {
    }

    void insertPerson(shared_ptr<Person> p) {
        if (this->person != nullptr) {
            cout << "fail: busy motorcycle\n";
            return;
        }
        this->person = p;
    }

    shared_ptr<Person> remove() {
        if (this->person == nullptr) {
            cout << "fail: empty motorcycle\n";
            return nullptr;
        }
        return exchange(this->person, nullptr);
    }

    string honk() const {
        return "P" + string(this->power, 'e') + "m";
    }

    void buyTime(int time) {
        this->time += time;
    }

    void drive(int time) {
        if (this->time == 0) {
            cout << "fail: buy time first\n";
            return;
        }
        if (this->person == nullptr) {
            cout << "fail: empty motorcycle\n";
            return;
        }
        if (this->person->getAge() > 10) {
            cout << "fail: too old to drive\n";
            return;
        }
        if (time > this->time) {
            cout << "fail: time finished after " << this->time << " minutes\n";
            this->time = 0;
            return;
        }
        this->time -= time;
    }

    string str() const {
        auto value = person == nullptr ? "empty" : person->str();
        stringstream ss;
        ss << "power:" << power << ", time:" << time << ", person:(" << value << ")";
        return ss.str();
    }
};

// @KEEP

int main() {
    // CRIE SUA MOTO AQUI COM POTENCIA 1
    // @DROP
    Motorcycle moto(1);
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } 
        // @COM
        else if (cmd == "init") {
            // INICIE A MOTO AQUI USANDO O CONSTRUTOR
            int power {};
            ss >> power;
            // @DROP
            moto = Motorcycle(power);
        } 
        else if (cmd == "show") {
            // MOSTRE A MOTO AQUI
            // @DROP
            cout << moto.str() << endl;
        }
        else if (cmd == "leave") {
            // RETIRE A PESSOA DA MOTO
            // SE EXISTIR, MOSTRE A PESSOA
            // @DROP
            auto person = moto.remove();
            if (person != nullptr) {
                cout << person->str() << endl;
            }
        }
        else if (cmd == "honk") {
            // BUZINE A MOTO
            // @DROP
            cout << moto.honk() << endl;
        }
        else if (cmd == "enter") {
            // CRIE UM PONTEIRO PARA PESSOA E INICIE-O AQUI
            // DEPOIS INSIRA A PERSON NA MOTO
            string name {};
            int age {};
            ss >> name >> age;
            // @DROP
            moto.insertPerson(make_shared<Person>(name, age));
        }
        else if (cmd == "buy") {
            // COMPRE TEMPO PARA DIRIGIR
            int time {};
            ss >> time;
            // @DROP
            moto.buyTime(time);
        }
        else if (cmd == "drive") {
            // DIRIJA A MOTO POR UM TEMPO
            int time {};
            ss >> time;
            // @DROP
            moto.drive(time);
        }
        // @KEEP
        else {
            cout << "fail: invalid command\n";
        }
    }
}
