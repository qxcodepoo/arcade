import java.util.Scanner;

public class Shell {
    public static void main(String[] _args) {
        Adapter adp = new Adapter(0);
        while (true) {
            var line = input();
            var args = line.split(" ");
            write('$' + line);

            if (args[0].equals("end")) { break; }
            else if (args[0].equals("init"))     { adp = new Adapter(Integer.parseInt(args[1])); }
            else if (args[0].equals("show"))     { write(adp.toString()); }
            else if (args[0].equals("reservar")) { adp.reservar(args[1], args[2], (int) number(args[3])); }
            else if (args[0].equals("cancelar")) { adp.cancelar(args[1]); }
            else                                 { write("fail: comando invalido"); }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}