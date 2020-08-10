import java.util.Scanner;

public class Solver{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		double reg = 0.0;

		while(true){
			String line = scanner.nextLine();
			System.out.println("$" + line);
			String ui[] = line.split(" "); //UI == user input
			String cmd = ui[0];

			if(line.equals("end")){
				break;
			}else if(cmd.equals("show")){
				System.out.printf("%.2f\n", reg);
			}else if(cmd.equals("add")){
				reg += Double.parseDouble(ui[1]);
			}else if(cmd.equals("mult")){
				reg *= Double.parseDouble(ui[1]);
			}else if(cmd.equals("div")){
				double value = Double.parseDouble(ui[1]);
				if(value == 0.0)
					System.out.println("fail: division by zero");
				else
					reg /= value;
			}else if(cmd.equals("addm")) {
				for(int i = 1; i < ui.length; i++){
					reg += Double.parseDouble(ui[i]);
				}
			}else{
				System.out.println("fail: command not found");
			}
		}
		scanner.close();
	}
}