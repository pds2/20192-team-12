#include <iostream>
#include <stdexcept>
#include <cmath>
#include "../include/modal.hpp"

// DECLARACAO DE CONSTANTES DEFAULT
#define MODAL_DEFAULT "rodoviario"
#define PRECO_DEFAULT 0.075
#define CAPACIDADE_DEFAULT 35
#define VELOCIDADE_DEFAULT 60
#define DISTANCIA_DEFAULT 0
/** Construtor sem argumentos da classe Modal\n
    Default:
    *  - nome_modal: rodoviário;
    *  - preco: 0.075;
    *  - capacidade: 35;
    *  - velocidade: 60; e 
    *  - distancia: 0.\n         
*/
Modal::Modal(){


    this->_tipo_modal = MODAL_DEFAULT;
    this->_preco = PRECO_DEFAULT;
    this->_capacidade = CAPACIDADE_DEFAULT;
    this->_velocidade = VELOCIDADE_DEFAULT;
    this->_distancia = DISTANCIA_DEFAULT;
    this->_flag = 0;
}

Modal::Modal(std::string nome_modal, float preco, float capacidade, float velocidade, int distancia){
    /**
     * Construtor da classe Modal\n
     *  Argumentos:
     *  - nome_modal: nome do modal de transporte;
     *  - preco: preço do modal de transporte em R$;
     *  - capacidade: capacidade do modal de transporte em toneladas;
     *  - velocidade: velocidade do modal de transporte em km/h; e 
     *  - distancia: distancia em km entre as localidades de origem e destino.\n 
    */    
    if (preco < 0 || capacidade < 0 || velocidade < 0 || distancia < 0){
        throw std::invalid_argument("As variaveis preco, capacidade, velocidade e distancia nao podem ser negativas!");
    }
    this->_tipo_modal = nome_modal;
    this->_preco = preco;
    this->_capacidade = capacidade;
    this->_velocidade = velocidade;
    this->_distancia = distancia;
    this->_flag = 0;
}
Modal::~Modal(){
    /** Destrutor da classe Modal
    */
}
//Metodos da classe Modal
void Modal::setPreco(float preco){
    /** Atribui o valor da variável preço.\n
     *   Argumento:
     *      - preço: valor pago pelo tranporte, em R$;\n
     .
     *  Exceção:\n
     *       - o valor não pode ser negativo;\n
    */
    if (preco < 0 ){
        throw std::invalid_argument("O preco nao pode ser negativo.");
    }    
    this->_preco = preco;
}
void Modal::setCapacidade(float capacidade){
    /** Atribui o valor da variável capacidade.\n
     *   Argumento:
     *      - capacidade: valor da capacidade transporte do modal, em toneladas;\n
     .
     *  Exceção:\n
     *       - o valor não pode ser negativo;\n
    */    
    if (capacidade < 0 ){
        throw std::invalid_argument("A capacidade nao pode ser negativa.");
    }     
    this->_capacidade = capacidade;
}
void Modal::setVelocidade(float velocidade){
    /** Atribui o valor da variável velocidade.\n
     *   Argumento:
     *      - velocidade: valor da velocidade do meio de transporte utilizado, em km/h;\n
     .
     *  Exceção:\n
     *       - o valor não pode ser negativo;\n
    */     
    if (velocidade < 0 ){
        throw std::invalid_argument("A velocidade nao pode ser negativa.");
    }    
    this->_velocidade = velocidade;
}
void Modal::setDistancia(int distancia){
    /** Atribui o valor da variável distancia.\n
     *  Argumento:
     *      - distancia: valor da distância entre as localidades de origem e destino da carga.\n
     *  Exceção:
     *       - o valor não pode ser negativo;
    */       
    if (distancia < 0 ){
        throw std::invalid_argument("A distancia nao pode ser negativa.");
    }    
    this->_distancia = distancia;
}
std::string Modal::getTipoModal(){
    /** Retorna o tipo de modal utilizado no transporte.\n
     *  Sem argumentos.
    */      
    return this->_tipo_modal;
}
float Modal::getPreco(){
    /** Retorna o preço do serviço de transporte de carga.\n
     *  Sem argumentos.
    */       
    return this->_preco;
}
float Modal::getCapacidade(){
    /** Retorna a capacidade do veículo de transporte de carga utilizado.\n
     *  Sem argumentos.
    */       
    return this->_capacidade;
}
float Modal::getVelocidade(){
    /** Retorna a velocidade média do veículo de transporte de carga utilizado.\n
     *  Sem argumentos.
    */     
    return this->_velocidade;
}
int Modal::getFlagAresta(){
    /** Retorna se há uma aresta entre duas localidades
    *
    */
    return this->_flag;
}
int Modal::getDistancia(){
    /** Retorna a distância em linha reta entre as localidades de origem e destino da carga.\n
     *  Sem argumentos.
    */         
    return this->_distancia;
}
float Modal::obterTempo(){
    /** Retorna o tempo de viagem entre as localidades de origem e destino da carga, a partir da velocidade média.\n
     *  Sem argumentos.
    */             
    return this->_distancia / this->_velocidade;
}
float Modal::obterCusto(float distancia) {
    /** Implementado somente nas classes derivadas
    */     
}

