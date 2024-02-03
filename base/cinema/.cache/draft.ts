
class Client {
    private id: string;
    private fone: string;

    constructor(id: string, fone: string) {
    }

    toString(): string {
    }

    getId(): string {
    }

    setId(id: string): void {
    }

    getFone(): string {
    }

    setFone(fone: string): void {
    }
}

class Sala {
    private cadeiras: (Client | null)[];

    constructor(capacidade: number) {
    }

    getCadeiras(): (Client | null)[] {
    }

    reservar(id: string, fone: string, ind: number): boolean {



    }

    cancelar(id: string): void {
    }

    toString(): string {
    }
}


let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let sala = new Sala(0);

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if      (args[0] == "end")      { break; }
        else if (args[0] == "init")     { sala = new Sala(+args[1]); }
        else if (args[0] == "show")     { write(sala.toString()); }
        else if (args[0] == "reservar") { sala.reservar(args[1], args[2], +args[3]); }
        else if (args[0] == "cancelar") { sala.cancelar(args[1]); }
        else                            { console.log("fail: comando invalido"); }
    }
}

main();