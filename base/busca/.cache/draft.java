import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class Solver {

    static boolean in(List<Integer> vet, int x) {
    }

    static int indexOf(List<Integer> vet, int x) {
    }

    static int findIf(List<Integer> vet) {
    }

    static int minElement(List<Integer> vet) {
    }

    static int findMinIf(List<Integer> vet) {
    }
    public static void main(String[] _args) {

        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if      ("end".equals(args[0])        ) {
                break;
            }
            else if ("in".equals(args[0])         ) {
                var result = in(strToVet(args[1]), number(args[2])); 
                write(result ? "true" : "false");
            }
            else if ("index_of".equals(args[0])   ) {
                var result = indexOf(strToVet(args[1]), number(args[2]));
                write("" + result);
            }
            else if ("find_if".equals(args[0])    ) {
                var result = findIf(strToVet(args[1]));
                write("" + result);
            }
            else if ("min_element".equals(args[0])) {
                var result = minElement(strToVet(args[1]));
                write("" + result);
            }
            else if ("find_min_if".equals(args[0])) {
                var result = findMinIf(strToVet(args[1]));
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