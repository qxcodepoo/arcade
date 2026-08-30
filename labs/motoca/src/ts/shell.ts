const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Pessoa {
    private age: number;
    private name: string;

    public constructor(name: string, age: number) {
        this.name = name;
        this.age = age;
    }
    public getAge(): number {
        return this.age;
    }
    public getName(): string {
        return this.name;
    }
    public toString(): string {
        return `${this.name}:${this.age}`;
    }
}

class Motoca {
    potencia:number = 1;
    time: number = 0;
    pessoa: Pessoa | null;

    constructor(potencia: number = 1) {
        this.potencia = potencia;
        this.pessoa = null; 
    }

    inserir(pessoa: Pessoa): boolean {
        if (this.pessoa === null) {
            this.pessoa = pessoa;
            return true;
        }
        console.log("fail: busy motorcycle")
        return false;
    }

    remover() : Pessoa | null {
        if (this.pessoa == null) {
            console.log("fail: empty motorcycle");
            return null;
        }
        let aux = this.pessoa;
        this.pessoa = null;
        return aux;
    }
    buzinar(): string {
        return "P" + Array(this.potencia).fill("e").join("") + "m";
    }

    dirigir(time: number): void {
        if (this.time === 0) {
            console.log("fail: buy time first")
            return;
        }
        if (this.pessoa === null) {
            console.log("fail: empty motorcycle");
            return;
        }
        if (this.pessoa.getAge() > 10) {
            console.log("fail: too old to drive");
            return;
        }
        if (this.time < time) {
            console.log(`fail: time finished after ${this.time} minutes`);
            this.time = 0;
            return;
        }
        this.time -= time;
    }

    aumentarTempo(value: number) {
        this.time += value;
    }

    public toString(): string {
        let valor = this.pessoa === null ? "empty" : "" + this.pessoa;
        return `power:${this.potencia}, time:${this.time}, person:(${valor})`;
    }
}

// @KEEP
function main() {
    //CRIE SUA MOTO AQUI    
    let moto = new Motoca(); // @DROP

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        } 
        // @COM
        else if (cmd == "init") {
            // INICIE SUA MOTO USANDO O CONSTRUTOR
            const power = parseInt(par[1]);
            // @DROP
            moto = new Motoca(power);
        }
        else if (cmd == "show") {
            // MOSTRE O ESTADO DA MOTO
            // @DROP
            console.log(moto.toString());
        }
        else if (cmd == "enter") {
            // CRIE UM OBJETO PESSOA E INSIRA NA MOTO
            const name = par[1];
            const age = parseInt(par[2]);
            // @DROP
            moto.inserir(new Pessoa(name, age));
        }
        else if (cmd == "leave") {
            // REMOVA A PESSOA DA MOTO
            // SE O OBJETO RETORNADO NÃO FOR NULO, MOSTRE SEUS DADOS
            // @DROP
            const pessoa = moto.remover();
            if (pessoa !== null) {
                console.log(pessoa.toString());
            }
        }
        else if (cmd == "honk") {
            // TOQUE A BUZINA
            // @DROP
            console.log(moto.buzinar());
        }
        else if (cmd == "buy") {
            // COMPRE TEMPO DE USO DA MOTO
            const time = parseInt(par[1]);
            // @DROP
            moto.aumentarTempo(time);
        }
        else if (cmd == "drive") {
            // DIRIJA A MOTO
            const time = parseInt(par[1]);
            // @DROP
            moto.dirigir(time);
        } 
        // @KEEP
        else {
            console.log("fail: comando invalido");
        }
    }
}

main()