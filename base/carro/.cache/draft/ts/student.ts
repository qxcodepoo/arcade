class Adapter {
    // car: Car = new Car();

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

    show(): void {
        // console.log(this.car.toString());
    }
}

export {Adapter};

if (require.main === module) {
    console.log("Rodando o arquivo do estudante");
}
