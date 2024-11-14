class Adapter {
    // private Mercantil mercantil = new Mercantil(0);
    public void init(int qtd_caixas) {
        // this.mercantil = new Mercantil(qtd_caixas);
    }

    public void arrive(String name) {
        // this.mercantil.chegar(new Pessoa(name));
    }
    public void call(int indice) {
        // this.mercantil.chamarNoCaixa(indice);
    }
    public void finish(int indice) {
        // this.mercantil.finalizar(indice);
    }

    public void show() {
        // System.out.println(this.mercantil.toString());
    }
}

public class Student {
    public static void main(String args[]) {
        System.out.println("Rodando o arquivo do estudante");
    }
}