//Contrutores da classe Ferroviario
Ferroviario::Ferroviario(){
    /** Construtor sem argumentos da classe Ferroviário
        Default:
     *  - nome_modal: ferroviario;
     *  - preco: 0.05;
     *  - capacidade: 70000;
     *  - velocidade: 20; e 
     *  - distancia: 0\n  
    */ 
    this->_tipo_modal = "ferroviario";
    this->_preco = this->ferroviario_preco;
    this->_capacidade = this->ferroviario_capacidade;
    this->_velocidade = this->ferroviario_velocidade;
    this->_flag = 1;
}
Ferroviario::Ferroviario(int distancia){
    /**
     * Construtor da classe Ferroviario\n
     *  Argumento:
     *  - distancia: distancia em km entre as localidades de origem e destino.
    */  
    if (distancia < 0){
        throw std::invalid_argument("A distancia nao pode ser negativa!");
    }
    this->_tipo_modal = "ferroviario";
    this->_preco = 0.05;
    this->_capacidade = 70000;
    this->_velocidade = 20;
    this->_distancia = distancia;
    this->_flag = 1;
}
Ferroviario::~Ferroviario(){
    /** Destrutor da classe Modal
    */
}
//Metodos da classe Ferroviario
void Ferroviario::setPreco(float preco){
    /** Atribui o valor da variável preço.\n 
     *  Argumento:
     *      - preço: valor pago pelo tranporte, em R$;
     * .
     *  Exceção:
     *      - o valor não pode ser negativo;
    */    
    if (preco < 0 ){
        throw std::invalid_argument("O preco nao pode ser negativo.");
    }    
    this->_preco = preco;
}
void Ferroviario::setCapacidade(float capacidade){
    /** Atribui o valor da variável capacidade.\n
     *  Argumento:
     *      - capacidade: valor da capacidade transporte do modal, em toneladas;
     * .
     *  Exceção:
     *      - o valor não pode ser negativo;
    */     
    if (capacidade < 0 ){
        throw std::invalid_argument("A capacidade nao pode ser negativa.");
    }     
    this->_capacidade = capacidade;
}
void Ferroviario::setVelocidade(float velocidade){
    /** Atribui o valor da variável velocidade.\n
     *  Argumento:
     *      - velocidade: valor da velocidade do meio de transporte utilizado, em km/h;
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */    

    if (velocidade < 0 ){
        throw std::invalid_argument("A velocidade nao pode ser negativa.");
    }    
    this->_velocidade = velocidade;
}
void Ferroviario::setDistancia(int distancia){
    /** Atribui o valor da variável distancia.\n
     *  Argumento:
     *      - distancia: valor da distância entre as localidades de origem e destino da carga.
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */      
    if (distancia < 0 ){
        throw std::invalid_argument("A distancia nao pode ser negativa.");
    }    
    this->_distancia = distancia;    
    
}
std::string Ferroviario::getTipoModal(){
    /** Retorna o tipo de modal utilizado no transporte.\n
     *  Sem argumentos.
    */          
    return this->_tipo_modal;
}
float Ferroviario::getPreco(){
    /** Retorna o preço do serviço de transporte de carga.\n
     *  Sem argumentos.
    */      
    return this->_preco;
}
float Ferroviario::getCapacidade(){
    /** Retorna a capacidade do veículo de transporte de carga utilizado.\n
     *  Sem argumentos.
    */      
    return this->_capacidade;
}
float Ferroviario::getVelocidade(){
    /** Retorna a velocidade média do veículo de transporte de carga utilizado.\n
     *  Sem argumentos.
    */    
    return this->_velocidade;
}
int Ferroviario::getDistancia(){
    /** Retorna a distância entre duas localidades.\n
     *  Sem argumentos.
    */    
    return this->_distancia;
}
float Ferroviario::obterCusto(float quantidade){
    /** Retorna o custo da viagem entre as localidades de origem e destino da carga, a partir da quantidade de carga, em toneladas,,
     * capacidade do veículo de transporte do modal, distância entre as localidades de origem e destino
     *  e do preço do serviço.\n
     * Argumentos:
     *  - quantidade: valor da quantidade de carga a ser transportada.
     * .
     *  Exceção:
     *      - o valor não pode ser negativo; 
    */    
    return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco);
}

