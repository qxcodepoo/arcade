
class Pessoa {
    private nome: string;
    constructor(nome: string) {
    }
    public getNome(): string {
    }
    public setNome(nome: string): void {
    }
}

class Mercantil {
    caixas: Array<Pessoa | null>;
    espera: Array<Pessoa>;

    constructor(nCaixas: number) {
    }
    chegar(pessoa: Pessoa): void {
    }
    chamar(index: number) {
    }
    finalizar(index: number): void {
    }

    toString(): string {
    }
}
let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let merc = new Mercantil(0);

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if       (args[0] == "end")    { break;                            }
        else  if (args[0] == "init")   { merc = new Mercantil(+args[1]);   }
        else  if (args[0] == "show")   { write(merc.toString());           }
        else  if (args[0] == "arrive") { merc.chegar(new Pessoa(args[1])); }
        else  if (args[0] == "call")   { merc.chamar(+args[1]);            }
        else  if (args[0] == "finish") { merc.finalizar(+args[1]);         }
        else                           { write("fail: comando invalido");  }
    }
}
main() 
