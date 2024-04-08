import { Pet } from "./pet";
import { Game } from "./game";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let game = new Game(new Pet(0, 0, 0));

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                            }
        else if (args[0] === "init")  { game = new Game(new Pet(+args[1], +args[2], +args[3])); }
        else if (args[0] === "show")  { write(game.toString());                                            }
        else if (args[0] === "play")  { game.play();                                                       }
        else if (args[0] === "eat")   { game.eat();                                                        }
        else if (args[0] === "sleep") { game.sleep();                                                      }
        else if (args[0] === "shower"){ game.shower();                                                     }
        else                          { write("fail: comando invalido");                                  }
    }
}

main();