function input() { return ""; };
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

function main(): void {
    let animal: Animal = new Animal("", "");
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(' ');
        const cmd = par[0];
        
        if (cmd === "init") {
            let species = par[1];
            let noise = par[2];
            animal = new Animal(species, noise);
        } else if (cmd === "grow") {
            let increment = +par[1];
            animal.ageBy(increment); 
        } else if (cmd === "noise") {
            console.log(animal.makeNoise());
        } else if (cmd === "show") {
            console.log(animal.toString());
        } else if (cmd === "end") { 
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();