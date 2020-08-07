import java.util.ArrayList;
import java.util.Scanner;

class Pessoa{
    String nome;
    int idade;
    public Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }
    public String toString(){
        return nome + ":" + idade;
    }
}

class Carro{
    Pessoa motorista;
    ArrayList<Pessoa> passageiros; //ISSO NAO EH UM ARRAYLIST
    public int maxPass;

    public Carro(){
        this.maxPass = 2;
        this.passageiros = new ArrayList<>();
        for(int i = 0; i < this.maxPass; i++)
            this.passageiros.add(null);
    }

    public void in(Pessoa pessoa, int indice){
        if(indice < 0 || indice >= this.maxPass){
            System.out.println("Posicao nao existe");
            return;
        }
        if(this.passageiros.get(indice) != null){
            System.out.println("Posicao esta ocupada");
            return;    
        }
        this.passageiros.set(indice, pessoa);
    }

    public void out(String nome){
        for(int i = 0; i < this.passageiros.size(); i++)
            if(this.passageiros.get(i) != null && passageiros.get(i).nome.equals(nome)){
                this.passageiros.set(i, null);
                break;
            }
    }

    public String toString(){
        String saida = "[--O--|------]\n";
        saida += this.passageiros.get(0) + "|" + this.passageiros.get(1) + "\n";
        saida += this.passageiros.get(2) + "|" + this.passageiros.get(3) + "|" +
        this.passageiros.get(4) + "\n";
        return saida;
    }
}

public class Solver {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Carro carro = new Carro();
        while(true){
            String line = scanner.nextLine();
            String[] ui = line.split(" ");
            if(ui[0].equals("end")){
                break;
            }else if(ui[0].equals("show")){
                System.out.println(carro);
            }else if(ui[0].equals("in")){//nome idade indice
                carro.in(new Pessoa(ui[1], Integer.parseInt(ui[2])), Integer.parseInt(ui[3]));
            }else if(ui[0].equals("init")){//init maxPass maxGas
                carro = new Carro();
            }else if(ui[0].equals("remover")){//init maxPass maxGas
                carro.out(ui[1]);
            }else{
                System.out.println("fail: comando invalido");
            }
        }
        scanner.close();            
    }

}