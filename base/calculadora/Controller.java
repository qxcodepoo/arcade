import java.util.Scanner;
class Calculadora {
	int bateriaMaxima;
	int bateria;
	
	public Calculadora(int bateriaMaxima) {
		this.bateriaMaxima = bateriaMaxima;
		this.bateria = 0;
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
	
	String soma(int a, int b){
		if(gastarBateria())
			return "" + (a + b);
		return "";
	}
	
	String div(int num, int den){
		if(!gastarBateria())
			return "";
		if(den == 0){
			System.out.println("fail: divisao por zero");
			return "";
		}
		return "" + (num/den);
	}
	
	public String toString(){
		return "battery = " + this.bateria;
	}
}

class Controller{
	Calculadora calc;
	static Scanner scan = new Scanner(System.in);
	
	public Controller() {
		calc = new Calculadora(0);
	}
	
	//nossa funcao shell que recebe uma pergunta e retorna uma resposta
	public void shell(String line){
		String ui[] = line.split(" ");
		if(ui[0].equals("help"))
			System.out.println("soma _a _b; show; div _a _b; charge _value");
		else if(ui[0].equals("init"))
			this.calc = new Calculadora(Integer.parseInt(ui[1]));
		else if(ui[0].equals("show"))
			System.out.println(calc);
		else if(ui[0].equals("charge")){
			calc.charge(Integer.parseInt(ui[1]));
		}else if(ui[0].equals("sum")){
			String value = calc.soma(Integer.parseInt(ui[1]), Integer.parseInt(ui[2]));
			if(!value.equals(""))
				System.out.println(value);
		}else if(ui[0].equals("div")){
			String value = calc.div(Integer.parseInt(ui[1]), Integer.parseInt(ui[2]));
			if(!value.equals(""))
				System.out.println(value);
		}else
			System.out.println("fail: comando invalido");
	}

	public static void main(String[] args) {
		Controller cont = new Controller();
		while(true){
			String line = scan.nextLine();
			System.out.println("$" + line);
			if(line.equals("end"))
				break;
			cont.shell(line);
		}
	}
}