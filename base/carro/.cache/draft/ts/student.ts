class Adapter {
    // car: Car;

    constructor() {
        // this.car = new Car();
    }

    enter(): void {
        // this.car.enter();
    }

    leave(): void {
        // this.car.leave();
    }

    fuel(gas: number): void {
        // this.car.fuel(gas);
    }

    drive(km: number): void {
        // this.car.drive(km);
    }

    toString(): string {
        // return this.car.toString();
        return "";
    }
}
export {Adapter};

if (require.main === module) {
    console.log("Rodando o arquivo do estudante");
}
