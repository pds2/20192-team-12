#ifndef MODAL_HPP
#define MODAL_HPP
#include <iostream>
/**
 * Esta classe representa uma conexão entre duas localidades e
 * o meio de transporte que as conecta.
 * .
 * O meio de transporte pode ser: rodoviário, ferroviário, aquaviário ou aéreo. 
 * Todos esses quatro meios de transporte possuem as seguintes informações:
 * 1) Tipo do modal: rodoviario, ferroviario, aquaviario ou aéreo;
 * 2) Preço: Reais/Km;
 * 3) Capacidade: em Toneladas;
 * 4) Velocidade: Km/h;
 * 5) Distância em Km;
 * .
 * O modal rodoviário tem como especificidade o fato de poder ter pedágio; 
 * já os modais aquaviário e aéreo tem como especificidade o fato de ter tarifa do terminal.
*/

class Modal {
    protected: 
        std::string _tipo_modal;
        float _preco;
        float _capacidade;
        float _velocidade;
        int _distancia;
        
    public:  
        Modal();      
        Modal(std::string, float, float, float, int);
        ~Modal();

        // void setTipoModal(std::string);
        void setPreco(float);
        void setCapacidade(float);
        void setVelocidade(float);
        void setDistancia(int);

        std::string getTipoModal();
        float getPreco();
        float getCapacidade();
        float getVelocidade();
        int getDistancia();

        // recebe a quantidade a ser transportada
        virtual float obterCusto(float);

        // retorna tempo em minutos
        float obterTempo();
};

class Ferroviario: public Modal {   
    private: 
        // valores dos preços, capacidade média e velocidade média do modal ferrovário
        const float ferroviario_preco = 0.05; 
        const float ferroviario_capacidade = 70000;   
        const float ferroviario_velocidade = 20;
    public:  
        Ferroviario();      
        Ferroviario(int);
        ~Ferroviario();

        void setPreco(float);
        void setCapacidade(float);
        void setVelocidade(float);
        void setDistancia(int);

        std::string getTipoModal();
        float getPreco();
        float getCapacidade();
        float getVelocidade();
        int getDistancia();

        // recebe a quantidade a ser transportada
        float obterCusto(float) override;
};

class Rodoviario: public Modal {
    private:
        // valores dos preços, capacidade média e velocidade média do modal rodoviário 
        const float rodoviario_preco = 0.075;
        const float rodoviario_capacidade = 35;
        const float rodoviario_velocidade = 60;

        int _pedagio;
        float _valor_pedagio;

    public:
        Rodoviario();
        Rodoviario(int, bool, float);
        ~Rodoviario();

        void setPedagio(int);
        void setValorPedagio(float);

        int isPedagio();
        float getValorPedagio();

        float obterCusto(float) override;
};

class Aquaviario: public Modal {
        // valores dos preços, capacidade média e velocidade média do modal rodoviário
        const float aquaviario_preco = 0.04375;
        const float aquaviario_capacidade = 1000;
        const float aquaviario_velocidade = 40;
    private:
        float _valor_terminal;

    public:
        Aquaviario();
        Aquaviario(int, float);
        ~Aquaviario();

        void setValorTerminal(float);
        float getValorTerminal();

        float obterCusto(float) override;
};

class Aereo: public Modal {
    private:
        // valores dos preços, capacidade média e velocidade média do modal rodoviário
        const float aereo_preco = 0.1;
        const float aereo_capacidade = 100;
        const float aereo_velocidade = 800;    
        float _valor_terminal;

    public:
        Aereo();
        Aereo(int, float);
        ~Aereo();

        void setValorTerminal(float);
        float getValorTerminal();

        float obterCusto(float) override;
};
#endif