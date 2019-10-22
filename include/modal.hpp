#ifndef MODAL_H
#define MODAL_H

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

    	Modal();  
    	Modal(std::string, float, float, float);
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
        Rodoviario();
        ~Rodoviario();

        void setPedagio(bool);
        void setValorPedagio(float);

        bool isPedagio();
        float getValorPedagio();

        void obterCusto() override;
} 

class Aquaviario: public Modal {
    private:
        float _valor_terminal;

    public:
        Aquaviario();
        ~Aquaviario();

        void setValorTerminal(float);

        float getValorTerminal();

        void obterCusto() override;
} 

#endif