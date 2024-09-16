import java.util.Scanner;

public class Shell {

    public static void testeEntrando() {
        Student car = new Student();
        System.out.println("$Carro criado");
        System.out.println(car.show());
        System.out.println("$Entrando no carro");
        car.enter();
        System.out.println(car.show());
        System.out.println("$Entrando no carro");
        car.enter();
        System.out.println(car.show());
        System.out.println("$Entrando no carro");
        car.enter();
        System.out.println(car.show());
    }

    public static void testeSaindo() {
        Student car = new Student();
        System.out.println("$Carro criado");
        System.out.println(car.show());
        System.out.println("$Entrando 2 pessoas no carro");
        car.enter();
        car.enter();
        System.out.println(car.show());
        System.out.println("$Saindo do carro");
        car.leave();
        System.out.println(car.show());
        System.out.println("$Saindo do carro");
        car.leave();
        System.out.println(car.show());
        System.out.println("$Saindo do carro");
        car.leave();
        System.out.println(car.show());
    }

    public static void testeAbastecendo() {
        Student car = new Student();
        System.out.println("$Carro criado");
        System.out.println(car.show());
        System.out.println("$Abastecendo 10 litros");
        car.fuel(10);
        System.out.println(car.show());
        System.out.println("$Abastecendo 30 litros");
        car.fuel(30);
        System.out.println(car.show());
        System.out.println("$Abastecendo 100 litros");
        car.fuel(100);
        System.out.println(car.show());
    }

    public static void testeDirigindo() {
        Student car = new Student();
        System.out.println("$Carro criado");
        System.out.println(car.show());
        System.out.println("$Tentando dirigir com carro vazio");
        car.drive(10);
        System.out.println(car.show());
        System.out.println("$Entrando no carro");
        car.enter();
        System.out.println(car.show());
        System.out.println("$Testando dirigir sem gasolina");
        car.drive(10);
        System.out.println(car.show());
        System.out.println("$Abastecendo 30 litros");
        car.fuel(30);
        System.out.println(car.show());
        System.out.println("$Testando dirigir com gasolina");
        car.drive(10);
        System.out.println(car.show());
        System.out.println("$Testando dirigir só parte do caminho");
        car.drive(50);
        System.out.println(car.show());
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String cmd = scanner.nextLine();

        switch (cmd) {
            case "entrando":
                testeEntrando();
                break;
            case "saindo":
                testeSaindo();
                break;
            case "abastecendo":
                testeAbastecendo();
                break;
            case "dirigindo":
                testeDirigindo();
                break;
            default:
                System.out.println("Comando não reconhecido.");
                break;
        }
        scanner.close();
    }
}
