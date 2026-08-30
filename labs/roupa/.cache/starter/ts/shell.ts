const input = () => ""; // MODO_TESTE
export {};

function main(): void {
    // CRIE SEU OBJETO AQUI

    while (true) {
        const line = input();
        console.log("$" + line);

        const args = line.split(" ");
        const cmd = args[0];

        if (cmd == "size") { // TENTE ATRIBUIR UM TAMANHO A ROUPA
            // const size = args[1];
        } else if (cmd == "show") { // MOSTRE A ROUPA
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: Comando inválido");
        }
    }
}

main();
