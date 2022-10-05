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

import { readFileSync } from "fs";

let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
let write = (text: any) => process.stdout.write("" + text);
let puts = (text: any) => console.log(text);
function evaluate(chain: Map<string, Function>, param: string[]) {
    while (true) {
        let line = input();
        puts("$" + line);
        param.splice(0); //apagar tudo
        line.split(" ").forEach((x: string) => param.push(x));

        let cmd = param[0];
        if (cmd == "end") {
            return;
        } else if (chain.has(cmd)) {
            chain.get(cmd)!();
        } else {
            puts("fail: command not found");
        }
    }
}

main()

