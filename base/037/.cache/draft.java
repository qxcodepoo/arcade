import java.util.*;


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
        StringBuilder Mercantil = new StringBuilder();
        Mercantil.append("Caixas: |");
        for (int i = 0; i < (int) this.caixas.size(); i++) {
            Mercantil.append(" " + i + ":");
            if (this.caixas.get(i) != null) {
                Mercantil.append(" " + caixas.get(i).getNome());
            } else {
                Mercantil.append("-----");
            }
            Mercantil.append(" |");
        }
        Mercantil.append("\nEspera: [");
        for (int i = 0; i < this.esperando.size(); i++) {
            Mercantil.append(this.esperando.get(i).getNome());
            if (i < this.esperando.size() - 1) {
                Mercantil.append(", ");
            }
        }
        Mercantil.append("]\n");
        return Mercantil.toString();
    }
}


class Solver {
    static Shell sh = new Shell();
    static Mercantil mercantil = new Mercantil(0);
    public static void main(String[] args) {
        sh.addCmd("init",   () -> mercantil = new Mercantil(sh.getInt(1)));
        sh.addCmd("call",   () -> mercantil.chamarNoCaixa(sh.getInt(1)));
        sh.addCmd("finish", () -> mercantil.finalizar(sh.getInt(1)));
        sh.addCmd("arrive", () -> mercantil.chegar(new Pessoa(sh.getStr(1))));
        sh.addCmd("show",   () -> System.out.print(mercantil.toString()));
        sh.evaluate();
    }
}