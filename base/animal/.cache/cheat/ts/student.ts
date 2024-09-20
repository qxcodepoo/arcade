import {Animal} from "./animal";
class Adapter {
    animal: Animal;
    constructor(especie: string, barulho: string) {
        this.animal = new Animal(especie, barulho);
    }

    grow(qtd: number): void {
        this.animal.envelhecer(qtd);
    }

    noise(): void {
        console.log(this.animal.fazerBarulho());
    }

    show(): void {
        console.log(this.animal.toString());
    }
}

export {Adapter};
