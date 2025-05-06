import java.util.ArrayList;
import java.util.Scanner;
import java.text.*;

class ArrayManip {
    ArrayList<Integer> vet = new ArrayList<Integer>();

    public void ArrayManip() {
    }

    public void add(int value) {
        vet.add(value);
    }

    public void add(int elements[]) {
        for (int x : elements) {
            vet.add(x);
        }
    }

    public void rmi(int index) {
        if (index < 0 || index > vet.size() - 1)
            System.out.println("fail");
        else
            vet.remove(index);
    }

    public void rma(int value) {
        for (int i = 0; i < vet.size(); i++) {
            if (value == vet.get(i)) {
                vet.remove(i);
                i--;
            }
        }
    }

    public void ins(int index, int element) {
        if (index >= vet.size())
            vet.add(element);
        else if (index >= 0)
            vet.add(index, element);
    }

    public int get(int index) {
        return vet.get(index);
    }

    public void set(int index, int element) {
        vet.set(index, element);
    }

    public String find(int[] index) {
        String string = "[ ";
        for (int i = 0; i < vet.size(); i++)
            string += vet.indexOf(index[i]) + " ";
        string += "]\n";
        return string;
    }

    public String show() {
        String string = "[ ";
        for (Integer x : vet)
            string += x + " ";
        string += "]\n";
        return string;
    }

    public String rshow() {
        String string = "[ ";
        for (int i = vet.size() - 1; i >= 0; i--)
            string += vet.get(i) + " ";
        string += "]\n";
        return string;
    }
}

class Main {
    public static void main(String[] args) {
        // __case inicio
        ArrayManip vet = new ArrayManip();
        System.out.print(vet.show());
        // [ ]
        vet.add(new int[] { 1, 2, 3, 4 });
        System.out.print(vet.show());
        // [ 1 2 3 4 ]

        // __case inicio
        vet = new ArrayManip();
        System.out.print(vet.show());
        // [ ]
        vet.add(new int[] { 1, 2, 3, 4 });
        vet.get(0);
        // 1
        vet.get(3);
        // 4
        vet.set(0, 9);
        System.out.print(vet.show());
        // [ 9 2 3 4 ]

        // __case rshow
        vet = new ArrayManip();
        System.out.print(vet.rshow());
        // [ ]
        vet.add(1);
        System.out.print(vet.rshow());
        // [ 1 ]
        vet.add(new int[] { 2, 3, 5 });
        System.out.print(vet.rshow());
        // [ 5 3 2 1 ]

        // __case add_mais_elementos
        vet = new ArrayManip();
        vet.add(new int[] { 4, 5, 6, 8, 1, 2, 2, 9 });
        vet.add(new int[] { 2, 2, 2, 8, 9, 0, 1, 4 });
        vet.add(new int[] { 3, 3, 2, 1 });
        System.out.print(vet.show());
        // [ 4 5 6 8 1 2 2 9 2 2 2 8 9 0 1 4 3 3 2 1 ]

        // __case find_elemento
        vet = new ArrayManip();
        vet.find(new int[] { 7 });
        // [ -1 ]
        vet.find(new int[] { 6, 8, 9 });
        // [ 2 3 7 ]
        vet.find(new int[] { 2, 0, 1, 7, 10 });
        // [ 5 13 4 -1 -1 ]

        // __case insert_indice
        vet = new ArrayManip();
        vet.add(new int[] { 3, 7 });
        System.out.print(vet.show());
        // [ 3 7 ]
        vet.ins(0, 2);
        System.out.print(vet.show());
        // [ 2 3 7 ]
        vet.ins(3, 1);
        System.out.print(vet.show());
        // [ 2 3 7 1 ]
        vet.ins(-2, 5);
        System.out.print(vet.show());
        // [ 2 3 7 1 ]
        vet.ins(9, 5);
        System.out.print(vet.show());
        // [ 2 3 7 1 5 ]
        vet.ins(2, 6);
        System.out.print(vet.show());
        // [ 2 3 6 7 1 5 ]

        // __case remover_por_indice
        vet = new ArrayManip();
        vet.add(new int[] { 4, 5, 6, 8, 1, 2, 2, 9 });
        vet.rmi(0);
        System.out.print(vet.show());
        // [ 5 6 8 1 2 2 9 ]
        vet.rmi(5);
        System.out.print(vet.show());
        // [ 5 6 8 1 2 9 ]
        vet.rmi(5);
        System.out.print(vet.show());
        // [ 5 6 8 1 2 ]
        vet.rmi(2);
        System.out.print(vet.show());
        // [ 5 6 1 2 ]
        vet.rmi(-1);
        // fail
        vet.rmi(4);
        // fail
        System.out.print(vet.show());
        // [ 5 6 1 2 ]

        // __case remove_all
        vet = new ArrayManip();
        vet.add(new int[] { 2, 2, 2, 2 });
        vet.rma(2);
        System.out.print(vet.show());
        // [ ]
        vet.add(new int[] { 4, 4, 4, 4, 2, 2, 2, 4, 4, 4, 1, 2, 3, 4 });
        vet.rma(7);
        System.out.print(vet.show());
        // [ 4 4 4 4 2 2 2 4 4 4 1 2 3 4 ]
        vet.rma(2);
        System.out.print(vet.show());
        // [ 4 4 4 4 4 4 4 1 3 4 ]
        vet.rma(4);
        System.out.print(vet.show());
        // [ 1 3 ]
    }
}