function input() { return ""; }
export {};


function main() {
    // CRIE SEU CARRO AQUI
    while(true) {
        let line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        } 
        else if (cmd == "show") {
            // MOSTRE O CARRO
        } 
        else if (cmd == "enter") {
            // TENTE EMBARCAR UMA PESSOA
        } 
        else if (cmd == "leave") {
            // TENTE DESEMBARCAR UMA PESSOA
        } 
        else if (cmd == "fuel") {
            // INCREMENTE O COMBUSTIVEL
            // const increment = parseInt(par[1]);
        } 
        else if (cmd == "drive") {
            // TENTE DIRIGIR CERTA DISTANCIA
            // const distance = parseInt(par[1]);
        } 
        else {
            console.log("fail: comando invalido");
        }
    }
}

main()
