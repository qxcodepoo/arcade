import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;


public class Shell{
    public static void main(String[] _args) {
        while (true) {
            var line = scanner.nextLine();
            var args = line.split(" ");
            var cmd = args[0];
            System.out.println("$" + line);

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("show")) {
            } else if (cmd.equals("init")) {
                // var id = Integer.parseInt(args[1]);
            } else if (cmd.equals("withdraw")) {
                // var value = Integer.parseInt(args[1]);
            } else if (cmd.equals("fee")) {
                // var value = Integer.parseInt(args[1]);
            } else if (cmd.equals("deposit")) {
                // var value = Integer.parseInt(args[1]);
            } else if (cmd.equals("reverse")) {
                // for (int i = 1; i < args.length; i++) {
                //     var index = Integer.parseInt(args[i]);
                // }
            } else if (cmd.equals("extract")) {
                // var qtdOp = Integer.parseInt(args[1]);
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
