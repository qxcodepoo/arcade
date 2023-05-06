
let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);


class Fone { //todo
  private id: string;
  private number: string;

  constructor(id: string = "", number: string = "") { //todo
    this.id = id;
    this.number = number;
  }

  getId(): string { //todo
    return this.id;
  }

  getNumber(): string { //todo
    return this.number;
  }

  isValid(): boolean { //todo
    const valid = "0123456789()-.";
    for (const c of this.number) { //todo
      if (!valid.includes(c)) { //todo
      }
    }
    return true;
  }

  toString(): string { //todo
    return `${this.id}:${this.number}`;
  }
}

class Contact { //todo
  private name: string;
  private favorited: boolean;
  private fones: Fone[];

  constructor(name: string = "") { //todo
    this.name = name;
    this.favorited = false;
    this.fones = [];
  }

  getName(): string { //todo
    return this.name;
  }

  getFones(): Fone[] { //todo
    return this.fones;
  }

  addFone(id: string, number: string): void { //todo
    const fone = new Fone(id, number);
    if (fone.isValid()) { //todo
      this.fones.push(new Fone(id, number));
    } else { //todo
      write("fail: invalid number");
    }
  }

  rmFone(index: number): void { //todo
    if (index < 0 || index >= this.fones.length) { //todo
      return;
    }
    this.fones.splice(index, 1);
  }

  toogleFavorited(): void { //todo
    this.favorited = !this.favorited;
  }

  isFavorited(): boolean { //todo
    return this.favorited;
  }

  toString(): string { //todo
    return `${this.favorited ? "@" : "-"} ${this.name} [${this.fones.join(", ")}]`;
  }
}


function main() {
    let contato = new Contact();
    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if (args[0] === "end") {
            break;
        } else if (args[0] === "init") {
            contato = new Contact(args[1]);
        } else if (args[0] === "add") {
            contato.addFone(args[1], args[2]);
        } else if (args[0] === "rm") {
            contato.rmFone(+args[1]);
        } else if (args[0] === "tfav") {
            contato.toogleFavorited();
        } else if (args[0] === "show") {
            write(contato);
        } else {
            write("fail: comando invalido");
        }
    }
}

main();