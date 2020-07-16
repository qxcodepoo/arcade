#include <iostream>
#include <list>
#include <sstream>
using namespace std;



class Kid{
private:
    int age;
    string name;
public:
    Kid(int age, string name){
        this->age = age;
        this->name = name;
    }
    int getAge(){
        return age;
    }
    string getName(){
        return name;
    }
    string toString(){
        return name + ":" + to_string(age);
    }
};

class Trampoline{
    list<Kid*> waiting;
    list<Kid*> playing;
    
    Kid * remove_kid(string name, list<Kid*>& _list){
        for(list<Kid*>::iterator it = _list.begin(); it != _list.end(); it++){
            if((*it)->getName() == name){
                auto kid = *it;
                _list.erase(it);
                return kid;
            }
        }
        return nullptr;
    }

public:
    Trampoline(){
    }
    ~Trampoline(){
    }
    
    void arrive(Kid * kid){
        waiting.push_front(kid);
    }

    void in(){
        playing.push_front(waiting.back());
        waiting.pop_back();
    }

    void out(){
        waiting.push_front(playing.back());
        playing.pop_back();
    }

    Kid * remove(string name){
        Kid * kid = remove_kid(name, waiting);
        if(kid)
            return kid;
        kid = remove_kid(name, playing);
        if(kid)
            return kid;
        return nullptr;
    }

    string toString(){
        string saida = "=> ";
        for(Kid * kid : waiting)
            saida += kid->toString() + " ";
        saida += "=> ";
        for(Kid * kid : playing)
            saida += kid->toString() + " ";
        return saida;
    }
};

int main(){
    string line;
    Trampoline tramp;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

    }
}