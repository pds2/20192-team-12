#ifndef EMBARCADOR_H
#define EMBARCADOR_H

/*
Esta classe representa o usuário do sistema, o qual
realiza uma solicitação de transporte de uma determinada
quantidade de carga entre duas localidades. Obtém como
resposta:
1) Caso haja uma rota entre as duas localidades, a rota que apresenta
o menor custo financeiro e a rota que apresenta o menor
tempo necessário;
2) Caso não haja uma rota entre as duas localidades, recebe
um informativo de que não é possível transportar o produto entre
as duas localidades desejadas
*/

class Embarcador {
    private: 
    	std::string _origem;
        std::string _destino;
        float _quantidade;
    	
    public:

    	Embarcador();  
    	Embarcador(std::string, std::string, float);
    	~Embarcador();

    	void setOrigem(std::string);
        void setDestino(std::string);
        void setQuantidade(float quantidade);

    	std::string getOrigem();
        std::string getDestino();
        float getQuantidade();

    	void obterRota();
};

#endif