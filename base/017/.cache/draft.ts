
class Coin { //todo
    private value: number;
    private volume: number;
    private label: string;
    
    public static C10 = new Coin(0.10, 1, "C10");
    public static C25 = new Coin(0.25, 2, "C25");
    public static C50 = new Coin(0.50, 3, "C50");
    public static C100 = new Coin(1.0, 4, "C100");

    private constructor(value: number, volume: number, label: string) { //todo
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

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let pig = new Pig(10);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "init")  { pig = new Pig(Number(args[1]));                              }
        else if (args[0] === "show")  { write(pig.toString());                                       }
        else if (args[0] === "add")   { pig.addItem(new Item(args[1], Number(args[2])));             }
        else if (args[0] === "addCoin")  {
            if      (args[1] === "10")  { pig.addCoin(Coin.C10); }
            else if (args[1] === "25")  { pig.addCoin(Coin.C25); }
            else if (args[1] === "50")  { pig.addCoin(Coin.C50); }
            else if (args[1] === "100") { pig.addCoin(Coin.C100); }
        }
        else if (args[0] === "addItem")  { pig.addItem(new Item(args[1], Number(args[2])));          }
        else if (args[0] === "getItems") { write(pig.getItems());                                    }
        else if (args[0] === "getCoins") { write(pig.getCoins().toFixed(2));                         }
        else if (args[0] === "break")    { pig.breakPig();                                           }
        else                             { write("fail: comando invalido");                          }
    }
}

main();


