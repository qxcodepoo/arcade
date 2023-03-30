import java.util.List;
import java.util.Arrays;
import java.util.Scanner;
import java.util.ArrayList;

public class Solver { //todo

    static boolean in(List<Integer> vet, int x) { //todo
    }

    static int indexOf(List<Integer> vet, int x) { //todo
    }

    static int findIf(List<Integer> vet) { //todo
    }

    static int minElement(List<Integer> vet) { //todo
    }

    static int findMinIf(List<Integer> vet) { //todo
    }
    public static void main(String[] args) {

        while (true) {
            String line = input();
            String[] argsL = line.split(" ");
            write('$' + line);

            if      ("end".equals(argsL[0])        ) { break;                                                        }
            else if ("in".equals(argsL[0])         ) { write(        "" + in(strToVet(argsL[1]), number(argsL[2]))); }                
            else if ("index_of".equals(argsL[0])   ) { write(   "" + indexOf(strToVet(argsL[1]), number(argsL[2]))); }  
            else if ("find_if".equals(argsL[0])    ) { write(    "" + findIf(strToVet(argsL[1])));                   }
            else if ("min_element".equals(argsL[0])) { write("" + minElement(strToVet(argsL[1])));                   }
            else if ("find_min_if".equals(argsL[0])) { write( "" + findMinIf(strToVet(argsL[1])));                   }
            else                                     { write("fail: comando invalido");                              }
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