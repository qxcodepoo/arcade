import java.util.Scanner;
import java.util.ArrayList;
import java.util.Locale;

public class Main {
    public static void main(String[] a) {
        Locale.setDefault(new Locale("en", "US"));
        ArrayList<String> vet = new ArrayList<>();
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if (args[0].equals("end")) {
                break;
            }
            else if(args[0].equals("push")) {
                for (int i = 1; i < args.length; i++) {
                    vet.add(args[i]);
                }
            }
            else if(args[0].equals("show")) {
                write("[" + String.join(", ", vet) + "]");
            }
            else if(args[0].equals("erase")) {
                vet.remove((int) number(args[1]));
            }
            else {
                write("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}
