import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;
import java.text.DecimalFormat;

class Adapter {

    public static int count(List<Integer> vet, int value) {
        return 0;
    }

    public static int sum(List<Integer> vet) {
        return 0;
    }

    public static double average(List<Integer> vet) {
        return 0;
    }

    public static String moreMen(List<Integer> vet) {
        return "";
    }

    public static String halfCompare(List<Integer> vet) {
        return "";
    }

    public static String sexBattle(List<Integer> vet) {
        return "";
    }
}


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
                int result = Adapter.count(strToVet(args[1]), number(args[2]));
                write("" + result);
            } else if (args[0].equals("half_compare")) {
                String result = Adapter.halfCompare(strToVet(args[1]));
                write(result);
            } else if (args[0].equals("sex_battle")) {
                String result = Adapter.sexBattle(strToVet(args[1]));
                write(result);
            } else if (args[0].equals("sum")) {
                int result = Adapter.sum(strToVet(args[1]));
                write("" + result);
            } else if (args[0].equals("average")) {
                DecimalFormat df = new DecimalFormat("0.00");
                String result = df.format(Adapter.average(strToVet(args[1])));
                write(result);
            } else if (args[0].equals("more_men")) {
                String result = Adapter.moreMen(strToVet(args[1]));
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
