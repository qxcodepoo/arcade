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
            console.log(`warning: ${this.especie} morreu`);
            this.estagio = 4;
        }
    }

    toString(): string {
        return `${this.especie}:${this.estagio}:${this.barulho}`;
    }
}

export {Animal};
