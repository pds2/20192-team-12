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
#include <stdexcept>
#include <cmath>
#include "modal.hpp"
// #include "tools.hpp"

/*
Wagner: Desenvolvendo testes de unidade
*/
//Contrutores da classe Modal
Modal::Modal(){
    /*Construtor sem argumentos
        Padrao: rodoviario;
    */

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
float Modal::obterCusto(float distancia) {}

//Contrutores da classe Ferroviario
Ferroviario::Ferroviario(){
    this->_tipo_modal = "ferroviario";
    this->_preco = 0.05;
    this->_capacidade = 70000;
    this->_velocidade = 20;
}
Ferroviario::Ferroviario(int distancia){
    if (distancia < 0){
        throw std::invalid_argument("A distancia nao pode ser negativa!");
    }
    this->_tipo_modal = "ferroviario";
    this->_preco = 0.05;
    this->_capacidade = 70000;
    this->_velocidade = 20;
    this->_distancia = distancia;
}
Ferroviario::~Ferroviario(){}

void Ferroviario::setPreco(float preco){
    if (preco < 0 ){
        throw std::invalid_argument("O preco nao pode ser negativo.");
    }    
    this->_preco = preco;
}
void Ferroviario::setCapacidade(float capacidade){
    if (capacidade < 0 ){
        throw std::invalid_argument("A capacidade nao pode ser negativa.");
    }     
    this->_capacidade = capacidade;
}
void Ferroviario::setVelocidade(float velocidade){
    if (velocidade < 0 ){
        throw std::invalid_argument("A velocidade nao pode ser negativa.");
    }    
    this->_velocidade = velocidade;
}
void Ferroviario::setDistancia(int distancia){
    if (distancia < 0 ){
        throw std::invalid_argument("A distancia nao pode ser negativa.");
    }    
    this->_distancia = distancia;    
    
}
std::string Ferroviario::getTipoModal(){
    return this->_tipo_modal;
}
float Ferroviario::getPreco(){
    return this->_preco;
}
float Ferroviario::getCapacidade(){
    return this->_capacidade;
}
float Ferroviario::getVelocidade(){
    return this->_velocidade;
}

float Ferroviario::obterCusto(float quantidade){
    return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco);
}

//Construtores da classe Rodoviario
Rodoviario::Rodoviario(){
    this->_tipo_modal = "rodoviario";
    this->_preco = 0.075;
    this->_capacidade = 35;
    this->_velocidade = 60;
    this->_distancia = 0;
    this->_pedagio = 0;
    this->_valor_pedagio = 0;
} 

Rodoviario::Rodoviario(int distancia, bool pedagio, float valor_pedagio){
    if (distancia < 0 || valor_pedagio < 0){
        throw std::invalid_argument("As variaveis distancia e valor_pedagio e  nao podem ser negativas!");
    }    
    if (pedagio != true || pedagio != false){
        throw std::invalid_argument("A variavel pedagio tem que ser true ou false.");
    }
    // Modal(nome_modal, preco, capacidade, velocidade, distancia);
    this->_tipo_modal = "rodoviario";
    this->_preco = 0.075;
    this->_capacidade = 35;
    this->_velocidade = 60;
    this->_distancia = distancia;
    this->_pedagio = pedagio;
    this->_valor_pedagio = valor_pedagio;
}

Rodoviario::~Rodoviario(){}

//Metodos da classe Rodoviario
void Rodoviario::setPedagio(bool pedagio){
    if (pedagio != true || pedagio != false){
        throw std::invalid_argument("A variavel pedagio deve ser true ou false.");
    }
    this->_pedagio = pedagio;
}
void Rodoviario::setValorPedagio(float valor_pedagio){
    if (valor_pedagio < 0){
        throw std::invalid_argument("O valor do pedagio nao pode ser negativo.");
    }
    this->_valor_pedagio = valor_pedagio;
}
bool Rodoviario::isPedagio(){
    return this->_pedagio;
}
float Rodoviario::getValorPedagio(){
    return this->_valor_pedagio;
}
float Rodoviario::obterCusto(float quantidade){
    // quantidade de viagens vezes o custo
    try {
        return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_pedagio);
    }catch (std::exception &e){
        std::cout << " A capacidade nao pode ser zero.\n";
    }
}

//Construtores da classe Aquaviario
Aquaviario::Aquaviario(): Modal(), _valor_terminal(0) {}
 
Aquaviario::Aquaviario(int distancia, float valor_terminal) {
    // if (preco < 0 || capacidade < 0 || velocidade < 0 || valor_terminal < 0){
    //     throw std::invalid_argument("As variaveis preco, capacidade e velocidade nao podem ser negativas!");
    // }
    if (distancia < 0 || valor_terminal < 0){
        throw std::invalid_argument("A distancia e a taxa do terminal nao podem ser negativas.");
    }
    // Modal(nome_modal, preco, capacidade, velocidade);
    this->_tipo_modal = "aquaviario";
    this->_preco = 0.04375;
    this->_capacidade = 1000;
    this->_velocidade = 40;
    this->_distancia = distancia;
    this->_valor_terminal = valor_terminal;

}

Aquaviario::~Aquaviario(){}

//Metodos da classe Aquaviario
void Aquaviario::setValorTerminal(float valor_terminal){
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor da taxa do terminal nao pode ser negativo!");
    }    
    this->_valor_terminal = valor_terminal;
}
float Aquaviario::getValorTerminal(){
    return this->_valor_terminal;
}
float Aquaviario::obterCusto(float quantidade){
    // quantidade de viagens vezes o custo
    return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_terminal);
}

//Construtores da classe Aereo
Aereo::Aereo(): Modal(), _valor_terminal(0){}

Aereo::Aereo(int distancia, float valor_terminal){
    // if (preco < 0 || capacidade < 0 || velocidade < 0){
    //     throw std::invalid_argument("As variaveis preco, capacidade e velocidade nao podem ser negativas!");
    // }    
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor da taxa do terminal nao pode ser negativo.");
    }
    // Modal(nome_modal, preco, capacidade, velocidade);
    this->_tipo_modal = "aereo";
    this->_preco = 0.1;
    this->_capacidade = 100;
    this->_velocidade = 800;
    this->_distancia = distancia;
    this->_valor_terminal = valor_terminal;
}

Aereo::~Aereo(){}

//Metodos da classe Aereo
void Aereo::setValorTerminal(float valor_terminal){
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor do terminal nao pode ser negativo.");
    }    
    this->_valor_terminal = valor_terminal;
}
float Aereo::getValorTerminal(){
    return this->_valor_terminal;
}
float Aereo::obterCusto(float quantidade){
    // quantidade de viagens vezes o custo
    return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_terminal);
}