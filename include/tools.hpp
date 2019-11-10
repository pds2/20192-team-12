#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "modal.hpp"
#include "localidade.hpp"

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
		std::vector <Localidade> _vector; // novo vetor
		unsigned int _padding = 20;
		unsigned int _columns = 4;
		unsigned int _spaces = 100;
		// std::vector <std::string> _vector; // antigo vetor
	public:
		Screen(std::vector <Localidade> &);
		~Screen();
		void setPadding(unsigned int);
		void setColumns(unsigned int);
		void setSpaces(unsigned int);
		
		unsigned int getPadding();
		unsigned int getColumns();
		unsigned int getSpaces();

		void setBarSize(unsigned int);
		void setVector(std::vector <Localidade> &);
		void showMainMenu(Screen*);
		// void showContinueMenu(Screen*);
		void showSubMenu();
		void showBar(std::string);
		void showVector(int);
		// void showTitle(std::string, unsigned int, std::string);
		void showTitle(std::string, std::string);
		void showWarning(std::string);
		
};

Localidade searchMunicipio(int, std::vector  <Localidade>& );
void lerArquivo(std::istream &, std::vector <std::string> &);
void lerLocalidades(std::istream &, std::vector <Localidade> &);
void menu(std::vector <std::string>&);
// class Screen{
// 	private:
// 		unsigned int _bar_size = 100;
// 		std::vector <std::string> _vector;
// 	public:
// 		Screen(std::vector <std::string> &);
// 		~Screen();
// 		void setBarSize(unsigned int);
// 		void setVector(std::vector <std::string> &);
// 		void showMainMenu(Screen*);
// 		void showContinueMenu(Screen*);
// 		void showSubMenu();
// 		void showBar(std::string);
// 		void showVector(int, int);
// 		void showTitle(std::string, unsigned int, std::string);
// 		void showWarning(std::string);
		
// };
#endif
