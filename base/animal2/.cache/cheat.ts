
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

class Adapter {
    animal: Animal;
    constructor() {
        this.animal = new Animal("", "");
    }

    init(especie: string, barulho: string): void {
        this.animal = new Animal(especie, barulho);
    }

    grow(nivel: number): void {
        this.animal.envelhecer(nivel);
    }

    noise(): string {
        return this.animal.fazerBarulho();
    }

    show(): string {
        return this.animal.toString();
    }
}

export {Adapter};
