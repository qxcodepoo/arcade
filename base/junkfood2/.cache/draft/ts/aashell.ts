import { Adapter } from "./adapter";


let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);


function main() {
    let adp = new Adapter(0);

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if (args[0] === "end") {
            break;
        } else if (args[0] === "show") {
            console.log(adp.toString());
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