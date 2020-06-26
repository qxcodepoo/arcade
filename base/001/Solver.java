import java.util.Scanner;
import java.text.*;

class Calculadora {
	int bateriaMaxima;
	int bateria;
	float display;
	
	public Calculadora(int bateriaMaxima) {
		this.bateriaMaxima = bateriaMaxima;
		this.bateria = 0;
		this.display = 0.0f;
	}
	
	void charge(int value){
		if(value < 0)
			return;
		this.bateria += value;
		if(this.bateria > this.bateriaMaxima)
			this.bateria = this.bateriaMaxima;
	}
	boolean gastarBateria() {
		if(this.bateria == 0){
			System.out.println("fail: bateria insuficiente");
			return false;
		}
		this.bateria -= 1;
		return true;
	}
	
	void soma(int a, int b){
		if(gastarBateria())
			this.display = (a + b);
	}
	
	void div(int num, int den){
		if(!gastarBateria())
			return;
		if(den == 0){
			System.out.println("fail: divisao por zero");
		}
		else
			this.display = (float) num / den;
	}
	
	public String toString(){
		DecimalFormat form = new DecimalFormat("0.00");
		return "display = " + form.format(this.display) + ", battery = " + this.bateria;
	}
}

class Solver{
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Calculadora calc = new Calculadora(0);
		while(true){
			String line = scan.nextLine();
			System.out.println("$" + line);
			if(line.equals("end"))
				break;
				String ui[] = line.split(" ");
				if(ui[0].equals("help"))
					System.out.println("soma _a _b; show; div _a _b; charge _value");
				else if(ui[0].equals("init"))
					calc = new Calculadora(Integer.parseInt(ui[1]));
				else if(ui[0].equals("show"))
					System.out.println(calc);
				else if(ui[0].equals("charge")){
					calc.charge(Integer.parseInt(ui[1]));
				}else if(ui[0].equals("sum")){
					calc.soma(Integer.parseInt(ui[1]), Integer.parseInt(ui[2]));
				}else if(ui[0].equals("div")){
					calc.div(Integer.parseInt(ui[1]), Integer.parseInt(ui[2]));
				}else
					System.out.println("fail: comando invalido");
		}
		scan.close();
	}
}