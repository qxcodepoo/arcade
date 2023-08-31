
// Nesse rascunho estão faltando os atributos e métodos
// correspondentes às funcionalidades de abastecer e dirigir o carro.


class Car{
    pass: number; // Passageiros
    passMax: number; // limite de Passageiros

    constructor() {
    }

    enter() {
    }

    leave() {
    }

    toString() {
    }
};


let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let car = new Car();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "show")  { write(car.toString());          }
        else if (args[0] === "enter") { car.enter();                    }
        else if (args[0] === "leave") { car.leave();                    }
        else if (args[0] === "end")   { break;                          }
        else                          { write("fail: comando invalido");}
    }
}

main()

