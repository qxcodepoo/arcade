import {Animal} from "./animal";

class Adapter {
    animal: Animal;

    constructor(especie: string, barulho: string) {
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
