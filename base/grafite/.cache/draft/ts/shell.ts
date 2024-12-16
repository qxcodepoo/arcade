function input() { return ""; }
export {};

function main() {

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "init") { // TODO
            // const thickness = parseFloat(par[1]);
        } else if (cmd == "show") { // TODO
        } else if (cmd == "insert") { // TODO
            // const thickness = parseFloat(par[1]);
            // const hardness = par[2];
            // const size = parseInt(par[3]);
        } else if (cmd == "remove") { // TODO
        } else if (cmd == "write") { // TODO
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
