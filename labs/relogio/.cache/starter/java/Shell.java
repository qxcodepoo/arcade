import java.util.*;


public class Shell {
    public static void main(String[] a) {
        // CRIE SEU RELÓGIO AQUI
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                // MOSTRE O RELÓGIO AQUI
            }
            else if (cmd.equals("init")) {
                // INICIE O RELÓGIO AQUI utilizando o construtor
                // int hour = Integer.parseInt(par[1]);
                // int minute = Integer.parseInt(par[2]);
                // int second = Integer.parseInt(par[3]);
            }
            else if (cmd.equals("set")) {
                // CHAME OS MÉTODOS SET AQUI
                // int hour = Integer.parseInt(par[1]);
                // int minute = Integer.parseInt(par[2]);
                // int second = Integer.parseInt(par[3]);
            }
            else if (cmd.equals("next")) {
                // CHAME O MÉTODO nextSecond AQUI
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
