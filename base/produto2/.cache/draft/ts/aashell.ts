import { Adapter } from "./adapter";

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = (): string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end: string = "\n") => process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter();

    while (true) {
        let line = input();
        write("$" + line);
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