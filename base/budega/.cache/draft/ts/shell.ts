function input() { return ""; }
export {};

function main() {
    while (true) {
        const line = input();
        console.log("$" + line);

        var par = line.split(" ");
        var cmd = par[0];

        if (cmd == "show") { // TODO
        } else if (cmd == "init") { // TODO
            // const nCaixas = parseInt(par[1]);
        } else if (cmd == "arrive") { // TODO
            // const nome = par[1];
        } else if (cmd == "call") { // TODO
            // const index = parseInt(par[1]);
        } else if (cmd == "finish") { // TODO
            // const index = parseInt(par[1]);
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}
main() 
