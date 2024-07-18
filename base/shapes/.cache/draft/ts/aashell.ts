import { Adapter } from "./adapter";

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "show")  { console.log(adp.toString())                                  }   
        else if (args[0] === "circle") {
            adp.circle(+args[1], +args[2], +args[3]);
        }
        else if (args[0] === "rect") {
            adp.rectange(+args[1], +args[2], +args[3], +args[4]);
        }
        else if (args[0] === "info") {
            console.log(adp.info());
        }
        else {
            write("fail: invalid command");
        }
    }
}

main();