import {Pencil} from "./pencil";
import {Lead} from "./lead";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let pencil = new Pencil(0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "init")  { pencil = new Pencil(+args[1]);                                    }
        else if (args[0] === "show")  { write(pencil.toString());                                         }
        else if (args[0] === "insert"){ pencil.insert(new Lead(+args[1], args[2], +args[3]));             }
        else if (args[0] === "remove"){ pencil.remove();                                                  }
        else if (args[0] === "write") { pencil.writePage();                                               }
        else if (args[0] === "end")   { break;                                                            }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();


