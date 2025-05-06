
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.stream.Collectors;

public class Shell {
    public static void main(String[] _args) {

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) {
                // int maxVolume = Integer.parseInt(par[1]);
            }
            else if (cmd.equals("show")) {
                // Imprima o estado do porquinho
            }
            else if (cmd.equals("addCoin")) {
                // var coin = par[1];
            }
            else if (cmd.equals("addItem")) {
                // var item = par[1];
                // var volume = Integer.parseInt(par[2]);
            }
            else if (cmd.equals("break")) {
                // pig.breakPig();
            }
            else if (cmd.equals("extractCoins")) {
                // Obtenha as moedas usando o método extractCoins
                // Imprima as moedas obtidas
            }
            else if (cmd.equals("extractItems")) {
                // Obtenha os itens usando o método extractItems
                // Imprima os itens obtidos
            }
            else {
                System.out.println("fail: invalid command");
            }
        }
    }

    public static Scanner scanner = new Scanner(System.in);
}
