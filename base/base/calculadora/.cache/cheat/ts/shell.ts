function input() { return ""; }
export {};


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


function main() {
    let calc = new Calculator(0);

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];
        if (cmd == "end") {
            break;
        } 
        else if (cmd == "init") {
            const batteryMax = parseInt(par[1]);
            calc = new Calculator(batteryMax);
        } 
        else if (cmd == "charge") {
            const value = parseInt(par[1]);
            calc.chargeBattery(value);
        } 
        else if (cmd == "sum") {
            const a = parseInt(par[1]);
            const b = parseInt(par[2]);
            calc.sum(a, b);
        } 
        else if (cmd == "div") {
            const num = parseInt(par[1]);
            const den = parseInt(par[2]);
            calc.division(num, den);
        } 
        else if (cmd == "show") {
            console.log(calc.toString());
        } 
        else {
            console.log("fail: comando invalido");
        }
    }
}

main()