#include "embarcador.hpp"
#include <iostream>

void Embarcador::setOrigem(std::string origem){
    this->_origem = origem;
}

void Embarcador::setDestino(std::string destino){
    this->_destino = destino;
}

void Embarcador::setQuantidade(float quantidade){
	try{
    	this->_quantidade = quantidade;
	}catch(std::invalid_argument &e){
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
