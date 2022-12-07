let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let vet = new Array<string>();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "push")  { 
            for (let i = 1; i < args.length; i++) { 
                vet.push(args[i]); 
            } 
        }
        else if (args[0] === "show")  { write ("[" + vet.join(", ") + "]");                          }
        else if (args[0] === "erase") { vet.splice(+args[1], 1);                                     }
        else                          { write("fail: comando invalido");                             }
    }
}

main();