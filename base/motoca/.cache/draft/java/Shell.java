import java.util.*;

class Shell{
    static Adapter adp = new Adapter(1);

    public static void main(String[] args) {    
        while(true) {
            String line = input();
            args = line.split(" ");
            write('$' + line);
            
            if      (args[0].equals("end"))      { break;                                 }
            else if (args[0].equals("show"))     { write(adp.toString());                 }
            else if (args[0].equals("init"))     { adp = new Adapter((int) number(args[1]));    }  
            else if (args[0].equals("enter"))    { adp.enter(args[1], (int) number(args[2]));   }
            else if (args[0].equals("buy"))      { adp.buy((int) number(args[1]));              }
            else if (args[0].equals("drive"))    { adp.drive((int) number(args[1]));            }
            else if (args[0].equals("honk"))     { write(adp.honk());                            }
            else if (args[0].equals("leave"))    { write(adp.leave());                    }
            else                                 { write("fail: comando invalido"); }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()            { return scanner.nextLine();      }
    public static void write(String value)  { System.out.println(value);      }
    public static double number(String str) { return Double.parseDouble(str); }
}
