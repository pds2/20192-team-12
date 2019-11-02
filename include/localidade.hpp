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
        int _codigo_municipio;
        std::string _municipio;
        float _lat;
        float _long;
    	std::string _estado;
        std::string _pais;
    	
    public:

    	Localidade();
    	Localidade(int, std::string, float, float, std::string, std::string);
    	~Localidade();

        void setCodigoMunicipio(int);
        void setMunicipio(std::string);
        void setLat(float);
        void setLong(float);
        void setEstado(std::string);
        void setPais(std::string);

    	int getCodigoMunicipio();
        std::string getMunicipio();
        float getLat();
        float getLong();
        std::string getEstado();
        std::string getPais();
};

#endif
