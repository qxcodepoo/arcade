class Adapter {
    public Adapter() {
    }

    // inicia uma nova calculadora
    public init(batteryMax: number): void {
        // battery e display inicializados com zero
        // batteryMax é inicializado com o valor passado por parametro
    }

    // retorna uma string com informações sobre a calculadora
    public show(): string {
        return "";
        // retorna o display da calculadora no formato
        // display = {%.2f}, bateria = {%.2f}
    }

    // recarrega a bateria de value
    public charge(value: number): void {
        // carrega a bateria ADICIONANDO o valor passado por parametro
        // se a bateria ultrapassar o valor maximo:
        //     a bateria é setada para o valor maximo
    }

    // realiza a soma de a + b para o display
    public sum(a: number, b: number): void {
        // se não tiver bateria:
        //     emite erro e retorna
        // gasta bateria
        // efetua a soma e guarda no display
    }

    // realiza a divisão de a por b
    public div(a: number, b: number): void {
        // se não tiver bateria:
        //     emite erro e retorna
        // gasta bateria
        // se a divisão for por 0:
        //     emite erro e retorna
        // guarda valor no display
    }
}

export { Adapter };