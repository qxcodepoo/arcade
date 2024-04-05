import { Adapter } from "./adapter";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);


function main(): void {
    let adp: Adapter = new Adapter("", "");

    while (true) {
        const line: string = input();
        const args: string[] = line.split(' ');
        write("$" + line);

        if (args[0] === "init") {
            adp = new Adapter(args[1], args[2]);
        } 
        else if (args[0] === "grow") {
            adp.grow(parseInt(args[1]));
        }
        else if (args[0] === "noise") {
            write(adp.noise());
        }
        else if (args[0] === "show") {
            write(adp.show());
        } 
        else if (args[0] === "end") {
            break;
        } 
        else {
            write("fail: comando invalido");
        }
    }
}

main();
