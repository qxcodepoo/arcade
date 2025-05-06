const input = () => ""; // MODO_TESTE
export {};


function main() {

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "show") { //TODO
        } else if (cmd == "arrive") {
            // const name = par[1];
            // const age = parseInt(par[2]);
        } else if (cmd == "enter") {
        } else if (cmd == "leave") {
        } else if (cmd == "remove") {
            // const name = par[1];
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
