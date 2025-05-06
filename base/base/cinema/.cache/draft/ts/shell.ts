const input = () => ""; // MODO_TESTE
export {};



function main() {

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd === "end") {
            break;
        } else if (cmd === "show") { 
        } else if (cmd === "init") {
            // const seats = parseInt(par[1], 10);
        } else if (cmd === "reserve") {
            // const id = par[1];
            // const phone = parseInt(par[2]);
            // const index = parseInt(par[3], 10);
        } else if (cmd === "cancel") {
            // const id = par[1];
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
