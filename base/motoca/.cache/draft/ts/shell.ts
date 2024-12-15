function input() { return ""; }
export {};

function main() {
    //CRIE SUA MOTO AQUI

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "init") {
            // INICIE SUA MOTO USANDO O CONSTRUTOR
            // const power = parseInt(par[1]);
        } else if (cmd == "show") {
            // MOSTRE O ESTADO DA MOTO
        } else if (cmd == "enter") {
            // CRIE UM OBJETO PESSOA E INSIRA NA MOTO
            // const name = par[1];
            // const age = parseInt(par[2]);
        } else if (cmd == "leave") {
            // REMOVA A PESSOA DA MOTO
            // SE O OBJETO RETORNADO NÃO FOR NULO, MOSTRE SEUS DADOS
        } else if (cmd == "honk") {
            // TOQUE A BUZINA
        } else if (cmd == "buy") {
            // COMPRE TEMPO DE USO DA MOTO
            // const time = parseInt(par[1]);
        } else if (cmd == "drive") {
            // DIRIJA A MOTO
            // const time = parseInt(par[1]);
        } else if (cmd == "end") {
            break;
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main()