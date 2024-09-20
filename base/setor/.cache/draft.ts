
function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};

function main() {
    let bilheteria = new Bilheteria();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // _TEST_ONLY_
        let args = line.split(" ");

        try {
            if (args[0] === "end")   { 
                break;                                                       
            } else if (args[0] === "addPessoa") {
                bilheteria.addPessoa(args[1], args[2] === "meia");
            } else if (args[0] === "addEvento") {
                bilheteria.addEvento(args[1]);
            } else if (args[0] === "addSetor") {
                bilheteria.addSetor(args[1], args[2], +args[3]);
            } else if (args[0] === "pessoas") {
                write("[" + bilheteria.getPessoas().map(p => p.toString()).join(", ") + "]");
            } else if (args[0] === "eventos") {
                write(bilheteria.getEventos().map(e => e.toString()).join("\n"));
            } else if (args[0] === "vender") {
                bilheteria.vender(args[1], args[2], args[3]);
            } else if (args[0] === "vendas") {
                write(bilheteria.getVendas().map(v => v.toString()).join("\n"));
            } else { 
                write("fail: comando invalido");
            }
        } catch (e) {
            write(e.message);
        }
    }
}


main();