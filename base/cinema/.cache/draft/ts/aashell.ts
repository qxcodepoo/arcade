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

        if      (args[0] == "end")      { break; }
        else if (args[0] == "init")     { adp = new Adapter(+args[1]); }
        else if (args[0] == "show")     { write(adp.toString()); }
        else if (args[0] == "reservar") { adp.reservar(args[1], args[2], +args[3]); }
        else if (args[0] == "cancelar") { adp.cancelar(args[1]); }
        else                            { console.log("fail: comando invalido"); }
    }
}



main();