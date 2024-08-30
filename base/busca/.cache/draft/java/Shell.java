import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class Shell {
    public static void main(String[] _args) {
        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if      ("end".equals(args[0])        ) {
                break;
            }
            else if ("in".equals(args[0])         ) {
                var result = Student.in(strToVet(args[1]), number(args[2])); 
                write(result ? "true" : "false");
            }
            else if ("index_of".equals(args[0])   ) {
                var result = Student.indexOf(strToVet(args[1]), number(args[2]));
                write("" + result);
            }
            else if ("find_if".equals(args[0])    ) {
                var result = Student.findIf(strToVet(args[1]));
                write("" + result);
            }
            else if ("min_element".equals(args[0])) {
                var result = Student.minElement(strToVet(args[1]));
                write("" + result);
            }
            else if ("find_min_if".equals(args[0])) {
                var result = Student.findMinIf(strToVet(args[1]));
                write("" + result);
            }
            else { 
                write("fail: comando invalido");
            }
        }
    }

    public static List<Integer> strToVet(String s) {
        if(s.length() == 2) return new ArrayList<>();
        List<String> parts = Arrays.asList(s.substring(1, s.length() - 1).split(","));
        List<Integer> result = new ArrayList<>();
        for (String part : parts)
            result.add(Integer.parseInt(part.trim()));
        return result;
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static int number(String str)   { return Integer.parseInt(str); }
}