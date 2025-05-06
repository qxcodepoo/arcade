const input = () => ""; // MODO_TESTE
export {};

function main() {
    while (true) {
        let line = input();
        console.log("$" + line);

        var par = line.split(" ");
        var cmd = par[0];

        if (cmd == "end") {
            break;
        } 
        // else if (cmd == "show") { 
        // }
        // else if (cmd == "turn_on") { 
        // }
        // else if (cmd == "turn_off") { 
        // }
        // else if (cmd == "use") { 
        //     const minutes = parseInt(par[1]);
        // }else if (cmd == "set_charger") {
        //     // CRIE UM CARREGADOR COM A POTÊNCIA INFORMADA E CONECTE AO NOTEBOOK
        //     const power = parseInt(par[1]);
        // }
        // else if (cmd == "rm_charger") {
        //     // REMOVA O CARREGADOR DO NOTEBOOK E O IMPRIMA
        // } 
        // else if (cmd == "set_battery") {
        //     // CRIE UMA BATERIA COM A CAPACIDADE INFORMADA E CONECTE AO NOTEBOOK
        //     const capacity = parseInt(par[1]);
        // } 
        // else if (cmd == "rm_battery") {
        //     // REMOVA A BATERIA DO NOTEBOOK E A IMPRIMA
        // } 
        else {
            console.log("fail: comando inválido");
        }
    }
}

main();
