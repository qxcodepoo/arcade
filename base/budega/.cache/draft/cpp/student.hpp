class Adapter {
    // Mercantil bank;
public:
    void init(int qtd_caixas) {
        (void) qtd_caixas;
        // bank = Mercantil(qtd_caixas);
    }
    void call(int indice) {
        (void) indice;
        // bank.chamarNoCaixa(indice);
    }
    void finish(int indice) {
        (void) indice;
        // bank.finalizar(indice);
    }
    void arrive(const std::string& nome) {
        // bank.chegar(std::make_shared<Pessoa>(nome));
        (void) nome;
    }

    void show() {
        // fn::write(bank.str());
    }
};
