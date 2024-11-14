import java.util.ArrayList;
import java.util.Locale;

public class Adapter {
    ArrayList<Shape> shape;

    public void circle(double x, double y, double r){
        shape.add(new Circle(new Point2D(x, y), r));
    }

    public void rectangle(double x1, double y1, double x2, double y2){
        shape.add(new Rectangle(new Point2D(x1, y1), new Point2D(x2, y2)));
    }

    public String info(){
        String str = "";
        
        for (int i = 0; i < shape.size(); i++) {
            if(i != 0) str += "\n";
            str += String.format(Locale.US, "%s: A=%.2f P=%.2f", shape.get(i).getName(), shape.get(i).getArea(), shape.get(i).getPerimeter());
        }

        return str;
        return "";
    }

    public String toString(){
        String str = "";

        for(int i = 0; i < shape.size(); i++){
            if(i != 0) str += "\n";
            str += shape.get(i);
        }

        return str;
        return "";
        
    }
}