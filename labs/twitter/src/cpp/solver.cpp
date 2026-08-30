#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <set>
#include <map>
using namespace std;

template <typename CONTAINER, typename FUNC>
string join(const CONTAINER& c, FUNC f, const string& delim) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it == c.begin() ? "" : delim) << f(*it);
    }
    return ss.str();
}

class TweetException : public exception {
    string message;
public:
    TweetException(const string& message) : 
        message(message) {
    }
    const char* what() const noexcept override {
        return message.c_str(); 
    }
};

class Tweet {
    int id;
    string username;
    string msg;
    set<string> likes;
    
    // ' guarda o tweet original que foi retweetado
    Tweet *rt {nullptr};

public:

    Tweet(int id, const string& username, const string& msg) : 
        id(id), username(username), msg(msg) {
    }

    int getId() const { 
        return id; 
    }

    string getSender() const {
        return username;
    }

    string getMsg() const {
        return msg;
    }

    string str() const {
        stringstream ss;
        ss << getId() << ":" << username + " (" << msg << ")";
        if (likes.size() > 0) {
            ss << " " << "[" << join(likes, [](auto s) {return s;}, ", ") << "]";
        }
        if (rt != nullptr) {
            ss << "\n    " << this->rt->str();
        }
        return ss.str();
    }

    // __like__

    void like(const string& username) { 
        likes.insert(username); 
    }

    set<string> getLikes() const {
        return likes;
    }
    
    // __retweet__

    void setRt(Tweet *rt) {
        this->rt = rt;
    }
    
    // __remover__

    bool deleted {false};
    
    void setDeleted() {
        this->deleted = true;
        this->msg = "esse tweet foi deletado";
        this->username = "";
        this->likes.clear();
    }

    bool isDeleted() const {
        return this->deleted;
    }
};

class Inbox {

    map<int, Tweet*> timeline;
    map<int, Tweet*> myTweets;
    
public:
    Inbox() {
    }

    void storeInTimeline(Tweet* tweet) {
        timeline[tweet->getId()] = tweet;
    }

    vector<Tweet*> getTimeline() const {
        vector<Tweet*> messages;
        for (auto it = timeline.rbegin(); it != timeline.rend(); ++it) {
            if (it->second->isDeleted() == false)
                messages.push_back(it->second);
        }
        return messages;
    }

    string str() const {
        stringstream ss;
        auto fn = [](Tweet* tweet) {return tweet->str();};
        return join(this->getTimeline(), fn, "\n");
    }

    // __like__
    Tweet* getTweet(int id) {
        if(auto it = timeline.find(id); it != timeline.end())
            return timeline[id];
        throw TweetException("fail: tweet nao existe");
    }

    // __unfollow__

    void rmMsgsFrom(const string& username) {
        auto keysToRemove = vector<int>();
        for (auto& [key, tweet] : timeline)
            if (tweet->getSender() == username)
                keysToRemove.push_back(key);
        for (auto key : keysToRemove)
            timeline.erase(key);
    }

    // __remover__

    void storeInMyTweets(Tweet* tweet) {
        myTweets[tweet->getId()] = tweet;
    }

    vector<Tweet*> getMyTweets() const {
        vector<Tweet*> messages;
        for (auto it = myTweets.rbegin(); it != myTweets.rend(); ++it)
            messages.push_back(it->second);
        return messages;
    }
};

class User {

    string username;
    Inbox inbox;
    map<string, User*> followers;
    map<string, User*> following;

    // __
public:

    User(const string& username) : 
        username(username) {
    }

    // ' mostra o nome dos seguidos e o nome dos seguires
    // + toString(): str
    string str () const {
        stringstream ss;
        auto keys = [](auto p) {return p.first;};

        ss << username << "\n" 
            << "  seguidos   [" << join(following, keys, ", ") << "]\n"
            << "  seguidores [" << join(followers, keys, ", ") << "]";
        return ss.str();
    }

    // __follow__
    void follow(User * other) {
        if(other == this)
            throw TweetException("You cannot follow yourself");
        if(following.count(other->username) == 1)
            throw TweetException("You are already following this user");
        following[other->username] = other;
        other->followers[username] = this;
    }

    // __twittar__

    Inbox& getInbox() {
        return inbox;
    }

    void sendTweet(Tweet * msg) {
        inbox.storeInTimeline(msg);
        inbox.storeInMyTweets(msg);
        for(auto& follower : followers)
            follower.second->getInbox().storeInTimeline(msg);
    }

