public class Pencil {
    private float thickness;
    private Lead tip;

    public Pencil(float thickness) {
    }

    public float getThickness() {
        return 0.0f;
    }

    public void setThickness(float value) {
    }

    public boolean hasLead() {
        return false;
    }

    public boolean insert(Lead grafite) {
        return false;
    }

    public Lead remove() {
        return null;
    }

    public void writePage() {
    }
    
    public String toString() {
        String saida = "calibre: " + thickness + ", grafite: ";
        if (tip != null)
            saida += "[" + tip + "]";
        else
            saida += "null";
        return saida;
    }
}
