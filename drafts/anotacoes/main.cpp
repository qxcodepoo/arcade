#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Nota{
    string titulo;
    string texto;
public:
    Nota(string titulo = " ", string texto = " "){
        this->titulo = titulo;
        this->texto = texto;
    }

    string getTitulo(){
        return titulo;
    }
    string getTexto(){
        return texto;
    }

    void setTitulo(string titulo){
        this->titulo = titulo;
    }

    void setTexto(string texto){
        this->texto = texto;
    }

};

class Usuario{
    string username;
    string password;
    vector<Nota> notas;
public:

    Usuario (string username = "", string password = ""){
        this->username = username;
        this->password = password;
    }

    string getUsername(){
        return username;
    }

    bool updatePass(string  oldpass, string newpass){
        if(this->password == oldpass){
            this->password = newpass;
            return true;
        }
        return false;
    }

    bool addNota(Nota nota){
        for(auto elemento : notas){
            if(elemento.getTitulo() == nota.getTitulo())
                return false;
        }
        notas.push_back(nota);
        return true;
    }

    bool rmNota(string titulo){
        for(int i = 0; i < (int) this->notas.size(); i++){
            if(notas[i].getTitulo() == titulo){
                notas.erase(notas.begin() + i);
                return true;
            }

        }
        return false;
    }

    bool checkPassword(string password){
        return this->password == password;
    }

    string toString(){
        stringstream ss;
        ss << username << endl;
        for(auto nota : notas)
            ss << "[" << nota.getTitulo() << "; " << nota.getTexto() << "]" << endl;
        return ss.str();
    }
};

class Sistema{
    vector<Usuario> usuarios;
public:
    Sistema(){
    }

    //não pode ter dois usernames iguais
    bool addUser(string username, string password){
        for(auto usuario : usuarios)
            if(usuario.getUsername() == username)
                return false;
        usuarios.push_back(Usuario(username, password));
        return true;
    }

    Usuario * getUser(string username, string password){
        for(auto& usuario : usuarios)
            if((usuario.getUsername() == username) && (usuario.checkPassword(password)))
                return &usuario;
        return nullptr;
    }
    vector<string> getUsernames(){
        vector<string> names;
        for(auto& user : usuarios)
            names.push_back(user.getUsername());
        return names;
    }
};

void commandLine(Sistema& sistema){
    string op = "";

    Usuario * usuario = nullptr;
    while(op != "fim"){
        cout << "Digite help ou comando: ";
        cin >> op;
        if(op == "help"){
            cout << "addUser $username $password" << endl
                 << "updatePass $oldpass $newpass" << endl
                 << "addNote $titulo $textao" << endl
                 << "rmNote $titulo" << endl
                 << "users" << endl
                 << "login $username $password" << endl
                 << "logout" << endl
                 << "show" << endl;
        }
        if(op == "users"){
            cout << "Usuarios: [ ";
            for(auto st : sistema.getUsernames())
                cout << st << " ";
            cout << "]"  << endl;
        }
        if(op == "addUser"){
            string name, pass;
            cin >> name >> pass;
            if(sistema.addUser(name, pass))
                cout << "sucesso" << endl;
            else
                cout << "username duplicado" << endl;
        }

        if(op == "login"){
            string name, pass;
            cin >> name >> pass;
            usuario = sistema.getUser(name, pass);
            if(usuario == nullptr)
                cout << "erro de login" << endl;
            else
                cout << "sucesso" << endl;
        }
        if(op == "show"){
            if(usuario == nullptr)
                cout << "ninguem logado" << endl;
            else
                cout << usuario->toString() << endl;
        }
        if(op == "rmNote"){
            string titulo;
            cin >> titulo;
            if(usuario == nullptr)
                cout << "ninguem logado" << endl;
            else
                cout << (usuario->rmNota(titulo)? "ok":"falhou") << endl;
        }

        if(op == "logout"){
            if(usuario != nullptr){
                usuario = nullptr;
                cout << "logout efetuado" << endl;
            }else{
                cout << "ninguem logado" << endl;
            }

        }
        if(op == "updatePass"){
            string old, newp;
            cin >> old >> newp;
            if(usuario == nullptr)
                cout << "ninguem logado" << endl;
            else
                cout << (usuario->updatePass(old, newp)? "ok" : "senha invalida") << endl;
        }
        if(op == "addNote"){
            string titulo, texto;
            cin >> titulo;
            getline(cin, texto);
            if(usuario)
                cout << (usuario->addNota(Nota(titulo, texto)) ? "nota adicionada" : "titulo duplicado") << endl;
            else
                cout << "usuario nao logado" << endl;

        }
    }
}


void initialize(Sistema &sistema){
    sistema.addUser("januario", "respeita");
    sistema.addUser("luiz", "luiz");
    Usuario * januario = sistema.getUser("januario", "respeita");
    januario->addNota(Nota("comprar", "baladeira de couro"));
    januario->addNota(Nota("vender", "baladeira pra ontem"));
    januario->addNota(Nota("chorar", "lagartixa que perdeu o rabo"));
    Usuario * luiz = sistema.getUser("luiz", "luiz");
    luiz->addNota(Nota("comprar", "estilingue"));
    luiz->addNota(Nota("vender", "estilingue com bolinhas"));
    luiz->addNota(Nota("rir", "i am bad!"));
}

int main()
{
    Sistema sistema;
    initialize(sistema);
    commandLine(sistema);
    return 0;
}
























