#include "embarcador.hpp"
#include <iostream>

void setOrigem(std::string origem){
    this->_origem = origem;
}

void setDestino(std::string destino){
    this->_destino = destino;
}

void setQuantidade(float quantidade){
    this->_quantidade = quantidade;
}

std::string getOrigem(){
    return this->_origem;
}
std::string getDestino(){
    return this->_destino;
}
float getQuantidade(){
    return this->_quantidade;
}
/*
Aguardando implementacao do metodo de obter rotas
*/
void obterRota();
