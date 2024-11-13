import { Adapter } from "./student";


function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }


function main() {
    let adp = new Adapter(0);

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        if (args[0] === "end") {
            break;
        } else if (args[0] === "show") {
            adp.show();
        } else if (args[0] === "init") {
            adp = new Adapter(+args[1]);
        } else if (args[0] === "limpar") {
            adp.limpar(+(args[1]));
        } else if (args[0] === "dinheiro") {
            adp.inserirDinheiro(+args[1]);
        } else if (args[0] === "comprar") {
            adp.comprar(+args[1]);
        } else if (args[0] === "set") {
            adp.setSlot(+args[1], args[2], +(args[3]), +args[4]);
        } else if (args[0] === "troco") {
            console.log(`voce recebeu ${adp.pedirTroco().toFixed(2)} RS`);
        } else {
            console.log("comando invalido");
        }
    }
}

main();