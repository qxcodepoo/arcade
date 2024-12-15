function input() { return ""; }
export {};

function main() {
    // CRIE SUA TOALHA AQUI
    // let toalha = new Toalha();
    while (true) {
        let line = input();
        console.log("$" + line);
        
        let par = line.split(" ");
        let cmd = par[0];

        if (cmd == "criar") { // ATUALIZE SUA TOALHA UTILIZANDO O CONSTRUTOR
            // const cor = par[1];
            // const tamanho = par[2];
        } else if (cmd == "mostrar") { // MOSTRE SUA TOALHA
        } else if (cmd == "enxugar") { // CHAME O METODO ENXUGAR
            // const quantidade = +par[1];
        } else if (cmd == "seca") { // UTILIZE O METODO PARA OBTER SE ESTA SECA E IMPRIMIR SIM OU NAO
        } else if (cmd == "torcer") { // CHAME O METODO TORCER
        } else if (cmd == "end") {
            break;
        } else {
            console.log("comando invalido");
        }
    }
}

main();
