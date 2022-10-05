
class Pet { //todo
    private energyMax: number;
    private hungryMax: number;
    private cleanMax: number;

    private energy: number;
    private hungry: number;
    private clean: number;

    private diamonds: number;
    private age: number;
    private alive: boolean;

    public constructor(energy: number, hungry: number, clean: number) {
        this.energyMax = energy;
        this.hungryMax = hungry;
        this.cleanMax = clean;

        this.energy = energy;
        this.hungry = hungry;
        this.clean = clean;

        this.diamonds = 0;
        this.age = 0;
        this.alive = true;
    }
    public setEnergy(value: number) { //todo
    }

    public setHungry(value: number) { //todo
    }

    public setClean(value: number) { //todo
    }

    private testAlive(): boolean { //todo
    }
    public toString(): string {
        return  `E:${this.energy}/${this.energyMax}` 
            + `, S:${this.hungry}/${this.hungryMax}` 
            + `, L:${this.clean}/${this.cleanMax}` 
            + `, D:${this.diamonds}, I:${this.age}`;
    }

    public play() {
        if (!this.testAlive()) 
            return;
        this.setEnergy(this.energy - 2);
        this.setHungry(this.hungry - 1);
        this.setClean(this.clean - 3);
        this.age += 1;
        this.diamonds += 1;
    }
    public shower() { //todo
    }
    public eat() { //todo
    }
    public sleep() { //todo
    }
    public getClean() {
        return this.clean;
    }
    public getHungry() {
        return this.hungry;
    }
    public getEnergy() {
        return this.energy;
    }
    public getDiamonds() {
        return this.diamonds;
    }
    public getAge() {
        return this.age;
    }
    public getAlive() {
        return this.alive;
    }

}

function main() {
    let chain = new Map();
    let param: string[] = [];
    let pet = new Pet(0, 0, 0);
    chain.set("init",   () => pet = new Pet(+param[1], +param[2], +param[3]));
    chain.set("show",   () => puts(pet.toString()));
    chain.set("play",   () => pet.play());
    chain.set("shower", () => pet.shower());
    chain.set("eat",    () => pet.eat());
    chain.set("sleep",  () => pet.sleep());

    evaluate(chain, param);
};

import { readFileSync } from "fs";
let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
let write = (text: any) => process.stdout.write("" + text);
let puts = (text: any) => console.log(text);

function evaluate(chain: Map<string, Function>, param: string[]) {
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

