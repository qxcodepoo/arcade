import java.util.*;


class Shell {
    public static void main(String[] _args) {
        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) { 
                // var qtd_caixas = Integer.parseInt(par[1]);
            }
            else if (cmd.equals("show")) { 
            }
            else if (cmd.equals("arrive")) { 
                // var nome = par[1];
            }
            else if (cmd.equals("call")) { 
                // var indice = Integer.parseInt(par[1]);
            }
            else if (cmd.equals("finish")) { 
                // var indice = Integer.parseInt(par[1]);
            }
            else {
                System.out.println("fail: comando invalido");

            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
