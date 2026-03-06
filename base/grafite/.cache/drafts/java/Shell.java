import java.util.Scanner;
import java.text.DecimalFormat;


public class Shell {
    public static void main(String[] args) {

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            // else if (cmd.equals("init")) { 
            //     var thickness = Double.parseDouble(par[1]);
            // }
            // else if (cmd.equals("show")) { 
            // }
            // else if (cmd.equals("insert")) { 
            //     var thickness = Double.parseDouble(par[1]);
            //     var hardness = par[2];
            //     var size = Integer.parseInt(par[3]);
            // }
            // else if (cmd.equals("remove")) { 
            // }
            // else if (cmd.equals("write")) { 
            // }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
