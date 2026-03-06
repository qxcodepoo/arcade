# @paciente

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Esqueleto](#esqueleto)
-- | -- | --
<!-- toch -->

![cover](cover.jpg)

## Intro

Na UTI do nosso hospital existem vários pacientes. Cada paciente é atendico por médicos de várias especialidades. Pacientes e médicos podem se comunicar via mensagens. O sistema deve ser capaz de.

- cadastrar pacientes e médicos.
- informar quais os médicos que atendem determinado paciente.
- informar quais pacientes que são atendidos por um médico.

- **Repositórios Individuais - 3.0 P**
  - Adicionar pacientes.
    - Cada paciente tem um id(nome) e uma diagnóstico.
  - Adicionar médicos.
    - Cada médico tem um id(nome) e uma especialidade.

```sh
#TEST_CASE inserir
$addPacs fred-fratura alvis-avc goku-hemorragia silva-sinusite
$addMeds bisturi-cirurgia snif-alergologia facada-cirurgia
$show
Pac: alvis:avc        Meds: []
Pac: fred:fratura     Meds: []
Pac: goku:hemorragia  Meds: []
Pac: silva:sinusite   Meds: []
Med: bisturi:cirurgia Pacs: []
Med: facada:cirurgia  Pacs: []
Med: snif:alergologia Pacs: []


#    - Vincular pacientes e médicos.
#        - Dois médicos da mesma especialidade não podem ser responsáveis pelo mesmo paciente.
#        - O paciente não deve entrar duas vezes na lista do médico e vice-versa.

#TEST_CASE vincular
# tie _med _pac _pac ...
$tie bisturi fred alvis goku
$tie snif silva alvis
$tie facada goku
fail: ja existe outro medico da especialidade cirurgia
$show
Pac: alvis:avc        Meds: [bisturi, snif]
Pac: fred:fratura     Meds: [bisturi]
Pac: goku:hemorragia  Meds: [bisturi]
Pac: silva:sinusite   Meds: [snif]
Med: bisturi:cirurgia Pacs: [alvis, fred, goku]
Med: facada:cirurgia  Pacs: []
Med: snif:alergologia Pacs: [alvis, silva]

$end
```

***

## Guide
![diagrama](diagrama.png)

***

## Esqueleto
<!--FILTER Solver.java java-->
```java
interface IPaciente {
    public String getId();
    public void addMedico(IMedico medico);
    public void removerMedico(String idMedico);
    public Collection<IMedico> getMedicos();
    public String getDiagnostico();
}
interface IMedico {
    public String getId();
    public void addPaciente(IPaciente paciente);
    public void removerPaciente(String idPaciente);
    public Collection<IPaciente> getPacientes();
    public String getClasse();
}
class Medico implements IMedico{
    String sender;
    String classe;
    TreeMap<String, IPaciente> pacientes = new TreeMap<>();
    public Medico(String sender, String classe);
    public String getId();
    public void addPaciente(IPaciente paciente);
    public void removerPaciente(String idPaciente);
    public Collection<IPaciente> getPacientes();
    public String getClasse();
    public String toString();
}
class Paciente implements IPaciente {
    protected String sender;
    protected String diagnostico;
    protected TreeMap<String, IMedico> medicos = new TreeMap<>();
    public Paciente(String sender, String diagnostico);
    public String getId();
    public void addMedico(IMedico medico);
    public void removerMedico(String idMedico);
    public Collection<IMedico> getMedicos();
    public String getDiagnostico();
    public String toString();
}
class Hospital {
    private TreeMap<String, IPaciente> pacientes = new TreeMap<>();
    private TreeMap<String, IMedico> medicos = new TreeMap<>();
    public Hospital();
    public void removerPaciente(String sender);
    public void removerMedico(String sender);
    public void addPaciente(IPaciente paciente);
    public void addMedico(IMedico medico);
    public void vincular(String nomeMedico, String nomePaciente);
    public String toString();
}
public class Solver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Hospital hospital = new Hospital();

        while (true) {
            String line = scanner.nextLine();
            System.out.println("$" + line);
            List<String> ui = Arrays.asList(line.split(" "));
            if (ui.get(0).equals("end")) {
                break;
            } else if (ui.get(0).equals("addPacs")) {
                ui.stream().skip(1)
                        .forEach(tk -> hospital.addPaciente(new Paciente(tk.split("-")[0], tk.split("-")[1])));
            } else if (ui.get(0).equals("addMeds")) {
                ui.stream().skip(1).forEach(tk -> hospital.addMedico(new Medico(tk.split("-")[0], tk.split("-")[1])));
            } else if (ui.get(0).equals("show")) {
                System.out.print(hospital.toString());
            } else if (ui.get(0).equals("tie")) {
                ui.stream().skip(2).forEach(name -> hospital.vincular(ui.get(1), name));
            }
            else {
                System.out.println("fail: comando invalido");
            }
        }
    }
}
```
<!--FILTER_END-->