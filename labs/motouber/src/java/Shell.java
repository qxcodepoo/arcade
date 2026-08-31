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

class LeaveResult {
    private Person passenger;
    private String error;

    public LeaveResult(Person passenger, String error) {
        this.passenger = passenger;
        this.error = error;
    }

    public Person getPassenger() {
        return passenger;
    }

    public String getError() {
        return error;
    }
}

class Uber {
    private Person driver = null;
    private Person passenger = null;
    private int runCost = 0;

    public String setDriver(Person driver) {
        if (this.driver != null) {
            return "fail: Driver is already set";
        }
        this.driver = driver;
        return null;
    }

    public String setPassenger(Person passenger) {
        if (this.driver == null) {
            return "fail: Driver is not set";
        }
        if (this.passenger != null) {
            return "fail: Passenger is already set";
        }
        this.passenger = passenger;
        this.runCost = 0;
        return null;
    }

    public String drive(int distance) {
        if (this.driver == null) {
            return "fail: Driver is not set";
        }
        if (this.passenger != null) {
            this.runCost += distance;
        }
        return null;
    }

    public LeaveResult leave() {
        if (this.driver == null) {
            return new LeaveResult(null, "fail: Driver is not set");
        }
        if (this.passenger == null) {
            return new LeaveResult(null, "fail: Passenger is not set");
        }

        if (this.passenger.getMoney() < this.runCost) {
            this.passenger.setMoney(0);
            var error = "fail: Passenger does not have enough money";
            this.driver.setMoney(this.driver.getMoney() + this.runCost);
            this.runCost = 0;
            Person leavingPassenger = this.passenger;
            this.passenger = null;
            return new LeaveResult(leavingPassenger, error);
        } else {
            this.passenger.setMoney(this.passenger.getMoney() - this.runCost);
        }

        this.driver.setMoney(this.driver.getMoney() + this.runCost);
        this.runCost = 0;

        Person leavingPassenger = this.passenger;
        this.passenger = null;
        return new LeaveResult(leavingPassenger, null);
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
                var error = uber.setDriver(driver);
                if (error != null) System.out.println(error);
            }
            else if (cmd.equals("setPass")) { 
                String name = par[1];
                int money = Integer.parseInt(par[2]);
                // @DROP
                Person passenger = new Person(name, money);
                var error = uber.setPassenger(passenger);
                if (error != null) System.out.println(error);
            }
            else if (cmd.equals("drive")) { 
                int distance = Integer.parseInt(par[1]);
                // @DROP
                var error = uber.drive(distance);
                if (error != null) System.out.println(error);
            }
            else if (cmd.equals("leavePass")) { 
                // @DROP
                var result = uber.leave();
                if (result.getError() != null) {
                    System.out.println(result.getError());
                }
                if (result.getPassenger() != null) {
                    System.out.println(result.getPassenger() + " left");
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
