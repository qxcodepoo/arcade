#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <sstream>
#include "auxiliar.hpp"

using namespace std;

class Chat;
class Service;

class User {
    string username;
    map<int, Chat*> chats;
    void addChat(Chat* chat);
public:
    User(string username) { this->username = username; }
    const map<int, Chat*>& getChats() { return chats; }
    string getUsername() { return username; }
    friend class Service;
    friend ostream& operator<<(ostream& os, const User& user);
};

class Chat {
    int chatId;
    string chatName;
    map<string, User*> users;
    void addUser(User* user) { users[user->getUsername()] = user; }
public:
    Chat(int chatId, string chatName) : chatId(chatId), chatName(chatName) {}
    const map<string, User*>& getUsers() { return users; }
    int getChatId() { return chatId; }
    string getChatName() { return chatName; }
    friend ostream& operator<<(ostream& os, const Chat& chat) {
        return (os << chat.chatId << ":" << chat.chatName << " " + aux::strlist(chat.users, xfn(x.first)));
    }
    friend class Service;
};

void User::addChat(Chat* chat) { chats[chat->getChatId()] = chat; }
ostream& operator<<(ostream& os, const User& user) {
    os << user.username << " [";
    os << aux::join(user.chats, ", ", xfn(to_string(x.second->getChatId()) + ":" + x.second->getChatName()));
    os << "]";
    return os;
}

class Service {
    map<string, shared_ptr<User>> users;
    map<int, shared_ptr<Chat>> chats;
    int nextChatId {0};
public:
    Service() = default;

    void addUser(string username) { aux::map_insert(users, username, make_shared<User>(username)); }
    
    void createChat(string username, string chatName) {
        auto user = aux::map_at(users, username);
        auto chat = make_shared<Chat>(nextChatId++, chatName);
        user->addChat(chat.get());
        chat->addUser(user.get());
        chats[chat->getChatId()] = chat;
    }

    void invitetoc-tableat(string owner, string invitee, int chatId) {
        auto ownerUser = aux::map_at(users, owner);
        auto inviteeUser = aux::map_at(users, invitee);
        auto chat = aux::map_at(ownerUser->getChats(), chatId);
        chat->addUser(inviteeUser.get());
        inviteeUser->addChat(chat);
    }

    void leaveChat(string username, int chatId) {
        auto user = aux::map_at(users, username);
        auto chat = aux::map_at(user->getChats(), chatId);
        chat->users.erase(username);
        user->chats.erase(chatId);
    }

    std::string showChats() {
        stringstream ss;
        ss << aux::join(this->chats, "\n", xfn(*x.second)) << "\n";
        return ss.str();
    }
    
    std::string showUsers() {
        stringstream ss;
        ss << aux::join(this->users, "\n", xfn(*x.second)) << "\n";
        return ss.str();
    }

    const map<string, shared_ptr<User>>& getUsers() { return users; }
    const map<int, shared_ptr<Chat>>& getChats() { return chats; }
};

int main(){
    Service service;
    while(true) {
        auto cmd = aux::getcmd();
        auto action = cmd.front();
        try {
            if (action == "end") {
                break;
            } else if (action == "add") {
                service.addUser(cmd[1]);
            } else if (action == "create") {
                service.createChat(cmd[1], cmd[2]);
            } else if (action == "users") {
                cout << service.showUsers();
            } else if (action == "invite") {
                service.invitetoc-tableat(cmd[1], cmd[2], stoi(cmd[3]));
            } else if (action == "leave") {
                service.leaveChat(cmd[1], stoi(cmd[2]));
            } else if (action == "chats") {
                cout << service.showChats();
            } else {
                cout << "fail: comando invalido" << '\n';
            }
        } catch (runtime_error &e) {
            cout << e.what() << '\n';
        }
    }
    return 0;
}
