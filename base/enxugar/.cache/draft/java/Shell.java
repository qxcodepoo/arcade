import java.util.Scanner;


public class Shell {
    
    public static void main(String[] a) {
        // Toalha toalha = new Toalha();
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("criar")) {
                // TODO
                // var cor = par[1];
                // var tamanho = par[2];
            } else if (cmd.equals("enxugar")) {
                // TODO
                // var quantidade = Integer.parseInt(par[1]);
            } else if (cmd.equals("seca")) {
                // TODO
            } else if (cmd.equals("torcer")) {
                // TODO
            } else if (cmd.equals("mostrar")) {
                // TODO
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("comando invalido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
