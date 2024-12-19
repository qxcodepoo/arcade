import java.util.*;

// }

public class Shell {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];
            

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                // var nPlayers = Integer.parseInt(par[1]);
                // var size = Integer.parseInt(par[2]);
            }
            else if (cmd.equals("addTrap")) {
                // var pos = Integer.parseInt(par[1]);
            }
            else if (cmd.equals("roll")) {
                // var value = Integer.parseInt(par[1]);
            }
            else if (cmd.equals("show")) {
            }
            else {
                System.out.println("invalid command");
            }
        }
        scanner.close();
    }
}
