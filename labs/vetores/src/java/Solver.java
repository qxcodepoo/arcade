import java.util.ArrayList;
import java.util.Scanner;

//!KEEP
public class Solver{	
    
    public static void main(String[] args) {
        ArrayList<Integer> vet = new ArrayList<Integer>();
        Scanner scan = new Scanner(System.in);

        while(true) {
            String line = scan.nextLine();
            System.out.println("$" + line);
            String ui[] = line.split(" ");
            String cmd = ui[0];

            if(line.equals("end")) {
                break;
            } else if(cmd.equals("show")) {
                System.out.print("[ ");
                for(Integer value : vet)
                    System.out.print(value + " ");
                System.out.print("]\n");
            } else if(cmd.equals("rshow")) {
                //!DEL
                System.out.print("[ ");
                for(int i = vet.size() - 1; i >= 0; --i)
                    System.out.print(vet.get(i) + " ");
                System.out.print("]\n");
                //!INS
            } else if(cmd.equals("add")) {
                for(int i = 1; i < ui.length; i++)
                    vet.add(Integer.parseInt(ui[i]));
            } else if(cmd.equals("find")) {
                //!DEL
                System.out.print("[ ");
                for(int i = 1; i < ui.length; i++)
                    System.out.print(vet.indexOf(Integer.parseInt(ui[i])) + " ");
                System.out.print("]\n");
                //!INS
            } else if(cmd.equals("get")) {
                //!DEL
                int ind = Integer.parseInt(ui[1]);
                System.out.println(vet.get(ind));
                //!INS
            } else if(cmd.equals("set")) {
                //!DEL
                int ind = Integer.parseInt(ui[1]);
                int value = Integer.parseInt(ui[2]);
                vet.set(ind, value);
                //!INS
            } else if(cmd.equals("ins")) {
                //!DEL
                int ind = Integer.parseInt(ui[1]);
                int value = Integer.parseInt(ui[2]);
                if(ind < 0)
                    continue;
                if(ind > vet.size())
                    ind = vet.size();
                vet.add(ind, value);
                //!INS
            } else if(cmd.equals("rmi")) {
                //!DEL
                int ind = Integer.parseInt(ui[1]);
                if((ind < 0) || (ind >= vet.size()))
                    System.out.println("fail");
                else
                    vet.remove(Integer.parseInt(ui[1]));
                //!INS
            } else if(cmd.equals("rma")) {
                //!DEL
                int value = Integer.parseInt(ui[1]);
                for (int i = 0; i < vet.size(); i++) {
                    if (value == vet.get(i)) {
                        vet.remove(i);
                        i--;
                    }
                }
                //!INS
            } else {
                System.out.print("fail: command not found\n");
            }
        }
        scan.close();
    }
}
//!OFF