class Time {
    private hour: number;
    private minute: number;
    private second: number;

    constructor(hour: number, minute: number, second: number) {

    }
    setHour(hour: number): void {
    }
    setMinute(minute: number): void {
    }

    setSecond(second: number): void {
    }
    getHour(): number {
    }
    getMinute(): number {
    }

    getSecond(): number {
    }
    nextSecond(): void {
    }
    toString() {
        let p2 = (n: number) => ("" + n).padStart(2, "0");
        return p2(this.hour) + ":" + p2(this.minute) + ":" + p2(this.second);
    }
}

export {Time};