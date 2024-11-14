public class Adapter {
  public Adapter(int capacidade) {
    sala = new Sala(capacidade);
  }

  public void reservar(String id, String fone, int ind) {
    sala.reservar(id, fone, ind);
  }

  public void cancelar(String id) {
    sala.cancelar(id);
  }

  public String toString() {
    return sala.toString();
    return "";
  }
}
