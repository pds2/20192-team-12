#include <iostream>
#include "localidade.hpp"

//Construtores da classe Localidades
Localidade::Localidade():Localidade(2, "BELO HORIZONTE", -19.891053, -43.951401, "MG", "BRASIL"){}
Localidade::Localidade(int codigo_municipio,
                       std::string municipio,
                       float lat, float lng,
                       std::string estado,
                       std::string pais){
    
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

Localidade::~Localidade(){}

//Metodos da classe Localidades
void Localidade::setCodigoMunicipio(int codigo_municipio){
    if (codigo_municipio < 0){
        throw std::invalid_argument("O codigo do municipio nao pode ser negativo.");
    }    
    this->_codigo_municipio = codigo_municipio; 
}
void Localidade::setMunicipio(std::string municipio){
    if (municipio.size() == 0){
        throw std::invalid_argument("O nome do municipio nao pode ser vazio.");
    }    
    this->_municipio = municipio;    
}
void Localidade::setLat(float lat){
    this->_lat = lat;
}
void Localidade::setLong(float lng){
    this->_long = lng;
}

void Localidade::setEstado(std::string estado){
    if (estado.size() == 0){
        throw std::invalid_argument("O nome do estado nao pode ser vazio.");
    }    
    this->_estado = estado;
}
void Localidade::setPais(std::string pais){
    if (pais.size() == 0){
        throw std::invalid_argument("O nome do pais nao pode ser vazio.");
    }    
    this->_pais = pais;   
}

int Localidade::getCodigoMunicipio(){
    return this->_codigo_municipio;
}
std::string Localidade::getMunicipio(){
    return this->_municipio;

}

float Localidade::getLat(){
    return this->_lat;
}
float Localidade::getLong(){
    return this->_long;

}
std::string Localidade::getEstado(){
    return this->_estado;

}
std::string Localidade::getPais(){
    return this->_pais;
}