    // __unfollow__

    void unfollow(string username) {
        if(following.count(username) == 0)
            throw TweetException("You are not following this user");
        auto other = following[username];
        
        this->inbox.rmMsgsFrom(username);
        following.erase(username);

        other->followers.erase(this->username);
    }

    // __like__

    void like(int twId) {
        inbox.getTweet(twId)->like(username);
    }

    // __remover__
    void unfollowAll() {
        for(auto& [username, user] : following) {
            user->followers.erase(this->username);
        }
        following.clear();
    }

    void rejectAll() {
        for(auto& [username, user] : followers) {
            user->following.erase(this->username);
        }
        followers.clear();
    }
};


// class Controller {
class Controller {
    // ' armazena o id para o proximo tweet a ser criado
    // - nextTweetId: int
    int nextTweetId { 0 };

    // ' armazena todos os usuarios do sistema
    // - users: map<str, User>
    map<string, shared_ptr<User>> users;

    // ' armazena todos os tweets do sistema
    // - tweets: map<int, Tweet>
    map<int, shared_ptr<Tweet>> tweets;

    // __
public:

    Controller() {}

    void addUser(string username) {
        if(users.find(username) != users.end())
            throw TweetException("fail: usuario ja existe");
        users[username] = make_shared<User>(username);
    }
    // __twittar__

private:
    Tweet* createTweet(string username, string msg) {
        auto msgObj = make_shared<Tweet>(nextTweetId++, username, msg);
        tweets[msgObj->getId()] = msgObj;
        return msgObj.get();
    }
public:

    User* getUser(string username) {
        if(users.find(username) == users.end())
            throw TweetException("fail: usuario nao encontrado");
        return users[username].get();
    }

    void sendTweet(string username, string msg) {
        auto sender = getUser(username);
        auto tw = createTweet(username, msg);
        sender->sendTweet(tw);
    }

    // __retweet__

    void sendRt(string username, int twId, string msg) {
        auto* sender = getUser(username);
        auto* rt = sender->getInbox().getTweet(twId);
        auto* tw = createTweet(username, msg);
        tw->setRt(rt);
        sender->sendTweet(tw);
    }

    // __remover__

    void rmUser(string username) {
        if(auto it = users.find(username); it != users.end()) {
            auto [username, user] = *it;
            user->unfollowAll();
            user->rejectAll();
            for(auto* tweet : user->getInbox().getMyTweets())
                tweet->setDeleted();
            users.erase(it);
        }
    }

    string str() {
        stringstream ss;
        auto fn = [](auto p) {return p.second->str();};
        return join(users, fn, "\n");
    }
};

int main() {
    Controller sistema;

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';
        stringstream ss(line);
        ss >> cmd;

        try
        {
            if (cmd == "end")
            {
                break;
            }
            else if (cmd == "add")
            {
                string username;
                ss >> username;
                sistema.addUser(username);
            }
            else if (cmd == "rm")
            {
                string username;
                ss >> username;
                sistema.rmUser(username);
            }
            else if (cmd == "show")
            {
                cout << sistema.str() << '\n';
            }
            else if (cmd == "follow")
            {
                string username, other;
                ss >> username >> other;
                sistema.getUser(username)->follow(sistema.getUser(other));
            }
            else if (cmd == "unfollow")
            {
                string username, other;
                ss >> username >> other;
                sistema.getUser(username)->unfollow(other);
            }
            else if (cmd == "twittar")
            {
                string username, msg;
                ss >> username;
                getline(ss, msg);
                msg = msg.substr(1);
                sistema.sendTweet(username, msg);
            }
            else if (cmd == "like")
            {
                string username;
                int id;
                ss >> username >> id;
                sistema.getUser(username)->like(id);
            }
            else if (cmd == "timeline")
            {
                string username;
                ss >> username;
                auto msgs = sistema.getUser(username)->getInbox().getTimeline();
                cout << join(msgs, [](auto msg) {return msg->str();}, "\n") << '\n';
            }
            else if (cmd == "rt")
            {
                string username;
                int id;
                string msg;
                ss >> username >> id;
                getline(ss, msg);
                msg = msg.substr(1);
                sistema.sendRt(username, id, msg);
            }
            else
            {
                cout << "fail: comando invalido\n";
            }
        }
        catch (TweetException &e)
        {
            cout << e.what() << '\n';
        }
    }
    return 0;
}
