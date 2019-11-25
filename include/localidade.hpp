#ifndef LOCALIDADE_HPP
#define LOCALIDADE_HPP
#include <iostream>
/**
 * A classe Localidade representa uma localidade que possui as seguintes propriedades:
 * 1) Código do município;
 * 2) Município;
 * 3) Latitude;
 * 4) Longitude;
 * 5) Estado;
 * 6) País;
*/

class Localidade {
    private:
        /** código do município */
        int _codigo_municipio;
        /** nome do município */
        std::string _municipio;
        /** latitude do município */
        float _lat;
        /** longitude do município */
        float _long;
        /** estado do município */
    	std::string _estado;
        /** pais do município */
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
