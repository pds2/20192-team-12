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

O modal rodoviário tem como especificidade o fato de poder ter pedágio; 
já o modal aquaviário tem como especificidade o fato de ter tarifa do terminal.
*/

class Modal {
    protected: 
        std::string _tipo_modal;
    	float _preco;
        float _capacidade;
        float _velocidade;
    	
    public:  
        Modal(): Modal("rodoviario", 0.075, 35, 60){}        
    	Modal(std::string nome_modal, float preco, float capacidade, float velocidade): _tipo_modal(nome_modal),
                                                                                        _preco(preco),
                                                                                        _capacidade(capacidade),
                                                                                        _velocidade(velocidade){}
    	~Modal();

    	void setTipoModal(std::string);
        void setPreco(float);
        void setCapacidade(float);
        void setVelocidade(float);

    	std::string getTipoModal();
        float getPreco();
        float getCapacidade();
        float getVelocidade();

    	virtual void obterCusto();
        void obterTempo();
};

class Rodoviario: public Modal {
    private:
        bool _pedagio;
        float _valor_pedagio;

    public:
        Rodoviario(): Rodoviario(0, 0 ){};
        Rodoviario(bool pedagio, float valor_pedagio): _pedagio(pedagio), _valor_pedagio(valor_pedagio){}
        ~Rodoviario();

        void setPedagio(bool);
        void setValorPedagio(float);

        bool isPedagio();
        float getValorPedagio();

        void obterCusto() override;
};

class Aquaviario: public Modal {
    private:
        float _valor_terminal;

    public:
        Aquaviario(): Aquaviario(0){}
        Aquaviario(float valor_terminal): _valor_terminal(valor_terminal){}
        ~Aquaviario();

        void setValorTerminal(float);
        float getValorTerminal();
        void obterCusto() override;
};
class Aereo: public Modal {
    private:
        float _valor_terminal;

    public:
        Aereo(): Aereo(0){}
        Aereo(float valor_terminal): _valor_terminal(valor_terminal){}
        ~Aereo();

        void setValorTerminal(float);
        float getValorTerminal();
        void obterCusto() override;
};
#endif