//Construtores da classe Rodoviario
Rodoviario::Rodoviario(): Rodoviario(0, 0, 0) {
    /** Construtor sem argumentos da classe Rodoviario\n
     *  Default:\n 
     *   - distância: 0 km; e 
     *   - pedagio: 0; e 
     *   - valor_pedágio: 0,00 R$.\n
     * .
     *  Exceção:
     *       - os valores não podem ser negativos;  
    */    
} 

Rodoviario::Rodoviario(int distancia, bool pedagio, float valor_pedagio){
    /**
     * Construtor da classe Rodoviario\n 
     *  Argumento: 
     *  - distancia: distancia em km entre as localidades de origem e destino;
     *  - pedagio: indicativo da existência de pedágio.
     *          - 1: existe pedágio;
     *          - 0: não existe pedágio. 
     *  - valor_pedágio: valor a ser pago do pedágio, em R$.\n 
    */ 
    if (distancia < 0 || valor_pedagio < 0){
        throw std::invalid_argument("As variaveis distancia e valor_pedagio e  nao podem ser negativas!");
    }
    if (pedagio != true && pedagio != false){
        throw std::invalid_argument("A variavel pedagio tem que ser true ou false.");
    }
    this->_tipo_modal = "rodoviario";
    this->_preco = 0.075;
    this->_capacidade = 35;
    this->_velocidade = 60;
    this->_distancia = distancia;
    this->_flag = 1;
    this->_pedagio = pedagio;
    this->_valor_pedagio = valor_pedagio;
}

Rodoviario::~Rodoviario(){
    /** Destrutor da classe Rodoviario
    */    
}

//Metodos da classe Rodoviario
void Rodoviario::setPedagio(int pedagio){
    /** Atribui o valor 1 ou 0 à variável pedagio.\n
     *  Argumento:
     *      - pedagio: indica se no trajeto do transporte há ou não pedágio na rodovia
     *          - 1: existe pedágio;
     *          - 0: não existe pedágio.
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */  

    if (pedagio != 1 && pedagio != 0){
        throw std::invalid_argument("A variavel pedagio deve ser true ou false.");
    }
    this->_pedagio = pedagio;
}
void Rodoviario::setValorPedagio(float valor_pedagio){
    /** Atribui o valor do pedágio da rodovia à variável valor_pedagio.\n
     *  Argumento:
     *      - valor_pedágio: valor a ser pago do pedágio, em R$.\n 
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */      
    if (valor_pedagio < 0){
        throw std::invalid_argument("O valor do pedagio nao pode ser negativo.");
    }
    this->_valor_pedagio = valor_pedagio;
}
int Rodoviario::isPedagio(){
    /** Retorna se existe ou não pedágio na rodovia.\n
     *  Sem argumentos.\n
     *  Retorno:
     *      - 1: existe pedágio;
     *      - 0: não existe pedágio.
    */     
    return this->_pedagio;
}
float Rodoviario::getValorPedagio(){
    /** Retorna o valor do pedágio a ser pago no transporte.\n
     *  Sem argumentos.
    */     
    return this->_valor_pedagio;
}
float Rodoviario::obterCusto(float quantidade){
    /** Retorna o custo da viagem entre as localidades de origem e destino da carga, a partir da quantidade de carga, em toneladas,,
     * capacidade do veículo de transporte do modal, distância entre as localidades de origem e destino
     *  e do preço do serviço.\n
     * Argumentos:
     *  - quantidade: valor da quantidade de carga a ser transportada. 
     * .
     *  Exceção:
     *       - os valores não podem ser negativos;  
    */    
    try {
        return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_pedagio);
    }catch (std::exception &e){
        std::cout << " A capacidade nao pode ser zero.\n";
    }
}

