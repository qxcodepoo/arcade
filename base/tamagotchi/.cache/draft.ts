// import {write, main} from "./shell"

export class Pet {
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

    private testAlive(): boolean {
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
    public shower() {
    }
    public eat() {
    }
    public sleep() {
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

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let pet = new Pet(0, 0, 0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                            }
        else if (args[0] === "init")  { pet = new Pet(+args[1], +args[2], +args[3]); }
        else if (args[0] === "show")  { write(pet.toString());                                            }
        else if (args[0] === "play")  { pet.play();                                                       }
        else if (args[0] === "eat")   { pet.eat();                                                        }
        else if (args[0] === "sleep") { pet.sleep();                                                      }
        else if (args[0] === "shower"){ pet.shower();                                                     }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();