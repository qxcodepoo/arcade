class Solver{
    public static void main(String[] s) {
        BankAgency agency = new BankAgency();
        while(true){
            try {
                var line = input();
                write("$" + line);
                var args = line.split(" ");

                if(line.equals("end")) {
                    break;
                } else if(args[0].equals("show")) {
                    write("" + agency);
                } else if(args[0].equals("addCli")) {
                    agency.addClient(args[1]);
                } else if(args[0].equals("saque")) { //accountId value
                    agency.withdraw((int) number(args[1]), number(args[2]));
                } else if(args[0].equals("deposito")) {//accountId value
                    agency.deposit((int) number(args[1]), number(args[2]));
                } else if(args[0].equals("transf")) {//from to value
                    agency.transfer((int) number(args[1]), (int) number(args[2]), number(args[3]));
                } else if(args[0].equals("update")) {
                    agency.monthlyUpdate();
                } else {
                    write("fail: comando invalido");
                }
            } catch (Exception e) {
                write(e.getMessage());
            }
        }
    }
    private static Scanner scanner = new Scanner(System.in);
    private static String  input()              { return scanner.nextLine(); }
    private static double  number(String value) { return Double.parseDouble(value); }
    private static void    write(String value)  { System.out.println(value); }
}
