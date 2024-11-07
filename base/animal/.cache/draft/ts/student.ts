class Adapter {
    // animal: Animal;
    constructor(especie: string, barulho: string) {
        //Inicializa o objeto animal com os valores passados e idade 0
        // this.animal = new Animal(especie, barulho);
    }

    // Envelhece qtd níveis
    grow(qtd: number): void {
        // this.animal.envelhecer(qtd);
    }

    // retorna o barulho que o animal faz
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