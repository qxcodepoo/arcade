import java.util.*;


public class Shell {
    
    public static void main(String[] a) {
        // CRIE SEU CARRO AQUI
        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                // MOSTRE OS ATRIBUTOS DO CARRO
            } 
            else if (cmd.equals("enter")) {
                // TENTE EMBARCAR UMA PESSOA
            } 
            else if (cmd.equals("leave")) {
                // TENTE DESEMBARCAR UMA PESSOA
            } 
            else if (cmd.equals("fuel")) {
                // AUMENTE A QUANTIDADE DE COMBUSTIVEL
                // int increment = Integer.parseInt(par[1]);
            } 
            else if (cmd.equals("drive")) {
                // TENTE DIRIGIR UMA CERTA DISTANCIA
                // int distance = Integer.parseInt(par[1]);
            }  
            else {
                System.out.println("fail: comando invalido");
            }
        }   
    }
    private static Scanner scanner = new Scanner(System.in);
}
