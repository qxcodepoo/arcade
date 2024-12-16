import java.util.*;


class Shell {
    public static void main(String[] _args) {
        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("init")) { // TODO
                // var qtd_caixas = Integer.parseInt(par[1]);
            } else if (cmd.equals("show")) { // TODO
            } else if (cmd.equals("arrive")) { // TODO
                // var nome = par[1];
            } else if (cmd.equals("call")) { // TODO
                // var indice = Integer.parseInt(par[1]);
            } else if (cmd.equals("finish")) { // TODO
                // var indice = Integer.parseInt(par[1]);
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");

            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}