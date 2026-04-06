import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] a) {
        ArrayList<String> vet = new ArrayList<>();

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
            var args = line.split(" ");
            var cmd = args[0];

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("push")) {
                for (int i = 1; i < args.length; i++) {
                    vet.add(args[i]);
                }
            } else if (cmd.equals("show")) {
                System.out.println("[" + String.join(", ", vet) + "]");
            } else if (cmd.equals("erase")) {
                var pos = Integer.parseInt(args[1]);
                vet.remove(pos);
            } else if (cmd.equals("media")) {
                double soma = 0;
                for (int i = 0; i < vet.size(); i++) {
                    soma += Double.parseDouble(vet.get(i));
                }
                System.out.println(String.format("%.2f", soma / vet.size()));
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
