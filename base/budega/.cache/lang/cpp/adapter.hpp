class Adapter {
public:
    Adapter() {
    }
    void init(int qtd_caixas) {
        (void) qtd_caixas;
    }
    void call(int indice) {
        (void) indice;
    }
    void finish(int indice) {
        (void) indice;
    }
    void arrive(const std::string& nome) {
        (void) nome;
    }

    std::string show() {
        return "";
    }
};
