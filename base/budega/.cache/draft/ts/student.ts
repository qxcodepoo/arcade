class Adapter {
    constructor(nCaixas: number) {
    }

    arrive(nome: string): void {
    }

    call(index: number): void {
    }

    finish(index: number): void {
    }

    show(): string {
        return "";
    }
}

if (require.main === module) {
    console.log("Rodando o arquivo do estudante");
}

export { Adapter };