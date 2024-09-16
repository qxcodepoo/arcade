import {Adapter} from "./student";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
// let input = () : string => require("readline-sync").question();
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);
export {};


function main() {
    let adp = new Adapter();

    while (true) {
        write("$", "");
        let line = input();
        write(line); // comente essa linha para rodar interativo
        let args = line.split(" ");

        if      (args[0] === "show")  { write(adp.toString());          }
        else if (args[0] === "enter") { adp.enter();                    }
        else if (args[0] === "leave") { adp.leave();                    }
        else if (args[0] === "fuel")  { adp.fuel(+args[1]);             }
        else if (args[0] === "drive") { adp.drive(+args[1]);            }
        
        else if (args[0] === "end")   { break;                          }
        else                          { write("fail: comando invalido");}
    }
}

main()