//Construtores da classe Aquaviario
Aquaviario::Aquaviario(): Aquaviario(0, 0){
   /** Construtor sem argumentos da classe Aquaviario\n 
     *  Default:\n 
     *   - distância: 0 km; e 
     *   - valor_terminal:0,00 R$.\n 
     * .
     *  Exceção:
     *       - os valores não podem ser negativos;     
    */       
}
 
Aquaviario::Aquaviario(int distancia, float valor_terminal) {
    /**
     * Construtor da classe Aquaviario\n 
     *  Argumento: 
     *  - distancia: distancia em km entre as localidades de origem e destino; e 
     *  - valor_terminal: valor da taxa de embarque da carga no terminal, em R$.\n 
     * .
     *  Exceção:
     *       - os valores não podem ser negativos;
    */  
    if (distancia < 0 || valor_terminal < 0){
        throw std::invalid_argument("A distancia e a taxa do terminal nao podem ser negativas.");
    }

    this->_tipo_modal = "aquaviario";
    this->_preco = aquaviario_preco;
    this->_capacidade = aquaviario_capacidade;
    this->_velocidade = aquaviario_velocidade;
    this->_distancia = distancia;
    this->_flag = 1;
    this->_valor_terminal = valor_terminal;

}

Aquaviario::~Aquaviario(){
    /** Destrutor da classe Aquaviario
    */    
}

//Metodos da classe Aquaviario
void Aquaviario::setValorTerminal(float valor_terminal){
    /** Atribui o valor da variável valor_terminal.\n
     *  Argumento:
     *      - valor_terminal: valor da taxa de embarque da carga no terminal, em R$.\n 
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */      
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor da taxa do terminal nao pode ser negativo!");
    }    
    this->_valor_terminal = valor_terminal;
}
float Aquaviario::getValorTerminal(){
    /** Retorna ao valor da taxa de embarque da carga no terminal, em R$.\n
     *  Sem argumentos.
    */      
    return this->_valor_terminal;
}
float Aquaviario::obterCusto(float quantidade){
    /** Retorna o custo da viagem entre as localidades de origem e destino da carga, a partir da quantidade de carga, em toneladas,,
     * capacidade do veículo de transporte do modal, distância entre as localidades de origem e destino
     *  e do preço do serviço.\n
     * Argumentos:
     *  - quantidade: valor da quantidade de carga a ser transportada. 
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;     
    */    
    return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_terminal);
}

/* Construtores da classe Aereo*/

Aereo::Aereo(): Aereo(0, 0){
    /** Default:\n 
     *   - distância: 0 km; e 
     *   - valor_terminal:0,00 R$.\n 
    */      
}

/** Construtor da classe Aereo*/
Aereo::Aereo(int distancia, float valor_terminal){
    /** Argumentos: 
     *  - distancia: distancia em km entre as localidades de origem e destino; e 
     *  - valor_terminal: valor da taxa de embarque da carga no terminal, em R$.\n 
    */  
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor da taxa do terminal nao pode ser negativo.");
    }
    this->_tipo_modal = "aereo";
    this->_preco = aereo_preco;
    this->_capacidade = aereo_capacidade;
    this->_velocidade = aereo_velocidade;
    this->_distancia = distancia;
    this->_flag = 1;
    this->_valor_terminal = valor_terminal;
}

Aereo::~Aereo(){
    /** Destrutor da classe Aereo\n 
    */    
}

//Metodos da classe Aereo
void Aereo::setValorTerminal(float valor_terminal){
    /** Atribui o valor da variável valor_terminal.\n
     *  Argumento:
     *      - valor_terminal: valor da taxa de embarque da carga no terminal, em R$.\n 
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */     
    if (valor_terminal < 0){
        throw std::invalid_argument("O valor do terminal nao pode ser negativo.");
    }    
    this->_valor_terminal = valor_terminal;
}
float Aereo::getValorTerminal(){
    /** Retorna ao valor da taxa de embarque da carga no terminal, em R$.\n
     *  Sem argumentos.
    */      
    return this->_valor_terminal;
}
float Aereo::obterCusto(float quantidade){
    /** Retorna o custo da viagem entre as localidades de origem e destino da carga, a partir da quantidade de carga, em toneladas,,
     * capacidade do veículo de transporte do modal, distância entre as localidades de origem e destino
     *  e do preço do serviço.\n
     * Argumentos:
     *  - quantidade: valor da quantidade de carga a ser transportada.
     * .
     *  Exceção:
     *       - o valor não pode ser negativo;
    */ 
    return ceil(quantidade / this->_capacidade) * (this->_distancia * this->_preco + this->_valor_terminal);
}