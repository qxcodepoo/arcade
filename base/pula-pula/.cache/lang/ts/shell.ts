import { Trampoline } from "./trampoline";
import { Kid } from "./kid";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let tr = new Trampoline();

    while (true) {
        let line = input();
        let args = line.split(" ");
        write("$" + line);

        if      (args[0] == "end"   ) { break                                  }
        else if (args[0] == "show"  ) { write(tr.toString());                  }
        else if (args[0] == "arrive") { tr.arrive(new Kid(args[1], +args[2])); }
        else if (args[0] == "enter" ) { tr.enter();                            }
        else if (args[0] == "leave" ) { tr.leave();                            }
        else if (args[0] == "remove") { let kid = tr.removeKid(args[1]);       }
        else                          { write("fail: comando invalido");       }
    }
}

main();