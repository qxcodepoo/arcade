
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.stream.Collectors;

// @DROP
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

    public String toString() {
        return String.format("%.2f:%d", value, volume);
    }
}



class Item {
    private String label;
    private int volume;

    public Item(String label, int volume) {
        this.label = label;
        this.volume = volume;
    }

    public int getVolume() {
        return volume;
    }

    public String getLabel() {
        return label;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public void setLabel(String label) {
        this.label = label;
    }

    public String toString() {
        return String.format("%s:%d", label, volume);
    }
}

class Pig {
    private ArrayList<Item> itens = new ArrayList<>();
    private ArrayList<Coin> coins = new ArrayList<>();
    private int volumeMax = 0;
    private boolean broken = false;

    public Pig(int volumeMax) {
        this.volumeMax = volumeMax;
    }

    public boolean addCoin(Coin coin) {
        if (broken) {
            System.out.println("fail: the pig is broken");
            return false;
        }
        if (coin.getVolume() + getVolume() > volumeMax) {
            System.out.println("fail: the pig is full");
            return false;
        }
        coins.add(coin);
        return true;
    }

    public boolean addItem(Item item) {
        if (broken) {
            System.out.println("fail: the pig is broken");
            return false;
        }
        if (item.getVolume() + getVolume() > volumeMax) {
            System.out.println("fail: the pig is full");
            return false;
        }
        itens.add(item);
        return true;
    }

    public boolean breakPig() {
        if (broken) {
            System.out.println("fail: the pig is already broken");
            return false;
        }
        broken = true;
        return true;
    }

    public ArrayList<Coin> extractCoins() {
        if (!broken) {
            System.out.println("fail: you must break the pig first");
            return new ArrayList<>();
        }
        ArrayList<Coin> extractedCoins = new ArrayList<>(coins);
        coins.clear();
        return extractedCoins;
    }

    public ArrayList<Item> extractItems() {
        if (!broken) {
            System.out.println("fail: you must break the pig first");
            return new ArrayList<>();
        }
        ArrayList<Item> extractedItems = new ArrayList<>(itens);
        itens.clear();
        return extractedItems;
    }

    public double getValue() {
        double value = 0;
        for (Coin coin : coins) {
            value += coin.getValue();
        }
        return value;
    }

    public int getVolume() {
        if (broken) {
            return 0;
        }
        int volume = 0;
        for (Coin coin : coins) {
            volume += coin.getVolume();
        }
        for (Item item : itens) {
            volume += item.getVolume();
        }
        return volume;
    }

    public String toString() {
        StringJoiner coinsStr = new StringJoiner(", ");
        coins.stream().map(n -> n.toString()).forEach(coinsStr::add);
        StringJoiner itens = new StringJoiner(", ");
        this.itens.stream().map(n -> n.toString()).forEach(itens::add);

        return String.format("state=%s : coins=[%s] : items=[%s] : value=%.2f : volume=%d/%d",
                (broken ? "broken" : "intact"), coinsStr.toString(), itens.toString(), getValue(), getVolume(), volumeMax);
    }

}

// @KEEP
public class Shell {
    public static void main(String[] _args) {
        // @DROP
        Pig pig = new Pig(0);
        // @KEEP

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                // @COM
                int maxVolume = Integer.parseInt(par[1]);
                // @DROP
                pig = new Pig(maxVolume);
            }
            else if (cmd.equals("show")) {
                // Imprima o estado do porquinho
                // @DROP
                System.out.println(pig.toString());
            }
            else if (cmd.equals("addCoin")) {
                // @COM
                var coin = par[1];
                // @DROP
                if (coin.equals("10")) {
                    pig.addCoin(Coin.C10);
                } else if (coin.equals("25")) {
                    pig.addCoin(Coin.C25);
                } else if (coin.equals("50")) {
                    pig.addCoin(Coin.C50);
                } else if (coin.equals("100")) {
                    pig.addCoin(Coin.C100);
                } else {
                    System.out.println("fail: invalid coin");
                }
            }
            else if (cmd.equals("addItem")) {
                // @COM
                var item = par[1];
                var volume = Integer.parseInt(par[2]);
                // @DROP
                pig.addItem(new Item(item, volume));
            }
            else if (cmd.equals("break")) {
                // @COM
                pig.breakPig();
            }
            else if (cmd.equals("extractCoins")) {
                // Obtenha as moedas usando o método extractCoins
                // Imprima as moedas obtidas
                // @DROP
                var coins = pig.extractCoins().stream().map(coin -> "" + coin.toString()).collect(Collectors.joining(", "));
                System.out.println("[" + coins + "]");
            }
            else if (cmd.equals("extractItems")) {
                // Obtenha os itens usando o método extractItems
                // Imprima os itens obtidos
                // @DROP
                var items = pig.extractItems().stream().map(item -> "" + item.toString()).collect(Collectors.joining(", "));
                System.out.println("[" + items + "]");
            }
            else {
                System.out.println("fail: invalid command");
            }
        }
    }

    public static Scanner scanner = new Scanner(System.in);
}