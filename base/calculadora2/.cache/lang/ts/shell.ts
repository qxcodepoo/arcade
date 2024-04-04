import { Adapter } from "./adapter";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter();

    while (true) {
        let line = input();
        let args = line.split(" ");
        console.log("$" + line);

        if      (args[0] == "show"  ) { console.log(adp.show());                     }
        else if (args[0] == "init"  ) { adp.init(+args[1]);                          }
        else if (args[0] == "charge") { adp.charge(+args[1]);                        }
        else if (args[0] == "sum"   ) { adp.sum(+args[1], +args[2]);                 }
        else if (args[0] == "div"   ) { adp.div(+args[1], +args[2]);                 }
        else if (args[0] == "end"   ) { break;                                       }
        else                          { console.log("fail: comando nao encontrado"); }
    }
}

main()
