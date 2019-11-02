#ifndef SOLICITACAO_H
#define SOLICITACAO_H
#include <iostream>
#include <stdexcept> 
/*
Esta classe representa uma solicitação de transporte de uma determinada
quantidade de carga entre duas localidades. 
*/

class Solicitacao {
    private: 
        int _origem;
        int _destino;
        float _quantidade;
    	
    public:

    	Solicitacao();
    	Solicitacao(int, int, float);
    	~Solicitacao(){};

        void setOrigem(int);
        void setDestino(int);
        void setQuantidade(float quantidade);

    	int getOrigem();
        int getDestino();
        float getQuantidade();
};
// class ParametroNaoNumerico : public std::exception {
//     public:
//     virtual const char* what() const noexcept override;
// };
// const char* ParametroNaoNumerico::what() const noexcept {
// return "O parametro deve ser numerico!";
// }
#endif
