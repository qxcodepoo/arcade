
let input,write;

function main() {
    let car = new Car();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "show")  { write(car.toString());                                       }
        else if (args[0] === "enter") { car.enter();                                                 }
        else if (args[0] === "leave") { car.leave();                                                 }
        else if (args[0] === "fuel")  { car.fuel(+args[1]);                                          }
        else if (args[0] === "drive") { car.drive(+args[1]);                                         }
        else                          { write("fail: comando invalido");                             }
    }
}


main()

