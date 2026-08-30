import java.util.Scanner;

// @DROP
class Person {
    private String name;
    private int money;

    public Person(String name, int money) {
        this.name = name;
        this.money = money;
    }

    public Person() {
        this("", 0);
    }

    @Override
    public String toString() {
        return this.name + ":" + this.money;
    }

    public String getName() {
        return this.name;
    }

    public void setMoney(int money) {
        this.money = money;
    }

    public int getMoney() {
        return this.money;
    }
}

class Uber {
    private Person driver = null;
    private Person passenger = null;
    private int runCost = 0;

    public void setDriver(Person driver) {
        if (this.driver != null) {
            System.out.println("fail: Driver is already set");
            return;
        }
        this.driver = driver;
    }

    public void setPassenger(Person passenger) {
        if (this.driver == null) {
            System.out.println("fail: Driver is not set");
            return;
        }
        this.passenger = passenger;
        this.runCost = 0;
    }

    public void drive(int distance) {
        if (this.driver == null) {
            System.out.println("fail: Driver is not set");
            return;
        }
        if (this.passenger != null) {
            this.runCost += distance;
        }
    }

    public Person leave() {
        if (this.driver == null) {
            System.out.println("fail: Driver is not set");
            return null;
        }
        if (this.passenger == null) {
            System.out.println("fail: Passenger is not set");
            return null;
        }

        if (this.passenger.getMoney() < this.runCost) {
            this.passenger.setMoney(0);
            System.out.println("fail: Passenger does not have enough money");
        } else {
            this.passenger.setMoney(this.passenger.getMoney() - this.runCost);
        }

        this.driver.setMoney(this.driver.getMoney() + this.runCost);
        this.runCost = 0;

        Person leavingPassenger = this.passenger;
        this.passenger = null;
        return leavingPassenger;
    }

    @Override
    public String toString() {
        String driverStr = (this.driver != null) ? this.driver.toString() : "None";
        String passengerStr = (this.passenger != null) ? this.passenger.toString() : "None";
        return "Cost: " + this.runCost + ", Driver: " + driverStr + ", Passenger: " + passengerStr;
    }
}

// @KEEP
public class Shell {

    public static void main(String[] args) {
        // @DROP
        Uber uber = new Uber();
        // @KEEP
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            // @COM
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(uber);
            }
            else if (cmd.equals("setDriver")) { 
                String name = par[1];
                int money = Integer.parseInt(par[2]);
                // @DROP
                Person driver = new Person(name, money);
                uber.setDriver(driver);
            }
            else if (cmd.equals("setPass")) { 
                String name = par[1];
                int money = Integer.parseInt(par[2]);
                // @DROP
                Person passenger = new Person(name, money);
                uber.setPassenger(passenger);
            }
            else if (cmd.equals("drive")) { 
                int distance = Integer.parseInt(par[1]);
                // @DROP
                uber.drive(distance);
            }
            else if (cmd.equals("leavePass")) { 
                // @DROP
                Person passenger = uber.leave();
                if (passenger != null) {
                    System.out.println(passenger + " left");
                }
            }
            // @KEEP
            else {
                System.out.println("fail: command not found");
            }
        }
    }
    static Scanner scanner = new Scanner(System.in);
}
