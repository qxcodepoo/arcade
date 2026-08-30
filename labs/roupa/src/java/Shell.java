import java.util.*;

// @DROP
class Roupa {
    private String size = "";

    public void setSize(String size) {
        List<String> validSizes = Arrays.asList("PP", "P", "M", "G", "GG");
        if (!validSizes.contains(size)) {
            System.out.println("fail: Valor inválido, tente PP, P, M, G, GG ou XG");
            return;
        }
        this.size = size;
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
        Roupa roupa = new Roupa();
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
                roupa.setSize(size);
            }
            else if (cmd.equals("show")) { // MOSTRE A ROUPA
                // @DROP
                System.out.println(roupa.toString());
            }
            else {
                System.out.println("fail: Comando inválido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
