function input() { return ""; }
export {};



function main() {

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd === "show") { // TODO
        } else if (cmd === "init") {
            // const seats = parseInt(par[1], 10);
        } else if (cmd === "reserve") {
            // const id = par[1];
            // const phone = par[2];
            // const index = parseInt(par[3], 10);
        } else if (cmd === "cancel") {
            // const id = par[1];
        } else if (cmd === "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();