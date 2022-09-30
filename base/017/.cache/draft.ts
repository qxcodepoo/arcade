import {evaluate, puts, write} from "./shell";


//create enumeration
enum Coin {
    M10,
    M25,
    M50,
    M100
}

class CoinValues {
    public value: number;
    public volume: number;
    public label: string;
    
    private static map = new Map<Coin, CoinValues>([
            [Coin.M10 , new CoinValues(0.10, 1, "M10")],
            [Coin.M25 , new CoinValues(0.25, 2, "M25")],
            [Coin.M50 , new CoinValues(0.50, 3, "M50")],
            [Coin.M100, new CoinValues(1.00, 4, "M100")]]);

    private constructor(value: number, volume: number, label: string) {
        this.value = value;
        this.volume = volume;
        this.label = label;
    }

    public static get(coin: Coin): CoinValues {
        return this.map.get(coin)!;
    }
    
    public toString(): string {
        return `value: ${this.value}, volume: ${this.volume}, label: ${this.label}`;
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

main()

