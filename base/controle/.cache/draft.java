import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

class Pair {
    Integer first;
    Integer second;

    Pair(Integer first, Integer second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return "(" + first + ", " + second + ")" ;
    }
};
public class Solver {

    public static List<Pair> occurr(List<Integer> vet) {
    }

    public static List<Pair> teams(List<Integer> vet) {
    }

    public static List<Integer> mnext(List<Integer> vet) {
    }

    private static boolean hasWoman(List<Integer> vet, int size, int index) {
    }

    public static List<Integer> alone(List<Integer> vet) {
    }

    public static int couple(List<Integer> vet) {
    }

    public static boolean hasSubseq(List<Integer> vet, List<Integer> seq, int pos) {
    }

    public static int subseq(List<Integer> vet, List<Integer> seq) {
    }

    public static List<Integer> erase(List<Integer> vet, List<Integer> pos_list) {
    }
    
    public static List<Integer> clear(List<Integer> vet, int value) {
    }
    // Main version in Java:
    public static void main(String[] args) {
        while(true) {
            String line = input();
            String[] argsL = line.split(" ");
            write('$' + line);

            if     (argsL[0].equals("occurr") ) { write("" + occurr(strToVet(argsL[1])));                     }
            else if(argsL[0].equals("teams" ) ) { write("" + teams(strToVet(argsL[1])));                      }
            else if(argsL[0].equals("mnext" ) ) { write("" + mnext(strToVet(argsL[1])));                      }
            else if(argsL[0].equals("alone" ) ) { write("" + alone(strToVet(argsL[1])));                      }
            else if(argsL[0].equals("erase" ) ) { write("" + erase(strToVet(argsL[1]), strToVet(argsL[2])));  }
            else if(argsL[0].equals("clear" ) ) { write("" + clear(strToVet(argsL[1]), number(argsL[2])));    }
            else if(argsL[0].equals("subseq") ) { write("" + subseq(strToVet(argsL[1]), strToVet(argsL[2]))); }
            else if(argsL[0].equals("couple") ) { write("" + couple(strToVet(argsL[1])));                     }
            else if(argsL[0].equals("end"   ) ) { break;                                                      }
            else                                { write("Invalid command");                                   }
        }
    }

    public static List<Integer> strToVet(String s) {
        if(s.equals("[]")) return new ArrayList<>();
        List<String> parts = Arrays.asList(s.substring(1, s.length() - 1 ).split(","));
        List<Integer> result = new ArrayList<>();
        for (String part : parts)
            result.add(Integer.parseInt(part.trim()));
        return result;
    }

    static Scanner scanner = new Scanner(System.in);

    public static String input()           { return scanner.nextLine();       }
    public static void write(String value) { System.out.println(value);       }
    public static int number(String str)   { return Integer.parseInt(str);    }
}