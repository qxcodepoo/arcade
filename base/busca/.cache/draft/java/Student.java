import java.util.List;

class Student {
    static boolean in(List<Integer> vet, int x) {
        for (var elem : vet)
            if (elem.equals(x))
                return true;
        return false;
        return false;
    }

    static int indexOf(List<Integer> vet, int x) {
        for (int i = 0; i < vet.size(); ++i)
            if (vet.get(i).equals(x)) 
                return i;
        return -1;
        return 0;
    }

    static int findIf(List<Integer> vet) {
        for (int i = 0; i < vet.size(); ++i)
            if (vet.get(i) > 0)
                return i;
        return -1;
        return 0;
    }

    static int minElement(List<Integer> vet) {
        int index = -1;
        for (int i = 0; i < vet.size(); ++i)
            if (index == -1 || vet.get(i) < vet.get(index))
                index = i;
        return index;
        return 0;
    }

    static int findMinIf(List<Integer> vet) {
        int index = -1;
        for (int i = 0; i < vet.size(); ++i)
            if (vet.get(i) > 0 && //homem
                (index == -1 || vet.get(i) < vet.get(index))) //primeiro ou melhor
                index = i;
        return index;
        return 0;
    }

    public static void main(String[] args) {
        System.out.println("Rodando o arquivo do estudante");
    }
}
