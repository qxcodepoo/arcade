import {Adapter} from "./adapter";


let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter(1);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                          }
        
        else if (args[0] === "show")  { write(adp.toString());          }
        else if (args[0] === "init")  { adp = new Adapter(+args[1]);    }
        else if (args[0] === "enter") { adp.enter(args[1], +args[2]);   }
        else if (args[0] === "leave") { write(adp.leave());             }
        else if (args[0] === "honk")  { write(adp.honk());              }
        else if (args[0] === "buy")   { adp.buy(+args[1]);              }
        else if (args[0] === "drive") { adp.drive(+args[1]);            }

        else                          { write("fail: comando invalido");}
    }
}

main()