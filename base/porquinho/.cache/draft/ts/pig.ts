//--

import { Coin } from "./coin";
import { Item } from "./item";

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

export { Pig };