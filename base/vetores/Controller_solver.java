import java.util.ArrayList;
import java.util.Scanner;



public class Controller{	
	static Scanner scan = new Scanner(System.in);

	public static void main(String[] args) {
		ArrayList<Integer> vet = new ArrayList<Integer>();

		while(true){
			String line = scan.nextLine();
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
				//_B
				System.out.print("[ ");
				for(int i = vet.size() - 1; i >= 0; --i)
					System.out.print(vet.get(i) + " ");
				System.out.print("]\n");
				//_E
			}else if(cmd.equals("add")){
				for(int i = 1; i < ui.length; i++)
					vet.add(Integer.parseInt(ui[i]));
			}else if(cmd.equals("find")){
				//_B
				System.out.print("[ ");
				for(int i = 1; i < ui.length; i++)
					System.out.print(vet.indexOf(Integer.parseInt(ui[i])) + " ");
				System.out.print("]\n");
				//_E
			}else if(cmd.equals("ins")){
				//_B
				int ind = Integer.parseInt(ui[1]);
				int value = Integer.parseInt(ui[2]);
				if(ind < 0)
					continue;
				if(ind > vet.size())
					ind = vet.size();
				vet.add(ind, value);
				//_E
			}else if(cmd.equals("rmi")){
				//_B
				int ind = Integer.parseInt(ui[1]);
				if((ind < 0) || (ind >= vet.size()))
					System.out.println("fail");
				else
					vet.remove(Integer.parseInt(ui[1]));
				//_E
			}else if(cmd.equals("rma")){
				//_B
				int value = Integer.parseInt(ui[1]);
			    for (int i = 0; i < vet.size(); i++) {
			        if (value == vet.get(i)) {
			            vet.remove(i);
			            i--;
			        }
			    }
			    //_E
			}else {
				System.out.print("fail: command not found\n");
			}
		}
	}
}