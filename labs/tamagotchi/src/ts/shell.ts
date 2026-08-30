const input = () => ""; // MODO_TESTE
export {};

// @DROP

class Pet {
    private energyMax: number;
    private cleanMax: number;

    private energy: number;
    private clean: number;

    private age: number;
    private alive: boolean;

    public constructor(energy: number, clean: number) {
        this.energyMax = energy;
        this.cleanMax = clean;

        this.energy = energy;
        this.clean = clean;

        this.age = 0;
        this.alive = true;
    }

    public setEnergy(value: number) {
        if (value <= 0) {
            this.alive = false;
            this.energy = 0;
            console.log("fail: pet morreu de fraqueza");
            return;
        }
        if (value > this.energyMax) {
            this.energy = this.energyMax;
            return;
        }
        this.energy = value;
    }

    public setClean(value: number) {
        if (value <= 0) {
            this.alive = false;
            this.clean = 0;
            console.log("fail: pet morreu de sujeira");
            return;
        }
        if (value > this.cleanMax) {
            this.clean = this.cleanMax;
            return;
        }
        this.clean = value;
    }

    public setAge(value: number) {
        this.age = value;
    }

    public toString(): string {
        return  `E:${this.energy}/${this.energyMax}` 
            + `, L:${this.clean}/${this.cleanMax}` 
            + `, I:${this.age}`;
    }

    public getClean() {
        return this.clean;
    }
    public getEnergy() {
        return this.energy;
    }

    public getCleanMax() {
        return this.cleanMax;
    }

    public getEnergyMax() {
        return this.energyMax;
    }

    public getAge() {
        return this.age;
    }
    public isAlive() {
        return this.alive;
    }
}

class Game {

    pet: Pet;

    constructor(pet: Pet) {
        this.pet = pet;
    }

    private testAlive(): boolean {
        if (!this.pet.isAlive()) {
            console.log("fail: pet esta morto");
            return false;
        }
        return true;
    }

    public play() {
        if (!this.testAlive()) 
            return;
        this.pet.setEnergy(this.pet.getEnergy() - 2);
        this.pet.setClean(this.pet.getClean() - 3);
        this.pet.setAge(this.pet.getAge() + 1);
    }

    public shower() {
        if (!this.testAlive()) 
            return;
        this.pet.setEnergy(this.pet.getEnergy() - 3);
        this.pet.setClean(this.pet.getCleanMax());
        this.pet.setAge(this.pet.getAge() + 2);
    }

    public sleep() {
        if (!this.testAlive()) 
            return;
        if (this.pet.getEnergyMax() - this.pet.getEnergy() < 5) {
            console.log("fail: nao esta com sono");
            return;
        }

        this.pet.setAge(this.pet.getAge() + this.pet.getEnergyMax() - this.pet.getEnergy());
        this.pet.setEnergy(this.pet.getEnergyMax());
    }

    toString() {
        return this.pet.toString();
    }
}

// @KEEP
function main() {
    // CRIE SEU JOGO AQUI COM UM PET ZERADO
    // @DROP
    let game = new Game(new Pet(0, 0));
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        } 
        // @COM
        else if (cmd == "init") {
            // CRIE UM NOVO JOGO COM UM NOVO PET
            const energy = parseInt(par[1]);
            const clean = parseInt(par[2]);
            // @DROP
            game = new Game(new Pet(energy, clean));
        } 
        else if (cmd == "play") { 
            // @DROP
            game.play();
        } 
        else if (cmd == "shower") { 
            // @DROP
            game.shower();
        } 
        else if (cmd == "sleep") { 
            // @DROP
            game.sleep();
        } 
        else if (cmd == "show") { 
            // @DROP
            console.log(game.toString());
        } 
        // @KEEP
        else {
            console.log("fail: comando invalido");
        }
    }
}

main();
