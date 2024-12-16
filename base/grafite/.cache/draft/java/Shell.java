import java.util.Scanner;
import java.text.DecimalFormat;


public class Shell {
    public static void main(String[] args) {

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("init")) { // TODO
                // var thickness = Double.parseDouble(par[1]);
            } else if (cmd.equals("show")) { // TODO
            } else if (cmd.equals("insert")) { // TODO
                // var thickness = Double.parseDouble(par[1]);
                // var hardness = par[2];
                // var size = Integer.parseInt(par[3]);
            } else if (cmd.equals("remove")) { // TODO
            } else if (cmd.equals("write")) { // TODO
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
