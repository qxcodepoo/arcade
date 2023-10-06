import {Pet} from "./solver"
// import { readFileSync } from "fs";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
export let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
export let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

export function main() {
    let pet = new Pet(0, 0, 0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                            }
        else if (args[0] === "init")  { pet = new Pet(+args[1], +args[2], +args[3]); }
        else if (args[0] === "show")  { write(pet.toString());                                            }
        else if (args[0] === "play")  { pet.play();                                                       }
        else if (args[0] === "eat")   { pet.eat();                                                        }
        else if (args[0] === "sleep") { pet.sleep();                                                      }
        else if (args[0] === "shower"){ pet.shower();                                                     }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();