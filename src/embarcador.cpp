#include "../include/embarcador.hpp"
#include <iostream>
#include <stdexcept>

Embarcador::Embarcador(int origem, int destino, float quantidade){
    try {    
        this->_origem = origem;
        this->_destino = destino;
        this->_quantidade = quantidade;
    }catch (std::invalid_argument &ia){
        std::cout << "Os paramentros quantidade, origem e destino deverm ser numericos\n";
    }
}
Embarcador::Embarcador(): Embarcador('2', 24, 35.0){}

void Embarcador::setOrigem(std::string origem){
    this->_origem = origem;
}

void Embarcador::setDestino(std::string destino){
    this->_destino = destino;
}

void Embarcador::setQuantidade(float quantidade){
	try{
    	this->_quantidade = quantidade;
	}catch(const std::invalid_argument& ia){
		std::cout << "A quantidade deve ser um valor numérico!";
	}	
}

std::string Embarcador::getOrigem(){
    return this->_origem;
}
std::string Embarcador::getDestino(){
    return this->_destino;
}
float Embarcador::getQuantidade(){
    return this->_quantidade;
}
/*
Aguardando implementacao do metodo de obter rotas
*/
void Embarcador::obterRota(){}
