#ifndef EMBARCADOR_H
#define EMBARCADOR_H
#include <iostream>
#include <stdexcept> 
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
    	// std::string _origem;
     //    std::string _destino;  
        int _origem;
        int _destino;
        float _quantidade;
    	
    public:

    	Embarcador();
    	Embarcador(int, int, float);
    	~Embarcador(){};

    	// void setOrigem(std::string);
     //    void setDestino(std::strin);
        void setOrigem(int);
        void setDestino(int);
        void setQuantidade(float quantidade);

    	int getOrigem();
        // std::string getOrigem();
        int getDestino();
        // std::string getDestino();
        float getQuantidade();
        
    	void obterRota();
};
// class ParametroNaoNumerico : public std::exception {
//     public:
//     virtual const char* what() const noexcept override;
// };
// const char* ParametroNaoNumerico::what() const noexcept {
// return "O parametro deve ser numerico!";
// }
#endif
