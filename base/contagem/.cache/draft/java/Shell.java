import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Optional;
import java.text.DecimalFormat;

public class Shell {
    public static void main(String[] _args) {
        while (true) {
            System.out.print("$");
            String line = input();
            write(line); // Test only
            
            String[] args = line.split(" ");
            
            if ("end".equals(args[0])) {
                break;
            } else if (args[0].equals("count")) {
                int result = Student.count(strToVet(args[1]), number(args[2]));
                write("" + result);
            } else if (args[0].equals("half_compare")) {
                String result = Student.halfCompare(strToVet(args[1]));
                write(result);
            } else if (args[0].equals("sex_battle")) {
                String result = Student.sexBattle(strToVet(args[1]));
                write(result);
            } else if (args[0].equals("sum")) {
                int result = Student.sum(strToVet(args[1]));
                write("" + result);
            } else if (args[0].equals("average")) {
                DecimalFormat df = new DecimalFormat("0.00");
                String result = df.format(Student.average(strToVet(args[1])));
                write(result);
            } else if (args[0].equals("more_men")) {
                String result = Student.moreMen(strToVet(args[1]));
                write(result);
            } else {
                write("fail: comando invalido");
            }
        }
    }

    public static List<Integer> strToVet(String s) {
        if (s.length() == 2) return new ArrayList<>();
        List<String> parts = Arrays.asList(s.substring(1, s.length() - 1).split(","));
        List<Integer> result = new ArrayList<>();
        for (String part : parts) {
            result.add(Integer.parseInt(part.trim()));
        }
        return result;
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static void write(char value)   { System.out.print(value);      }
    public static int number(String str)   { return Integer.parseInt(str); }
}
