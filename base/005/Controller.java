import java.util.ArrayList;
import java.util.Scanner;

public class Controller{	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer> vet = new ArrayList<Integer>();
		
		while(true){
			String line = scanner.nextLine();
			System.out.println("$" + line);
			String ui[] = line.split(" ");
			String cmd = ui[0];

			if(line.equals("end")){
				break;
			}else if(cmd.equals("show")){
				System.out.print("[ ");
				for(Integer value : vet)
					System.out.print(value + " ");
				System.out.print("]\n");
			}else if(cmd.equals("rshow")){
			}else if(cmd.equals("add")){
				for(int i = 1; i < ui.length; i++)
					vet.add(Integer.parseInt(ui[i]));
			}else if(cmd.equals("find")){
			}else if(cmd.equals("ins")){
			}else if(cmd.equals("rmi")){
			}else if(cmd.equals("rma")){
			}else {
				System.out.print("fail: command not found\n");
			}
		}
		scanner.close();
	}
}