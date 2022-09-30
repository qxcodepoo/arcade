import {evaluate, puts} from "./shell"

class Pessoa { //todo
    private age: number;
    private name: string;

    public constructor(name: string, age: number) { //todo
    }
    public getAge(): number { //todo
    }
    public getname(): string { //todo
    }
    public toString(): string { //todo
    }
}

class Motoca { //todo
    potencia:number = 1;
    time: number = 0;
    pessoa: Pessoa | null;

    constructor(potencia: number = 1) { //todo
    }

    buzinar(): string { //todo
    }

    inserir(pessoa: Pessoa): boolean { //todo
    }

    remover() : Pessoa | null { //todo
    }

    drive(time: number): void { //todo
    }

    comprarTempo(value: number) { //todo
    }

    public toString(): string {
        return `power:${this.potencia}, time:${this.time}, person:` +
            "(" +  (this.pessoa === null ? "empty" : "" + this.pessoa) + ")";
    }
}

function main() {
    let chain = new Map();
    let param: string[] = [];
    let moto = new Motoca();

    chain.set("init", () => moto = new Motoca(+param[1]));
    chain.set("show", () => console.log("" + moto));
    chain.set("enter", () => moto.inserir(new Pessoa(param[1], +param[2])));
    chain.set("honk", () => console.log(moto.buzinar()));
    chain.set("leave", () => {
        let person = moto.remover();
        if (person !== null)
            console.log("" + person);
    });
    chain.set("drive", () => moto.drive(+param[1]));
    chain.set("buy", () => moto.comprarTempo(+param[1]));
    
    evaluate(chain, param);
}

main()