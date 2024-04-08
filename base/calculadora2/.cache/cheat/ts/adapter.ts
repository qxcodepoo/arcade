import {Calculator} from "./calculadora";

class Adapter {
    calc: Calculator;
    public constructor(batteryMax: number) {
        this.calc = new Calculator(batteryMax);
    }

    public show(): string {
        return this.calc.toString();
    }

    public charge(value: number): void {
        this.calc.chargeBattery(value);
    }

    public sum(a: number, b: number): void {
        this.calc.sum(a, b);
    }

    public div(a: number, b: number): void {
        this.calc.division(a, b);
    }
}

export { Adapter };


if (require.main === module) {
    console.log("Testando Adapter");
}
