import java.util.Scanner;


class Animal {
    private String species;
    private String noise;
    private int age;
    public Animal(String species, String noise) {
        this.species = species;
        this.noise = noise;
        this.age = 0;
    }

    public String makeNoise() {
        if (age == 0) {
            return "---";
        }
        if (age == 4) {
            return "RIP";
        }
        return this.noise;
    }

    public void ageBy(int increment) {
        age += increment;
        if (age >= 4) {
            System.out.printf("warning: %s morreu%n", species);
            age = 4;
        }
    }

    public String toString() {
        return String.format("%s:%d:%s", species, age, noise);
    }
}

public class Shell {

    public static void main(String[] _args) {
        Animal animal = new Animal("", "");

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("init") ) {
                var species = par[1];
                var noise = par[2];
                animal = new Animal(species, noise);
            } else if (cmd.equals("show")) {
                System.out.println(animal);
            } else if (cmd.equals("noise")) {
                System.out.println(animal.makeNoise());
            } else if (cmd.equals("grow") ) {
                var increment = Integer.parseInt(par[1]);
                animal.ageBy(increment);
            } else if (cmd.equals("end")  ) { 
                break;
            } else {
                System.out.println("fail: comando invalido\n");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}