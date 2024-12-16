import java.util.Scanner;
import java.util.LinkedList;

public class Shell {
    public static void main(String[] args) {
        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("show")) { // TODO
            } else if (cmd.equals("arrive")) {
                // var name = par[1];
                // var age = Integer.parseInt(par[2]);
            } else if (cmd.equals("enter")) {
            } else if (cmd.equals("leave")) {
            } else if (cmd.equals("remove")) {
                // var name = par[1];
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
