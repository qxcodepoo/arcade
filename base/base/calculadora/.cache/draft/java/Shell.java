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

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                // CHAME O CONSTRUTOR
                // int batteryMax = Integer.parseInt(par[1]);
            } 
            else if (cmd.equals("show")) {
                // MOSTRAR
            } 
            else if (cmd.equals("charge")) {
                // RECARREGAR A BATERIA
                // int value = Integer.parseInt(par[1]);
            } 
            else if (cmd.equals("sum")) {
                // SOMAR
                // int a = Integer.parseInt(par[1]);
                // int b = Integer.parseInt(par[2]);
            } 
            else if (cmd.equals("div")) {
                // DIVIDIR
                // int num = Integer.parseInt(par[1]);
                // int den = Integer.parseInt(par[2]);
            } 
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
