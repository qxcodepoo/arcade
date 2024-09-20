import {CarAdp} from "./student";

function input(): string { let X: any = input; X.L = X.L || require("fs").readFileSync(0).toString().split(/\r?\n/); return X.L.shift(); } // _TEST_ONLY_
// function input(): string { let X: any = input; X.P = X.P || require("readline-sync"); return X.P.question() } // _FREE_ONLY_
function write(text: any, endl="\n") { process.stdout.write("" + text + endl); }
export {};



function testeEntrando() {
    const car = new CarAdp();
    console.log("$Carro criado");
    console.log(car.show());
    console.log("$Entrando no carro");
    car.enter();
    console.log(car.show());
    console.log("$Entrando no carro");
    car.enter();
    console.log(car.show());
    console.log("$Entrando no carro");
    car.enter();
    console.log(car.show());
}

function testeSaindo() {
    const car = new CarAdp();
    console.log("$Carro criado");
    console.log(car.show());
    console.log("$Entrando 2 pessoas no carro");
    car.enter();
    car.enter();
    console.log(car.show());
    console.log("$Saindo do carro");
    car.leave();
    console.log(car.show());
    console.log("$Saindo do carro");
    car.leave();
    console.log(car.show());
    console.log("$Saindo do carro");
    car.leave();
    console.log(car.show());
}

function testeAbastecendo() {
    const car = new CarAdp();
    console.log("$Carro criado");
    console.log(car.show());
    console.log("$Abastecendo 10 litros");
    car.fuel(10);
    console.log(car.show());
    console.log("$Abastecendo 30 litros");
    car.fuel(30);
    console.log(car.show());
    console.log("$Abastecendo 100 litros");
    car.fuel(100);
    console.log(car.show());
}

function testeDirigindo() {
    const car = new CarAdp();
    console.log("$Carro criado");
    console.log(car.show());
    console.log("$Tentando dirigir com carro vazio");
    car.drive(10);
    console.log(car.show());
    console.log("$Entrando no carro");
    car.enter();
    console.log(car.show());
    console.log("$Testando dirigir sem gasolina");
    car.drive(10);
    console.log(car.show());
    console.log("$Abastecendo 30 litros");
    car.fuel(30);
    console.log(car.show());
    console.log("$Testando dirigir com gasolina");
    car.drive(10);
    console.log(car.show());
    console.log("$Testando dirigir só parte do caminho");
    car.drive(50);
    console.log(car.show());
}

function main() {
    let cmd = input()
    switch (cmd) {
        case "entrando":
            testeEntrando();
            break;
        case "saindo":
            testeSaindo();
            break;
        case "abastecendo":
            testeAbastecendo();
            break;
        case "dirigindo":
            testeDirigindo();
            break;
        default:
            console.log("Comando não reconhecido.");
            break;
    }
}

main();
