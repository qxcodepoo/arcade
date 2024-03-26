import java.util.Scanner;

public class Shell {

    public static void main(String[] _args) {
        Animal animal = new Animal("", "");

        while (true) {
            var line = input();
            var args = line.split(" ");
            write("$" + line);

            if (args[0].equals("init")) {
                animal = new Animal(args[1], args[2]);
            } else if (args[0].equals("grow")) {
                animal.envelhecer((int) number(args[1]));
            } else if (args[0].equals("noise")) {
                write(animal.fazerBarulho());
            } else if (args[0].equals("show")) {
                write(animal.toString());
            } else if (args[0].equals("end")) {
                break;
            } else {
                write("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static double number(String str)   { return Double.parseDouble(str); }
}
