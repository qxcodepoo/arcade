let input,write;

function main() {
    let vet = new Array<string>();

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "push")  { 
            for (let i = 1; i < args.length; i++) { 
                vet.push(args[i]); 
            } 
        }
        else if (args[0] === "show")  { write ("[" + vet.join(", ") + "]");                          }
        else if (args[0] === "erase") { vet.splice(+args[1], 1);                                     }
        else if (args[0] === "media") {
            let soma = 0;
            for (let i = 0; i < vet.length; i++) {
                soma += +vet[i];
            }
            // imprime a soma com duas casas decimais
            write((soma / vet.length).toFixed(2));
        }
        else                          { write("fail: comando invalido");                             }
    }
}

main();