import {Adapter} from "./adapter";
import {Lead} from "./lead";

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

        if      (args[0] === "init")  { adp = new Adapter(+args[1]);                                    }
        else if (args[0] === "show")  { write(adp.toString());                                         }
        else if (args[0] === "insert"){ adp.insert(+args[1], args[2], +args[3]);             }
        else if (args[0] === "remove"){ adp.remove();                                                  }
        else if (args[0] === "write") { adp.writePage();                                               }
        else if (args[0] === "end")   { break;                                                            }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();


