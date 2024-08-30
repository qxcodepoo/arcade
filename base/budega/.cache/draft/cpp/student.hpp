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

    std::string str() {
        return "";
    }
};

struct Student {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
    }
};
