import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.Collections;


public class Shell{

    public static void main(String[] Args) {
        Scanner scanner = new Scanner(System.in);
        Agenda agenda = new Agenda();

        while (true) {
            String line = scanner.nextLine();
            write("$" + line);
            String[] args = line.split(" ");
            
            if      (args[0].equals("end"))     { break;                           }
            else if (args[0].equals("add"))     {
                ArrayList<Fone> fones = new ArrayList<>();
                for (int i = 2; i < args.length; i++) {
                    String[] fone = args[i].split(":");
                    fones.add(new Fone(fone[0], fone[1]));
                }
                agenda.addContato(args[1], fones);
            }
            
            else if (args[0].equals("show"))    { write(agenda.str());                                     }
            else if (args[0].equals("rm"))      { agenda.rmContact(args[1]);                               }
            else if (args[0].equals("favs"))    { write(agenda.getFavorited().stream().map(contact -> contact.str()).collect(Collectors.joining("\n")));   }
            else if (args[0].equals("search"))  { write(agenda.search(args[1]).stream().map(contact -> contact.str()).collect(Collectors.joining("\n")));  }
            
            else if (args[0].equals("rmFone"))  {
                Contact contato = agenda.getContact(args[1]);
                if (contato != null) contato.rmFone(number(args[2]));
            }
            else if (args[0].equals("tfav"))    {
                Contact contato = agenda.getContact(args[1]);
                if (contato != null) contato.toogleFavorited();
            }
            
            else                           {  write("fail: invalid command");           }
        }
        scanner.close();
    }
    public static int number(String number) { return Integer.parseInt(number); }
    public static void write(String str)    { System.out.println(str);         }
}