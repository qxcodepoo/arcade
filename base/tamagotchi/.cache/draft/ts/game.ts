import { Pet } from "./pet";

class Game {

    pet: Pet;

    constructor(pet: Pet) {
        this.pet = pet;
    }
    //se estiver morto, avise e retorne false
    private testAlive(): boolean {
    }
    public play() {
        if (!this.testAlive()) 
            return;
        this.pet.setEnergy(this.pet.getEnergy() - 2);
        this.pet.setHungry(this.pet.getHungry() - 1);
        this.pet.setClean(this.pet.getClean() - 3);
        this.pet.setAge(this.pet.getAge() + 1);
        this.pet.setDiamonds(this.pet.getDiamonds() + 1);
    }
    public shower() {
    }
    public eat() {
    }
    public sleep() {

    }
    toString() {
        return this.pet.toString();
    }
}


export { Game };