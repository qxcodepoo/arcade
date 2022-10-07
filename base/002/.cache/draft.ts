
function main() {
    let chain = new Map();
    let param = [];
    let car = new Car();

    chain.set("enter",      () => car.enter());
    chain.set("leave",      () => car.leave());
    chain.set("show",       () => puts(car.toString()));
    chain.set("drive",      () => car.drive(+param[1]));
    chain.set("fuel",       () => car.fuel(+param[1]));
    chain.set("help",       () => puts("show, enter, leave, drive, fuel, help, end"));

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

