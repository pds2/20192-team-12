#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void lerArquivo(std::istream &arquivo, std::vector <std::string> &vector);
void lerArestas(std::istream &arestas);
void lerLocalidades(std::istream &localidades);
#endif