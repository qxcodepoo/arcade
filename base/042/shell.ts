import { readFileSync } from "fs";

let __lines = readFileSync(0).toString().split("\n");
let input = () => { 
    let a = __lines.shift(); 
    return a === undefined ? "" : a; 
};
export let write = (text: any) => process.stdout.write("" + text);
export let puts = (text: any) => console.log(text);

export function evaluate(chain: Map<string, Function>, ui: string[]) {
    while (true) {
        let line = input();
        puts("$" + line);
        ui.splice(0); //apagar tudo
        line.split(" ").forEach((x: string) => ui.push(x));

        let cmd = ui[0];
        if (cmd == "end") {
            return;
        } else if (chain.has(cmd)) {
            chain.get(cmd)!();
        } else {
            puts("fail: command not found");
        }
    }
}
