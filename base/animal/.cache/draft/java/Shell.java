import java.util.Scanner;

public class Shell {

    public static void main(String[] _args) {
        // Animal animal = new Animal("", "");

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("init") ) {
                // var species = par[1];
                // var noise = par[2];
            } else if (cmd.equals("show")) {
            } else if (cmd.equals("noise")) {
            } else if (cmd.equals("grow") ) {
                // var increment = Integer.parseInt(par[1]);
            } else if (cmd.equals("end")  ) { 
                break;
            } else {
                System.out.println("fail: comando invalido\n");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
