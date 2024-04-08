import java.text.DecimalFormat;

public class Lead {
    private float thickness; //calibre
    private String hardness; //dureza
    private int size; //tamanho em mm

    public Lead(float thickness, String hardness, int size) {
    }

    public float getThickness() {
        return 0.0f;
    }

    public String getHardness() {
        return "";
    }

    public int getSize() {
        return 0;
    }

    public void setSize(int size) {
    }

    public int usagePerSheet() {
        if(hardness.equals("HB")) {
            return 1;
        } else if(hardness.equals("2B")) {
            return 2;
        } else if(hardness.equals("4B")) {
            return 4;
        } else {
            return 6;
        }
    }

    public String toString() {
        DecimalFormat form = new DecimalFormat("0.0");
        return form.format(thickness) + ":" + hardness + ":" + size;
    }
}
