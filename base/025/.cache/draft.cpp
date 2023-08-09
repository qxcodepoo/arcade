#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include <algorithm>




class TweetException : public std::exception {
    std::string message;
public:
    TweetException(const std::string& message) : 
        message(message) {
    }
    const char* what() const noexcept override {
        return message.c_str(); 
    }
};

class Tweet {
    int id;
    std::string username;
    std::string msg;
    std::set<std::string> likes;
    
    // ' guarda o tweet original que foi retweetado
    Tweet *rt {nullptr};

public:

    Tweet(int id, const std::string& username, const std::string& msg) : 

    int getId() const { 

    std::string getSender() const { return {}; }

    std::string getMsg() const { return {}; }

    std::string str() const { return {}; }

    // __like__

    void like(const std::string& username) { 

    std::set<std::string> getLikes() const { return {}; }
    
    // __retweet__

    void setRt(Tweet *rt) { return {}; }
    
    // __remover__

    bool deleted {false};
    
    void setDeleted() { return {}; }

    bool isDeleted() const { return {}; }
};

std::ostream& operator<<(std::ostream& os, const Tweet& msg) {
    return os << msg.str();
}

std::ostream& operator<<(std::ostream& os, Tweet* msg) {
    return os << msg->str();
}
//++

class Inbox {

    std::map<int, Tweet*> timeline;

    std::map<int, Tweet*> myTweets;
    
public:
    Inbox() {
    }

    void storeInTimeline(Tweet* tweet) {
        timeline[tweet->getId()] = tweet;
    }

    std::vector<Tweet*> getTimeline() const {
        std::vector<Tweet*> messages;
        for (auto it = timeline.rbegin(); it != timeline.rend(); ++it) {
            if (it->second->isDeleted() == false)
                messages.push_back(it->second);
        }
        return messages;
    }

    friend std::ostream& operator<<(std::ostream& os, const Inbox& inbox) {
        return os << fn::join(inbox.getTimeline(), "\n");
    }

    // __like__
    Tweet* getTweet(int id) {
        if(auto it = timeline.find(id); it != timeline.end())
            return timeline[id];
        throw TweetException("fail: tweet nao existe");
    }

    // __unfollow__

    void rmMsgsFrom(const std::string& username) {
        auto keysToRemove = std::vector<int>();
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

    std::vector<Tweet*> getMyTweets() const {
        std::vector<Tweet*> messages;
        for (auto it = myTweets.rbegin(); it != myTweets.rend(); ++it)
            messages.push_back(it->second);
        return messages;
    }
};

class User {

    std::string username;
    Inbox inbox;
    std::map<std::string, User*> followers;
    std::map<std::string, User*> following;

    // __
public:

    User(const std::string& username) : 
        username(username) {
    }

    // ' mostra o nome dos seguidos e o nome dos seguires
    // + toString(): str
    std::string str() {
        std::stringstream ss;
        auto keys = [](auto p) {return p.first;};
        ss << username << "\n" 
            << "  seguidos   [" << fn::join(fn::map(following, keys)) << "]\n"
            << "  seguidores [" << fn::join(fn::map(followers, keys)) << "]";
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

    void unfollow(std::string username) {
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


std::ostream& operator<<(std::ostream& os, const User& user) { return os << user.str(); }


// class Controller {
class Controller {
    // ' armazena o id para o proximo tweet a ser criado
    // - nextTweetId: int
    int nextTweetId { 0 };

    // ' armazena todos os usuarios do sistema
    // - users: map<str, User>
    std::map<std::string, std::shared_ptr<User>> users;

    // ' armazena todos os tweets do sistema
    // - tweets: map<int, Tweet>
    std::map<int, std::shared_ptr<Tweet>> tweets;

    // __
public:

    Controller() {}

    void addUser(std::string username) { return {}; }

    friend std::ostream& operator<<(std::ostream& os, const Controller& ctrl);

    // __twittar__

private:
    Tweet* createTweet(std::string username, std::string msg) { return {}; }
public:

    User* getUser(std::string username) { return {}; }

    void sendTweet(std::string username, std::string msg) { return {}; }

    // __retweet__

    void sendRt(std::string username, int twId, std::string msg) { return {}; }

    // __remover__

    void rmUser(std::string username) { return {}; }
};


std::ostream& operator<<(std::ostream& os, const Controller& ctrl) {
    return os << aux::join(aux::map(ctrl.users, [](auto p) {return *p.second;}), "\n");
}


using namespace aux;

int main() {
    Controller sistema;

    while(true) {
        auto line = input();
        write("$" + line);
        auto args = split(line, ' ');
        
        try {
            if      (args[0] == "end"     ) { break;                                                                     } 
            else if (args[0] == "add"     ) { sistema.addUser(args[1]);                                                  } 
            else if (args[0] == "rm"      ) { sistema.rmUser(args[1]);                                                   }
            else if (args[0] == "show"    ) { write(sistema);                                                            }
            else if (args[0] == "follow"  ) { sistema.getUser(args[1])->follow(sistema.getUser(args[2]));                }
            else if (args[0] == "unfollow") { sistema.getUser(args[1])->unfollow(args[2]);                               }
            else if (args[0] == "twittar" ) { sistema.sendTweet(args[1], join(slice(args, 2), " "));                     }
            else if (args[0] == "like"    ) { sistema.getUser(args[1])->like((int) +(args[2]));                     }
            else if (args[0] == "timeline") { write(join(sistema.getUser(args[1])->getInbox().getTimeline(), "\n"));     } 
            else if (args[0] == "rt"      ) { sistema.sendRt(args[1], (int) +(args[2]), join(slice(args, 3), " ")); } 
            else                            { write("fail: comando invalido");                                           }
        } catch (TweetException &e) {
            std::cout << e.what() << '\n';
        }
    }
    return 0;
}

