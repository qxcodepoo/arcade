class Student {
    // calc: Calculator = new Calculator(0);
    public init(batteryMax: number): void {
        // this.calc = new Calculator(batteryMax);
    }

    public show(): void {
        // console.log(this.calc.toString());
    }

    public charge(value: number): void {
        // this.calc.chargeBattery(value);
    }

    public sum(a: number, b: number): void {
        // this.calc.sum(a, b);
    }

    public div(a: number, b: number): void {
        // this.calc.division(a, b);
    }
}

export { Student };


if (require.main === module) {
    console.log("Testando Adapter");
}
