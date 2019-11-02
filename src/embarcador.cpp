#include "../include/embarcador.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>
Embarcador::Embarcador(int origem, int destino, float quantidade){
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
Embarcador::Embarcador(): Embarcador('2', 24, 35.0){}

// void Embarcador::setOrigem(std::string origem){
void Embarcador::setOrigem(int origem){
    // if (origem == NULL){
    //     throw std::invalid_argument("o argumento nao pode ser vazio.");
    // }
    if (origem < 0){
        throw std::invalid_argument("O codigo da origem nao pode ser negativo.");
    }

    this->_origem = origem;
}

// void Embarcador::setDestino(std::string destino){
void Embarcador::setDestino(int destino){
    // if (destino == NULL){
    //     throw std::invalid_argument("o argumento nao pode ser vazio.");
    // }    
    if (destino < 0){
        throw std::invalid_argument("O codigo do destino nao pode ser negativo.");
    }    
    this->_destino = destino;
}

void Embarcador::setQuantidade(float quantidade){
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

int Embarcador::getOrigem(){
// std::string Embarcador::getOrigem(){
    return this->_origem;
}
// std::string Embarcador::getDestino(){
int Embarcador::getDestino(){
    return this->_destino;
}
float Embarcador::getQuantidade(){
    return this->_quantidade;
}
