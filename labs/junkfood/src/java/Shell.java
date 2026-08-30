import java.util.*;

// @DROP
class Slot {
    String nome;
    int qtd;
    double preco;

    public Slot(String nome, int qtd, double preco) {
        this.nome = nome;
        this.qtd = qtd;
        this.preco = preco;
    }

    public Slot() {
        this("empty", 0, 0.0);
    }

    @Override
    public String toString() {
        return String.format("[%8s :%2d U : %.2f RS]", nome, qtd, preco);
    }
}

class Machine {
    List<Slot> espirais;
    double saldo;
    double lucro;

    public Machine(int qtd) {
        this.espirais = new ArrayList<>(Collections.nCopies(qtd, new Slot()));
        this.saldo = 0;
        this.lucro = 0;
    }

    public Slot get(int indice) {
        if (indice < 0 || indice >= espirais.size()) {
            System.out.println("fail: indice nao existe");
            return new Slot();
        }
        return espirais.get(indice);
    }

    public void setSlot(int indice, String name, int qtd, double price) {
        if (indice < 0 || indice >= espirais.size()) {
            System.out.println("fail: indice nao existe");
            return;
        }
        if (qtd < 0) {
            System.out.println("fail: quantidade invalida");
            return;
        }
        espirais.set(indice, new Slot(name, qtd, price));
    }

    public void limpar(int indice) {
        if (indice >= 0 && indice < espirais.size()) {
            espirais.set(indice, new Slot());
        }
    }

    public void inserirDinheiro(double value) {
        if (value <= 0) {
            System.out.println("fail: valor invalido");
            return;
        }
        saldo += value;
    }

    public double pedirTroco() {
        double troco = saldo;
        saldo = 0;
        return troco;
    }

    public void comprar(int ind) {
        if (ind < 0 || ind >= espirais.size()) {
            System.out.println("fail: indice nao existe");
            return;
        }
        Slot slot = espirais.get(ind);
        if (saldo < slot.preco) {
            System.out.println("fail: saldo insuficiente");
            return;
        }
        if (slot.qtd == 0) {
            System.out.println("fail: espiral sem produtos");
            return;
        }
        saldo -= slot.preco;
        slot.qtd -= 1;
        System.out.println("voce comprou um " + slot.nome);
    }

    public double getSaldo() {
        return saldo;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("saldo: %.2f\n", saldo));
        for (int i = 0; i < espirais.size(); i++) {
            sb.append(i).append(" ").append(espirais.get(i).toString()).append("\n");
        }
        // removing last \n
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
}

// @KEEP
public class Shell {

    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Machine machine = new Machine(0); // @DROP

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            String[] argsSplit = line.split(" ");
            String cmd = argsSplit[0];

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("show")) {
                // @DROP
                System.out.println(machine.toString());
            } else if (cmd.equals("init")) {
                // @COM
                int qtdEspirais = Integer.parseInt(argsSplit[1]);
                // @DROP
                machine = new Machine(qtdEspirais);
            } else if (cmd.equals("limpar")) {
                // @COM
                int indice = Integer.parseInt(argsSplit[1]);
                // @DROP
                machine.limpar(indice);
            } else if (cmd.equals("dinheiro")) {
                // @COM
                double value = Double.parseDouble(argsSplit[1]);
                // @DROP
                machine.inserirDinheiro(value);
            } else if (cmd.equals("comprar")) {
                // @COM
                int ind = Integer.parseInt(argsSplit[1]);
                // @DROP
                machine.comprar(ind);
            } else if (cmd.equals("set")) {
                // @COM
                int indice = Integer.parseInt(argsSplit[1]);
                String nome = argsSplit[2];
                int qtd = Integer.parseInt(argsSplit[3]);
                double preco = Double.parseDouble(argsSplit[4]);
                // @DROP
                machine.setSlot(indice, nome, qtd, preco);
            } else if (cmd.equals("troco")) {
                // @COM
                double troco = machine.pedirTroco();
                // @DROP
                System.out.println("voce recebeu " + String.format("%.2f", troco) + " RS");
            } else {
                System.out.println("comando invalido");
            }
        }
    }
}
