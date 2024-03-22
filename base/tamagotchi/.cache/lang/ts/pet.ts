
class Pet {
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
    public setEnergy(value: number) {
    }

    public setHungry(value: number) {
    }

    public setClean(value: number) {
    }

    public setDiamonds(value: number) {
    }
    public setAge(value: number) {
    }

    public toString(): string {
        return  `E:${this.energy}/${this.energyMax}` 
            + `, S:${this.hungry}/${this.hungryMax}` 
            + `, L:${this.clean}/${this.cleanMax}` 
            + `, D:${this.diamonds}, I:${this.age}`;
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

    public getCleanMax() {
        return this.cleanMax;
    }
    public getHungryMax() {
        return this.hungryMax;
    }
    public getEnergyMax() {
        return this.energyMax;
    }

    public getDiamonds() {
        return this.diamonds;
    }
    public getAge() {
        return this.age;
    }
    public isAlive() {
        return this.alive;
    }
}

export { Pet };