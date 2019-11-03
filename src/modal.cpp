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
#include <stdexcept>
#include <cmath>

//Contrutores da classe Modal
Modal::Modal(){
    /*Construtor sem argumentos
        Padrao: rodoviario;
    */

    // Modal("rodoviario", 0.075, 35, 60, 100){} // Default: modal rodoviario
    this->_tipo_modal = "rodoviario";
    this->_preco = 0.075;
    this->_capacidade = 35;
    this->_velocidade = 60;
    this->_distancia = 100;
}

Modal::Modal(std::string nome_modal, float preco, float capacidade, float velocidade, int distancia){
    if (preco < 0 || capacidade < 0 || velocidade < 0 || distancia < 0){
        throw std::invalid_argument("As variaveis preco, capacidade, velocidade e distancia nao podem ser negativas!");
    }
    this->_tipo_modal = nome_modal;
    this->_preco = preco;
    this->_capacidade = capacidade;
    this->_velocidade = velocidade;
    this->_distancia = distancia;
}
Modal::~Modal(){}

//Metodos da classe Modal
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
void Modal::setDistancia(int distancia){
    this->_distancia = distancia;
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
int Modal::getDistancia(){
    return this->_distancia;
}
float Modal::obterTempo(){
    return this->_distancia / this->_velocidade * 60;
}

//Construtores da classe Rodoviario
Rodoviario::Rodoviario(): Modal(), _pedagio = 0, _valor_pedagio = 0 {}

Rodoviario::Rodoviario(std::string nome_modal, float preco, float capacidade, float velocidade, int distancia, bool pedagio, float valor_pedagio){
    if (pedagio != true || pedagio != false){
        throw std::invalid_argument("A variavel pedagio tem que ser true ou false.");
    }
    if (valor_pedagio < 0){
        throw std::invalid_argument("O valor do pedagio nao pode ser negativo.");
    }
    Modal(nome_modal, preco, capacidade, velocidade, distancia);
    this->_pedagio = pedagio;
    this->_valor_pedagio = valor_pedagio;
} 

Rodoviario::~Rodoviario(){}

//Metodos da classe Rodoviario
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
float Rodoviario::obterCusto(float quantidade){
    // quantidade de viagens vezes o custo
    return cmath::ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_pedagio);
}

//Construtores da classe Aquaviario
Aquaviario::Aquaviario(): Modal(), _valor_terminal = 0 {}
 
Aquaviario::Aquaviario(std::string nome_modal, float preco, float capacidade, float velocidade, int distancia, float valor_terminal): {
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor do terminal nao pode ser negativo.");
    }
    Modal(nome_modal, preco, capacidade, velocidade);
    this->_valor_terminal = valor_terminal;

}

Aquaviario::~Aquaviario(){}

//Metodos da classe Aquaviario
void Aquaviario::setValorTerminal(float valor_terminal){
    this->_valor_terminal = valor_terminal;
}
float Aquaviario::getValorTerminal(){
    return this->_valor_terminal;
}
float Aquaviario::obterCusto(){
    // quantidade de viagens vezes o custo
    return cmath::ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_terminal);
}

//Construtores da classe Aereo
Aereo::Aereo(): Modal(), _valor_terminal = 0 {}

Aereo::Aereo(std::string nome_modal, float preco, float capacidade, float velocidade, int distancia, float valor_terminal): {
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor do terminal nao pode ser negativo.");
    }
    Modal(nome_modal, preco, capacidade, velocidade);
    this->_valor_terminal = valor_terminal;
}

Aereo::~Aereo(){}

//Metodos da classe Aereo
void Aereo::setValorTerminal(float valor_terminal){
     this->_valor_terminal = valor_terminal;
}
float Aereo::getValorTerminal(){
    return this->_valor_terminal;
}
float Aereo::obterCusto(){
    // quantidade de viagens vezes o custo
    return cmath::ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_terminal);
}