
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

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let pet = new Pet(0, 0, 0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                            }
        else if (args[0] === "init")  { pet = new Pet(Number(args[1]), Number(args[2]), Number(args[3])); }
        else if (args[0] === "show")  { write(pet.toString());                                            }
        else if (args[0] === "play")  { pet.play();                                                       }
        else if (args[0] === "eat")   { pet.eat();                                                        }
        else if (args[0] === "sleep") { pet.sleep();                                                      }
        else if (args[0] === "shower"){ pet.shower();                                                     }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();