import java.util.Scanner;

// @DROP

class Animal {
    public String species;
    public String noise;
    public int age;
    public Animal(String species, String noise) {
        this.species = species;
        this.noise = noise;
        this.age = 0;
    }

    public String makeSound() {
        if (age == 0) {
            return "---";
        }
        if (age == 4) {
            return "RIP";
        }
        return this.noise;
    }

    public boolean ageBy(int increment) {
        age += increment;
        if (age >= 4) {
            age = 4;
            return false;
        }
        return true;
    }

    public String toString() {
        return String.format("%s:%d:%s", species, age, noise);
    }
}

// @KEEP
public class Shell {

    public static void main(String[] _args) {
        // @COM
        Animal animal = new Animal("", "");
        // @KEEP

        while (true) {
            var line = scanner.nextLine();
            System.out.println("$" + line);

            var par = line.split(" ");
            var cmd = par[0];

            if (cmd.equals("end")  ) { 
                break;
            }
            else if (cmd.equals("init") ) {
                // INICIE O ANIMAL UTILIZANDO O CONSTRUTOR
                // @COM
                var species = par[1];
                var noise = par[2];
                // @DROP
                animal = new Animal(species, noise);
            } 
            else if (cmd.equals("show")) {
                // MOSTRE O ANIMAL
                // @DROP
                System.out.println(animal);
            } 
            else if (cmd.equals("noise")) {
                // OBTER O BARULHO DO ANIMAL E IMPRIMA
                // @DROP
                System.out.println(animal.makeSound());
            } 
            else if (cmd.equals("grow") ) {
                // AUMENTE A IDADE DO ANIMAL
                // @COM
                var increment = Integer.parseInt(par[1]);
                // @DROP
                if (!animal.ageBy(increment)) {
                    System.out.println("warning: " + animal.species + " morreu");
                }
            }  
            else {
                System.out.println("fail: comando invalido\n");
            }
        }
    }

    static Scanner scanner = new Scanner(System.in);
}
