function input() { return ""; }
export {};

function main() {
    // let calc = new Calculator(0);

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];
        if (cmd == "end") {
            break;
        } 
        else if (cmd == "init") {
            // CHAME O CONSTRUTOR AQUI
            // const batteryMax = parseInt(par[1]);
        } 
        else if (cmd == "charge") {
            // RECARREGAR A BATERIA
            // const value = parseInt(par[1]);
        } 
        else if (cmd == "sum") {
            // SOMAR
            // const a = parseInt(par[1]);
            // const b = parseInt(par[2]);
        } 
        else if (cmd == "div") {
            // DIVIDIR
            // const num = parseInt(par[1]);
            // const den = parseInt(par[2]);
        } 
        else if (cmd == "show") {
            // MOSTRAR
        } 
        else {
            console.log("fail: comando invalido");
        }
    }
}

main()
