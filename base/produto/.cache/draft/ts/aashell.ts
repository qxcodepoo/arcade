import { Adapter } from "./adapter";

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

        if (args[0] === "end") {
            break;
        }
        else if (args[0] === "add") {
            let label = args[1];
            let preco = +args[2];
            adp.addProduct(label, preco);
        }
        else if (args[0] === "addPacote") {
            let indexes = args.slice(1).map(x => +x);
            adp.addBundle(indexes);
        }
        else if (args[0] === "addDesconto") {
            let index = +args[1];
            let desconto = +args[2];
            adp.addDiscount(index, desconto);
        }
        else if (args[0] === "show") {
            write(adp.toString());
        }
        else {
            write("fail: comando invalido");
        }
    }
}

main();