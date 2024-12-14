import java.util.*;


public class Shell {
    
    public static void main(String[] a) {
        // Car car = new Car();
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("show")) {
                // TODO
            } else if (cmd.equals("enter")) {
                // TODO
            } else if (cmd.equals("leave")) {
                // TODO
            } else if (cmd.equals("fuel")) {
                // TODO
                // int increment = Integer.parseInt(par[1]);
            } else if (cmd.equals("drive")) {
                // TODO
                // int distance = Integer.parseInt(par[1]);
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");
            }
        }   
    }
    private static Scanner scanner = new Scanner(System.in);
}
