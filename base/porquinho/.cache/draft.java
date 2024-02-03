import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.stream.Collectors;


enum Coin {
    C10(0.10, 1, "C10"),
    C25(0.25, 2, "C25"),
    C50(0.50, 3, "C50"),
    C100(1.00, 4, "C100");

    private final double value;
    private final int volume;
    private final String label;

    Coin(double value, int volume, String label) {
        this.value = value;
        this.volume = volume;
        this.label = label;
    }

    public double getValue() {
        return value;
    }

    public int getVolume() {
        return volume;
    }

    public String getLabel() {
        return label;
    }

    public String str() {
        return String.format("%.2f:%d", value, volume);
    }
}


class Item {
    private String label;
    private int volume;

    public Item(String label, int volume) {
    }

    public int getVolume() {
    }

    public String getLabel() {
    }

    public void setVolume(int volume) {
    }

    public void setLabel(String label) {
    }

    public String str() {
    }
}

class Pig {
    private ArrayList<Item> itens = new ArrayList<>();
    private ArrayList<Coin> coins = new ArrayList<>();
    private int volumeMax = 0;
    private boolean broken = false;

    public Pig(int volumeMax) {
    }

    public boolean addCoin(Coin coin) {
    }

    public boolean addItem(Item item) {
    }

    public boolean breakPig() {
    }

    public ArrayList<Coin> extractCoins() {
    }

    public ArrayList<Item> extractItems() {
    }

    public double getValue() {
    }

    public int getVolume() {
    }
    public String str() {
        StringJoiner coinsStr = new StringJoiner(", ");
        coins.stream().map(n -> n.str()).forEach(coinsStr::add);
        StringJoiner itens = new StringJoiner(", ");
        this.itens.stream().map(n -> n.str()).forEach(itens::add);

        return String.format("state=%s : coins=[%s] : items=[%s] : value=%.2f : volume=%d/%d",
                (broken ? "broken" : "intact"), coinsStr.toString(), itens.toString(), getValue(), getVolume(), volumeMax);
    }

}

public class Solver {
    public static void main(String[] _args) {
        Pig pig = new Pig(0);

        while (true) {
            var line = input();
            var args = line.split(" ");
            write("$" + line);

            if (args[0].equals("end")) {
                break;
            }
            else if (args[0].equals("addCoin")) {
                if (args[1].equals("10")) {
                    pig.addCoin(Coin.C10);
                } else if (args[1].equals("25")) {
                    pig.addCoin(Coin.C25);
                } else if (args[1].equals("50")) {
                    pig.addCoin(Coin.C50);
                } else if (args[1].equals("100")) {
                    pig.addCoin(Coin.C100);
                }
            } 
            else if (args[0].equals("init")) {
                pig = new Pig(number(args[1]));
            } 
            else if (args[0].equals("addItem")) {
                pig.addItem(new Item(args[1], number(args[2])));
            } 
            else if (args[0].equals("break")) {
                pig.breakPig();
            } 
            else if (args[0].equals("extractCoins")) {
                write("[" + pig.extractCoins().stream().map(coin -> "" + coin.str()).collect(Collectors.joining(", "))
                        + "]");
            }

            else if (args[0].equals("extractItems")) {
                write("[" + pig.extractItems().stream().map(item -> "" + item.str()).collect(Collectors.joining(", "))
                        + "]");
            }
            else if (args[0].equals("show")) {
                write(pig.str());
            }
            else {
                write("fail: invalid command");
            }
        }
    }

    public static Scanner scanner = new Scanner(System.in);

    public static String input() {
        return scanner.nextLine();
    }

    public static int number(String number) {
        return Integer.parseInt(number);
    }

    public static void write(String str) {
        System.out.println(str);
    }
}