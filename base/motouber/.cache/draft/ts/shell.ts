function input() { return ""; }
export {};

function main(): void {
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "show") { // TODO
        } else if (cmd == "setDriver") { // TODO
            // const name = par[1];
            // const money = parseInt(par[2]);
        } else if (cmd == "setPass") { // TODO
            // const name = par[1];
            // const money = parseInt(par[2]);
        } else if (cmd == "drive") { // TODO
            // const distance = parseInt(par[1]);
        } else if (cmd == "leavePass") { // TODO
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: command not found");
        }
    }
}

main();
