import { Kid } from "./kid";

class Trampoline {
    private waiting: Kid[] = [];
    private playing: Kid[] = [];

    Trampoline() {
    }

    private removeFromList(name: string, list: Kid[]): Kid | null {
        return null;
    }

    arrive(kid: Kid): void {
    }

    enter(): void {
    }

    leave(): void {
    }

    removeKid(name: string): Kid | null {
        return null;
    }

    toString(): string {
        return  "[" + this.waiting.map(kid => kid.toString()).join(", ") + "]" + " => " + 
                "[" + this.playing.map(kid => kid.toString()).join(", ") + "]";
    }
}

export { Trampoline };