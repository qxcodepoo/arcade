import java.util.*;

public class Shell {    
    public static void main(String[] args) {
        // CRIE SEU OBJETO AQUI
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
            
            var par = line.split(" ");
            var cmd = par[0];
            
            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("size")) { // TENTE ATRIBUIR UM TAMANHO A ROUPA
                // String size = par[1];
            }
            else if (cmd.equals("show")) { // MOSTRE A ROUPA
            }
            else {
                System.out.println("fail: Comando inválido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
