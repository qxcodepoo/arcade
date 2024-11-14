
import { Kid } from "./kid";

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
        return null;
    }


    toString(): string {
        return  "[" + this.waiting.map(kid => kid.toString()).join(", ") + "]" + " => " + 
                "[" + this.playing.map(kid => kid.toString()).join(", ") + "]";
    }
}

export { Trampoline };