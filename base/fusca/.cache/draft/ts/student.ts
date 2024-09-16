class CarAdp {
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

    show(): string {
        // return this.car.toString();
        return "";
    }
}
export {CarAdp as CarAdp};

if (require.main === module) {
    console.log("Rodando o arquivo do estudante");
}
