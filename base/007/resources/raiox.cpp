class Operacao{
    int indice;  
    string descricao;  
    float valor; 
    float saldo; 
public:
    Operacao(indice, descricao, valor, saldo);
    friend ostream& operator<<(ostream& os, Operacao& operacao);
};


class Conta{
    int nextId; //id da próxima operaçao
    float saldo; 
    int numero; 
    Operacao[] extrato; 
public:
    salvarOperacao(string label, float value, float saldo) // usado para alterar saldo e extrato
    debitar(string label, float value)//usado para saque e tarifa
    creditar(string label, float value)// usado para extorno e depósito
    getExtratoN( int N)//retorna as última n operacoes
    friend ostream& operator<<(ostream& os, Conta& conta);
}