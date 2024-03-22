import { Pessoa } from "./pessoa";
class Motoca {
    potencia:number = 1;
    time: number = 0;
    pessoa: Pessoa | null;

    constructor(potencia: number = 1) {
        //todo
    }

    inserir(pessoa: Pessoa): boolean {
        //todo
        return false;
    }

    remover() : Pessoa | null {
        //todo
        return null;
    }
    buzinar(): string {
    }

    drive(time: number): void {
        //todo
    }

    comprarTempo(value: number) {
        //todo
    }

    public toString(): string {
        let valor = this.pessoa === null ? "empty" : "" + this.pessoa;
        return `power:${this.potencia}, time:${this.time}, person:(${valor})`;
    }
}

export { Motoca };