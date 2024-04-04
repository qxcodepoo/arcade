import java.util.*;
import java.util.stream.Collectors;

class Pessoa {
    private String nome;
    Pessoa(String nome) {
    }
    public String getNome() {
    }
}

class Mercantil {
    private ArrayList < Pessoa > caixas; //caixas do supermercado
    private LinkedList < Pessoa > esperando; //lista de clientes esperando
    //inicializa esperando como uma lista de tamanho vazio
    //inicializa caixas como um vetor de tamanho qtd_caixas com todas as posições iguais a null
    Mercantil(int qtd_caixas) { //número de caixas no mercado
    }
    //verifica se o indice é válido para acessar os
    public boolean validarIndice(int indice) {
    }
    public void chegar(Pessoa person) {
    }
    //1. verifica se o indice é válido
    //2. verifica se o caixa chamado está vazio
    //3. verifica se existe alguem na lista de espera
    //4. se tudo estiver ok, o primeiro cliente da lista de espera é movido para este caixa
    public boolean chamarNoCaixa(int indice) {
    }
    //1. verifica se o indice é válido
    //2. verifica se este caixa possui um cliente
    //3. Se tudo estiver ok, o cliente é removido do caixa e volta a ser null para indicar que está vazio
    public Pessoa finalizar(int indice) {
    }
    public String toString() {
        var caixas = this.caixas.stream()
                         .map(pessoa -> pessoa == null ? "-----" : pessoa.getNome())
                         .collect(Collectors.joining(", "));
        var espera = this.esperando.stream()
                         .map(pessoa -> pessoa.getNome())
                         .collect(Collectors.joining(", "));
        return "Caixas: [" + caixas + "]\nEspera: [" + espera + "]";
    }
}


class Solver {
    static Mercantil mercantil = new Mercantil(0);
    public static void main(String[] _args) {
        while(true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if     (args[0].equals("init"     )) { mercantil = new Mercantil(number(args[1])); }
            else if(args[0].equals("arrive"   )) { mercantil.chegar(new Pessoa(args[1]));      }
            else if(args[0].equals("call"     )) { mercantil.chamarNoCaixa(number(args[1]));   }
            else if(args[0].equals("finish"   )) { mercantil.finalizar(number(args[1]));       }
            else if(args[0].equals("show"     )) { write(mercantil.toString());                }
            else if(args[0].equals("end"      )) { break;                                      }
            else                                 { write("fail: comando invalido");      }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();       }
    public static void write(String value) { System.out.println(value);       }
    public static int number(String str)   { return Integer.parseInt(str);    }
}