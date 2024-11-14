class Adapter {
    // private mercantil: Mercantil = new Mercantil(0);
    init(nCaixas: number) {
        // this.mercantil = new Mercantil(nCaixas);
    }

    arrive(nome: string): void {
        // this.mercantil.chegar(new Pessoa(nome));
    }

    call(index: number): void {
        // this.mercantil.chamar(index);
    }

    finish(index: number): void {
        // this.mercantil.finalizar(index);
    }

    show(): void {
        // console.log(this.mercantil.toString());
    }
}

if (require.main === module) {
    console.log("Rodando o arquivo do estudante");
}

export { Adapter };