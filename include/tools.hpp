#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../include/modal.hpp"

class Tipo{
	public:
		Tipo(){}
		~Tipo(){}
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
class Screen{
	private:
		unsigned int _bar_size = 100;
		std::vector <std::string> _vector;
	public:
		Screen(std::vector <std::string> &);
		~Screen();
		void setBarSize(unsigned int);
		void setVector(std::vector <std::string> &);
		void showMenu();
		void showBar(std::string);
		void showVector(int, int);
		void showTitle(std::string, unsigned int, std::string);
		void showWarning(std::string);
		
};
void lerArquivo(std::istream &, std::vector <std::string> &);
void menu(std::vector <std::string>&);
#endif
