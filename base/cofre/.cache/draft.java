import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;

public class Solver {
    public static void main(String[] a) {
        // Locale.setDefault(new Locale("en", "US"));
        Pig pig = new Pig(0);
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");
            
            try {
                if (args[0].equals("end")) {
                    break;
                }
                else if(args[0].equals("addCoin")) {
                    String value = args[1];
                    if     (value.equals("10"))  pig.addValuable(Coin.M10);
                    else if(value.equals("25"))  pig.addValuable(Coin.M25);
                    else if(value.equals("50"))  pig.addValuable(Coin.M50);
                    else if(value.equals("100")) pig.addValuable(Coin.M100);
                }
                else if(args[0].equals("init")) {
                    pig = new Pig(Integer.parseInt(args[1]));
                }
                else if(args[0].equals("addItem")) {
                    pig.addValuable(new Item(args[1], number(args[2]), (int) number(args[3])));
                }
                else if(args[0].equals("break"))    { 
                    pig.breakPig(); 
                }
                else if(args[0].equals("extractCoins")) { 
                    write("[" + pig.extractCoins().stream().map(Coin::toString).collect(Collectors.joining(", ")) + "]");
                }
                else if(args[0].equals("extractItems")) { 
                    write("[" + pig.extractItems().stream().map(Item::toString).collect(Collectors.joining(", ")) + "]");
                }
                else if(args[0].equals("show"))     { 
                    write("" + pig);
                }
                else {
                    write("fail: comando invalido");
                }
            } catch (RuntimeException e) {
                write(e.getMessage());
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}
