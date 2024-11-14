class Adapter {
    constructor(capacidade: number) {
        this.sala = new Sala(capacidade);
    }

    reservar(id: string, fone: number, ind: number): void {
        this.sala.reservar(id, fone, ind);
    }

    cancelar(id: string): void {
        this.sala.cancelar(id);
    }

    toString(): string {
        return this.sala.toString();
        return "";
    }

}

export {Adapter};