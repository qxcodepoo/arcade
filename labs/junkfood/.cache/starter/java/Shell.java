import java.util.*;

public class Shell {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            String[] argsSplit = line.split(" ");
            String cmd = argsSplit[0];

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("show")) {
            } else if (cmd.equals("init")) {
                // int qtdEspirais = Integer.parseInt(argsSplit[1]);
            } else if (cmd.equals("limpar")) {
                // int indice = Integer.parseInt(argsSplit[1]);
            } else if (cmd.equals("dinheiro")) {
                // double value = Double.parseDouble(argsSplit[1]);
            } else if (cmd.equals("comprar")) {
                // int ind = Integer.parseInt(argsSplit[1]);
            } else if (cmd.equals("set")) {
                // int indice = Integer.parseInt(argsSplit[1]);
                // String nome = argsSplit[2];
                // int qtd = Integer.parseInt(argsSplit[3]);
                // double preco = Double.parseDouble(argsSplit[4]);
            } else if (cmd.equals("troco")) {
                // double troco = machine.pedirTroco();
            } else {
                System.out.println("comando invalido");
            }
        }
    }
}
