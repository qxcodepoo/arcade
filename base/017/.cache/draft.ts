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

    public toString(): string { //todo
    }
}

function main() { //todo
    let chain = new Map();
    let param: string[] = [];
    let pig = new Pig(0);


    chain.set("addCoin", () => { //todo
    });
    chain.set("init",     () => pig = new Pig(+param[1])               );
    chain.set("addItem",  () => pig.addItem(new Item(param[1], +param[2])));
    chain.set("break",    () => pig.breakPig()                      );
    chain.set("getCoins", () => puts(pig.getCoins().toFixed(2))     );
    chain.set("getItems", () => puts(pig.getItems())                );
    chain.set("show",     () => puts(pig.toString())                );

    evaluate(chain, param);
}

import { //todo readFileSync } from "fs";

let __lines = readFileSync(0).toString().split("\n");
let input = () => { //todo 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
let write = (text: any) => process.stdout.write("" + text);
let puts = (text: any) => console.log(text);

function evaluate(chain: Map<string, Function>, ui: string[]) { //todo
    while (true) { //todo

    }
}

main()

