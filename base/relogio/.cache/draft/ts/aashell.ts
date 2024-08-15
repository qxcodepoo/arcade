import { Adapter } from "./adapter";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let adp = new Adapter();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if (args[0] === "show") { 
            write(adp.toString());
        }
        else if (args[0] == "init") { 
            adp = new Adapter(+args[1], +args[2], +args[3]);
        }
        else if (args[0] === "set") { 
            adp.setHour(+args[1]);
            adp.setMinute(+args[2]);
            adp.setSecond(+args[3]);
        }
        else if (args[0] === "next") {
            adp.nextSecond();
        }
        else if (args[0] === "end")   {
            break;
        }
        else {
            write("fail: comando invalido");
        }
    }
}

main()

