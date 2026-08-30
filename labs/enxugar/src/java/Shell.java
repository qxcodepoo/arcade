import java.util.Scanner;
// @DROP
class Towel {
    private String color;
    private String size;
    private int wetness;

    public Towel(String color, String size) {
        this.color = color;
        this.size = size;
        this.wetness = 0;
    }

    public Towel() {
        this("", "P");
    }

    public boolean dry(int amount) {
        int limit = this.getMaxWetness();
        if (this.wetness + amount > limit) {
            this.wetness = limit;
            return false;
        }
        this.wetness = Math.min(this.wetness + amount, limit);
        return true;
    }

    public void wringOut() {
        this.wetness = 0;
    }

    public int getMaxWetness() {
        switch (this.size) {
            case "P":
                return 10;
            case "M":
                return 20;
            case "G":
                return 30;
            default:
                return 0;
        }
    }

    public boolean isDry() {
        return this.wetness == 0;
    }

    public String toString() {
        return "Cor: " + this.color + ", Tamanho: " + this.size + ", Umidade: " + this.wetness;
    }
}

// @KEEP

public class Shell {
    
    public static void main(String[] a) {
        // CRIE SUA TOALHA AQUI
        // @COM
        var towel = new Towel();
        // @KEEP
        
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("criar")) { // ATUALIZE SUA TOALHA USANDO O CONSTRUTOR
                // @COM
                var cor = par[1];
                var tamanho = par[2];
                // @DROP
                towel = new Towel(cor, tamanho);
            }
            else if (cmd.equals("mostrar")) { // MOSTRE SUA TOALHA
                // @DROP
                System.out.println(towel.toString());
            }
            else if (cmd.equals("enxugar")) { // ENXUGUE
                // @COM
                var quantidade = Integer.parseInt(par[1]);
                // @DROP
                if (!towel.dry(quantidade)) {
                    System.out.println("fail: toalha nao conseguiu enxugar tudo");
                }
            }
            else if (cmd.equals("seca")) { // OBTENHA SE ESTA SECA E IMPRIMA SIM OU NAO
                // @DROP
                if (towel.isDry()) {
                    System.out.println("sim");
                } else {
                    System.out.println("nao");
                }
            }
            else if (cmd.equals("torcer")) { // CHAME O METODO TORCER
                // @DROP
                towel.wringOut();
            }
            else {
                System.out.println("comando invalido");
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
}
