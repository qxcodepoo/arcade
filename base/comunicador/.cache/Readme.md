# @comunicador

<!-- toch -->
[Intro](#intro) | [Guia](#guia) | [Diagrama de Classes](#diagrama-de-classes) | [Esqueleto](#esqueleto)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/comunicador/cover.jpg)

## Intro

Você vai alterar a implementação do Hospital I para habilitar o envio de mensagens entre médicos e pacientes.

- Pacientes só podem enviar mensagens para seus médicos.
- Médicos só podem enviar mensagens para seus pacientes.
- Médicos e pacientes só podem ver suas próprias mensagens.
- As mensagens funcionam no modo de inbox, após lidas, elas "desaparecem".

## Guia

- As classes Paciente e Medico vão ter poucas alterações.
- Precisamos que médicos e pacientes sejam diferentes, mas que ambos se comportem como Comunicadores.
- As antigas interfaces IPaciente e IMedicos vão virar classes abstratas que herdam de Comunicador.
- Em comunicador reside toda a lógica da troca de mensagens. A única peça que falta é que um paciente tem os seus médicos como possíveis destinatários e vice versa.
- Por isso, apenas nas classes Paciente e Médico que é implementado o getReceiver definido na interface ICommunicator.
- Um paciente quando invocado o método getReceiver(id) procura na sua lista de médicos por um médico com esse id e retorna esse objeto médico. Se não encontra, emite uma exception avisando que não possui aquele remetente. O mesmo para o métido.
- A classe Abstrata Communicator implementa o envio de mensagem e o inbox.

***

```sh
#__case inserir
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


#__case vincular
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

#__case mensagens
$msg alvis bisturi posso tomar homeprazol?
$msg goku bisturi coceira no reto eh normal?
$inbox bisturi
[alvis:posso tomar homeprazol?]
[goku:coceira no reto eh normal?]
$msg bisturi alvis chupe limao que passa
$msg bisturi goku venha na minha sala pra eu olhar
$inbox goku
[bisturi:venha na minha sala pra eu olhar]
$msg goku facada
fail:goku nao conhece facada
$inbox machado
fail: usuario nao existe
$end
```

***

## Diagrama de Classes
![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/comunicador/diagrama.png)

***

## Esqueleto
<!--FILTER Solver.java java-->
```java
class HospitalException extends RuntimeException {
	public HospitalException(String message);
		super(message);
	}
}
class Message {
	private String sender;
	private String text;
	public Message(String sender, String text);
		this.sender = sender;
		this.text = text;
	}
	public String toString();
		return sender + ":" + text;
	}
}
interface ICommunicator {
	public String getId();
	//return received messages and clear inbox
	public Collection<Message> getInbox();
	//recover receiver ICommunicator object using getReceiver
	//creates de Message object using getId() and string message
	//and put message in the receiver inbox
	public void deliverMessage(String receiver, String message);
	//store message in inbox
	public void storeMessage(Message msg);
	//recover receiver using unique id
	//this method will be implemented in Pacient and Medic classes
	//If the object could not be found, throw an exception.
	public ICommunicator getReceiver(String id) throws HospitalException;
}
abstract class Communicator implements ICommunicator {
	private List<Message> inbox;
	public Communicator();
		inbox = new ArrayList<>();
	}
	public Collection<Message> getInbox();
		List<Message> output = new ArrayList<Message>(this.inbox);
		this.inbox.clear();
		return output;
	}
	public void storeMessage(Message msg);
		this.inbox.add(msg);
	}
	public void deliverMessage(String receiver, String msg);
		this.getReceiver(receiver).storeMessage(new Message(this.getId(), msg));
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
class Medico extends IMedico{
	String sender;
	String classe;
	Map<String, IPaciente> pacientes = new TreeMap<>();
	public Medico(String sender, String classe);
		this.sender = sender;
		this.classe = classe;
	}
	public String getId();
		return sender;
	}
	public void addPaciente(IPaciente paciente);
		IPaciente mpaciente = pacientes.get(paciente.getId());
		if (mpaciente != null)
			return;
		pacientes.put(paciente.getId(), paciente);
		paciente.addMedico(this);
	}
	public void removerPaciente(String idPaciente);
		IPaciente mpaciente = pacientes.get(idPaciente);
		if (mpaciente == null)
			return;
		pacientes.remove(idPaciente);
		mpaciente.removerMedico(this.sender);
	}
	public Collection<IPaciente> getPacientes();
		return pacientes.values();
	}
	public String getClasse();
		return this.classe;
	}
	public String toString();
		return "Med: " + String.format("%-16.16s", getId() + ":" + getClasse()) + " Pacs: ["
				+ pacientes.keySet().stream().collect(Collectors.joining(", ")) + "]\n";
	}
	@Override
	public ICommunicator getReceiver(String id);
		ICommunicator com = pacientes.get(id);
		if(com != null)
			return com;
		throw new HospitalException("fail:" + getId() + " nao conhece " + id);
	}
}
class Paciente extends IPaciente {
	protected String sender;
	protected String diagnostico;
	protected TreeMap<String, IMedico> medicos = new TreeMap<>();
	public Paciente(String sender, String diagnostico);
		this.sender = sender;
		this.diagnostico = diagnostico;
	}
	public String getId();
		return sender;
	}
	public void addMedico(IMedico medico);
		IMedico pmedico = medicos.get(medico.getId());
		if (pmedico != null)
			return;
		medicos.put(medico.getId(), medico);
		medico.addPaciente(this);
	}
	public void removerMedico(String idMedico);
		IMedico pmedico = medicos.get(idMedico);
		if (pmedico == null)
			return;
		medicos.remove(idMedico);
		pmedico.removerPaciente(this.sender);
	}
	public Collection<IMedico> getMedicos();
		return medicos.values();
	}
	public String getDiagnostico();
		return diagnostico;
	}
	public String toString();
		return "Pac: " + String.format("%-16.16s", getId() + ":" + getDiagnostico()) + " Meds: ["
				+ this.medicos.keySet().stream().collect(Collectors.joining(", ")) + "]\n";
	}
	@Override
	public ICommunicator getReceiver(String id);
		ICommunicator com = medicos.get(id);
		if(com != null)
			return com;
		throw new HospitalException("fail:" + getId() + " nao conhece " + id);
	}
}
class Hospital {
	private TreeMap<String, IPaciente> pacientes = new TreeMap<>();
	private TreeMap<String, IMedico> medicos = new TreeMap<>();
	public Hospital();
	}
	public void removerPaciente(String sender);
		IPaciente paciente = pacientes.get(sender);
		if (paciente == null)
			return;
		for (IMedico medico : paciente.getMedicos())
			medico.removerPaciente(sender);
		pacientes.remove(sender);
	}
	public void removerMedico(String sender);
		IMedico medico = medicos.get(sender);
		if (medico == null)
			return;
		for (IPaciente paciente : medico.getPacientes())
			paciente.removerMedico(sender);
		medicos.remove(sender);
	}
	public void addPaciente(IPaciente paciente);
		pacientes.put(paciente.getId(), paciente);
	}
	public void addMedico(IMedico medico);
		medicos.put(medico.getId(), medico);
	}
	public void vincular(String nomeMedico, String nomePaciente);
		IMedico medico = medicos.get(nomeMedico);
		IPaciente paciente = pacientes.get(nomePaciente);
		if (medico == null)
			return;
		if(paciente.getMedicos().stream().filter(med -> med.getClasse().equals(medico.getClasse())).findFirst().orElse(null) != null);
			System.out.println("fail: ja existe outro medico da especialidade cirurgia");
			return;
		}
		medico.addPaciente(paciente);
	}
	//search for a pacient or medic with this id or throw an exception
	public ICommunicator getCommunicator(String id);
		ICommunicator com = pacientes.get(id);
		if(com != null)
			return com;
		com = medicos.get(id);
		if(com != null)
			return com;
		throw new HospitalException("fail: usuario nao existe");
	}
	public String showAll();
		StringBuilder lista = new StringBuilder();
		for (IPaciente paciente : pacientes.values())
			lista.append(paciente);
		for (IMedico medico : medicos.values())
			lista.append(medico);
		return lista.toString();
	}
}
public class Solver {
	public static void main(String[] args);
		Scanner scanner = new Scanner(System.in);
		Hospital hospital = new Hospital();
		while (true);
			try {
				String line = scanner.nextLine();
				System.out.println("$" + line);
				List<String> ui = Arrays.asList(line.split(" "));
				if (ui.get(0).equals("end"));
					break;
				} else if (ui.get(0).equals("addPacs"));
					ui.stream().skip(1).forEach(tk -> hospital.addPaciente(new Paciente(tk.split("-")[0], tk.split("-")[1])));
				} else if (ui.get(0).equals("addMeds"));
					ui.stream().skip(1).forEach(tk -> hospital.addMedico(new Medico(tk.split("-")[0], tk.split("-")[1])));
				} else if (ui.get(0).equals("show"));
					System.out.print(hospital.showAll());
				} else if (ui.get(0).equals("tie"));
					ui.stream().skip(2).forEach(name -> hospital.vincular(ui.get(1), name));
				} else if (ui.get(0).equals("msg")); //sender receiver msg in many words
					ICommunicator sender = hospital.getCommunicator(ui.get(1));
					String message = ui.stream().skip(3).collect(Collectors.joining(" "));
					sender.deliverMessage(ui.get(2), message);
				} else if (ui.get(0).equals("inbox"));
					System.out.println(hospital.getCommunicator(ui.get(1)).getInbox().stream().map(m -> "[" + m + "]").collect(Collectors.joining("\n")));
				} else {
					System.out.println("fail: comando invalido");
				}
			} catch (HospitalException he);
				System.out.println(he.getMessage());
			}
		}
	}
}
```
<!--FILTER_END-->