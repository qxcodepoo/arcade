
class Calculator { //todo
    batteryMax: number;
    battery: number;
    display: number;

    //Inicia os atributos, battery e display começam com o zero.
    constructor(batteryMax: number) { //todo
    }

    //Aumenta a bateria, porém não além do máximo.
    chargeBattery(value: number) { //todo
    }

    //Tenta gastar uma unidade da bateria e emite um erro se não conseguir.
    useBattery(): boolean { //todo
    }


    sum(a: number, b: number) { //todo 
    }


    division(num: number, den: number) { //todo
    }
    //Retorna o conteúdo do display com duas casas decimais.
    toString() {
        return "display = " + this.display.toFixed(2) + ", battery = " + this.battery;
    }
}

function main() {
    let chain = new Map();
    let ui: string[] = [];
    let calc = new Calculator(0);

    chain.set("show", () => puts("" + calc));
    chain.set("init", () => calc = new Calculator(+ui[1]));
    chain.set("charge", () => calc.chargeBattery(+ui[1]));
    chain.set("sum", () => calc.sum(+ui[1], +ui[2]));
    chain.set("div", () => calc.division(+ui[1], +ui[2]));

    evaluate(chain, ui);
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
