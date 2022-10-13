//create enumeration
enum Cents {
    C10,
    C25,
    C50,
    C100
}

class Coin { //todo
    private value: number;
    private volume: number;
    private label: string;
    
    public constructor(cents: Cents) { //todo
    }
    public toString(): string { //todo
    }
    public getValue(): number { //todo
    }
    public getVolume(): number { //todo
    }
    public getLabel(): string { //todo
    }
}


class Item { //todo
    private label: string;
    private volume: number;

    public constructor(label: string, volume: number) { //todo
    }
    public getLabel(): string { //todo
    }
    public getVolume(): number { //todo
    }
    public setVolume(volume: number): void { //todo
    }
    public setLabel(label: string): void { //todo
    }
    public toString(): string { //todo
    }
}

class Pig { //todo
    private items: string[];
    private volumeMax: number;
    private volume: number;
    private value: number;
    private broken: boolean;

    public constructor(volumeMax: number) { //todo
    }

    public addItem(item: Item): boolean { //todo
    }

    public addCoin(coin: Coin): boolean { //todo
    }

    public breakPig(): boolean { //todo
    }

    public getCoins() : number { //todo
    }

    public getItems(): string { //todo
    }
    public toString(): string {
        let aux = "[" + this.items.join(", ") + "]";
        return `${aux} : ${this.value.toFixed(2)}\$ : ${this.volume}/${this.volumeMax} : ${this.broken ? "broken" : "unbroken"}`;
    }
}

function main() {
    let chain = new Map();
    let param: string[] = [];
    let pig = new Pig(0);


    chain.set("addCoin", () => {
        if      (param[1] == "10") pig.addCoin(new Coin(Cents.C10));
        else if (param[1] == "25") pig.addCoin(new Coin(Cents.C25));
        else if (param[1] == "50") pig.addCoin(new Coin(Cents.C50));
    });
    chain.set("init",     () => pig = new Pig(+param[1])               );
    chain.set("addItem",  () => pig.addItem(new Item(param[1], +param[2])));
    chain.set("break",    () => pig.breakPig()                      );
    chain.set("getCoins", () => puts(pig.getCoins().toFixed(2))     );
    chain.set("getItems", () => puts(pig.getItems())                );
    chain.set("show",     () => puts(pig.toString())                );

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

function evaluate(chain: Map<string, Function>, ui: string[]) {
    while (true) {
        let line = input();
        puts("$" + line);
        ui.splice(0); //apagar tudo
        line.split(" ").forEach((x: string) => ui.push(x));

        let cmd = ui[0];
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

