const input = () => ""; // MODO_TESTE
export {};

// @DROP
class Point2D {
    x: number;
    y: number;
    constructor(x: number, y: number) {
        this.x = x; 
        this.y = y;
    }
    toString(): string {
        return `(${this.x.toFixed(2)}, ${this.y.toFixed(2)})`;
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
        this.center = center;
        this.radius = radius;
    }

    getName(): string {
        return this.name;
    }

    getArea(): number {
        return Math.PI * this.radius * this.radius;
    }

    getPerimeter(): number {
        return Math.PI * 2 * this.radius;
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
        this.p1 = p1;
        this.p2 = p2;
    }

    getName(): string {
        return this.name;
    }

    getArea(): number {
        const width = Math.abs(this.p1.x - this.p2.x); 
        const height = Math.abs(this.p1.y - this.p2.y);
        return width * height;
    }

    getPerimeter(): number {
        const width = Math.abs(this.p1.x - this.p2.x);
        const height = Math.abs(this.p1.y - this.p2.y);
        return 2 * width + 2 * height;
    }

    getP1(): Point2D {
        return this.p1;
    }

    getP2(): Point2D {
        return this.p2;
    }

    toString(): string {
        return `${this.getName()}: P1=${"" + this.p1} P2=${"" + this.p2}`;
    }
}

// @KEEP
function main() {
    const shapes: Shape[] = []; // @COM

    while (true) {
        const line = input();
        console.log("$" + line);

        const par = line.split(" ");
        const cmd = par[0];

        if (cmd == "end") {
            break;
        }
        else if (cmd == "show") {
            // @DROP
            console.log(shapes.map(x => x.toString()).join("\n"));
        }
        else if (cmd == "circle") {
            // @COM
            const x = parseFloat(par[1]);
            const y = parseFloat(par[2]);
            const r = parseFloat(par[3]);
            // @DROP
            shapes.push(new Circle(new Point2D(x, y), r));
        }
        else if (cmd == "rect") {
            // @COM
            const x1 = parseFloat(par[1]);
            const y1 = parseFloat(par[2]);
            const x2 = parseFloat(par[3]);
            const y2 = parseFloat(par[4]);
            // @DROP
            shapes.push(new Rectangle(new Point2D(x1, y1), new Point2D(x2, y2)));
        }
        else if (cmd == "info") {
            // @DROP
            const info = (shape: Shape) => `${shape.getName()}: A=${shape.getArea().toFixed(2)} P=${shape.getPerimeter().toFixed(2)}`
            console.log(shapes.map(info).join('\n'));
        }
        else {
            console.log("fail: invalid command");
        }
    }
}

main();