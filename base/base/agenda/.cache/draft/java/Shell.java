import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.Collections;

public class Shell {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] _args) {

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            String[] args = line.split(" ");
            
            if (args[0].equals("end")) {
                break;
            }
            else if (args[0].equals("add")) {
                // ArrayList<Fone> fones = new ArrayList<>();
                // for (int i = 2; i < args.length; i++) {
                //     String[] fone = args[i].split(":");
                //     fones.add(new Fone(fone[0], fone[1]));
                // }
            }
            else if (args[0].equals("show")) {
            }
            else if (args[0].equals("rm")) {
                // var name = args[1];
            }
            else if (args[0].equals("favs")) {
            }
            else if (args[0].equals("search")) {
            }
            else if (args[0].equals("rmFone"))  {
                // var name = args[1];
                // var index = Integer.parseInt(args[2]);
            }
            else if (args[0].equals("tfav")) {
                // var name = args[1];
            }
            else {
                System.out.println("fail: invalid command");
            }
        }
    }
}
