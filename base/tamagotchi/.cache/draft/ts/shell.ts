const input = () => ""; // MODO_TESTE
export {};

function main() {
    // CRIE SEU JOGO AQUI COM UM PET ZERADO

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        } 
        // else if (cmd == "init") {
        //     // CRIE UM NOVO JOGO COM UM NOVO PET
        //     const energy = parseInt(par[1]);
        //     const clean = parseInt(par[2]);
        // } 
        // else if (cmd == "play") { 
        // } 
        // else if (cmd == "shower") { 
        // } 
        // else if (cmd == "sleep") { 
        // } 
        // else if (cmd == "show") { 
        // } 
        else {
            console.log("fail: comando invalido");
        }
    }
}

main();
