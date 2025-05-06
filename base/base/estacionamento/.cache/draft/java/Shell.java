import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;


public class Shell {

    public static void main(String[] a) {
        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
            }
            else if (cmd.equals("init")) {
            }
            else if (cmd.equals("estacionar")) {
                // var veiculo = par[1];
                // var id = par[2];
            }
            else if (cmd.equals("pagar")) {
                // CHAME OS METODOS DE PAGAMENTO E SAIDA
                // var veiculo = par[1];
            }
            else if (cmd.equals("tempo")) {
                // var tempo = Integer.parseInt(par[1]);
            }
            else {
                System.out.println("fail: comando inválido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
