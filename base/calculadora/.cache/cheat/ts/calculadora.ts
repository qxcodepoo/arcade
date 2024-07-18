class Calculator {
    batteryMax: number;
    battery: number;
    display: number;

    constructor(batteryMax: number) {
        this.batteryMax = batteryMax;
        this.battery = 0;
        this.display = 0;
    }

    chargeBattery(value: number): void {
        this.battery += value;
        if (this.battery > this.batteryMax) {
            this.battery = this.batteryMax;
        }
    }

    sum(a: number, b: number): void { 
        if(this.battery == 0){
            console.log("fail: bateria insuficiente");
            return;
        }
        this.battery -= 1;
        this.display = (a + b);
    }

    division(num: number, den: number): void {
        if(this.battery == 0){
            console.log("fail: bateria insuficiente");
            return;
        }
        this.battery -= 1;
        if(den == 0){
            console.log("fail: divisao por zero");
            return;
        }
        this.display = num / den;
    }

    toString(): string {
        return `display = ${this.display.toFixed(2)}, battery = ${this.battery}`;
    }
}

export {Calculator};

if (require.main === module) {
    let calc = new Calculator(5);
    calc.chargeBattery(2);
    calc.sum(2, 3);
    console.log(calc.toString());
    calc.division(5, 0);
    console.log(calc.toString());
}
