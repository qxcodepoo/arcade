function input() { return ""; }
export {};

function main() {
    // let toalha = new Toalha();
    while (true) {
        let line = input();
        console.log("$" + line);
        
        let par = line.split(" ");
        let cmd = par[0];

        if (cmd == "criar") {
            // TODO
            // const cor = par[1];
            // const tamanho = par[2];
        } else if (cmd == "enxugar") {
            // TODO
            // const quantidade = +par[1];
        } else if (cmd == "seca") {
            // TODO
        } else if (cmd == "torcer") {
            // TODO
        } else if (cmd == "mostrar") {
            // TODO
        } else if (cmd == "end") {
            break;
        } else {
            console.log("comando invalido");
        }
    }
}

main();
