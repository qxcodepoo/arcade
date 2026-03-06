import java.util.*;

public class Shell {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Agiota agiota = new Agiota();

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            String[] parts = line.split(" ");
            String cmd = parts[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
            }
            else if (cmd.equals("addCli")) {
                // String name = parts[1];
                // int limite = Integer.parseInt(parts[2]);
            }
            else if (cmd.equals("showCli")) {
                // String name = parts[1];
            }
            else if (cmd.equals("kill")) {
                // String name = parts[1];
            }
            else if (cmd.equals("give")) {
                // String name = parts[1];
                // int value = Integer.parseInt(parts[2]);
            }
            else if (cmd.equals("take")) {
                // String name = parts[1];
                // int value = Integer.parseInt(parts[2]);
            }
            else if (cmd.equals("plus")) {
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}
