import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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

    public Medico(String sender, String classe) {
        this.sender = sender;
        this.classe = classe;
    }

    public String getId() {
        return sender;
    }

    public void addPaciente(IPaciente paciente) {
        IPaciente mpaciente = pacientes.get(paciente.getId());
        if (mpaciente != null)
            return;
        pacientes.put(paciente.getId(), paciente);
        paciente.addMedico(this);
    }

    public void removerPaciente(String idPaciente) {
        IPaciente mpaciente = pacientes.get(idPaciente);
        if (mpaciente == null)
            return;
        pacientes.remove(idPaciente);
        mpaciente.removerMedico(this.sender);
    }

    public Collection<IPaciente> getPacientes() {
        return pacientes.values();
    }

    public String getClasse() {
        return this.classe;
    }

    public String toString() {
        return "Med: " + String.format("%-16.16s", getId() + ":" + getClasse()) + " Pacs: ["
                + pacientes.keySet().stream().collect(Collectors.joining(", ")) + "]";
    }
}

class Paciente implements IPaciente {
    protected String sender;
    protected String diagnostico;
    protected TreeMap<String, IMedico> medicos = new TreeMap<>();

    public Paciente(String sender, String diagnostico) {
        this.sender = sender;
        this.diagnostico = diagnostico;
    }

    public String getId() {
        return sender;
    }

    public void addMedico(IMedico medico) {
        IMedico pmedico = medicos.get(medico.getId());
        if (pmedico != null)
            return;
        medicos.put(medico.getId(), medico);
        medico.addPaciente(this);
    }

    public void removerMedico(String idMedico) {
        IMedico pmedico = medicos.get(idMedico);
        if (pmedico == null)
            return;
        medicos.remove(idMedico);
        pmedico.removerPaciente(this.sender);
    }

    public Collection<IMedico> getMedicos() {
        return medicos.values();
    }

    public String getDiagnostico() {
        return diagnostico;
    }

    public String toString() {
        return "Pac: " + String.format("%-16.16s", getId() + ":" + getDiagnostico()) + " Meds: ["
                + this.medicos.keySet().stream().collect(Collectors.joining(", ")) + "]";
    }
}

class Hospital {
    private TreeMap<String, IPaciente> pacientes = new TreeMap<>();
    private TreeMap<String, IMedico> medicos = new TreeMap<>();

    public Hospital(){
        
    }

    public void removerPaciente(String sender) {
        IPaciente paciente = pacientes.get(sender);
        if (paciente == null)
            return;
        for (IMedico medico : paciente.getMedicos())
            medico.removerPaciente(sender);
        pacientes.remove(sender);
    }

    public void removerMedico(String sender) {
        IMedico medico = medicos.get(sender);
        if (medico == null)
            return;
        for (IPaciente paciente : medico.getPacientes())
            paciente.removerMedico(sender);
        medicos.remove(sender);
    }

    public void addPaciente(IPaciente paciente) {
        pacientes.put(paciente.getId(), paciente);
    }

    public void addMedico(IMedico medico) {
        medicos.put(medico.getId(), medico);
    }

    public void vincular(String nomeMedico, String nomePaciente) {
        IMedico medico = medicos.get(nomeMedico);
        IPaciente paciente = pacientes.get(nomePaciente);
        if (medico == null)
            return;
        for (IMedico med : paciente.getMedicos()) {
            if (medico.getClasse().equals(med.getClasse())) {
                System.out.println("fail: ja existe outro medico da especialidade cirurgia");
                return;
            }
        }
        medico.addPaciente(paciente);
        paciente.addMedico(medico);
    }

    public String toString() {
        String saida = "";
        saida += pacientes.values().stream().map(Object::toString).collect(Collectors.joining("\n")) + "\n";
        saida += medicos.values().stream().map(Object::toString).collect(Collectors.joining("\n")) + "\n";
        return saida;
    }
}

//!KEEP
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
//!OFF
