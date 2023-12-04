class Point2D {
    x: number;
    y: number;
    constructor(x: number, y: number) {
    }
    toString(): string {
    }
}

interface Shape {
    getArea(): number;
    getPerimeter(): number;
    getName(): string;
}

class Circle implements Shape {
    private name: string = "Circ";
    private center: Point2D;
    private radius: number;

    constructor(center: Point2D, radius: number) {
    }

    getName(): string {
    }

    getArea(): number {
    }

    getPerimeter(): number {
    }
    toString(): string {
        return `${this.getName()}: C=${this.center.toString()}, R=${this.radius.toFixed(2)}`;
    }
}
class Rectangle implements Shape {
    private name: string = "Rect";
    private p1: Point2D;
    private p2: Point2D;

    constructor(p1: Point2D, p2: Point2D) {
    }

    getName(): string {
    }

    getArea(): number {
    }

    getPerimeter(): number {
    }

    getP1(): Point2D {
    }

    getP2(): Point2D {
    }
    toString(): string {
        return `${this.getName()}: P1=${"" + this.p1} P2=${"" + this.p2}`;
    }
}

let _cin_: string[] = require("fs").readFileSync(0).toString().split("\n");
let input = () : string => _cin_.length === 0 ? "" : _cin_.shift()!;
let write = (text: any, end:string="\n")=> process.stdout.write("" + text + end);

function main() {
    let shapes: Shape[] = [];

    while (true) {
        let line = input();
        write("$" + line);
        let args = line.split(" ");

        if      (args[0] === "end")   { break;                                                       }
        else if (args[0] === "show")  { 
            for (let shape of shapes) {
                write(shape.toString());
            }
        }
        else if (args[0] === "circle") {
            let x = +args[1];
            let y = +args[2];
            let r = +args[3];
            shapes.push(new Circle(new Point2D(x, y), r));
        }
        else if (args[0] === "rect") {
            let p1: Point2D = new Point2D(+args[1], +args[2]);
            let p2: Point2D = new Point2D(+args[3], +args[4]);
            shapes.push(new Rectangle(p1, p2));
        }
        else if (args[0] === "info") {
            for (let shape of shapes) {
                write(`${shape.getName()}: A=${shape.getArea().toFixed(2)} P=${shape.getPerimeter().toFixed(2)}`);
            }
        }
        else {
            write("fail: invalid command");
        }
    }
}

main();

