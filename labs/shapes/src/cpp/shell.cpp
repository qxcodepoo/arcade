#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
using namespace std;

template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "");
        ss << f(*it);
    }
    return ss.str();
}

// @DROP
class Point2D {
public:
    double x;
    double y;

    Point2D(double x, double y) :
        x(x), y(y) {
    }

    string str() const {
        char buffer[100];
        sprintf(buffer, "(%.2f, %.2f)", x, y);
        return buffer;
    }
};

class Shape {
    string name;
public:
    Shape(string name = "") :
        name(name){
    }

    virtual ~Shape(){}

    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual string getName() const = 0;

    virtual string info() const {
        stringstream ss;
        ss << getName() << ": A=" << fixed << setprecision(2) << getArea() << " P=" << getPerimeter();
        return ss.str();
    }

    virtual string str() const = 0;
};

class Circle : public Shape {
    string name;
    Point2D center;
    double radius;
public:
    Circle(Point2D center, double radius) :
        name("Circ"), center(center), radius(radius) {}

    string getName() const override {
        return name;
    }

    double getArea() const override {
        return M_PI * this->radius * this->radius;
    }

    double getPerimeter() const override {
        return M_PI * 2 * this->radius;
    }

    string str() const override {
        char buffer[500];
        sprintf(buffer, "%s: C=%s, R=%.2f", this->getName().c_str(), this->center.str().c_str(), this->radius);
        return buffer;
    }
};

class Rectangle : public Shape {
    string name;
    Point2D p1;
    Point2D p2;

public:
    Rectangle(Point2D p1, Point2D p2)
        :name("Rect"), p1(p1), p2(p2) {}

    string getName() const override {
        return name;
    }

    double getArea() const override {
        auto largura = fabs(this->p1.x - this->p2.x);
        auto altura  = fabs(this->p1.y - this->p2.y);
        return largura * altura;
    }

    double getPerimeter() const override {
        auto largura = fabs(this->p1.x - this->p2.x);
        auto altura  = fabs(this->p1.y - this->p2.y);
        return 2 * largura + 2 * altura;
    }

    Point2D getP1() const {
        return p1;
    }

    Point2D getP2() const {
        return p2;
    }

    string str() const override {
        char buffer[100];
        sprintf(buffer, "%s: P1=%s P2=%s", this->getName().c_str(), p1.str().c_str(), p2.str().c_str());
        return buffer;
    }
};

// @KEEP
int main() {
    // @COM
    vector<shared_ptr<Shape>> shapes;
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end")  { 
            break;                                  
        }
        else if (cmd == "show") { 
            // Imprima as formas, uma por linha
            // @DROP
            cout << map_join(shapes, [](auto x) { return x->str(); }, "\n") << endl;
        }
        else if (cmd == "circle") { 
            // Crie um novo circulo e adicione ao vetor
            // @COM
            double x{}, y{}, radius{};
            ss >> x >> y >> radius;
            // @DROP
            shapes.push_back(make_shared<Circle>(Point2D{x, y}, radius));
        }
        else if (cmd == "rect") {
            // Crie um retangulo e insira no vetor
            // @COM
            double x1{}, y1{}, x2{}, y2{};
            ss >> x1 >> y1 >> x2 >> y2;
            // @DROP
            auto p1 = Point2D{x1, y1};
            auto p2 = Point2D{x2, y2};
            shapes.push_back(make_shared<Rectangle>(p1, p2));
        }
        else if (cmd == "info") {
            // Imprima as informações de área e perímetro de todas as formas
            // @DROP
            cout << map_join(shapes, [](auto x) { return x->info(); }, "\n") << endl;
        }
        else {
            cout << "fail: comando inválido" << '\n';
        }
    }
}
