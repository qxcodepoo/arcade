import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.stream.Collectors;

class MsgException extends RuntimeException {
    public MsgException(String message) {
        super(message);
    }
}

abstract class Funcionario {
    protected String nome;
    protected int bonus;
    protected int diarias;
    protected int maxDiarias;

    public Funcionario(String nome) {
        this.nome = nome;
        this.diarias = 0;
        this.maxDiarias = 0;
    }

    public String getNome() {
        return nome;
    }

    public void setBonus(int bonus) {
      this.bonus = bonus;
    }
    //se não atingiu o máximo, adicione mais uma diária
    //se atingiu o máximo, lance uma MsgException
    public void addDiaria() {
        if (this.diarias < this.maxDiarias)
            this.diarias++;
        else
            throw new MsgException("fail: limite de diarias atingido");
    }
    //retorna bonus + diarias * 100
    public int getSalario() {
        return bonus + diarias * 100;
    }
}

class Professor extends Funcionario {
    protected String classe;

    //inicializa classe e muda maxDiarias para 2
    public Professor(String nome, String classe) {
        super(nome);
        this.classe = classe;
        this.maxDiarias = 2;
    }

    public String getClasse() {
        return classe;
    }
    //lógica do salário do professor
    //usa o super.getSalario para pegar bonus e diarias
    public int getSalario() {
        int salario;
        switch (classe) {
        case "A":
            salario = 3000;
            break;
        case "B":
            salario = 5000;
            break;
        case "C":
            salario = 7000;
            break;
        case "D":
            salario = 9000;
            break;
        case "E":
            salario = 11000;
            break;
        default:
            salario = 0;
        }
        return salario + super.getSalario();
    }

    @Override
    public String toString() {
        return "prof:" + getNome() + ":" + getClasse() + ":" + this.getSalario();
    }
}

class STA extends Funcionario {
    protected int nivel;

    public STA(String nome, int nivel) {
        super(nome);
        this.nivel = nivel;
        this.maxDiarias = 1;
    }

    public int getNivel() {
        return nivel;
    }

    public int getSalario() {
        return 3000 + 300 * this.nivel + super.getSalario();
    }

    @Override
    public String toString() {
        return "sta:" + getNome() + ":" + getNivel() + ":" + getSalario();
    }
}

class Tercerizado extends Funcionario {
    protected int horas;
    protected boolean isSalubre = false;

    public Tercerizado(String nome, int horas, String isSalubre) {
        super(nome);
        this.horas = horas;
        this.isSalubre = isSalubre.equals("sim");
    }

    public int getHoras() {
        return horas;
    }

    public String getIsSalubre() {
        return isSalubre ? "sim" : "nao";
    }

    public int getSalario() {
        return (4 * horas) + (this.isSalubre ? 500 : 0) + super.getSalario();
    }

    public void addDiaria() {
        throw new MsgException("fail: terc nao pode receber diaria");
    }

    @Override
    public String toString() {
        return "ter:" + getNome() + ":" + getHoras() + ":" + getIsSalubre() + ":" + getSalario();
    }
}

class UFC {
    private Map<String, Funcionario> funcionarios = new TreeMap<>();

    public String toString() {
        return this.funcionarios.values().stream().map(f -> "" + f).collect(Collectors.joining("\n"));
    }

    public Funcionario getFuncionario(String nome) {
        Funcionario func = funcionarios.get(nome);
        if(func == null)
            throw new MsgException("fail: funcionario nao existe");
        return func;
    }

    public void addFuncionario(Funcionario funcionario) {
        funcionarios.put(funcionario.getNome(), funcionario);
    }

    public void rmFuncionario(String nome) {
        funcionarios.remove(nome);
    }

    //reparte o bonus para todos os funcionarios
    public void setBonus(int bonus) {
        int bonificacao = bonus/funcionarios.size();
        funcionarios.values().forEach(fuc -> fuc.setBonus(bonificacao));
    }
}

//!KEEP
class Solver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        UFC ufc = new UFC();
        while (true) {
            try {
                String line = scanner.nextLine();
                System.out.println("$" + line);
                String ui[] = line.split(" ");
                if (ui[0].equals("end")) {
                    break;
                } else if (ui[0].equals("addProf")) {
                    ufc.addFuncionario(new Professor(ui[1], ui[2]));
                } else if (ui[0].equals("addSta")) {
                    ufc.addFuncionario(new STA(ui[1], Integer.parseInt(ui[2])));
                } else if (ui[0].equals("addTer")) {
                    ufc.addFuncionario(new Tercerizado(ui[1], Integer.parseInt(ui[2]), ui[3]));
                } else if (ui[0].equals("rm")) {
                    ufc.rmFuncionario(ui[1]);
                } else if (ui[0].equals("showAll")) {
                    System.out.println(ufc);
                } else if (ui[0].equals("show")) {
                    System.out.println(ufc.getFuncionario(ui[1]));
                } else if (ui[0].equals("addDiaria")) {
                    ufc.getFuncionario(ui[1]).addDiaria();
                } else if (ui[0].equals("setBonus")) {
                    ufc.setBonus(Integer.parseInt(ui[1]));
                } else {
                    System.out.print("fail: comando invalido");
                }
            } catch (MsgException me) {
                System.out.println(me.getMessage());
            }
        }
    }
}
//!OFF