function input() { return ""; }
export {};


function main() {
    while (true) {
        let line = input();
        console.log("$" + line);
        
        let args = line.split(" ");
        let cmd = args[0];

        if (cmd == "show") {
        } else if (cmd == "init") {
            // let qtd_espirais = parseInt(args[1]);
        } else if (cmd == "limpar") {
            // let indice = parseInt(args[1]);
        } else if (cmd == "dinheiro") {
            // let value = parseFloat(args[1]);
        } else if (cmd == "comprar") {
            // let ind = parseInt(args[1]);
        } else if (cmd == "set") {
            // let indice = parseInt(args[1]);
            // let nome = args[2];
            // let qtd = parseInt(args[3]);
            // let preco = parseFloat(args[4]);
        } else if (cmd == "troco") {
            // let troco = machine.pedirTroco();
        } else if (cmd == "end") {
            break;
        } else {
            console.log("comando invalido");
        }
    }
}

main();