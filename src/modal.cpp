/*
Esta classe representa uma conexão entre duas localidades e
o meio de transporte que as conecta.

O meio de transporte pode ser: ferroviário, rodoviário ou aquaviário. 
Todos esses três meios de transporte possuem as seguintes informações:
1) Tipo do modal: rodoviario, ferroviario ou aquaviario;
2) Preço: Reais/Km;
3) Capacidade: em Kg;
4) Velocidade: Km/h;

O modal rodoviário tem como especificidade o fato de poder ter pedágio; 
já o modal aquaviário tem como especificidade o fato de ter tarifa do terminal.
*/
#include <iostream>
#include "../include/modal.hpp"

void Modal::setTipoModal(std::string tipo_modal){
    this->_tipo_modal = tipo_modal;
}
void Modal::setPreco(float preco){
    this->_preco = preco;
}
void Modal::setCapacidade(float capacidade){
    this->_capacidade = capacidade;
}
void Modal::setVelocidade(float velocidade){
    this->_velocidade = velocidade;
}
std::string Modal::getTipoModal(){
    return this->_tipo_modal;
}
float Modal::getPreco(){
    return this->_preco;
}
float Modal::getCapacidade(){
    return this->_capacidade;
}
float Modal::getVelocidade(){
    return this->_velocidade;
}
void Rodoviario::setPedagio(bool tem_pedagio){
    this->_pedagio = tem_pedagio;
}
void Rodoviario::setValorPedagio(float pedagio){
    this->_valor_pedagio = pedagio;
}
bool Rodoviario::isPedagio(){
    return _pedagio;
}
float Rodoviario::getValorPedagio(){
    return _valor_pedagio;
}
void Aquaviario::setValorTerminal(float valor_terminal){
    this->_valor_terminal = valor_terminal;
}
float Aquaviario::getValorTerminal(){
    return this->_valor_terminal;
}
void Aereo::setValorTerminal(float valor_terminal){
     this->_valor_terminal = valor_terminal;
}
float Aereo::getValorTerminal(){
    return this->_valor_terminal;
}