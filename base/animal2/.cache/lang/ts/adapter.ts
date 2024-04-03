
class Adapter {
    // animal: Animal;
    constructor() {
        // Inicializa o objeto animal com valor vazio
    }

    // Inicia um novo animal com a espécie e barulho passados
    // com idade 0
    init(especie: string, barulho: string): void {
    }

    // Envelhece um nível
    grow(nivel: number): void {
        // envelhece um nível
        // se tiver atingido o nível 4:
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
