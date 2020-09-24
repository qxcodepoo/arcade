import java.util.*;

interface Conta{
    void depositar(float value);
    void saque(float valor);
    void tarifa(float valor);
    void extrato();
    void extratoN(int valor);
    void extornar(int valor)
}
public class Solver {
    public static void main(String[] args) {
        Conta sys = new Conta(100);
        System.out.println(sys);
/*
    conta:100 saldo:0
*/
        sys.depositar(100);
        sys.depositar(-10);
/*
    fail: valor invalido
*/
        System.out.println(sys);
/*
    conta:100 saldo:100
*/
        sys.saque(20);
        sys.tarifa(10);
        System.out.println(sys);
/*
    conta:100 saldo:70
*/
        sys.saque(150);
/*
    fail: saldo insuficiente
*/
        sys.saque(30);
        sys.tarifa(5);
        sys.depositar(5);
        sys.tarifa(1);
        System.out.println(sys);
/*
    conta:100 saldo:39
*/
        sys.extrato();
/*
0: abertura:    0:    0
1: deposito:  100:  100
2:    saque:  -20:   80
3:   tarifa:  -10:   70
4:    saque:  -30:   40
5:   tarifa:   -5:   35
6: deposito:    5:   40
7:   tarifa:   -1:   39
*/
        sys.extratoN(2);
/*
6: deposito:    5:   40
7:   tarifa:   -1:   39
*/
        for(int id : Arrays.asList(1, 5, 7, 50))
            sys.extornar(id);
/*
fail: indice 1 nao e tarifa
fail: indice 50 invalido
*/
        sys.extrato();
/*
0: abertura:    0:    0
1: deposito:  100:  100
2:    saque:  -20:   80
3:   tarifa:  -10:   70
4:    saque:  -30:   40
5:   tarifa:   -5:   35
6: deposito:    5:   40
7:   tarifa:   -1:   39
8:  extorno:    5:   44
9:  extorno:    1:   45
*/
        sys.tarifa(5);
        sys.extratoN(2);
/*
9:  extorno:    1:   45
10:   tarifa:  -50:   -5
*/
    }
}