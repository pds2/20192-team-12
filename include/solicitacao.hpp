#ifndef SOLICITACAO_HPP
#define SOLICITACAO_HPP
#include <iostream>
#include <stdexcept> 
/**
 * A classe Solicitacao representa uma solicitação de transporte de uma determinada
 * quantidade de carga entre duas localidades. 
*/
class Solicitacao {
    private:
        /** codigo do município de origem*/
        int _origem;
        /** codigo do município de destino*/
        int _destino;
        /** quantidade de carga a ser transportada*/
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
