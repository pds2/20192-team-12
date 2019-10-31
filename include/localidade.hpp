#ifndef LOCALIDADE_H
#define LOCALIDADE_H
#include <iostream>
/*
Esta classe representa uma localidade que possui as seguintes propriedades:
1) Código do município;
2) Município;
3) Latitude;
4) Longitude;
5) Estado;
6) País;
*/

class Localidade {
    private: 
        std::string _codigo_municipio;
        std::string _municipio;
        float _lat;
        float _long;
    	std::string _estado;
        std::string _pais;
    	
    public:

    	Localidade():Localidade("2", "BELO HORIZONTE", -19.891053, -43.951401, "MG", "BRASIL"){}
    	Localidade(std::string codigo_municipio,
                   std::string municipio,
                   float lat,
                   float lng,
                   std::string estado,
                   std::string pais): _codigo_municipio(codigo_municipio),
                                      _municipio(municipio),
                                      _lat(lat),
                                      _long(lng),
                                      _estado(estado),
                                      _pais(pais){}
    	~Localidade();

    	void setCodigoMunicipio(std::string);
        void setMunicipio(std::string);
        void setLat(float);
        void setLong(float);
        void setEstado(std::string);
        void setPais(std::string);

    	std::string getCodigoMunicipio();
        std::string getMunicipio();
        float getLat();
        float getLong();
        std::string getEstado();
        std::string getPais();
};

#endif
