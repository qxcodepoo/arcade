import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;


public class Shell {
    public static void main(String[] _args) {
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var args = line.split(" ");
            var cmd = args[0];

            if (cmd.equals("show")) { // TODO
            } else if (cmd.equals("init")) {
                // var seats = Integer.parseInt(args[1]);
            } else if (cmd.equals("reserve")) {
                // var id = args[1];
                // var phone = args[2];
                // var index = Integer.parseInt(args[3]);
            } else if (cmd.equals("cancel")) {
                // var id = args[1];
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);

}
