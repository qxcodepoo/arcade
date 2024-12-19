import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Shell {
    static List<Integer> get_men(List<Integer> vet) {
        return new ArrayList<>();
    }

    static List<Integer> get_calm_women(List<Integer> vet) {
        return new ArrayList<>();
    }

    static List<Integer> sort(List<Integer> vet) {
        return new ArrayList<>();
    }

    static List<Integer> sort_stress(List<Integer> vet) {
        return new ArrayList<>();
    }

    static List<Integer> reverse(List<Integer> vet) {
        return new ArrayList<>();
    }

    static void reverse_inplace(List<Integer> vet) {
    }

    static boolean exists(List<Integer> vet, int value) {
        return false;
    }

    static List<Integer> unique(List<Integer> vet) {
        return new ArrayList<>();
    }

    static List<Integer> repeated(List<Integer> vet) {
        return new ArrayList<>();
    }

    public static void main(String[] _args) {
        while (true) {
            var line = scanner.nextLine();
            var args = line.split(" ");
            var cmd = args[0];
            System.out.println("$" + line);

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("get_men")) {
                var array = strToVet(args[1]);
                System.out.println("" + get_men(array));
            } else if (cmd.equals("get_calm_women")) {
                var array = strToVet(args[1]);
                System.out.println("" + get_calm_women(array));
            } else if (cmd.equals("sort")) {
                var array = strToVet(args[1]);
                System.out.println("" + sort(array));
            } else if (cmd.equals("sort_stress")) {
                var array = strToVet(args[1]);
                System.out.println("" + sort_stress(array));
            } else if (cmd.equals("reverse")) {
                var array = strToVet(args[1]);
                System.out.println("" + reverse(array));
            } else if (cmd.equals("reverse_inplace")) {
                var array = strToVet(args[1]);
                reverse_inplace(array);
                System.out.println("" + array);
            } else if (cmd.equals("exists")) {
                var array = strToVet(args[1]);
                var value = Integer.parseInt(args[2]);
                System.out.println("" + exists(array, value));
            } else if (cmd.equals("unique")) {
                var array = strToVet(args[1]);
                System.out.println("" + unique(array));
            } else if (cmd.equals("repeated")) {
                var array = strToVet(args[1]);
                System.out.println("" + repeated(array));
            } else {
                System.out.println("Invalid command");
            }
        }
    }

    public static List<Integer> strToVet(String s) {
        if (s.equals("[]"))
            return new ArrayList<>();
        List<String> parts = Arrays.asList(s.substring(1, s.length() - 1).split(","));
        List<Integer> result = new ArrayList<>();
        for (String part : parts)
            result.add(Integer.parseInt(part.trim()));
        return result;
    }

    static Scanner scanner = new Scanner(System.in);
}
