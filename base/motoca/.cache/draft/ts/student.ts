class Student {
    // motoca: Motoca = new Motoca(1);
    init(potencia: number): void {
        // this.motoca = new Motoca(potencia);
    }

    enter(name: string, age: number): void {
        // this.motoca.inserir(new Pessoa(name, age))
    }

    leave(): void {
        // let pessoa = this.motoca.remover();
        // if (pessoa === null) {
        //     console.log("---");
        // } else {
        //     console.log(pessoa.toString());
        // }
    }

    honk(): void {
        // console.log(this.motoca.buzinar());
    }

    drive(time: number): void {
        // this.motoca.dirigir(time);
    }

    buy(time: number): void {
        // this.motoca.aumentarTempo(time);
    }
    
    show(): void {
        // console.log(this.motoca.toString());
    }
}

export {Student};
