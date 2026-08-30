import java.util.*;

// @DROP
import java.util.*;
import java.util.stream.Collectors;

class Pessoa {
    private String nome;
    Pessoa(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return this.nome;
    }
}

class Mercantil {
    private ArrayList < Pessoa > caixas; //caixas do supermercado
    private LinkedList < Pessoa > esperando; //lista de clientes esperando
    Mercantil(int qtd_caixas) { //número de caixas no mercado
        this.caixas    = new ArrayList <Pessoa> (Collections.nCopies(qtd_caixas, null));
        this.esperando = new LinkedList <Pessoa> ();
    }
    public boolean validarIndice(int indice) {
        if (indice < 0 || indice >= (int) this.caixas.size()) {
            System.out.println("fail: caixa inexistente");
            return false;
        }
        return true;
    }
    public void chegar(Pessoa person) {
        this.esperando.add(person);
    }
    public boolean chamarNoCaixa(int indice) {
        if (!validarIndice(indice)) {
            return false;
        }
        if (this.caixas.get(indice) != null) {
            System.out.println("fail: caixa ocupado");
            return false;
        }
        if (this.esperando.isEmpty()) {
            System.out.println("fail: sem clientes");
            return false;
        }
        this.caixas.set(indice, this.esperando.getFirst());
        this.esperando.removeFirst();
        return true;
    }
    public Pessoa finalizar(int indice) {
        if (!validarIndice(indice)) {
            return null;
        }
        if (this.caixas.get(indice) == null) {
            System.out.println("fail: caixa vazio");
            return null;
        }
        return this.caixas.set(indice, null);
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
// @KEEP

class Shell {
    public static void main(String[] _args) {
        // @DROP
        Mercantil mercantil = new Mercantil(3);
        // @KEEP
        while(true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("init")) { 
                // @COM
                var qtd_caixas = Integer.parseInt(par[1]);
                // @DROP
                mercantil = new Mercantil(qtd_caixas);
            }
            else if (cmd.equals("show")) { 
                // @DROP
                System.out.println(mercantil);
            }
            else if (cmd.equals("arrive")) { 
                // @COM
                var nome = par[1];
                // @DROP
                mercantil.chegar(new Pessoa(nome));
            }
            else if (cmd.equals("call")) { 
                // @COM
                var indice = Integer.parseInt(par[1]);
                // @DROP
                mercantil.chamarNoCaixa(indice);
            }
            else if (cmd.equals("finish")) { 
                // @COM
                var indice = Integer.parseInt(par[1]);
                // @DROP
                mercantil.finalizar(indice);
            }
            else {
                System.out.println("fail: comando invalido");

            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}