
class Pessoa { //todo
    private age: number;
    private name: string;

    public constructor(name: string, age: number) { //todo
    }
    public getAge(): number { //todo
    }
    public getname(): string { //todo
    }
    public toString(): string { //todo
    }
}

class Motoca { //todo
    potencia:number = 1;
    time: number = 0;
    pessoa: Pessoa | null;

    constructor(potencia: number = 1) { //todo
    }

    buzinar(): string { //todo
    }

    inserir(pessoa: Pessoa): boolean { //todo
    }

    remover() : Pessoa | null { //todo
    }

    drive(time: number): void { //todo
    }

    comprarTempo(value: number) { //todo
    }

    public toString(): string {
        return `power:${this.potencia}, time:${this.time}, person:` +
            "(" +  (this.pessoa === null ? "empty" : "" + this.pessoa) + ")";
    }
}

function main() {
    let chain = new Map();
    let param: string[] = [];
    let moto = new Motoca();

    chain.set("init", () => moto = new Motoca(+param[1]));
    chain.set("show", () => console.log("" + moto));
    chain.set("enter", () => moto.inserir(new Pessoa(param[1], +param[2])));
    chain.set("honk", () => console.log(moto.buzinar()));
    chain.set("leave", () => {
        let person = moto.remover();
        if (person !== null)
            console.log("" + person);
    });
    chain.set("drive", () => moto.drive(+param[1]));
    chain.set("buy", () => moto.comprarTempo(+param[1]));
    
    execute(chain, param);
}

import { readFileSync } from "fs";

let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
let write = (text: any) => process.stdout.write("" + text);
let puts = (text: any) => console.log(text);
function execute(chain: Map<string, Function>, param: string[]) {
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