import java.util.*;

// @DROP
class Garment {
    private String size = "";

    public boolean setSize(String size) {
        List<String> validSizes = Arrays.asList("PP", "P", "M", "G", "GG", "XG");
        if (!validSizes.contains(size)) {
            return false;
        }
        this.size = size;
        return true;
    }

    public String getSize() {
        return this.size;
    }

    @Override
    public String toString() {
        return "size: (" + this.size + ")";
    }
}

// @KEEP
public class Shell {    
    public static void main(String[] args) {
        // CRIE SEU OBJETO AQUI
        // @DROP
        Garment garment = new Garment();
        // @KEEP
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);
            
            var par = line.split(" ");
            var cmd = par[0];
            
            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("size")) { // TENTE ATRIBUIR UM TAMANHO A ROUPA
                // @COM
                String size = par[1];
                // @DROP
                if (!garment.setSize(size)) {
                    System.out.println("fail: Valor inválido, tente PP, P, M, G, GG ou XG");
                }
            }
            else if (cmd.equals("show")) { // MOSTRE A ROUPA
                // @DROP
                System.out.println(garment.toString());
            }
            else {
                System.out.println("fail: Comando inválido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
