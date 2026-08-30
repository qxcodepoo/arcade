import java.util.Scanner;
import java.util.*;
import java.util.stream.Collectors;

// @DROP

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
        this.value = value;
        this.volume = volume;
        this.label = label;
    }
    
    @Override
    public String getLabel() {
        return this.label;
    }

    @Override
    public int getVolume() {
        return volume;
    }

    @Override
    public double getValue() {
        return value;
    }

    public String toString() {
        return label + ":" + String.format("%.02f", value) + ":" + volume;
    }
}


class Item implements Valuable { 
    private String label;
    private double value;
    private int volume;

    public Item(String label, double value, int volume) {
        this.label = label;
        this.volume = volume;
        this.value = value;
    }

    public void setLabel(String label) {
        this.label = label;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    @Override
    public int getVolume() {
        return this.volume;
    }

    @Override
    public String getLabel() {
        return this.label;
    }

    @Override
    public double getValue() {
        return this.value;
    }

    public String toString() {
        return String.format("%s:%.02f:%d", label, value, volume);
    }
}


class Pig {
    private ArrayList<Valuable> valuables;
    private int volumeMax;
    private boolean broken = false;
    
    //inicializa o volumeMax
    public Pig(int volumeMax) {
        this.volumeMax = volumeMax;
        this.valuables = new ArrayList<Valuable>();
    }

    public double calcValue() {
        double value = 0;

        for (int i = 0; i < this.valuables.size(); i++) {
            value += this.valuables.get(i).getValue();
        }

        return value;
    }


    //se não estiver quebrado e couber, adicione no volume e na descrição
    public boolean addValuable(Valuable val) {
        if (this.broken) {
            System.out.println("fail: the pig is broken");
            return false;
        }
        if (val.getVolume() + this.getVolume() > this.volumeMax) {
            System.out.println("fail: the pig is full");
            return false;
        }
        this.valuables.add(val);

        return true;
    }

    //quebre o pig, zere o volume
    public boolean breakPig(){
        if (!this.broken) {
            this.broken = true;
            return true;
        }
        System.out.println("fail: the pig is already broken");
        return false;
    }

    //se estiver quebrado, retorne as moedas e as retire do porco
    //se não estiver quebrado, retorne uma lista vazia
    public ArrayList<Coin> extractCoins(){
        if(!this.broken){
            throw new RuntimeException("fail: you must break the pig first");
        }
        var coins = new ArrayList<Coin>();
        var left = new ArrayList<Valuable>();
        for (var val : this.valuables) {
            if (val instanceof Coin) {
                coins.add((Coin) val);
            } else {
                left.add(val);
            }
        }
        this.valuables = left;
        return coins;
    }

    //se estiver quebrado, pegue e retorno os itens
    //se não estiver quebrado, emita o erro e retorne uma lista vazia
    public ArrayList<Item> extractItems(){
        if(!this.broken){
            throw new RuntimeException("fail: you must break the pig first");
        }
        var items = new ArrayList<Item>();
        var left = new ArrayList<Valuable>();
        for (var val : this.valuables) {
            if (val instanceof Item) {
                items.add((Item) val);
            } else {
                left.add(val);
            }
        }
        this.valuables = left;
        return items;
    }

    public int getVolume() {
        int volume = 0;
        if (this.broken) {
            return 0;
        }
        for (var val : this.valuables) {
            volume += val.getVolume();
        }
        return volume;
    }

    public float getValue() {
        float value = 0;
        for (var val : this.valuables) {
            value += val.getValue();
        }
        return value;
    }

    public int getVolumeMax() {
        return this.volumeMax;
    }

    public boolean isBroken() {
        return this.broken;
    }

    public String toString() {
        return "[" + valuables.stream().map(Valuable::toString).collect(Collectors.joining(", ")) + "]"  
                + " : " + String.format("%.02f", this.getValue()) + "$"
                + " : " + this.getVolume() + "/" + volumeMax 
                + " : " + (broken ? "broken" : "intact");
    }
}

// @KEEP
public class Shell {
    public static void main(String[] a) {
        Pig pig = new Pig(0);
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
            var args = line.split(" ");
            var cmd = args[0];
            
            try {
                if (cmd.equals("end")) {
                    break;
                }
                else if(cmd.equals("show")) { 
                    // @DROP
                    System.out.println("" + pig);
                }
                else if(cmd.equals("addCoin")) {
                    // @COM
                    String value = args[1];
                    // @DROP
                    if     (value.equals("10"))  pig.addValuable(Coin.M10);
                    else if(value.equals("25"))  pig.addValuable(Coin.M25);
                    else if(value.equals("50"))  pig.addValuable(Coin.M50);
                    else if(value.equals("100")) pig.addValuable(Coin.M100);
                }
                else if(cmd.equals("init")) {
                    // @COM
                    var volume = Integer.parseInt(args[1]);
                    // @DROP
                    pig = new Pig(volume);
                }
                else if(cmd.equals("addItem")) {
                    // @COM
                    var label = args[1];
                    var value = Double.parseDouble(args[2]);
                    var volume = Integer.parseInt(args[3]);
                    // @DROP
                    pig.addValuable(new Item(label, value, volume));
                }
                else if(cmd.equals("break")) {
                    // @DROP 
                    pig.breakPig(); 
                }
                else if(cmd.equals("extractCoins")) { 
                    // @DROP
                    System.out.println("[" + pig.extractCoins().stream().map(Coin::toString).collect(Collectors.joining(", ")) + "]");
                }
                else if(cmd.equals("extractItems")) { 
                    // @DROP
                    System.out.println("[" + pig.extractItems().stream().map(Item::toString).collect(Collectors.joining(", ")) + "]");
                }
                else {
                    System.out.println("fail: comando invalido");
                }
            } catch (RuntimeException e) {
                System.out.println(e.getMessage());
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
