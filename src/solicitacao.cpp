#include "../include/solicitacao.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>

Solicitacao::Solicitacao(int origem, int destino, float quantidade){
    if (origem < 0 || destino < 0 || quantidade < 0){
        throw std::invalid_argument("Os valores nao podem ser negativos!");
    }
    try {
        this->_origem = origem;
        this->_destino = destino;
        this->_quantidade = quantidade;
    }catch (std::invalid_argument &ia){
    // }catch (std::ios_base::failure const& ex){
        std::cout << "Os paramentros quantidade, origem e destino devem ser numericos\n";
    }
}
Solicitacao::Solicitacao(): Solicitacao(2, 24, 35.0){}

void Solicitacao::setOrigem(int origem){
    // if (origem == NULL){
    //     throw std::invalid_argument("o argumento nao pode ser vazio.");
    // }
    if (origem < 0){
        throw std::invalid_argument("O codigo da origem nao pode ser negativo.");
    }

    this->_origem = origem;
}

void Solicitacao::setDestino(int destino){
    // if (destino == NULL){
    //     throw std::invalid_argument("o argumento nao pode ser vazio.");
    // }    
    if (destino < 0){
        throw std::invalid_argument("O codigo do destino nao pode ser negativo.");
    }    
    this->_destino = destino;
}

void Solicitacao::setQuantidade(float quantidade){
    // if (quantidade == NULL){
    //     throw std::invalid_argument("o argumento nao pode ser vazio.");
    // }      
    if (quantidade < 0){
        throw std::invalid_argument("A quantidade de carga nao pode ser negativa.");
    }    
	try{
    	this->_quantidade = quantidade;
	}catch(const std::invalid_argument& ia){
		std::cout << "A quantidade deve ser um valor numérico!";
	}	
}

int Solicitacao::getOrigem(){
    return this->_origem;
}

int Solicitacao::getDestino(){
    return this->_destino;
}
float Solicitacao::getQuantidade(){
    return this->_quantidade;
}
