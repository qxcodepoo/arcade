let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

class Animal {
    especie: string;
    barulho: string;
    estagio: number;

    constructor(especie: string, barulho: string) {
        this.especie = especie;
        this.barulho = barulho;
        this.estagio = 0;
    }

    fazerBarulho(): string {
        if (this.estagio === 0) {
            return "---";
        }
        if (this.estagio === 4) {
            return "RIP";
        }
        return this.barulho;
    }

    envelhecer(nivel: number): void {
        this.estagio += nivel;
        if (this.estagio >= 4) {
            write(`warning: ${this.especie} morreu`);
            this.estagio = 4;
        }
    }

    toString(): string {
        return `${this.especie}:${this.estagio}:${this.barulho}`;
    }
}

function main(): void {
    let animal: Animal = new Animal("", "");

    while (true) {
        const line: string = input();
        const args: string[] = line.split(' ');
        write("$" + line);

        if (args[0] === "init") {
            animal = new Animal(args[1], args[2]);
        } else if (args[0] === "grow") {
            animal.envelhecer(+args[1]);
        } else if (args[0] === "noise") {
            write(animal.fazerBarulho());
        } else if (args[0] === "show") {
            write(animal);
        } else if (args[0] === "end") {
            break;
        } else {
            write("fail: comando invalido");
        }
    }
}

main();
