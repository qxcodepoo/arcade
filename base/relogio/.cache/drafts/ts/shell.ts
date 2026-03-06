const input = () => ""; // MODO_TESTE
export {};
function main() {
    // CRIE SEU RELÓGIO AQUI
    while (true) {
        let line = input();
        console.log("$" + line);

        const args = line.split(" ");
        const cmd = args[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            // MOSTRE SEU RELÓGIO AQUI
        } else if (cmd == "init") {
            // INICIE SEU RELÓGIO AQUI UTILIZANDO O CONSTRUTOR
            // const hour = parseInt(args[1]);
            // const minute = parseInt(args[2]);
            // const second = parseInt(args[3]);
        } else if (cmd == "set") {
            // AJUSTE SEU RELÓGIO AQUI CHAMANDO OS MÉTODOS setHour, setMinute e setSecond
            // const hour = parseInt(args[1]);
            // const minute = parseInt(args[2]);
            // const second = parseInt(args[3]);
        } else if (cmd == "next") {
            // AVANCE SEU RELÓGIO AQUI CHAMANDO O MÉTODO nextSecond
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main()
