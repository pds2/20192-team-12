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
		unsigned int _bar_size = 100; // tamanho da barra em numero de caracteres
		std::vector <Localidade> _vector; // vetor de localidades
		unsigned int _padding = 20; // espaco entre as colunas
		unsigned int _columns = 4; // numero de colunas na tela
		unsigned int _spaces = 100; // numero de espacos para centralizacao

		// EXCLUIR
		// std::vector <std::string> _vector; // antigo vetor
	public:
		// Construtor e destrutor da classe
		Screen(std::vector <Localidade> &);
		~Screen();
		// Metodos publicos da classe
		void setPadding(unsigned int);

		void showMainMenu(Screen*);
		void showEntradaDados(float&, int&, int&, int&, int);
		void showSolicitacao(int, int, float, std::vector <Localidade>);
		void showSubMenu();
		void showBar(std::string);
		void showVector(int);
		void showTitle(std::string, std::string);
		void showWarning(std::string);
		// void lerLocalidades(std::istream &, std::vector  <Localidade> &);

		// EXCLUIR
		// void showContinueMenu(Screen*);
		// std::string formattString(std::string);
		// void setColumns(unsigned int);
		// void setSpaces(unsigned int);
		
		// unsigned int getPadding();
		// unsigned int getColumns();
		// unsigned int getSpaces();

		// void setBarSize(unsigned int);
		// void setVector(std::vector <Localidade> &);
		
};

Localidade searchMunicipio(int, std::vector  <Localidade>&); // funcao para encontrar o nome do municipio dado o codigo
// void lerArquivo(std::istream &, std::vector <std::string> &);
void lerArquivoLocalidades(std::istream &, std::vector <Localidade> &);// funcao para ler o arquivo de localidades
// void menu(std::vector <std::string>&);


// EXCLUIR

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
// class Tipo{
// 	/**
// 	 * Esta classe obtem os tipos das variavesi. 
// 	*/	
// 	public:
// 		Tipo(){}
// 		~Tipo(){}
// 		std::string getTipo(std::string); // retorna para variaveis do tipo string
// 		std::string getTipo(int); // retorna para variaveis do tipo int
// 		std::string getTipo(float); // retorna para variaveis do tipo float
// 		std::string getTipo(double); // retorna para variaveis do tipo double
// 		std::string getTipo(bool); // retorna para variaveis do tipo bool
// 		std::string getTipo(std::istream); // retorna para variaveis do tipo std::istream
// 		std::string getTipo(std::ifstream); // retorna para variaveis do tipo std::ifstream
// 		std::string getTipo(Ferroviario); // retorna para variaveis do tipo Ferroviario
// 		std::string getTipo(Rodoviario); // retorna para variaveis do tipo Rodoviario
// 		std::string getTipo(Aquaviario); // retorna para variaveis do tipo Aquaviario
// 		std::string getTipo(Aereo); // retorna para variaveis do tipo Aereo
// };
#endif
