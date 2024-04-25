/* 
class Coin {
    private value: number;
    private volume: number;
    private label: string;
    
    public static C10 = new Coin(0.10, 1, "C10");
    public static C25 = new Coin(0.25, 2, "C25");
    public static C50 = new Coin(0.50, 3, "C50");
    public static C100 = new Coin(1.0, 4, "C100");

    private constructor(value: number, volume: number, label: string) {
    }
    public toString(): string {
    }
    public getValue(): number {
    }
    public getVolume(): number {
    }
    public getLabel(): string {
    }
}


class Item {
    private label: string;
    private volume: number;

    public constructor(label: string, volume: number) {
    }
    public getLabel(): string {
    }
    public getVolume(): number {
    }
    public setVolume(volume: number): void {
    }
    public setLabel(label: string): void {
    }
    public toString(): string {
    }
}

class Pig {
    private items: Item[];
    private coins: Coin[];
    volumeMax: number;
    broken: boolean;

    public constructor(volumeMax: number) {
    }

    public addCoin(coin: Coin): boolean {
    }

    public addItem(item: Item): boolean {
    }

    public getVolume(): number {
    }
    public getValue(): number {
    }

    public breakPig(): boolean {
    }

    public extractCoins(): Coin[] {
    }

    public extractItems(): Item[] {
    }

    public toString(): string {
        let state = this.broken ? "broken" : "intact";
        let coins = "[" + this.coins.map(coin => coin.toString()).join(", ") + "]";
        let items = "[" + this.items.map(item => item.toString()).join(", ") + "]";
        return `state=${state} : coins=${coins} : items=${items}` + 
                ` : value=${this.getValue().toFixed(2)}` + 
                ` : volume=${this.getVolume()}/${this.volumeMax}`;
    }
}

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
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
        else if (args[0] === "extractItems") { 
            let output = "[" + pig.extractItems().map(item => item.toString()).join(", ") + "]";
            write(output);
        }
        else if (args[0] === "extractCoins") { 
            let output = "[" + pig.extractCoins().map(item => item.toString()).join(", ") + "]";
            write(output);
        }
        else if (args[0] === "break")    { pig.breakPig();                                           }
        else                             { write("fail: comando invalido");                          }
    }
}

main();


 */