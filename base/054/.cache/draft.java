import java.util.Scanner;

class Animal {
    private String especie;
    private String barulho;
    private int estagio;

    public Animal(String especie, String barulho) {
        this.especie = especie;
        this.barulho = barulho;
        this.estagio = 0;
    }

    public String fazerBarulho() {
        if (estagio == 0) {
            return "---";
        }
        if (estagio == 4) {
            return "RIP";
        }
        return this.barulho;
    }

    public void envelhecer(int nivel) {
        estagio += nivel;
        if (estagio >= 4) {
            System.out.printf("warning: %s morreu%n", especie);
            estagio = 4;
        }
    }

    public String toString() {
        return String.format("%s:%d:%s", especie, estagio, barulho);
    }
}

public class Solver {

    public static void main(String[] _args) {
        Animal animal = new Animal("", "");

        while (true) {
            String line = input();
            String[] args = line.split(" ");
            write("$" + line);

            if (args[0].equals("init")) {
                animal = new Animal(args[1], args[2]);
            } else if (args[0].equals("grow")) {
                animal.envelhecer((int) number(args[1]));
            } else if (args[0].equals("noise")) {
                write(animal.fazerBarulho());
            } else if (args[0].equals("show")) {
                write(animal.toString());
            } else if (args[0].equals("end")) {
                break;
            } else {
                write("fail: comando invalido");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
    public static String input()           { return scanner.nextLine();    }
    public static void write(String value) { System.out.println(value);    }
    public static double number(String str)   { return Double.parseDouble(str); }
}
