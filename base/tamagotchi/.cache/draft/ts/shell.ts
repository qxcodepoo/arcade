function input() { return ""; }
export {};

function main() {
    // CRIE SEU JOGO AQUI COM UM PET ZERADO

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "init") {
            // CRIE UM NOVO JOGO COM UM NOVO PET
            // const energy = parseInt(par[1]);
            // const clean = parseInt(par[2]);
        } else if (cmd == "play") { // TODO
        } else if (cmd == "shower") { // TODO
        } else if (cmd == "sleep") { // TODO
        } else if (cmd == "show") { // TODO
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
