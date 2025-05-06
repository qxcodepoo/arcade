import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.stream.Collectors;

class Message {
	private String sender;
	private String text;

	public Message(String sender, String text) {
		this.sender = sender;
		this.text = text;
	}

	public String toString() {
		return sender + ":" + text;
	}
}

interface ICommunicator {
	public String getId();
	//return received messages and clear inbox
	public Collection<Message> getInbox();
	//recover receiver ICommunicator object using getReceiver
	//and put message in his inbox
	public void deliverMessage(Message msg, String receiver);
	//store message in inbox
	public void storeMessage(Message msg);
	//recover receiver using unique id
	public ICommunicator getReceiver(String id);
}

abstract class Communicator implements ICommunicator {
	private List<Message> inbox;

	public Collection<Message> getInbox() {
		List<Message> output = new ArrayList<Message>(this.inbox);
		this.inbox.clear();
		return output;
	}

	public void storeMessage(Message msg) {
		this.inbox.add(msg);
	}

	public void deliverMessage(Message msg, String receiver) {
		this.getReceiver(receiver).storeMessage(msg);
	}
}

abstract class IPaciente extends Communicator {
	public abstract void addMedico(IMedico medico);
	public abstract void removerMedico(String idMedico);
	public abstract Collection<IMedico> getMedicos();
	public abstract String getDiagnostico();
}

abstract class IMedico extends Communicator {
	public abstract void addPaciente(IPaciente paciente);
	public abstract void removerPaciente(String idPaciente);
	public abstract Collection<IPaciente> getPacientes();
	public abstract String getClasse();
}

class Medico implements IMedico{
	String sender;
	String classe;
	Map<String, IPaciente> pacientes = new TreeMap<>();

	Medico(String sender, String classe) {
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
				+ pacientes.keySet().stream().collect(Collectors.joining(", ")) + "]\n";
	}

		return pacientes.get(id);
	}
}

class Paciente extends Communicator implements IPaciente {
	protected String sender;
	protected String diagnostico;
	protected TreeMap<String, IMedico> medicos = new TreeMap<>();

	Paciente(String sender, String diagnostico) {
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
				+ this.medicos.keySet().stream().collect(Collectors.joining(", ")) + "]\n";
	}

	@Override
	public ICommunicator getReceiver(String id) {
		return medicos.get(id);
	}
}

class Hospital {
	private TreeMap<String, IPaciente> pacientes = new TreeMap<>();
	private TreeMap<String, IMedico> medicos = new TreeMap<>();

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

	public void addPaciente(Paciente paciente) {
		pacientes.put(paciente.getId(), paciente);
	}

	public void addMedico(Medico medico) {
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

	public String showAll() {
		StringBuilder lista = new StringBuilder();
		for (IPaciente paciente : pacientes.values())
			lista.append(paciente);
		for (IMedico medico : medicos.values())
			lista.append(medico);
		return lista.toString();
	}
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
			} else if (ui.get(0).equals("seeAll")) {
				System.out.print(hospital.showAll());
			} else if (ui.get(0).equals("tie")) {
				ui.stream().skip(2).forEach(name -> hospital.vincular(ui.get(1), name));
			} else {
				System.out.println("fail: comando invalido");
			}
		}
	}
}
