class Adapter {
    // crie um atributo animal do tipo Animal
    // animal: Animal;
    // Inicia um novo animal com a espécie e barulho passados
    // com idade 0
    constructor(especie: string, barulho: string) {
        // Inicializa o objeto animal com os valores passados
    }

    // Envelhece um nível
    grow(qtd: number): void {
        // envelhece o animal de qtd niveis
        // se ja estiver morrto ou tiver atingido o nível 4:
        //     exibe uma mensagem de aviso
        //     e impede de ir para o nível 5
    }

    // retorna o barulho que o animal faz
    noise(): string {
        // retorna o barulho que o animal faz
        // se o animal estiver com idade 0, retorna ---
        // se o animal estiver com idade 4, retorna RIP
        // caso contrário, retorna o barulho do animal
        return "";
    }

    // retorna a representação do animal como texto
    // no formato "{especie}:{estagio}:{barulho}"
    show(): string {
        return "";
    }
}

export {Adapter};
