class Adapter {
    public constructor(batteryMax: number) {
    }

    public show(): string {
        return "";
    }

    public charge(value: number): void {
    }

    public sum(a: number, b: number): void {
    }

    public div(a: number, b: number): void {
    }
}

export { Adapter };


if (require.main === module) {
    console.log("Testando Adapter");
}
