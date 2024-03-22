import {  Pessoa } from "./pessoa";
import { Motoca } from "./motoca";


let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let moto = new Motoca();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "show")  { write(moto.toString());         }
        else if (args[0] === "init")  { moto = new Motoca(+args[1]);    }
        else if (args[0] === "enter") { moto.inserir(new Pessoa(args[1], +args[2])); }
        else if (args[0] === "leave") { 
            let aux = moto.remover();
            if (aux !== null) {
                write(aux);
            }
        }
        else if (args[0] === "honk")  { write(moto.buzinar());          }
        else if (args[0] === "buy")   { moto.comprarTempo(+args[1]);    }
        else if (args[0] === "drive") { moto.drive(+args[1]);           }
        else if (args[0] === "end")   { break;                          }
        else                          { write("fail: comando invalido");}
    }
}

main()