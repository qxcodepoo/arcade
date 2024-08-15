
class Adapter {
    Car car;

    public Adapter() {
        this.car = new Car();
    }
    
    public void enter() {
        car.enter();
    }

    public void leave() {
        car.leave();
    }

    public void fuel(int gas) {
        car.fuel(gas);
    }

    public void drive(int km) {
        car.drive(km);
    }

    public String toString() {
        return car.toString();
    }

    public static void main(String[] args) {
        System.out.println("Rodando adapter");
    }
}