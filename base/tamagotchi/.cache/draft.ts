
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
    }
    public getHungry() {
    }
    public getEnergy() {
    }

    public getCleanMax() {
    }
    public getHungryMax() {
    }
    public getEnergyMax() {
    }

    public getDiamonds() {
    }
    public getAge() {
    }
    public isAlive() {
    }
}

class Game {

    pet: Pet;

    constructor(pet: Pet) {
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
    }
}


let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let game = new Game(new Pet(0, 0, 0));

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                            }
        else if (args[0] === "init")  { game = new Game(new Pet(+args[1], +args[2], +args[3])); }
        else if (args[0] === "show")  { write(game.toString());                                            }
        else if (args[0] === "play")  { game.play();                                                       }
        else if (args[0] === "eat")   { game.eat();                                                        }
        else if (args[0] === "sleep") { game.sleep();                                                      }
        else if (args[0] === "shower"){ game.shower();                                                     }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();