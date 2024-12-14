function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }


function main() {
    while (true) {
        let line = input();
        let args = line.split(" ");
        let action = args[0];
        write("$" + line);

        if (action == "show") {
        } else if (action == "init") {
            // let qtd_espirais = parseInt(args[1]);
        } else if (action == "limpar") {
            // let indice = parseInt(args[1]);
        } else if (action == "dinheiro") {
            // let value = parseFloat(args[1]);
        } else if (action == "comprar") {
            // let ind = parseInt(args[1]);
        } else if (action == "set") {
            // let indice = parseInt(args[1]);
            // let nome = args[2];
            // let qtd = parseInt(args[3]);
            // let preco = parseFloat(args[4]);
        } else if (action == "troco") {
            // let troco = machine.pedirTroco();
        } else if (action == "end") {
            break;
        } else {
            console.log("comando invalido");
        }
    }
}

main();