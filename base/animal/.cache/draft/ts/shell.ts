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
            // INICIE O ANIMAL UTILIZANDO O CONSTRUTOR
            // let species = par[1];
            // let noise = par[2];
        } else if (cmd === "grow") {
            // AUMENTE A IDADE DO ANIMAL
            // let increment = +par[1];
        } else if (cmd === "noise") {
            // OBTENHA O BARULHO DO ANIMAL E IMPRIMA
        } else if (cmd === "show") {
            // IMPRIMA O ANIMAL
        } else if (cmd === "end") { 
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();
