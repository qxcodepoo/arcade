
let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let bilheteria = new Bilheteria();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        try {
            if (args[0] === "end")   { 
                break;                                                       
            } else if (args[0] === "addPessoa") {
                bilheteria.addPessoa(args[1], args[2] === "meia");
            } else if (args[0] === "addEvento") {
                bilheteria.addEvento(args[1], +args[2]);
            } else if (args[0] === "pessoas") {
                write("[" + bilheteria.getPessoas().map(p => p.toString()).sort().join(", ") + "]");
            } else if (args[0] === "eventos") {
                write("[" + bilheteria.getEventos().map(e => e.toString()).sort().join(", ") + "]");
            } else if (args[0] === "vender") {
                bilheteria.vender(args[1], args[2]);
            } else if (args[0] === "vendas") {
                write("[" + bilheteria.getVendas().map(v => v.toString()).join(", ") + "]");
            } else { 
                write("fail: comando invalido");
            }
        } catch (e) {
            write(e.message);
        }
    }
}

main();