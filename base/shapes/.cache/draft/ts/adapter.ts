
class Adapter {
    circle(x: number, y: number, r: number): void {
        this.shapes.push(new Circle(new Point2D(x, y), r));
    }

    rectange(x1: number, y1: number, x2: number, y2: number): void {
        this.shapes.push(new Rectangle(new Point2D(x1, y1), new Point2D(x2, y2)));
    }

    info(): string {
        let infoStrings = this.shapes.map(shape => 
            `${shape.getName()}: A=${shape.getArea().toFixed(2)} P=${shape.getPerimeter().toFixed(2)}`
        );
        return (infoStrings.join('\n'));
        return "";
    }

    toString(): string {
        return this.shapes.map(shape => shape.toString()).join('\n');
        return "";
    }

}

export { Adapter };