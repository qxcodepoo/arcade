import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;
import java.util.Locale;


enum Coin {
    M10(0.10, 1),
    M25(0.25, 2),
    M50(0.50, 3),
    M100(1.00, 4);

    private double value;
    private int volume;
    
    private Coin(double value, int volume) {
        this.value = value;
        this.volume = volume;
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
    
    //inicializa o volumeMax
    public Pig(int volumeMax) { //todo
    }

    //se nao estiver quebrado e couber, adicione o value e o volume
    public boolean addCoin(Coin moeda){
    }

    //se não estiver quebrado e couber, adicione no volume e na descrição
    public boolean addItem(Item item) { //todo
    }

    //quebre o pig, zere o volume
    public boolean breakPig(){
    }

    //se estiver quebrado, pegue e retorne o value
    public double getCoins(){
    }

    //se estiver quebrado, pegue e retorno os itens
    //se não estiver quebrado, emita o erro e retorne uma lista vazia
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
        sh.addCmd("addCoin",    () -> {
            String value = sh.getStr(1);
            if     (value.equals("10"))  pig.addCoin(Coin.M10);
            else if(value.equals("25"))  pig.addCoin(Coin.M25);
            else if(value.equals("50"))  pig.addCoin(Coin.M50);
            else if(value.equals("100")) pig.addCoin(Coin.M100);
        });
        sh.addCmd("init",     () -> pig = new Pig(sh.getInt(1)));
        sh.addCmd("addItem",  () -> pig.addItem(new Item(sh.getStr(1), sh.getInt(2))));
        sh.addCmd("break",    () -> pig.breakPig());
        sh.addCmd("getCoins", () -> System.out.println(String.format("%.02f", pig.getCoins())));
        sh.addCmd("getItems", () -> System.out.println("[" + pig.getItens().stream().collect(Collectors.joining(", ")) + "]"));
        sh.addCmd("show",     () -> System.out.println(pig));

        sh.evaluate();
    }
}

