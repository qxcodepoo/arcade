function input() { return ""; };
export {};

function main(): void {
    // let animal: Animal = new Animal("", "");
    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(' ');
        const cmd = par[0];
        
        if (cmd === "init") {
            // let species = par[1];
            // let noise = par[2];
        } else if (cmd === "grow") {
            // let increment = +par[1];
        } else if (cmd === "noise") {
        } else if (cmd === "show") {
        } else if (cmd === "end") { 
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
