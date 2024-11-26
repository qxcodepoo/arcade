import java.util.*;

class Adapter {
    // private Mercantil mercantil = new Mercantil(0);
    public void init(int qtd_caixas) {
        // this.mercantil = new Mercantil(qtd_caixas);
    }

    public void arrive(String name) {
        // this.mercantil.chegar(new Pessoa(name));
    }
    public void call(int indice) {
        // this.mercantil.chamarNoCaixa(indice);
    }
    public void finish(int indice) {
        // this.mercantil.finalizar(indice);
    }

    public void show() {
        // System.out.println(this.mercantil.toString());
    }
}


class Shell {
    public static void main(String[] _args) {
        Adapter adp = new Adapter();
        while(true) {
            String line = input();
            String[] args = line.split(" ");
            write('$' + line);

            if     (args[0].equals("init"     )) { adp.init(number(args[1]));            }
            else if(args[0].equals("arrive"   )) { adp.arrive(args[1]);                  }
            else if(args[0].equals("call"     )) { adp.call(number(args[1]));            }
            else if(args[0].equals("finish"   )) { adp.finish(number(args[1]));          }
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