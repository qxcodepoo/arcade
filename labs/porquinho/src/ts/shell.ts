const input = () => ""; // MODO_TESTE
export {};

// @DROP

class Coin {
    private value: number;
    private volume: number;
    private label: string;
    
    public static C10 = new Coin(0.10, 1, "C10");
    public static C25 = new Coin(0.25, 2, "C25");
    public static C50 = new Coin(0.50, 3, "C50");
    public static C100 = new Coin(1.0, 4, "C100");

    private constructor(value: number, volume: number, label: string) {
        this.value = value;
        this.volume = volume;
        this.label = label;
    }
    public toString(): string {
        return `${this.value.toFixed(2)}:${this.volume}`;
    }
    public getValue(): number {
        return this.value;
    }
    public getVolume(): number {
        return this.volume;
    }
    public getLabel(): string {
        return this.label;
    }
}



class Item {
    private label: string;
    private volume: number;

    public constructor(label: string, volume: number) {
        this.label = label;
        this.volume = volume;
    }
    public getLabel(): string {
        return this.label;
    }
    public getVolume(): number {
        return this.volume;
    }
    public setVolume(volume: number): void {
        this.volume = volume;
    }
    public setLabel(label: string): void {
        this.label = label;
    }
    public toString(): string {
        return `${this.label}:${this.volume}`;
    }
}

class Pig {
    private items: Item[];
    private coins: Coin[];
    volumeMax: number;
    broken: boolean;

    public constructor(volumeMax: number) {
        this.volumeMax = volumeMax;
        this.broken = false;
        this.items = [];
        this.coins = [];
    }

    public addCoin(coin: Coin): boolean {
        if (this.broken) {
            console.log("fail: the pig is broken");
            return false;
        }
        if (this.getVolume() + coin.getVolume() > this.volumeMax) {
            console.log("fail: the pig is full");
            return false;
        }
        this.coins.push(coin);
        return true;
    }

    public addItem(item: Item): boolean {
        if (this.broken) {
            console.log("fail: the pig is broken");
            return false;
        }
        if (this.getVolume() + item.getVolume() > this.volumeMax) {
            console.log("fail: the pig is full");
            return false;
        }
        this.items.push(item);
        return true;
    }

    public getVolume(): number {
        if (this.broken) {
            return 0;
        }
        let volume = 0;
        for (let item of this.items) {
            volume += item.getVolume();
        }
        for (let coin of this.coins) {
            volume += coin.getVolume();
        }
        return volume;
    }
    public getValue(): number {
        let value = 0;
        for (let coin of this.coins) {
            value += coin.getValue();
        }
        return value;
    }

    public breakPig(): boolean {
        if (this.broken) {
            console.log("fail: the pig is already broken");
            return false;
        }
        this.broken = true;
        return true;
    }

    public extractCoins(): Coin[] {
        if (!this.broken) {
            console.log("fail: you must break the pig first");
            return [];
        }
        let aux = this.coins;
        this.coins = [];
        return aux;
    }

    public extractItems(): Item[] {
        if (!this.broken) {
            console.log("fail: you must break the pig first");
            return [];
        }
        let aux = this.items;
        this.items = [];
        return aux;
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

// @KEEP
function main() {
    // @DROP
    let pig = new Pig(10);
    // @KEEP
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        else if (cmd == "init") {
            // @COM
            const volume = parseInt(par[1]);
            // @DROP
            pig = new Pig(volume);
        }
        else if (cmd == "show") {
            // @DROP
            console.log(pig.toString());
        }
        else if (cmd == "addCoin") {
            // @COM
            const value = parseInt(par[1]);
            // @DROP
            if (value == 10) {
                pig.addCoin(Coin.C10);
            } else if (value == 25) {
                pig.addCoin(Coin.C25);
            } else if (value == 50) {
                pig.addCoin(Coin.C50);
            } else if (value == 100) {
                pig.addCoin(Coin.C100);
            }
        }
        else if (cmd == "addItem") {
            // @COM
            const label = par[1];
            const volume = parseInt(par[2]);
            // @DROP
            pig.addItem(new Item(label, volume));
        }
        else if (cmd == "break") {
            // @DROP
            pig.breakPig();
        }
        else if (cmd == "extractCoins") {
            // @DROP
            const coins = pig.extractCoins();
            console.log("[" + coins.map(coin => coin.toString()).join(", ") + "]");
        }
        else if (cmd == "extractItems") {
            // @DROP
            const items = pig.extractItems();
            console.log("[" + items.map(item => item.toString()).join(", ") + "]");
        }
        else {
            console.log("fail: invalid command");
        }
    }
}

main();
