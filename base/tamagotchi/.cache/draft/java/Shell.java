import java.util.*;

class Adapter {
    // private Game game = new Game(new Pet(0, 0));
    // 
    public void init(int energy, int clean) {
        // this.game = new Game(new Pet(energy, clean));
    }

    public void show() {
        // System.out.println(this.game.toString());
    }

    public void play() {
        // this.game.play();
    }

    public void shower() {
        // this.game.shower();
    }

    public void sleep() {
        // this.game.sleep();
    }
}

public class Shell {
    public static void main(String[] a) {
        Adapter adp = new Adapter();
        
        while (true) {
            var line = input();
            write("$" + line);
            var args = line.split(" ");

            if      (args[0].equals("end"))   { break;                                                }
            else if (args[0].equals("show"))  { adp.show();                                           }
            else if (args[0].equals("init"))  { adp.init((int)number(args[1]), (int)number(args[2])); }
            else if (args[0].equals("play"))  { adp.play();                                           }
            else if (args[0].equals("sleep")) { adp.sleep();                                          }
            else if (args[0].equals("shower")){ adp.shower();                                         }
            else                              { write("fail: comando invalido");                      }
        }
    }

    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}
