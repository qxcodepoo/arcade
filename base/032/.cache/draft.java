import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Solver {
    static List<Integer> get_men(List<Integer> vet) {
    }

    static List<Integer> get_calm_women(List<Integer> vet) {
    }

    static List<Integer> sort(List<Integer> vet) {
    }

    static List<Integer> sort_stress(List<Integer> vet) {
    }

    static List<Integer> reverse(List<Integer> vet) {
    }

    static void reverse_inplace(List<Integer> vet) {
    }


    public static void main(String[] args) {
        while (true) {
            String line = scanner.nextLine();
            String[] argsL = line.split(" ");
            write("$" + line);

            if     ("end".equals(argsL[0])            ) { break;                                                    }
            else if("get_men".equals(argsL[0])        ) { write("" + get_men(strToVet(argsL[1])));                  }
            else if("get_calm_women".equals(argsL[0]) ) { write("" + get_calm_women(strToVet(argsL[1])));           }
            else if("sort".equals(argsL[0])           ) { write("" + sort(strToVet(argsL[1])));                     }
            else if("sort_stress".equals(argsL[0])    ) { write("" + sort_stress(strToVet(argsL[1])));              }
            else if("reverse".equals(argsL[0])        ) { write("" + reverse(strToVet(argsL[1])));                  }
            else if("reverse_inplace".equals(argsL[0])) { 
                List<Integer> vet = strToVet(argsL[1]);
                reverse_inplace(vet);
                write("" + vet);
            }
            else if("exists".equals(argsL[0])         ) { write("" + exists(strToVet(argsL[1]), number(argsL[2]))); }
            else if("unique".equals(argsL[0])         ) { write("" + unique(strToVet(argsL[1])));                   }
            else if("repeated".equals(argsL[0])       ) { write("" + repeated(strToVet(argsL[1])));                 }
            else                                        { write("Invalid command");                                 }
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
    public static String input()           { return scanner.nextLine();    }
    public static int number(String str)   { return Integer.parseInt(str); }
    public static void write(String value) { System.out.println(value);    }
}