#ifndef MODAL_HPP
#define MODAL_HPP
#include <iostream>
/**
 * A superclasse Modal representa uma conexão entre duas localidades e o meio de transporte que as conecta.\n 
 * O meio de transporte pode ser: rodoviário, ferroviário, aquaviário ou aéreo.\n 
 * Todos esses quatro meios de transporte possuem as seguintes informações:
 * 1) Tipo do modal: rodoviario, ferroviario, aquaviario ou aéreo;
 * 2) Preço: Reais/Km;
 * 3) Capacidade: em Toneladas;
 * 4) Velocidade: Km/h;
 * 5) Distância em Km;
 * O modal rodoviário tem como especificidade o fato de poder ter pedágio; 
 * Já os modais aquaviário e aéreo tem como especificidade o fato de ter tarifa do terminal.
*/
class Modal {

    protected: 
        /** tipo de modal: ferroviário, rodoviário, aquaviário e aéreo*/
        std::string _tipo_modal;
        /** preço do serviço de transporte*/
        float _preco;
        /** capacidade do veículo de carga*/
        float _capacidade;
        /** velocidade do veículo de transporte*/
        float _velocidade;
        /** distância entre as localidades*/
        int _distancia;
        /** indicador de aresta válida:
         *  - válida: 1;
         *  - inválida: 0.
        */
        int _flag;
        
    public:

        /** Construtor sem argumento da classe Modal*/
        Modal();      
        /** Construtor da classe Modal*/
        Modal(std::string, float, float, float, int);
        /** Destrutor da classe Modal*/
        ~Modal();

        /* Configura o preco do servico*/
        void setPreco(float);
        /* Configura a capacidade padrao do veiculo do modal*/
        void setCapacidade(float);
        /* Configura a velocidade padrao do veiculo do modal*/
        void setVelocidade(float);
        /** Configura entre as arestas*/
        void setDistancia(int);
        /* Obtem o tipo de modal*/
        std::string getTipoModal();
        /* Obtem o preco do servico*/
        float getPreco();
        /* Obtem a capacidade padrao do veiculo do modal*/
        float getCapacidade();
        /* Obtem a velocidade padrao do veiculo do modal*/
        float getVelocidade();
        // int getDistancia();
        int getFlagAresta();
        /** Distancia entre as arestas*/
        int getDistancia();
        /** obtem o custo do transporte */
        virtual float obterCusto(float);
        /** Obtem o tempo do transporte */
        float obterTempo();
};
/** A subclasse Ferroviario representa o modal de transporte ferroviário,
 * herdando os atributos e métodos da classe Modal.
*/
class Ferroviario: public Modal {   
    private: 
        // valores dos preços, capacidade média e velocidade média do modal ferrovário
        const float ferroviario_preco = 0.05; 
        const float ferroviario_capacidade = 70000;   
        const float ferroviario_velocidade = 20;
    public:
        /** Construtor sem argumento da classe Ferroviario*/
        Ferroviario();      
        /** Construtor da classe Ferroviario*/
        Ferroviario(int);
        /** Destrutor da classe Ferroviario*/
        ~Ferroviario();
        
        /* Configura o preco do servico*/
        void setPreco(float);
        /* Configura a capacidade padrao do veiculo do modal*/        
        void setCapacidade(float);
        /* Configura a velocidade padrao do veiculo do modal*/
        void setVelocidade(float);
        /** Configura entre as arestas*/
        void setDistancia(int);
        /* Obtem o tipo de modal*/
        std::string getTipoModal();
        /* Obtem o preco do servico*/
        float getPreco();
        /* Obtem a capacidade padrao do veiculo do modal*/
        float getCapacidade();
        /* Obtem a velocidade padrao do veiculo do modal*/
        float getVelocidade();
        /** Obtem o custo do transporte */
        /** Distancia entre as arestas*/
        int getDistancia();
        /** obtem o custo do transporte */
        float obterCusto(float) override;
};
/** A subclasse Rodoviario representa o modal de transporte ferroviário,
 * herdando os atributos e métodos da classe Modal.
*/
class Rodoviario: public Modal {
    private:
        // valores dos preços, capacidade média e velocidade média do modal rodoviário 
        const float rodoviario_preco = 0.075;
        const float rodoviario_capacidade = 35;
        const float rodoviario_velocidade = 60;

        int _pedagio;
        float _valor_pedagio;

    public:
        /** Construtor sem argumento da classe Rodoviario*/
        Rodoviario();
        /** Construtor da classe Rodoviario*/
        Rodoviario(int, bool, float);
        /** Destrutor da classe Rodoviario*/
        ~Rodoviario();

        /** Configura se existe pedagio*/
        void setPedagio(int);
        /** Configura o valor do pedagio*/
        void setValorPedagio(float);
        /** Retorna se existe pedagio no trajeto*/
        int isPedagio();
        /** Obtem o valor do pedagio*/
        float getValorPedagio();
        /** Distancia entre as arestas*/
        int getDistancia();
        /** Obtem o custo do transporte */
        float obterCusto(float) override;
};
/** A subclasse Aquaviario representa o modal de transporte ferroviário,
 * herdando os atributos e métodos da classe Modal.
*/
class Aquaviario: public Modal {
        // valores dos preços, capacidade média e velocidade média do modal rodoviário
        const float aquaviario_preco = 0.04375;
        const float aquaviario_capacidade = 1000;
        const float aquaviario_velocidade = 40;
    private:
        /** Valor da taxa do terminal*/
        float _valor_terminal;

    public:
        /** Construtor sem argumento da classe Aquaviario*/
        Aquaviario();
        /** Construtor da classe Aquaviario*/
        Aquaviario(int, float);
        /** Destrutor da classe Aquaviario*/
        ~Aquaviario();
        /** Configura o valor da tarifa do terminal */
        void setValorTerminal(float);
        /** Obtem o valor da tarifa do terminal */
        float getValorTerminal();
        /** Obtem o custo do transporte */
        float obterCusto(float) override;
};
/** A subclasse Aereo representa o modal de transporte ferroviário,
 * herdando os atributos e métodos da classe Modal.
*/
class Aereo: public Modal {
    private:
        // valores dos preços, capacidade média e velocidade média do modal rodoviário
        const float aereo_preco = 0.1;
        const float aereo_capacidade = 100;
        const float aereo_velocidade = 800;    
        float _valor_terminal;

    public:
        /** Construtor sem argumento da classe Aereo*/
        Aereo();
        /** Construtor com argumentos da classe Aereo*/
        Aereo(int, float);
        /** Destrutor da classe Aereo*/
        ~Aereo();
        /** Configura o valor da tarifa do terminal */
        void setValorTerminal(float);
        /** Obtem o valor da tarifa do terminal */
        float getValorTerminal();
        /** Obtem o custo do transporte */
        float obterCusto(float) override;
};
#endif