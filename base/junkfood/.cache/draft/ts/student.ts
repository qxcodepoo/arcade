class Adapter {
    // private machine: Machine;
    constructor(qtd: number) {
        // this.machine = new Machine(qtd);
    }

    setSlot(indice: number, name: string, qtd: number, price: number): void {
        // this.machine.setSlot(indice, name, qtd, price);
    }

    limpar(indice: number): void {
        // this.machine.limpar(indice);
    }
    
    inserirDinheiro(value: number): void {
        // this.machine.inserirDinheiro(value);
    }

    pedirTroco(): number {
        // return this.machine.pedirTroco();
        return 0;
    }

    comprar(ind: number): void {
        // this.machine.comprar(ind);
    }

    show(): void {
        // console.log(this.machine.toString());
    }

}

export {Adapter};