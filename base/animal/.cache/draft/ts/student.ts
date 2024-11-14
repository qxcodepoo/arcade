class Adapter {
    // animal: Animal = new Animal("", "");
    init(especie: string, barulho: string): void {
        // this.animal = new Animal(especie, barulho);
    }

    grow(qtd: number): void {
        // this.animal.envelhecer(qtd);
    }

    noise(): void {
        // console.log(this.animal.fazerBarulho());
    }

    // mostra a representação do animal como texto
    // no formato "{especie}:{estagio}:{barulho}"
    show(): void {
        // console.log(this.animal.toString());
    }
}

export {Adapter};
