#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include <cmath>


class Point2D {
public:
    double x;
    double y;

    Point2D(double x, double y) ;

    std::string str() const;

};

std::ostream& operator<<(std::ostream& os, const Point2D& p) { return os << p.str(); }


class Shape {
    std::string name;
public:
    Shape(std::string name = "") ;

    virtual ~Shape(){}

    virtual double getArea() const = 0;

    virtual double getPerimeter() const = 0;

    virtual std::string getName() const = 0;

    virtual std::string str() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Shape& p) { return os << p.str(); }

class Circle : public Shape {
    std::string name;
    Point2D center;
    double radius;
public:
    Circle(Point2D center, double radius) ;

    std::string getName() const override;

    double getArea() const override;

    double getPerimeter() const override;

    std::string str() const override;
};

class Rectangle : public Shape {
    std::string name;
    Point2D p1;
    Point2D p2;

public:
    Rectangle(Point2D p1, Point2D p2)

    std::string getName() const override;

    double getArea() const override;

    double getPerimeter() const override;

    Point2D getP1() const;

    Point2D getP2() const;

    std::string str() const override;
};


int main() {
    std::vector<std::shared_ptr<Shape>> shapes;

    while (true) {
        auto line = fn::input();
        auto args =  fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end")  { 
            break;                                  
        }
        else if (args[0] == "show") { 
            for (auto shape : shapes) {
                fn::write(shape->str());
            }
        }
        else if (args[0] == "circle") { 
            auto x = +args[1];
            auto y = +args[2]; 
            auto r = +args[3];
            shapes.push_back(std::make_shared<Circle>(Point2D{x, y}, r));
        }
        else if (args[0] == "rect") { 
            auto p1 = Point2D{+args[1], +args[2]};
            auto p2 = Point2D{+args[3], +args[4]};
            shapes.push_back(std::make_shared<Rectangle>(p1, p2));
        }
        else if (args[0] == "info") {
            for (auto shape : shapes) {
                fn::print("{}: A={%.2f} P={%.2f}\n", 
                shape->getName(), shape->getArea(), shape->getPerimeter());
            }
        }
        else {
            fn::write("fail: invalid command");
        }
    }
}
