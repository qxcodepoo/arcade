import java.util.*;
import java.util.stream.Collectors;
import java.text.DecimalFormat;

// @DROP
interface Shape {
    public String getName();
    public Boolean inside(Point2D point);
    public double getArea();
    public double getPerimeter();
}

class Point2D {
    public double x;
    public double y;

    public Point2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return "(" + df.format(this.x) + ", " + df.format(this.y) + ")";
    }
}

class Circle implements Shape {
    public Point2D center;
    public double radius;

    public Circle(Point2D center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public String getName() {
        return "Circ";
    }

    public Boolean inside(Point2D point) {
        double distance = Calc.distance(this.center, point);
        return distance <= this.radius;
    }

    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    public double getPerimeter() {
        return 2 * Math.PI * this.radius;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("#.00");
        return this.getName() + ": C=" + this.center + ", R=" + df.format(this.radius);
    }
}


class Rectangle implements Shape {
    Point2D p1;
    Point2D p2;

    public Rectangle(Point2D p1, Point2D p2) {
        this.p1 = p1;
        this.p2 = p2;
    }

    public Boolean inside(Point2D point) {
        return (point.x >= p1.x && point.x <= p2.x && point.y >= p1.y && point.y <= p2.y);
    }

    public String getName() {
        return "Rect";
    }

    public double getArea() {
        return (p1.x - p2.x) * (p1.y - p2.y);
    }

    public double getPerimeter() {
        return Math.abs(p1.x - p2.x) * 2 + Math.abs(p1.y - p2.y) * 2;
    }

    public String toString() {
        return this.getName() + ": P1=" + this.p1 + " P2=" + this.p2;
    }
}


class Calc {
    public static double distance(Point2D a, Point2D b) {
        return Math.sqrt(Math.pow(a.x - b.x, 2) + Math.pow(a.y - b.y, 2));
    }
}

// @KEEP
public class Shell {

    // @COM
    public static String info(Shape shape) {
        DecimalFormat df = new DecimalFormat("#.00");
        return String.format("%s: A=%s P=%s", shape.getName(), df.format(shape.getArea()), df.format(shape.getPerimeter()));   
    }
    // @KEEP
    public static void main(String[] a) {
        // @DROP
        ArrayList<Shape> shapes = new ArrayList<>();
        // @KEEP
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
    
            var par = line.split(" ");
            var cmd = par[0];
            
            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                // @DROP
                var output = shapes.stream().map(shape -> shape.toString()).collect(Collectors.joining("\n"));
                System.out.println(output);
            }
            else if (cmd.equals("circle")) {
                // @COM
                var x = Double.parseDouble(par[1]);
                var y = Double.parseDouble(par[2]);
                var radius = Double.parseDouble(par[3]);
                // @DROP
                shapes.add(new Circle(new Point2D(x, y), radius));
            }
            else if (cmd.equals("rect")) {
                // @COM
                var x1 = Double.parseDouble(par[1]);
                var y1 = Double.parseDouble(par[2]);
                var x2 = Double.parseDouble(par[3]);
                var y2 = Double.parseDouble(par[4]);
                // @DROP
                shapes.add(new Rectangle(new Point2D(x1, y1), new Point2D(x2, y2)));
            }
            else if (cmd.equals("info")) {
                // @DROP
                var output = shapes.stream().map(shape -> info(shape)).collect(Collectors.joining("\n"));
                System.out.println(output);
            }
            else {
                System.out.println("Comando inválido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}