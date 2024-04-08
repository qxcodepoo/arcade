class Calculator {
    batteryMax: number;
    battery: number;
    display: number;

    constructor(batteryMax: number) {
    }

    chargeBattery(value: number): void {
    }

    useBattery(): boolean {
    }


    sum(a: number, b: number): void { 
    }

    division(num: number, den: number): void {
    }

    toString(): string {
        return "display = " + this.display.toFixed(2) + ", battery = " + this.battery;
    }
}

export {Calculator};