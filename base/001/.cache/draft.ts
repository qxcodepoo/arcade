let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

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

    useBattery(): boolean {
        if(this.battery == 0){
            write("fail: bateria insuficiente");
            return false;
        }
        this.battery -= 1;
        return true;
    }


    sum(a: number, b: number): void { 
        if(this.useBattery()) {
            this.display = (a + b);
        }
    }


    division(num: number, den: number): void {
        if(!this.useBattery())
            return;
        if(den == 0){
            write("fail: divisao por zero");
            return;
        }
        this.display = num / den;
    }

    toString() {
        return "display = " + this.display.toFixed(2) + ", battery = " + this.battery;
    }
}
