import {Time} from "./time";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let time = new Time(0, 0, 0);

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if (args[0] === "show") { 
            write(time.toString());
        }
        else if (args[0] === "init") {
            time = new Time(+args[1], +args[2], +args[3]);
        }
        else if (args[0] === "set") { 
            time.setHour(+args[1]);
            time.setMinute(+args[2]);
            time.setSecond(+args[3]);
        }
        else if (args[0] === "next") {
            time.nextSecond();
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

