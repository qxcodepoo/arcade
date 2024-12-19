const input = () => ""; // MODO_TESTE
export {};

function main() {

    while (true) {
        const line = input();
        console.log("$" + line);

        const args = line.split(" ");
        const cmd = args[0];

        if (cmd === "end") {
            break;
        } else if (cmd === "show") {
        } else if (cmd === "estacionar") {
            // const tipo = args[1];
            // const id = args[2];
        } else if (cmd === "tempo") {
            const tempo = +args[1];
        } else if (cmd === "pagar") {
            // CHAME OS METODOS PAGAR E SAIR
            // const id = args[1];
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
