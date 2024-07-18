import {Animal} from "./animal";

class Adapter {
    animal: Animal;

    constructor(especie: string, barulho: string) {
        this.animal = new Animal(especie, barulho);
    }

    grow(qtd: number): void {
        this.animal.envelhecer(qtd);
    }

    noise(): string {
        return this.animal.fazerBarulho();
    }

    show(): string {
        return this.animal.toString();
    }
}

export {Adapter};
