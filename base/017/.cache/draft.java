import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;
import java.util.Locale;

enum Cents {
    C10, C25, C50, C100;
}

class Coin {
    private double value;
    private int volume;
    private String label;
    
    public Coin(Cents cents) {
        switch (cents) {
            case C10:
                value = 0.1;
                volume = 1;
                label = "C10";
                break;
            case C25:
                value = 0.25;
                volume = 2;
                label = "C25";
                break;
            case C50:
                value = 0.5;
                volume = 3;
                label = "C50";
                break;
            case C100:
                value = 1;
                volume = 4;
                label = "C100";
                break;
        }
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
    
    public ArrayList<String> getItens(){
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



public class Solver {

    static Shell sh = new Shell();
    static Pig pig = new Pig(0);
    public static void main(String[] args) {
        var chain = sh.chain;
        var param = sh.param;

        chain.put("addCoin",    () -> {
            String value = param.get(1);
            if     (value.equals("10"))  pig.addCoin(new Coin(Cents.C10));
            else if(value.equals("25"))  pig.addCoin(new Coin(Cents.C25));
            else if(value.equals("50"))  pig.addCoin(new Coin(Cents.C50));
            else if(value.equals("100")) pig.addCoin(new Coin(Cents.C100));
        });
        chain.put("init",     () -> pig = new Pig(parInt(1)));
        chain.put("addItem",  () -> pig.addItem(new Item(param.get(1), parInt(2))));
        chain.put("break",    () -> pig.breakPig());
        chain.put("getCoins", () -> System.out.println(String.format("%.02f", pig.getCoins())));
        chain.put("getItems", () -> System.out.println("[" + pig.getItens().stream().collect(Collectors.joining(", ")) + "]"));
        chain.put("show",     () -> System.out.println(pig));

        sh.execute();
    }

    static int parInt(int index) {
        return Integer.parseInt(sh.param.get(index));
    }

}

class Shell {    
    public Scanner scanner = new Scanner(System.in);
    public HashMap<String, Runnable> chain = new HashMap<>();
    public ArrayList<String> param = new ArrayList<>();
    public Shell() {
        Locale.setDefault(new Locale("en", "US"));
    }
    public void execute() {
        while(true) {
            param.clear();
            String line = scanner.nextLine();
            Collections.addAll(param, line.split(" "));
            System.out.println("$" + line);
            if(param.get(0).equals("end")) {
                break;
            } else if (chain.containsKey(param.get(0))) {
                chain.get(param.get(0)).run();
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}
