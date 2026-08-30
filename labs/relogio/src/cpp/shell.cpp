#include <iostream>
#include <sstream>
#include <iomanip> // std::setfill, std::setw
using namespace std;

// @DROP
class Time {
private:
    int hour {0}, minute {0}, second {0};
public:
    Time(int hour = 0, int minute = 0, int second = 0) {
        this->setHour(hour);
        this->setMinute(minute);
        this->setSecond(second);
    }

    void setHour(int hour) {
        if (hour < 0 || hour > 23) {
            cout << "fail: hora invalida" << endl;
            return;
        }
        this->hour = hour;
    }

    void setMinute(int minute) {
        if (minute < 0 || minute > 59) {
            cout << "fail: minuto invalido" << endl;
            return;
        } 
        this->minute = minute;
    }

    void setSecond(int second) {
        if (second < 0 || second > 59) {
            cout << "fail: segundo invalido" << endl;
            return;
        }
        this->second = second;
    }

    int getHour() const {
        return hour;
    }

    int getMinute() const {
        return minute;
    }

    int getSecond() const {
        return second;
    }
    
    void nextSecond() {
        second++;
        if (second > 59) {
            second = 0;
            minute++;
            if (minute > 59) {
                minute = 0;
                hour++;
                if (hour > 23) {
                    hour = 0;
                }
            }
        }
    }

    std::string str() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << hour << ":";
        ss << setfill('0') << setw(2) << minute << ":";
        ss << setfill('0') << setw(2) << second;
        return ss.str();
    }
};

// @KEEP
int main() {
    // CRIE SEU RELÓGIO AQUI
    // @DROP
    Time time;
    // @KEEP

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "set") {
            
            // Chame os métodos setHour, setMinute e setSecond
            // @COM
            int hour {}, minute {}, second {};
            ss >> hour >> minute >> second;
            // @DROP
            time.setHour(hour);
            time.setMinute(minute);
            time.setSecond(second);
        } else if (cmd == "init") {
            
            // Chame o construtor para inicializar o relógio
            // @COM
            int hour {}, minute {}, second {};
            ss >> hour >> minute >> second;
            // @DROP
            time = Time(hour, minute, second);
        } else if (cmd == "show") {
            
            // Chame o método str e imprima o horário
            // @COM
            cout << time.str() << endl;
        } else if (cmd == "next") {
            
            // Chame o método nextSecond
            // @COM
            time.nextSecond();
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}