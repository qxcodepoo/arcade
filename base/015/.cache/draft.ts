
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

class Agenda { //todo
    private contatos: Contact[];
    constructor() { //todo
    }
    private findContact(name: string): number { //todo
    }
    addContact(name: string, fones: Fone[]): void { //todo
    }
    rmContact(name: string): void { //todo
    }
    getContact(name: string): Contact | null { //todo
    }
    getContacts(): Contact[] { //todo
    }
    getFavorited(): Contact[] { //todo
      return this.contatos.filter((contact) => contact.isFavorited());
    }
    search(pattern: string): Contact[] { //todo
    }
    toString(): string { //todo
    }
}

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main(): void {
  const agenda = new Agenda();
  while (true) {
      let line = input();
      write("$" + line);
      let args = line.split(" ");
      
      if (args[0] === "end") {
          break;
      } else if (args[0] === "add") {//name id:fone id:fone ...
          const fones: Fone[] = [];
          for (let i = 2; i < args.length; i++) {
              const parts: string[] = args[i].split(':');
              fones.push(new Fone(parts[0], parts[1]));
          }
          agenda.addContact(args[1], fones);
      } else if (args[0] === "show") {
          write(agenda.toString());
      } else if (args[0] === "rmFone") {//id index
          const contato: Contact | null = agenda.getContact(args[1]);
          if (contato !== null) {
              contato.rmFone(Number(args[2]));
          }
      } else if (args[0] === "rm") {//id
          agenda.rmContact(args[1]);
      } else if (args[0] === "tfav") {
          const contato: Contact | null = agenda.getContact(args[1]);
          if (contato !== null) {
              contato.toogleFavorited();
          }
      } else if (args[0] === "search") {//pattern
          write(agenda.search(args[1]).join("\n"));
      } else if (args[0] === "favs") {//pattern
        write(agenda.getFavorited(args[1]).join("\n"));
      } else {
          write("fail: comando invalido");
      }
  }
}


main();