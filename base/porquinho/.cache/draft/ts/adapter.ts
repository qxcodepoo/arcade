class Adapter {
    public constructor(volumeMax: number) {
        this.pig = new Pig(volumeMax);
    }

    addCoin(value: number): void {
        if      (value === 10)   { this.pig.addCoin(Coin.C10); }
        else if (value === 25)   { this.pig.addCoin(Coin.C25); }
        else if (value === 50)   { this.pig.addCoin(Coin.C50); }
        else if (value ===  100) { this.pig.addCoin(Coin.C100);}
    }

    addItem(label: string, volume: number): void {
        let item = new Item(label, volume)
        this.pig.addItem(item);
    }

    breakPig(): void {
        this.pig.breakPig();
    }

    extractItems(): string {
        return "[" + this.pig.extractItems().map(item => item.toString()).join(", ") + "]";
        return "";
    }

    extractCoins(): string{
        return "[" + this.pig.extractCoins().map(item => item.toString()).join(", ") + "]";
        return "";
    }

    toString(): string {
        return this.pig.toString();
        return "";
    }
}

export { Adapter };