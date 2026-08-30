// @DROP

interface Valuable {
    getLabel(): string;

    getValue(): number;

    getVolume(): number;
}

class Coin implements Valuable {
    private label: string;
    private value: number;
    private volume: number;

    constructor(label: string, value: number, volume: number) {
        this.label = label;
        this.value = value;
        this.volume = volume;
    }

    static readonly C10 = new Coin("M10", 0.10, 1);
    static readonly C25 = new Coin("M25", 0.25, 2);
    static readonly C50 = new Coin("M50", 0.50, 3);
    static readonly C100 = new Coin("M100", 1.00, 4);

    getLabel(): string {
        return this.label;
    }

    getVolume(): number {
        return this.volume;
    }

    getValue(): number {
        return this.value;
    }

    toString(): string {
        return `${this.label}:${this.value.toFixed(2)}:${this.volume}`;
    }
}

class Item implements Valuable {
    private label: string;
    private value: number;
    private volume: number;

    constructor(label: string, value: number, volume: number) {
        this.label = label;
        this.value = value;
        this.volume = volume;
    }

    getLabel(): string {
        return this.label;
    }

    getVolume(): number {
        return this.volume;
    }

    getValue(): number {
        return this.value;
    }

    toString(): string {
        return `${this.label}:${this.value.toFixed(2)}:${this.volume}`;
    }
}

class Pig {
    private volumeMax: number;
    private broken: boolean;
    private valuables: Valuable[];

    constructor(volumeMax: number) {
        this.volumeMax = volumeMax;
        this.broken = false;
        this.valuables = [];
    }

    addValuable(val: Valuable): void {
        if (this.broken) {
            throw new Error("fail: the pig is broken");
        }
        if (val.getVolume() + this.getVolume() > this.volumeMax) {
            throw new Error("fail: the pig is full");
        }
        this.valuables.push(val);
    }

    breakPig(): void {
        if (this.broken) {
            throw new Error("fail: the pig is already broken");
        }
        this.broken = true;
    }

    extractCoins(): Coin[] {
        if (!this.broken) {
            throw new Error("fail: you must break the pig first");
        }
        const coins = this.valuables.filter((val) => val instanceof Coin) as Coin[];
        this.valuables = this.valuables.filter((val) => !(val instanceof Coin));
        return coins;
    }

    extractItems(): Item[] {
        if (!this.broken) {
            throw new Error("fail: you must break the pig first");
        }
        const items = this.valuables.filter((val) => val instanceof Item) as Item[];
        this.valuables = this.valuables.filter((val) => !(val instanceof Item));
        return items;
    }

    getVolume(): number {
        if (this.broken) return 0;
        return this.valuables.reduce((total, val) => total + val.getVolume(), 0);
    }

    getValue(): number {
        return this.valuables.reduce((total, val) => total + val.getValue(), 0);
    }
    toString(): string {
        const status = this.broken ? "broken" : "intact";
        const values = "[" + this.valuables.join(", ") + "]";
        return `${values} : ${this.getValue().toFixed(2)}$ : ${this.getVolume()}/${this.volumeMax} : ${status}`;
    }
}

// @KEEP
const input = () => ""; // MODO_TESTE
export {};

function main() {
    let pig = new Pig(0); // @DROP
    
    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");
        
        try {
            if (args[0] == "end") {
                break;
            }
            else if (args[0] == "show") {
                // @DROP
                console.log(pig.toString());
            }
            else if (args[0] == "init") {
                // @COM
                const volumeMax = parseInt(args[1]);
                // @DROP
                pig = new Pig(volumeMax);
            }
            else if (args[0] == "addCoin") {
                // @COM
                let value = parseInt(args[1]);
                // @DROP
                if      (value == 10) { pig.addValuable(Coin.C10); } 
                else if (value == 25) { pig.addValuable(Coin.C25); } 
                else if (value == 50) { pig.addValuable(Coin.C50); }
                else if (value == 100) { pig.addValuable(Coin.C100); }
            }
            else if (args[0] == "addItem") {
                // @COM
                const label = args[1];
                const value = parseInt(args[2]);
                const volume = parseInt(args[3]);
                // @DROP
                pig.addValuable(new Item(label, value, volume));
            }
            else if (args[0] == "break") {
                // @DROP
                pig.breakPig();
            }
            else if (args[0] == "extractCoins") {
                // @DROP
                let coins = pig.extractCoins();
                console.log("[" + coins.join(", ") + "]");
            }
            else if (args[0] == "extractItems") {
                // @DROP
                let itens = pig.extractItems();
                console.log("[" + itens.join(", ") + "]");
            }
            else {
                console.log("fail: invalid command");
            }
        } catch (e) {
            console.log(e.message);
        }
    }
}

main();
