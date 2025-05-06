const input = () => ""; // MODO_TESTE
export { };

function main() {

    while (true) {
        let line = input();
        console.log("$" + line);
        let args = line.split(" ");

        if (args[0] == "end") {
            break;
        } else if (args[0] == "init") {
            const id = parseInt(args[1]);
        } else if (args[0] == "show") {
        } else if (args[0] == "withdraw") {
            const value = parseInt(args[1]);
        } else if (args[0] == "fee") {
            const value = parseInt(args[1]);
        } else if (args[0] == "reverse") {
            for (let i = 1; i < args.length; i++) {
            }
        } else if (args[0] == "deposit") {
            const value = parseInt(args[1]);
        } else if (args[0] == "extract") {
            const qtdOp = parseInt(args[1]);
        } else {
            console.log("fail: invalid command");
        }
    }
}

main();
