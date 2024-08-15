#include "car.hpp"

struct Adapter {
  Car car;
  Adapter() {}

  void enter() { car.enter(); }
  void leave() { car.leave(); }
  void fuel(int q) {
    car.fuel(q);
  }
  void drive(int q) {
    car.drive(q);
  }
  std::string str() {
    return car.str();
  }
};
