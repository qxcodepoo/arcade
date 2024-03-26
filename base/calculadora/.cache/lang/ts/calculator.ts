class Calculator {
    batteryMax: number;
    battery: number;
    display: number;

    constructor(batteryMax: number) {
        //todo
        this.display = 0;
    }

    chargeBattery(value: number): void {
        //todo
    }

    useBattery(): boolean {
        //todo: deixe pra fazer no final
        return false;
    }


    sum(a: number, b: number): void { 
        //todo
    }

    division(num: number, den: number): void {
        //todo
    }

    toString(): string {
        return "display = " + this.display.toFixed(2) + ", battery = " + this.battery;
    }
}

export {Calculator};