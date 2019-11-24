#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include "solicitacao.hpp"
Solicitacao::Solicitacao(): Solicitacao(2, 24, 35.0){
    /** Construtor sem argumentos da classe Rodoviario 
    */       
}
Solicitacao::Solicitacao(int origem, int destino, float quantidade){
   /**
     * Construtor da classe Modal\n
     * Argumentos:
     *  - origem: código do município de origem;
     *  - destino: código do município de destino;
     *  - quantidade: valor da quantidade de carga, em toneladas.
     * .
     *  Exceção:
     *       - os valores não podem ser negativos e o valor da carga não pode ser zero;  
    */      
    if (origem < 0 || destino < 0 || quantidade <= 0){
        throw std::invalid_argument("Os valores nao podem ser negativos e o valor da carga não pode ser zero.\n");
    }
    try {
        this->_origem = origem;
        this->_destino = destino;
        this->_quantidade = quantidade;
    }catch (std::invalid_argument &ia){
        std::cout << "Os paramentros quantidade, origem e destino devem ser numericos\n";
    }
}
void Solicitacao::setOrigem(int origem){
    /** Atribui o valor do código do município de origem.\n 
     *  Argumento:
     *      - origem: código do município de origem
     * .
     *  Exceção:
     *      - o valor não pode ser negativo;
    */    
    if (origem < 0){
        throw std::invalid_argument("O codigo da origem nao pode ser negativo.");
    }

    this->_origem = origem;
}

void Solicitacao::setDestino(int destino){
    /** Atribui o valor do código do município de destino.\n 
     *  Argumento:
     *      - destino: código do município de destino
     * .
     *  Exceção:
     *      - o valor não pode ser negativo;
    */      
    if (destino < 0){
        throw std::invalid_argument("O codigo do destino nao pode ser negativo.");
    }    
    this->_destino = destino;
}

void Solicitacao::setQuantidade(float quantidade){
    /** Atribui o valor da quantidade de carga a ser transportada.\n 
     *  Argumento:
     *      - quantidade: valor da quantidade de carga
     * .
     *  Exceção:
     *      - o valor não pode ser negativo;
    */       
    
    if (quantidade <= 0){
        throw std::invalid_argument("A quantidade de carga dever ser positiva.");
    }    
	try{
    	this->_quantidade = quantidade;
	}catch(const std::invalid_argument& ia){
		std::cout << "A quantidade deve ser um valor numérico!";
	}	
}

int Solicitacao::getOrigem(){
    /** Retorna o código do município de origem.\n
     *  Sem argumentos.
    */       
    return this->_origem;
}

int Solicitacao::getDestino(){
    /** Retorna o código do município de destino.\n
     *  Sem argumentos.
    */      
    return this->_destino;
}
float Solicitacao::getQuantidade(){
    /** Retorna o valor da quantidade de carga a ser transportada.\n
     *  Sem argumentos.
    */      
    return this->_quantidade;
}
