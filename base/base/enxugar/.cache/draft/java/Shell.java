import java.util.Scanner;


public class Shell {
    
    public static void main(String[] a) {
        // CRIE SUA TOALHA AQUI
        // Toalha toalha = new Toalha();
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("criar")) { // ATUALIZE SUA TOALHA USANDO O CONSTRUTOR
                // var cor = par[1];
                // var tamanho = par[2];
            }
            else if (cmd.equals("mostrar")) { // MOSTRE SUA TOALHA
            }
            else if (cmd.equals("enxugar")) { // ENXUGUE
                // var quantidade = Integer.parseInt(par[1]);
            }
            else if (cmd.equals("seca")) { // OBTENHA SE ESTA SECA E IMPRIMA SIM OU NAO
            }
            else if (cmd.equals("torcer")) { // CHAME O METODO TORCER
            }
            else {
                System.out.println("comando invalido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
