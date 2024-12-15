import java.util.*;

public class Shell{
    
    public static void main(String[] args) {
        // CRIE SUA MOTO AQUI

        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("init")) {
                // CRIE SUA MOTO AQUI
                // var power = Integer.parseInt(par[1]);
            } else if (cmd.equals("show")) {
                // MOSTRE SUA MOTO AQUI
            } else if (cmd.equals("enter")) {
                // CRIE UM OBJETO PESSOA AQUI
                // DEPOIS INSIRA NA MOTO
                // var name = par[1];
                // var age = Integer.parseInt(par[2]);
            } else if (cmd.equals("leave")) {
                // RETIRE A PESSOA DA MOTO
                // MOSTRE A PESSOA RETIRADA AQUI
            } else if (cmd.equals("buy")) {
                // COMPRE TEMPO
                // var time = Integer.parseInt(par[1]);
            } else if (cmd.equals("drive")) {
                // DIRIJA A MOTO
                // var time = Integer.parseInt(par[1]);
            } else if (cmd.equals("honk")) {
                // BUZINE
            } else if (cmd.equals("end")) {
                break;
            } else {
                System.out.println("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
