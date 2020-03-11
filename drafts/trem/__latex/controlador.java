package controle;

import trem.Locomotiva;
import trem.Passageiro;
import trem.Trem;
import trem.Vagao;

public class Controlador {
    public static void main(String[] args) {
        Locomotiva locomotiva = new Locomotiva(2);

        Vagao vagao = new Vagao(1);
        Vagao vagao2 = new Vagao(2);
        Vagao vagao3 = new Vagao(3);

        Trem trem = new Trem(locomotiva);
        trem.addVagao(vagao);
        trem.addVagao(vagao2);
        trem.addVagao(vagao3);

        trem.embarcar(new Passageiro("A"));
        trem.embarcar(new Passageiro("B"));
        trem.embarcar(new Passageiro("C"));
        Passageiro pass = new Passageiro("D");
                
        trem.embarcar(pass);
        System.out.println(trem);
        trem.desembarcar(1);
        System.out.println(trem);   
        trem.embarcar(pass);
        System.out.println(trem);     
    }
}