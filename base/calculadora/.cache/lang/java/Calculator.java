
class Calculator {
    public int batteryMax;
    public int battery;
    public float display;

    public Calculator(int batteryMax) {
    }

    public void chargeBattery(int value) {
    }

    public boolean useBattery() {
    }

    public void sum(int a, int b) {
    }

    public void division(int num, int den) {
    }

    public String toString() {
        return String.format("display = %.2f, battery = %d", this.display, this.battery);

        // se seu java estiver utilizando `,` como separador decimal, use:
        // DecimalFormat df = new DecimalFormat("0.00");
        // return String.format("display = %s, battery = %d", df.format(this.display), this.battery);
    }
}