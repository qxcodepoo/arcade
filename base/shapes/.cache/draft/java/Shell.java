import java.util.*;
import java.util.stream.Collectors;
import java.text.DecimalFormat;

public class Shell {

    // public static String info(Shape shape) {
    //     DecimalFormat df = new DecimalFormat("#.00");
    //     return String.format("%s: A=%s P=%s", shape.getName(), df.format(shape.getArea()), df.format(shape.getPerimeter()));   
    // }
    public static void main(String[] a) {
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
    
            var par = line.split(" ");
            var cmd = par[0];
            
            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
            }
            else if (cmd.equals("circle")) {
                // var x = Double.parseDouble(par[1]);
                // var y = Double.parseDouble(par[2]);
                // var radius = Double.parseDouble(par[3]);
            }
            else if (cmd.equals("rect")) {
                // var x1 = Double.parseDouble(par[1]);
                // var y1 = Double.parseDouble(par[2]);
                // var x2 = Double.parseDouble(par[3]);
                // var y2 = Double.parseDouble(par[4]);
            }
            else if (cmd.equals("info")) {
            }
            else {
                System.out.println("Comando inválido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
