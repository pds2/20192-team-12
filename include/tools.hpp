#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/modal.hpp"

class Tipo{
	public:
		std::string getTipo(std::string);
		std::string getTipo(int);
		std::string getTipo(float);
		std::string getTipo(double);
		std::string getTipo(std::istream);
		std::string getTipo(std::ifstream);
		std::string getTipo(Ferroviario);
		std::string getTipo(Rodoviario);
		std::string getTipo(Aquaviario);
		std::string getTipo(Aereo);
};
void lerArquivo(std::istream &arquivo, std::vector <std::string> &vector);
#endif
