import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;
import java.text.DecimalFormat;

class Student {

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
            String line = scanner.nextLine();
            System.out.println("$" + line);
            
            var args = line.split(" ");
            var cmd = args[0];
            
            if (cmd.equals("end")) {
                break;
            } else if (args[0].equals("count")) {
                int result = Student.count(strToVet(args[1]), Integer.parseInt(args[2]));
                System.out.println("" + result);
            } else if (args[0].equals("half_compare")) {
                String result = Student.halfCompare(strToVet(args[1]));
                System.out.println(result);
            } else if (args[0].equals("sex_battle")) {
                String result = Student.sexBattle(strToVet(args[1]));
                System.out.println(result);
            } else if (args[0].equals("sum")) {
                int result = Student.sum(strToVet(args[1]));
                System.out.println("" + result);
            } else if (args[0].equals("average")) {
                DecimalFormat df = new DecimalFormat("0.00");
                String result = df.format(Student.average(strToVet(args[1])));
                System.out.println(result);
            } else if (args[0].equals("more_men")) {
                String result = Student.moreMen(strToVet(args[1]));
                System.out.println(result);
            } else {
                System.out.println("fail: comando invalido");
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
}
