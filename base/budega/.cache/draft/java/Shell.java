import java.util.*;

class Shell {
    static Adapter adp = new Adapter();
    public static void main(String[] _args) {
        while(true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if     (args[0].equals("init"     )) { adp.init(number(args[1]));            }
            else if(args[0].equals("arrive"   )) { adp.chegar(args[1]);                  }
            else if(args[0].equals("call"     )) { adp.chamarNoCaixa(number(args[1]));   }
            else if(args[0].equals("finish"   )) { adp.finalizar(number(args[1]));       }
            else if(args[0].equals("show"     )) { adp.show();                           }
            else if(args[0].equals("end"      )) { break;                                }
            else                                 { write("fail: comando invalido");      }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();       }
    public static void write(String value) { System.out.println(value);       }
    public static int number(String str)   { return Integer.parseInt(str);    }
}