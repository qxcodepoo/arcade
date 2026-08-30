import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

// @DROP
abstract class Veiculo {

    private String id;
    protected String tipo;
    protected int horaEntrada;

    public Veiculo(String id, String tipo) {
        this.id = id;
        this.tipo = tipo;
    }

    public String getId() {
        return id;
    }

    public String getTipo() {
        return tipo;
    }

    public int getEntrada() {
        return horaEntrada;
    }

    public void setEntrada(int horaEntrada) {
        this.horaEntrada = horaEntrada;
    }

    public abstract void calcularValor(int horaSaida);

    @Override
    public String toString() {
        return String.format(
            "%10s-:-%10s-:-%s",
            this.tipo,
            this.id,
            this.horaEntrada
        )
            .replace(' ', '_')
            .replace('-', ' ');
    }
}

class Moto extends Veiculo {

    public Moto(String id) {
        super(id, "Moto");
    }

    @Override
    public void calcularValor(int horaSaida) {
        float valor = (horaSaida - this.getEntrada()) / 20;
        DecimalFormat df = new DecimalFormat("#.00");
        String str_valor = df.format(valor);
        System.out.println(
            this.getTipo() +
            " chegou " +
            this.getEntrada() +
            " saiu " +
            horaSaida +
            ". Pagar R$ " +
            str_valor
        );
    }
}

class Carro extends Veiculo {

    public Carro(String id) {
        super(id, "Carro");
    }

    @Override
    public void calcularValor(int horaSaida) {
        float valor = (horaSaida - this.getEntrada()) / 10;

        if (valor < 5) {
            valor = 5;
        }
        DecimalFormat df = new DecimalFormat("#.00");
        System.out.println(
            this.getTipo() +
            " chegou " +
            this.getEntrada() +
            " saiu " +
            horaSaida +
            ". Pagar R$ " +
            df.format(valor)
        );
    }
}

class Bike extends Veiculo {

    public Bike(String id) {
        super(id, "Bike");
    }

    @Override
    public void calcularValor(int horaSaida) {
        System.out.println(
            this.getTipo() +
            " chegou " +
            this.getEntrada() +
            " saiu " +
            horaSaida +
            ". Pagar R$ 3.00"
        );
    }
}

class Estacionamento {

    private ArrayList<Veiculo> veiculos;
    private int horaAtual;

    public Estacionamento() {
        veiculos = new ArrayList<Veiculo>();
    }

    private int procurarVeiculo(String id) {
        int indice = -1;

        for (Veiculo v : veiculos) {
            if (v.getId().equals(id)) {
                indice = veiculos.indexOf(v);
            }
        }

        return indice;
    }

    public void estacionar(Veiculo v) {
        if (procurarVeiculo(v.getId()) == -1) {
            v.setEntrada(horaAtual);
            veiculos.add(v);
        }
    }

    public void pagar(String id) {
        int i = procurarVeiculo(id);
        Veiculo v = veiculos.get(i);
        v.calcularValor(horaAtual);
    }

    public void sair(String id) {
        int i = procurarVeiculo(id);
        veiculos.remove(i);
    }

    public void passarTempo(int tempo) {
        this.horaAtual += tempo;
    }

    public String toString() {
        String s = "";

        for (Veiculo v : veiculos) {
            s += v.toString() + "\n";
        }

        s += "Hora atual: " + horaAtual;

        return s;
    }
}

// @KEEP

public class Shell {

    public static void main(String[] a) {
        // @DROP
        Estacionamento estacionamento = new Estacionamento();
        // @KEEP
        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")) {
                break;
            }
            else if (cmd.equals("show")) {
                // @DROP
                System.out.println(estacionamento);
            }
            else if (cmd.equals("init")) {
                // @DROP
                estacionamento = new Estacionamento();
            }
            else if (cmd.equals("estacionar")) {
                // @COM
                var veiculo = par[1];
                var id = par[2];
                // @DROP
                if (veiculo.equals("moto")) {
                    estacionamento.estacionar(new Moto(id));
                } else if (veiculo.equals("carro")) {
                    estacionamento.estacionar(new Carro(id));
                } else if (veiculo.equals("bike")) {
                    estacionamento.estacionar(new Bike(id));
                }
            }
            else if (cmd.equals("pagar")) {
                // CHAME OS METODOS DE PAGAMENTO E SAIDA
                // @COM
                var veiculo = par[1];
                // @DROP
                estacionamento.pagar(veiculo);
                estacionamento.sair(veiculo);
            }
            else if (cmd.equals("tempo")) {
                // @COM
                var tempo = Integer.parseInt(par[1]);
                // @DROP
                estacionamento.passarTempo(tempo);
            }
            else {
                System.out.println("fail: comando inválido");
            }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
}
