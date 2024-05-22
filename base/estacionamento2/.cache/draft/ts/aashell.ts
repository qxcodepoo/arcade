import { Adapter } from "./adapter";

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end") { 
            break;                                                       
        }
        else if (args[0] === "show") { 
            console.log(adp.toString());                                 
        }
        else if (args[0] === "estacionar") {
            adp.estacionar((args[1]), args[2]);
        }
        else if (args[0] === "tempo") {
            adp.passarTempo(+args[1]);
        }
        else if (args[0] === "pagar") {
            adp.pagar(args[1]);
            adp.sair(args[1]);
        }
        else {
            console.log("fail: comando invalido");
        }
    }
}

main();