function input() { return ""; }
export {};

// @DROP
class Person {
    private name: string;
    private money: number;

    constructor(name: string = "", money: number = 0) {
        this.name = name;
        this.money = money;
    }

    toString(): string {
        return `${this.name}:${this.money}`;
    }

    getName(): string {
        return this.name;
    }

    setMoney(money: number): void {
        this.money = money;
    }

    getMoney(): number {
        return this.money;
    }
}

class Uber {
    private driver: Person | null = null;
    private passenger: Person | null = null;
    private runCost: number = 0;

    setDriver(driver: Person): void {
        if (this.driver !== null) {
            console.log("fail: Driver is already set");
            return;
        }
        this.driver = driver;
    }

    setPassenger(passenger: Person): void {
        if (this.driver === null) {
            console.log("fail: Driver is not set");
            return;
        }
        this.passenger = passenger;
        this.runCost = 0;
    }

    drive(distance: number): void {
        if (this.driver === null) {
            console.log("fail: Driver is not set");
            return;
        }
        if (this.passenger !== null) {
            this.runCost += distance;
        }
    }

    leave(): Person | null {
        if (this.driver === null) {
            console.log("fail: Driver is not set");
            return null;
        }
        if (this.passenger === null) {
            console.log("fail: Passenger is not set");
            return null;
        }

        if (this.passenger.getMoney() < this.runCost) {
            this.passenger.setMoney(0);
            console.log("fail: Passenger does not have enough money");
        } else {
            this.passenger.setMoney(this.passenger.getMoney() - this.runCost);
        }

        this.driver.setMoney(this.driver.getMoney() + this.runCost);
        this.runCost = 0;

        const leavingPassenger = this.passenger;
        this.passenger = null;
        return leavingPassenger;
    }

    toString(): string {
        const driverStr = this.driver ? this.driver.toString() : "None";
        const passengerStr = this.passenger ? this.passenger.toString() : "None";
        return `Cost: ${this.runCost}, Driver: ${driverStr}, Passenger: ${passengerStr}`;
    }
}

// @KEEP
function main(): void {
    // @DROP
    let uber = new Uber();
    // @KEEP
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        // @COM
        else if (cmd == "show") { 
            // @DROP
            console.log(uber.toString());
        }
        else if (cmd == "setDriver") { 
            const name = par[1];
            const money = parseInt(par[2]);
            // @DROP
            let driver = new Person(name, money);
            uber.setDriver(driver);
        }
        else if (cmd == "setPass") { 
            const name = par[1];
            const money = parseInt(par[2]);
            // @DROP
            let passenger = new Person(name, money);
            uber.setPassenger(passenger);
        }
        else if (cmd == "drive") { 
            const distance = parseInt(par[1]);
            // @DROP
            uber.drive(distance);
        }
        else if (cmd == "leavePass") { 
            // @DROP
            let passenger = uber.leave();
            if (passenger !== null) {
                console.log(passenger.toString() + " left");
            }
        }
        // @KEEP
        else {
            console.log("fail: command not found");
        }
    }
}

main();
