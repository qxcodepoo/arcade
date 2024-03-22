import java.util.*;

public class Shell {
    static Calculator calc = new Calculator(0);

    public static void main(String[] _args) {
        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if ("show".equals(args[0])) {
                write(calc.toString());
            }
            else if ("init".equals(args[0])) {
                calc = new Calculator((int) number(args[1]));
            }
            else if ("charge".equals(args[0])) {
                calc.chargeBattery((int) number(args[1]));
            }
            else if ("sum".equals(args[0])) {
                calc.sum((int) number(args[1]), (int) number(args[2]));
            }
            else if ("div".equals(args[0])) {
                calc.division((int) number(args[1]), (int) number(args[2]));
            }
            else if ("end".equals(args[0])) {
                break;
            }
            else {
                write("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String input() { return scanner.nextLine(); }
    private static double number(String value) { return Double.parseDouble(value); }
    private static void write(String value) { System.out.println(value); }
}
