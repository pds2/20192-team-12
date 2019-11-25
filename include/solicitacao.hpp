#ifndef SOLICITACAO_HPP
#define SOLICITACAO_HPP
#include <iostream>
#include <stdexcept> 
/**
 * Esta classe representa uma solicitação de transporte de uma determinada
 * quantidade de carga entre duas localidades. 
*/

class Solicitacao {
    private:
        /** código do município de origem*/
        int _origem;
        /** código do município de destino*/
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
#endif
