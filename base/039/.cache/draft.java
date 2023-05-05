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
        int size = vet.size();
        if (size == 0)
            return new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < size; i++) {
            int key = Math.abs(vet.get(i));
            if (map.containsKey(key))
                map.put(key, map.get(key) + 1);
            else
                map.put(key, 1);
        }
        List<Pair> output = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet())
            output.add(new Pair(entry.getKey(), entry.getValue()));
        return output;
    }

    public static List<Pair> teams(List<Integer> vet) {
        int size = vet.size();
        if (size == 0)
            return new ArrayList<>();
        List<Pair> output = new ArrayList<>();
        output.add(new Pair(vet.get(0), 1));
        for (int i = 1; i < size; i++) {
            if (output.get(output.size() - 1).first.equals(vet.get(i))) {
                int count = output.get(output.size() - 1).second;
                output.set(output.size() - 1, new Pair(vet.get(i), count + 1));
            } else
                output.add(new Pair(vet.get(i), 1));
        }
        return output;
    }

    public static List<Integer> mnext(List<Integer> vet) {
        int size = vet.size();
        List<Integer> output = new ArrayList<>();
        for (int i = 0; i < size; i++)
            if(vet.get(i) > 0 && (hasWoman(vet, size, i - 1) || hasWoman(vet, size, i + 1)))
                output.add(1);
            else
                output.add(0);
        return output;
    }

    private static boolean hasWoman(List<Integer> vet, int size, int index) {
        return index >= 0 && index < size && vet.get(index) < 0;
    }

    public static List<Integer> alone(List<Integer> vet) {
        int size = vet.size();
        List<Integer> output = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            if (vet.get(i) > 0 && (!hasWoman(vet, size, i - 1) && !hasWoman(vet, size, i + 1))) {
                output.add(1);
            } else {
                output.add(0);
            }
        }
        return output;
    }

    public static int couple(List<Integer> vet) {
        int qtd = 0;
        int size = vet.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (vet.get(i) != 0 && vet.get(j) != 0 && vet.get(j).equals(-vet.get(i))) {
                    vet.set(i, 0);
                    vet.set(j, 0);
                    qtd++;
                }
            }
        }
        return qtd;
    }

    public static boolean hasSubseq(List<Integer> vet, List<Integer> seq, int pos) {
        for (int i = 0; i < seq.size(); i++)
            if (pos + i >= vet.size() || !vet.get(pos + i).equals(seq.get(i)))
                return false;
        return true;
    }

    public static int subseq(List<Integer> vet, List<Integer> seq) {
        int vetSize = vet.size();
        for (int i = 0; i < vetSize; i++)
            if (hasSubseq(vet, seq, i))
                return i;
        return -1;
    }

    public static List<Integer> erase(List<Integer> vet, List<Integer> pos_list) {
        List<Integer> output = new ArrayList<>();
        for (int i = 0; i < vet.size(); i++) {
            if (!pos_list.contains(i)) {
                output.add(vet.get(i));
            }
        }
        return output;
    }
    
    public static List<Integer> clear(List<Integer> vet, int value) {
        List<Integer> output = new ArrayList<>();
        for (int elem : vet) {
            if (elem != value) {
                output.add(elem);
            }
        }
        return output;
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