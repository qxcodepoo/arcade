import { Adapter } from "./student";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if      (args[0] === "end") { 
            break;                                                       
        }
        else if (args[0] === "show") { 
            adp.show();                                 
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