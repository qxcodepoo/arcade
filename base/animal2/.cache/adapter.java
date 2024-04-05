public class Adapter {
    private Animal animal;
    public Adapter(String especie, String barulho) {
        animal = new Animal(especie, barulho);
    }
    
    public String noise() {
        return animal.fazerBarulho();
    }

    public void grow(int nivel) {
        animal.envelhecer(nivel);
    }

    public String toString() {
        return animal.toString();
    }
}
