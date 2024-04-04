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
        write("$" + line);

        if       (args[0] == "end")    { break;                            }    
        else if (args[0] == "init")   { adp.init(+args[1]);                }
        else if (args[0] == "show")   { write(adp.show());                 }
        else if (args[0] == "arrive") { adp.arrive(args[1]);               }
        else if (args[0] == "call")   { adp.call(+args[1]);                }
        else if (args[0] == "finish") { adp.finish(+args[1]);              }
        else                          { write("fail: comando invalido");   }
    }
}
main() 
