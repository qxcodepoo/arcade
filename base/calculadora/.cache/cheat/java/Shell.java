import java.util.*;

public class Shell {
    static Student stu = new Student();

    public static void main(String[] _args) {
        while (true) {
            System.out.print("$");
            String line = input();
            String[] args = line.split(" ");
            write(line);

            if ("show".equals(args[0])) {
                stu.show();
            }
            else if ("init".equals(args[0])) {
                stu.init((int) number(args[1]));
            }
            else if ("charge".equals(args[0])) {
                stu.charge((int) number(args[1]));
            }
            else if ("sum".equals(args[0])) {
                stu.sum((int) number(args[1]), (int) number(args[2]));
            }
            else if ("div".equals(args[0])) {
                stu.div((int) number(args[1]), (int) number(args[2]));
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