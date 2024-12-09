function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};


class Animal {
    species: string;
    noise: string;
    age: number;
    constructor(species: string, noise: string) {
        this.species = species;
        this.noise = noise;
        this.age = 0;
    }

    makeNoise(): string {
        if (this.age === 0) {
            return "---";
        }
        if (this.age === 4) {
            return "RIP";
        }
        return this.noise;
    }

    ageBy(increment: number): void {
        this.age += increment;
        if (this.age >= 4) {
            console.log(`warning: ${this.species} morreu`);
            this.age = 4;
        }
    }

    toString(): string {
        return `${this.species}:${this.age}:${this.noise}`;
    }
}

class Adapter {
    animal: Animal = new Animal("", "");
    
    init(species: string, noise: string): void {
        this.animal = new Animal(species, noise);
    }

    grow(increment: number): void {
        this.animal.ageBy(increment);
    }

    noise(): void {
        console.log(this.animal.makeNoise());
    }

    show(): void {
        console.log(this.animal.toString());
    }
}


function main(): void {
    let adp: Adapter = new Adapter();

    while (true) {
        write("$", "");
        const line: string = input();
        const args: string[] = line.split(' ');
        write(line); //_TEST_ONLY_

        if      (args[0] === "end"  ) { break;                               }

        else if (args[0] === "init" ) { adp.init(args[1], args[2]); }
        else if (args[0] === "grow" ) { adp.grow(parseInt(args[1]));         }
        else if (args[0] === "noise") { adp.noise();                         }
        else if (args[0] === "show" ) { adp.show();                          }

        else                          { write("fail: comando invalido");     }
    }
}

main();