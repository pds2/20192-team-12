#include <iostream>
#include "localidade.hpp"

void Localidade::setCodigoMunicipio(std::string codigo_municipio){
    this->_codigo_municipio = codigo_municipio; 
}
void Localidade::setMunicipio(std::string municipio){
    this->_municipio = municipio;    
}
void Localidade::setLat(float lat){
    this->_lat = lat;
}
void Localidade::setLong(float lng){
    this->_long = lng;
}

void Localidade::setEstado(std::string estado){
    this->_estado = estado;
}
void Localidade::setPais(std::string pais){
    this->_pais = pais;   
}

std::string Localidade::getCodigoMunicipio(){
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