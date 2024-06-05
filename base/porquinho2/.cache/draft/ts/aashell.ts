import { Adapter } from "./adapter";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter(0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "init")  { adp = new Adapter(Number(args[1]));                          }
        else if (args[0] === "show")  { write(adp.toString());                                       }
        else if (args[0] === "addItem")   { adp.addItem(args[1], +args[2]);                          }
        else if (args[0] === "addCoin")   { adp.addCoin(+args[1]);
        }
        else if (args[0] === "extractItems") { 
            write(adp.extractItems());
        }
        else if (args[0] === "extractCoins") { 
            write(adp.extractCoins());
        }
        else if (args[0] === "break")    { adp.breakPig();                                           }
        else                             { write("fail: comando invalido");                          }
    }
}

main();