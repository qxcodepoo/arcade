class Cliente {
    id: string;
    fone: number;
    toString(): string {
        return this.id + ":" + this.fone;
    }
}

class SalaDeCinema {
    cadeiras: (Cliente | undefined)[];

    constructor(capacidade: number) {
        this.cadeiras = [];
        for(let i = 0; i < capacidade; i++)
            this.cadeiras.push(undefined);
    }

    toString(): string {
        return "[" + this.cadeiras.map(x => x ? x.id : "-").join(" ") + "]";
    }

    reservar(pos: number, cliente: Cliente) {
        if(this.cadeiras[pos] == undefined)
            this.cadeiras[pos] = cliente;
        else
            throw new Error("fail: cadeira reservada para outro cliente");
    }
    
    desistir(clienteId: string) {
        let pos = this.cadeiras.findIndex(x => x ? x.id == clienteId : false);
        if(pos == -1)
            throw new Error("fail: nenhum cliente nesta cadeira");
        this.cadeiras[pos] = undefined;
    }
}

