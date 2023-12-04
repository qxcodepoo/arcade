import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;
import java.util.Locale;


interface Valuable {
    public String getLabel();
    public int getVolume();
    public double getValue();
}

enum Coin implements Valuable {
    M10(0.10, 1, "M10"),
    M25(0.25, 2, "M25"),
    M50(0.50, 3, "M50"),
    M100(1.00, 4, "M100");

    private double value;
    private int volume;
    private String label;
    
    private Coin(double value, int volume, String label) {
    }
    
    @Override
    public String getLabel() {
    }

    @Override
    public int getVolume() {
    }

    @Override
    public double getValue() {
    }

    public String toString() {
    }
}


class Item implements Valuable { 
    private String label;
    private double value;
    private int volume;

    public Item(String label, double value, int volume) {
    }

    public void setLabel(String label) {
    }

    public void setVolume(int volume) {
    }

    @Override
    public int getVolume() {
    }

    @Override
    public String getLabel() {
    }

    @Override
    public double getValue() {
    }

    public String toString() {
    }
}


class Pig {
    private ArrayList<Valuable> valuables;
    private int volumeMax;
    private boolean broken = false;
    
    //inicializa o volumeMax
    public Pig(int volumeMax) {
    }

    public double calcValue() {


    }


    //se não estiver quebrado e couber, adicione no volume e na descrição
    public boolean addValuable(Valuable val) {

    }

    //quebre o pig, zere o volume
    public boolean breakPig(){
    }

    //se estiver quebrado, retorne as moedas e as retire do porco
    //se não estiver quebrado, retorne uma lista vazia
    public ArrayList<Coin> extractCoins(){
    }

    //se estiver quebrado, pegue e retorno os itens
    //se não estiver quebrado, emita o erro e retorne uma lista vazia
    public ArrayList<Item> extractItems(){
    }

    public int getVolume() {
    }

    public float getValue() {
    }

    public int getVolumeMax() {
    }

    public boolean isBroken() {
    }

    public String toString() {
    }
}

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
