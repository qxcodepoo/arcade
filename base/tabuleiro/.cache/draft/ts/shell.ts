function input() { return ""; }
export {};


function main() {

    while (true) {
        let line = input();
        console.log("$" + line);

        let args = line.split(" ");
        let cmd = args[0];

        if (cmd == "init") {
            // let nPlayers = parseInt(args[1]);
            // let size = parseInt(args[2]);
        } else if (cmd == "addTrap") {
            // let pos = parseInt(args[1]);
        } else if (cmd == "roll") {
            // let value = parseInt(args[1]);
        } else if (cmd == "show") {
        } else if (cmd == "end") {
            break;
        } else {
            console.log("Comando inválido");
        }
    }
}

main()
