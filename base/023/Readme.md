# Salário

![cover](cover.jpg)

[](toc)

- [Requisitos parte 1](#requisitos-parte-1)
- [Regras de negócio parte 1](#regras-de-negócio-parte-1)
- [Regras de negócio parte 2](#regras-de-negócio-parte-2)
- [Requisitos e Regras de negócio parte 3](#requisitos-e-regras-de-negócio-parte-3)
- [Instruções](#instruções)
- [Diagrama](#diagrama)
- [Esqueleto](#esqueleto)
[](toc)

A UFC está precisando de um novo sistema de geração de folhas de pagamento, você aceita o desafio?'

Você deve desenvolver um sistema para calcular o salário de um funcionário de acordo com sua função e adicionais

## Requisitos parte 1

- Cadastrar funcionario pelo nome.
    - nome do funcionario é único
    - funcionário pode ser professor, servidor tec. administrativo ou terceirizado
- Mostrar funcionário
- Remover funcionário

## Regras de negócio parte 1

- O salário de professor deve ser calculado com base na sua classe
    - A 3000
    - B 5000
    - C 7000
    - D 9000
    - E 11000
- O Sta(Servidor Técnico Administrativo) tem um salario base de 3000 e é acrescentado mais 300 de acordo com seu nível
    - salario = 3000 + 300 * nivel
- O salário do Ter(Terceirizado) é obtido do produto das horas trabalhadas e 4
    e é acrescentado 500 se for insalubre
    - salario = 4 * horas (+ 500 se insalubre)

## Regras de negócio parte 2

- Adicionar diárias
- Prof podem receber no máximo 2 diárias, Sta no máximo 1 e Ter não podem receber.
- Diarias aumentam 100 reais no salario

## Requisitos e Regras de negócio parte 3

- Adicionar bônus. O valor do bônus é definido e então é dividido igualmente entre todos os funcionários.
- O valor do bônus pode mudar e o salário deve ser recalculado.

```bash
#__case begin
$addProf david C
$addProf elvis D
$addSta gilmario 3
$addTer helder 40 sim
$showAll
prof:david:C:7000
prof:elvis:D:9000
sta:gilmario:3:3900
ter:helder:40:sim:660
$rm elvis
$showAll
prof:david:C:7000
sta:gilmario:3:3900
ter:helder:40:sim:660

#__case diaria
$addDiaria david
$addDiaria david
$addDiaria david
fail: limite de diarias atingido
$show david
prof:david:C:7200
$addDiaria gilmario
$addDiaria gilmario
fail: limite de diarias atingido
$show gilmario
sta:gilmario:3:4000
$addDiaria helder
fail: terc nao pode receber diaria

#__case bonus

# um bonus de 600, para 3 funcionários vai dar 200 reais pra cada
$setBonus 600
$show gilmario 
sta:gilmario:3:4200

$setBonus 300
$show gilmario
sta:gilmario:3:4100
$end
```

## Instruções

- Faça com que prof, sta e ter sejam subclasses de Funcionário, ou seja herdem todos os atributos e métodos da classe Funcionário.
- Utilize apenas um repositório (tire proveito do polimorfismo).
- As classes filhas devem sobrescrever os métodos herdados da classe pai sempre que você achar necessário.

***

## Diagrama
![diagrama](diagrama.png)

***

## Esqueleto

<!--FILTER Solver.java java-->
```java
class MsgException extends RuntimeException {
    public MsgException(String message);
}
abstract class Funcionario {
    protected String nome;
    protected int bonus;
    protected int diarias;
    protected int maxDiarias;
    public Funcionario(String nome);
    public String getNome();
    public void setBonus(int bonus);
      this.bonus = bonus;
    //se não atingiu o máximo, adicione mais uma diária
    //se atingiu o máximo, lance uma MsgException
    public void addDiaria();
    //retorna bonus + diarias * 100
    public int getSalario();
}
class Professor extends Funcionario {
    protected String classe;
    //inicializa classe e muda maxDiarias para 2
    public Professor(String nome, String classe);
    public String getClasse();
    //lógica do salário do professor
    //usa o super.getSalario para pegar bonus e diarias
    public int getSalario();
    public String toString();
}
class STA extends Funcionario {
    protected int nivel;
    public STA(String nome, int nivel);
    public int getNivel();
    public int getSalario();
    public String toString();
}
class Tercerizado extends Funcionario {
    protected int horas;
    protected boolean isSalubre = false;
    public Tercerizado(String nome, int horas, String isSalubre);
    public int getHoras();
    public String getIsSalubre();
    public int getSalario();
    public void addDiaria();
    public String toString();
}
class UFC {
    private Map<String, Funcionario> funcionarios = new TreeMap<>();
    public String toString();
    public Funcionario getFuncionario(String nome);
    public void addFuncionario(Funcionario funcionario);
    public void rmFuncionario(String nome);
    //reparte o bonus para todos os funcionarios
    public void setBonus(int bonus);
}
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
```
<!--FILTER_END-->