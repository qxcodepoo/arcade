import java.util.*;
import java.util.stream.Collectors;

public class Shell {
    public static void main(String[] s) {
        while(true){
            try {
                var line = scanner.nextLine();
                var args = line.split(" ");
                var cmd = args[0];
                System.out.println("$" + line);

                if(cmd.equals("end")) {
                    break;
                }
                else if(cmd.equals("show")) {
                }
                else if(cmd.equals("addCli")) {
                    // var clientId = args[1];
                }
                else if(cmd.equals("saque")) {
                    // var accountId = Integer.parseInt(args[1]);
                    // var value = Double.parseDouble(args[2]);
                }
                else if(cmd.equals("deposito")) {
                    // var accountId = Integer.parseInt(args[1]);
                    // var value = Double.parseDouble(args[2]);
                }
                else if(cmd.equals("transf")) {
                    // var accountIdFrom = Integer.parseInt(args[1]);
                    // var accountIdTo = Integer.parseInt(args[2]);
                    // var value = Double.parseDouble(args[3]);
                }
                else if(cmd.equals("update")) {
                }
                else {
                    System.out.println("fail: comando invalido");
                }
            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
