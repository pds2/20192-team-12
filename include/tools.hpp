#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
class Type{
	public:
		std::string get_type(std::string);
		std::string get_type(int);
		std::string get_type(float);
		std::string get_type(double);
		std::string get_type(std::istream);
};
void lerArquivo(std::istream &arquivo, std::vector <std::string> &vector);
#endif
