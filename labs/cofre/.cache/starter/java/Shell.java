import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;

public class Shell {
    public static void main(String[] a) {
        Pig pig = new Pig(0);
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
            var args = line.split(" ");
            var cmd = args[0];
            
            try {
                if (cmd.equals("end")) {
                    break;
                }
                else if(cmd.equals("show")) { 
                }
                else if(cmd.equals("addCoin")) {
                    // String value = args[1];
                }
                else if(cmd.equals("init")) {
                    // var volume = Integer.parseInt(args[1]);
                }
                else if(cmd.equals("addItem")) {
                    // var label = args[1];
                    // var value = Double.parseDouble(args[2]);
                    // var volume = Integer.parseInt(args[3]);
                }
                else if(cmd.equals("break")) {
                }
                else if(cmd.equals("extractCoins")) { 
                }
                else if(cmd.equals("extractItems")) { 
                }
                else {
                    System.out.println("fail: comando invalido");
                }
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
