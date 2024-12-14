import java.util.*;
import java.text.DecimalFormat;


public class Shell {

    public static void main(String[] args) {
        // Calculator calculator = new Calculator(0);
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("init")) {
                // TODO
                // int batteryMax = Integer.parseInt(par[1]);
            } else if (cmd.equals("show")) {
                // TODO
            } else if (cmd.equals("charge")) {
                // TODO
                // int value = Integer.parseInt(par[1]);
            } else if (cmd.equals("sum")) {
                // TODO
                // int a = Integer.parseInt(par[1]);
                // int b = Integer.parseInt(par[2]);
            } else if (cmd.equals("div")) {
                // TODO
                // int num = Integer.parseInt(par[1]);
                // int den = Integer.parseInt(par[2]);
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
