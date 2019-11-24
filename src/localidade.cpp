#include <iostream>
#include "localidade.hpp"

//Construtores da classe Localidades
Localidade::Localidade():Localidade(2, "BELO HORIZONTE", -19.891053, -43.951401, "MG", "BRASIL"){
    /** Construtor sem argumentos da classe Localidade 
    */   
    
}
Localidade::Localidade(int codigo_municipio,
                       std::string municipio,
                       float lat, float lng,
                       std::string estado,
                       std::string pais){
    /**
     * Construtor da classe Modal\n
     * Argumentos:
     *   - codigo_municipio: código do município
     *   - municipio: nome do município
     *   - lat: latitude do município
     *   - lng: longitude do município
     *   - estado: estado do município
     *   - pais: país do município
     * Exceções:
     *  - codigo_municipio: não pode ser negativo
     *  - municipio, estado e pais não podem ter comprimento igual a zero
     */
    
    if (codigo_municipio < 0){
        throw std::invalid_argument("O codigo do municipio nao pode ser negativo.");
    }
    if (municipio.size() == 0 || estado.size() == 0 || pais.size() == 0){
        throw std::invalid_argument("O nome do municipio, estado ou pais nao pode ser vazio.");
    }
    this->_codigo_municipio = codigo_municipio;
    this->_municipio = municipio;
    this->_lat = lat;
    this->_long = lng;
    this->_estado = estado;
    this->_pais = pais;
}

Localidade::~Localidade(){
    /** Destrutor da classe Localidade
    */    
}

//Metodos da classe Localidades
void Localidade::setCodigoMunicipio(int codigo_municipio){
    /** Atribui o valor da variável codigo_municipio.\n
     *  Argumento:
     *      - codigo_municipio: código do município;
     * .
     *  Exceção:
     *      - o valor não pode ser negativo;
    */     
    if (codigo_municipio < 0){
        throw std::invalid_argument("O codigo do municipio nao pode ser negativo.");
    }    
    this->_codigo_municipio = codigo_municipio; 
}
void Localidade::setMunicipio(std::string municipio){
    /** Atribui o valor no nome do município.\n
     *  Argumento:
     *      - municipio: nome do município;
     * .
     *  Exceção:
     *      - o comprimento da string naõ pode ser zero;
    */    
    if (municipio.size() == 0){
        throw std::invalid_argument("O nome do municipio nao pode ser vazio.");
    }    
    this->_municipio = municipio;    
}
void Localidade::setLat(float lat){
    /** Atribui o valor da variável lat.\n
     *  Argumento:
     *      - lat: latitude do município;
    */         
    this->_lat = lat;
}
void Localidade::setLong(float lng){
    /** Atribui o valor da variável lng.\n
     *  Argumento:
     *      - lng: longitude do município;
    */      
    this->_long = lng;
}

void Localidade::setEstado(std::string estado){
    /** Atribui o valor no nome do estado.\n
     *  Argumento:
     *      - estado: nome do estado;
     * .
     *  Exceção:
     *      - o comprimento da string naõ pode ser zero;
    */       
    if (estado.size() == 0){
        throw std::invalid_argument("O nome do estado nao pode ser vazio.");
    }    
    this->_estado = estado;
}
void Localidade::setPais(std::string pais){
    /** Atribui o valor no nome do pais.\n
     *  Argumento:
     *      - pais: nome do pais;
     * .
     *  Exceção:
     *      - o comprimento da string naõ pode ser zero;
    */     
    if (pais.size() == 0){
        throw std::invalid_argument("O nome do pais nao pode ser vazio.");
    }    
    this->_pais = pais;
}

int Localidade::getCodigoMunicipio(){
    /** Retorna o código do município.\n
     *  Sem argumentos.
    */    
    return this->_codigo_municipio;
}
std::string Localidade::getMunicipio(){
    /** Retorna o nome do município.\n
     *  Sem argumentos.
    */      
    return this->_municipio;

}

float Localidade::getLat(){
    /** Retorna a latitude do município.\n
     *  Sem argumentos.
    */      
    return this->_lat;
}
float Localidade::getLong(){
    /** Retorna a longitude do município.\n
     *  Sem argumentos.
    */       
    return this->_long;

}
std::string Localidade::getEstado(){
    /** Retorna o nome do estado.\n
     *  Sem argumentos.
    */      
    return this->_estado;

}
std::string Localidade::getPais(){
    /** Retorna o nome do país.\n
     *  Sem argumentos.
    */      
    return this->_pais;
}