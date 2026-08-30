const input = () => ""; // MODO_TESTE
export {};


function main(): void {
    while (true) {
        try {
            const line = input();
            const args = line.split(" ");
            console.log("$" + line);

            if (line === "end") {
                break;
            } else if (args[0] === "show") {
            } else if (args[0] === "addCli") {
                // const clientId = args[1];
            } else if (args[0] === "saque") {
                // const idConta = +args[1];
                // const value = +args[2];
            } else if (args[0] === "deposito") {
                // const idConta = +args[1];
                // const value = +args[2];
            } else if (args[0] === "transf") {
                // const idContaDe = +args[1];
                // const idContaPara = +args[2];
                // const value = +args[3];
            } else if (args[0] === "update") {
            } else {
                console.log("fail: comando invalido");
            }
        } catch (e) {
            console.log(e.message);
        }
    }
}

main();
