import { Pessoa } from "./pessoa";
class Motoca {
    potencia:number = 1;
    time: number = 0;
    pessoa: Pessoa | null;

    constructor(potencia: number = 1) {
    }

    inserir(pessoa: Pessoa): boolean {
    }

    remover() : Pessoa | null {
    }
    buzinar(): string {
    }

    drive(time: number): void {
    }

    comprarTempo(value: number) {
    }

    public toString(): string {
        let valor = this.pessoa === null ? "empty" : "" + this.pessoa;
        return `power:${this.potencia}, time:${this.time}, person:(${valor})`;
    }
}

export { Motoca };