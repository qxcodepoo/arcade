import java.util.Scanner;

public class Shell {

    public static void main(String[] args) {
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("show")) { // TODO
            } else if (cmd.equals("setDriver")) { // TODO
                // String name = par[1];
                // int money = Integer.parseInt(par[2]);
            } else if (cmd.equals("setPass")) { // TODO
                // String name = par[1];
                // int money = Integer.parseInt(par[2]);
            } else if (cmd.equals("drive")) { // TODO
                // int distance = Integer.parseInt(par[1]);
            } else if (cmd.equals("leavePass")) { // TODO
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: command not found");
            }
        }
    }
    static Scanner scanner = new Scanner(System.in);
}
