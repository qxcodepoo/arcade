import {evaluate, puts} from "./shell";

class Time { //todo
    private hour: number;
    private minute: number;
    private second: number;

    constructor(hour: number, minute: number, second: number) { //todo
    }

    setHour(hour: number): void { //todo
    }

    setMinute(minute: number): void { //todo
    }

    setSecond(second: number): void { //todo
    }

    getHour(): number { //todo
    }

    getMinute(): number { //todo
    }

    getSecond(): number { //todo
    }

    nextSecond(): void { //todo
    }
    toString() {
        let p2 = n => ("" + n).padStart(2, "0");
        return p2(this.hour) + ":" + p2(this.minute) + ":" + p2(this.second);
    }
}

function main() {
    let chain = new Map();
    let param: string[] = [];
    let time = new Time(0, 0, 0);

    chain.set("set", () => {
        time.setHour(+param[1]);
        time.setMinute(+param[2]); 
        time.setSecond(+param[3]);
    });
    chain.set("show", () => { puts(time.toString()); });
    chain.set("next", () => {      time.nextSecond();});
    evaluate(chain, param);
}


main()

