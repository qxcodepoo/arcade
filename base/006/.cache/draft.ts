import {evaluate, puts, write} from "./shell";


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

    private testAlive() { //todo
    }
    public toString(): string {
        return `E:${this.energy}/${this.energyMax}, S:${this.hungry}/${this.hungryMax}, L:${this.clean}/${this.cleanMax}, D:${this.diamonds}, I:${this.age}`;
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

    public getClean() { //todo
    }
    public getHungry() { //todo
    }
    public getEnergy() { //todo
    }
    public getDiamonds() { //todo
    }
    public getAge() { //todo
    }
    public getAlive() { //todo
    }

}

function main() { //todo
    let chain = new Map();
    let param: string[] = [];
    let pet = new Pet(0, 0, 0);
    chain.set("init",   () => pet = new Pet(+param[1], +param[2], +param[3]));
    chain.set("show",   () => puts(pet.toString()));
    chain.set("play",   () => pet.play());
    chain.set("clean",  () => pet.shower());
    chain.set("eat",    () => pet.eat());
    chain.set("sleep",  () => pet.sleep());

    evaluate(chain, param);
};

main()

