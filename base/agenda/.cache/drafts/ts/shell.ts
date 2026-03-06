const input = () => ""; // MODO_TESTE
export {};


function main(): void {
    while (true) {
        let line = input();
        console.log("$" + line);
        
        let args = line.split(" ");
        
        if (args[0] === "end") {
            break;
        } else if (args[0] === "add") {//name id:fone id:fone ...
            // const name = args[1];
            // const fones: Fone[] = [];
            // for (let i = 2; i < args.length; i++) {
            //     const [label, number] = args[i].split(':');
            //     fones.push(new Fone(label, number));
            // }
        } else if (args[0] === "show") {
        } else if (args[0] === "rmFone") {//id index
            // const id = args[1];
            // const index = parseInt(args[2]);
        } else if (args[0] === "rm") {
            const name = args[1];
        } else if (args[0] === "tfav") {
            // const id = args[1];
        } else if (args[0] === "search") {//pattern
            // const pattern = args[1];
        } else if (args[0] === "favs") {
        } else {
            console.log("fail: comando invalido");
        }
    }
}


main();
