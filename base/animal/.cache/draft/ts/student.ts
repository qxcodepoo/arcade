class Adapter {
    // animal: Animal;
    // Inicia um novo animal com a espécie e barulho passados
    // com idade 0
    constructor(especie: string, barulho: string) {
        // this.animal = new Animal(especie, barulho);
        // Inicializa o objeto animal com os valores passados
    }

    // Envelhece qtd níveis
    grow(qtd: number): void {
        // envelhece o animal de qtd niveis
        // se ja estiver morrto ou tiver atingido o nível 4:
        //     exibe uma mensagem de aviso
        //     e impede de ir para o nível 5
        // this.animal.envelhecer(qtd);
    }

    // retorna o barulho que o animal faz
    noise(): void {
        // retorna o barulho que o animal faz
        // se o animal estiver com idade 0, retorna ---
        // se o animal estiver com idade 4, retorna RIP
        // caso contrário, retorna o barulho do animal
        // console.log(this.animal.fazerBarulho());
    }

    // mostra a representação do animal como texto
    // no formato "{especie}:{estagio}:{barulho}"
    show(): void {
        console.log(this.animal.toString());
        return "";
    }
}

export {Adapter};
