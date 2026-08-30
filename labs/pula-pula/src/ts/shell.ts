const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Kid {
    private age: number;
    private name: string;

    constructor(name: string, age: number) {
        this.age = age;
        this.name = name;
    }

    getAge(): number {
        return this.age;
    }

    getName(): string {
        return this.name;
    }

    toString(): string {
        return this.name + ":" + this.age.toString();
    }
}

class Trampoline {
    private waiting: Kid[] = [];
    private playing: Kid[] = [];

    Trampoline() {
    }

    private removeFromList(name: string, list: Kid[]): Kid | null {
        for (let i = 0; i < list.length; i++) {
            if (list[i].getName() === name) {
                const kid = list.splice(i, 1)[0];
                return kid;
            }
        }
        return null;
    }

    arrive(kid: Kid): void {
        this.waiting.unshift(kid);
    }

    enter(): void {
        if (this.waiting.length === 0) {
            return;
        }
        this.playing.unshift(this.waiting.pop()!);
    }

    leave(): void {
        if (this.playing.length === 0) {
            return;
        }
        this.waiting.unshift(this.playing.pop()!);
    }

    removeKid(name: string): Kid | null {
        let kid = this.removeFromList(name, this.waiting);
        if (kid !== null) {
            return kid;
        }
        kid = this.removeFromList(name, this.playing);
        if (kid !== null) {
            return kid;
        }
        return null;
    }


    toString(): string {
        return  "[" + this.waiting.map(kid => kid.toString()).join(", ") + "]" + " => " + 
                "[" + this.playing.map(kid => kid.toString()).join(", ") + "]";
    }
}

// @KEEP

function main() {
    // @DROP
    let trampoline = new Trampoline();
    // @KEEP

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        } else if (cmd == "show") { //TODO
            // @DROP
            console.log(trampoline.toString());
        } else if (cmd == "arrive") {
            // @COM
            const name = par[1];
            const age = parseInt(par[2]);
            // @DROP
            trampoline.arrive(new Kid(name, age));
        } else if (cmd == "enter") {
            // @DROP
            trampoline.enter();
        } else if (cmd == "leave") {
            // @DROP
            trampoline.leave();
        } else if (cmd == "remove") {
            // @COM
            const name = par[1];
            // @DROP
            const kid = trampoline.removeKid(name);
            if (kid === null) {
                console.log("fail: " + name + " nao esta no pula-pula");
            }
        } else {
            console.log("fail: comando invalido");
        }
    }
}

main();