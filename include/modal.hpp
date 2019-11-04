#ifndef MODAL_H
#define MODAL_H
#include <iostream>
/*
Esta classe representa uma conexão entre duas localidades e
o meio de transporte que as conecta.

O meio de transporte pode ser: ferroviário, rodoviário ou aquaviário. 
Todos esses três meios de transporte possuem as seguintes informações:
1) Tipo do modal: rodoviario, ferroviario ou aquaviario;
2) Preço: Reais/Km;
3) Capacidade: em Kg;
4) Velocidade: Km/h;
5) Distância em Km;

O modal rodoviário tem como especificidade o fato de poder ter pedágio; 
já o modal aquaviário tem como especificidade o fato de ter tarifa do terminal.
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

        void setTipoModal(std::string);
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
        virtual float obterCusto(float) = 0;

        // retorna tempo em minutos
        float obterTempo();
};
class Ferroviario {
    protected: 
        std::string _tipo_modal;
        float _preco;
        float _capacidade;
        float _velocidade;
        int _distancia;
        
    public:  
        Ferroviario();      
        Ferroviario(std::string, float, float, float, int);
        ~Ferroviario();

        void setTipoModal(std::string);
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
        float obterCusto(float);

        // retorna tempo em minutos
        float obterTempo();
};
class Rodoviario: public Modal {
    private:
        bool _pedagio;
        float _valor_pedagio;

    public:
        Rodoviario();
        Rodoviario(std::string, float, float, float, int, bool, float);
        ~Rodoviario();

        void setPedagio(bool);
        void setValorPedagio(float);

        bool isPedagio();
        float getValorPedagio();

        float obterCusto(float);
};

class Aquaviario: public Modal {
    private:
        float _valor_terminal;

    public:
        Aquaviario();
        Aquaviario(std::string, float, float, float, int, float);
        ~Aquaviario();

        void setValorTerminal(float);
        float getValorTerminal();

        float obterCusto(float);
};

class Aereo: public Modal {
    private:
        float _valor_terminal;

    public:
        Aereo();
        Aereo(std::string, float, float, float, int, float);
        ~Aereo();

        void setValorTerminal(float);
        float getValorTerminal();

        float obterCusto(float);
};
#endif