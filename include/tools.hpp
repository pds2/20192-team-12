#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "modal.hpp"
#include "localidade.hpp"
/**
 * A classe Screen manuseia eventos para exibição na tela do terminal 
*/

class Screen{	
	private:
		/** tamanho da barra na tela*/
		unsigned int _bar_size = 100;
		/** vetor para armazenar as localidades*/
		std::vector <Localidade> _vector; // novo vetor
		/** padding para formatar a saída*/
		unsigned int _padding = 20;
		/** número de colunas entre as localidades*/
		unsigned int _columns = 4;
		/** espaços para centralizar o título na barra*/
		unsigned int _spaces = 100;
	public:
		Screen(std::vector <Localidade> &);
		~Screen();
		void setPadding(unsigned int);

		void showMainMenu(Screen*);
		void showEntradaDados(float&, int&, int&, int&, int);
		void showSolicitacao(int, int, float, std::vector <Localidade>);
		void showSubMenu();
		void showBar(std::string);
		void showVector(int);
		void showTitle(std::string, std::string);
		void showWarning(std::string);
		
};

Localidade searchMunicipio(int, std::vector  <Localidade>& );
void lerArquivoLocalidades(std::istream &, std::vector <Localidade> &);
void menu(std::vector <std::string>&);
#endif
