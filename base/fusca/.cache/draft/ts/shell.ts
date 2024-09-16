import {CarAdp} from "./student";

let _cin_ : string[] = [];
try { _cin_ = require("fs").readFileSync(0).toString().split(/\r?\n/); } catch(e){}
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
// let input = () : string => require("readline-sync").question();
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);
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
