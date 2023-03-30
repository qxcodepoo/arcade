import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;

enum Coin {

    //initializing the enum C10, C25, C50, C100
    C10(0.10, 1, "C10"),
    C25(0.25, 2, "C25"),
    C50(0.50, 3, "C50"),
    C100(1.00, 4, "C100");

    private double value;
    private int volume;
    private String label;

    private Coin(double value, int volume, String label) {
        this.value = value;
        this.volume = volume;
        this.label = label;
    }
    
    public int getVolume() {
        return volume;
    }
    public double getValue() {
        return value;
    }
    public String toString() {
        return String.format("%.02f", value) + ":" + volume;
    }
}

class Item { //todo
    private String label;
    private int volume;

    public Item(String label, int volume) { //todo
    }

    public String getLabel() { //todo
    }

    public void setLabel(String label) { //todo
    }

    public void setVolume(int volume) { //todo
    }

    public int getVolume() { //todo
    }

    public String toString() {
        return label + ":" + volume;
    }
}


class Pig{
    private ArrayList<String> items;
    private double value = 0;
    private int volume = 0;
    private int volumeMax;
    private boolean broken = false;
    
    public Pig(int volumeMax) { //todo
    }

    public boolean addCoin(Coin moeda){
    }

    public boolean addItem(Item item) { //todo
    }

    public boolean breakPig(){
    }

    public double getCoins(){
    }
    
    public String getItems(){
    }

    public int getVolume() { //todo
    }

    public int getVolumeMax() { //todo
    }

    public boolean isBroken() { //todo
    }

    public String toString() {

        return "[" + items.stream().collect(Collectors.joining(", ")) + "]"  
                + " : " + String.format("%.02f", value) + "$"
                + " : " + volume + "/" + volumeMax 
                + " : " + (broken ? "broken" : "unbroken");
    }
}



class Solver {
    public static void main(String[] a) {
        Pig pig = new Pig(0);
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if (args[0].equals("end"))        { break;                                      }
            else if(args[0].equals("init"))   { pig = new Pig((int) number(args[1]));        }
            else if(args[0].equals("addCoin")){
                var value = args[1];
                if (value.equals("10"))  { pig.addCoin(Coin.C10);  }
                if (value.equals("25"))  { pig.addCoin(Coin.C25);  }
                if (value.equals("50"))  { pig.addCoin(Coin.C50);  }
                if (value.equals("100")) { pig.addCoin(Coin.C100); }
            }
            else if(args[0].equals("addItem")){ pig.addItem(new Item(args[1], (int) number(args[2])));}
            else if(args[0].equals("break"))  { pig.breakPig();                             }
            else if(args[0].equals("getCoins")){ write(String.format("%.02f", pig.getCoins()));}
            else if(args[0].equals("getItems")){ write(pig.getItems()); }
            else if(args[0].equals("show"))   { write(pig.toString());                      }
            else                              { write("fail: invalid command");              }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}


