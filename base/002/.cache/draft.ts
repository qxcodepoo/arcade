import {evaluate, puts} from "./shell"

class Car{
    pass: number; // Passageiros
    passMax: number; // limite de Passageiros
    gas: number; // tanque
    gasMax: number; // limite do tanque
    km: number; // quantidade de quilometragem

    constructor() { //todo
    }



    enter() { //todo
    }

    leave() { //todo
    }
    
    fuel(gas: number) { //todo
    }

    drive (km: number) { //todo
    }    

    toString() {
        return "pass: " + this.pass + ", gas: " + this.gas + ", km: " + this.km;
    }
};


function main() {
    let chain = new Map();
    let ui = [];
    let car = new Car();

    chain.set("enter",      () => car.enter());
    chain.set("leave",      () => car.leave());
    chain.set("show",       () => puts(car.toString()));
    chain.set("drive",      () => car.drive(+ui[1]));
    chain.set("fuel",       () => car.fuel(+ui[1]));
    chain.set("help",       () => puts("show, enter, leave, drive, fuel, help, end"));

    evaluate(chain, ui);
}

main()

