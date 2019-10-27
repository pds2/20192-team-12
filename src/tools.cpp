#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/tools.hpp"

void lerArquivo(std::istream &arquivo){
    std::string linha;   
    std::string entrada;
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);
    while(!arquivo.eof()){
        getline(arquivo, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            std::cout << entrada << std::endl;
        }
    }    
}

void lerLocalidades(std::istream &localidades){
    std::string linha;   
    std::string entrada;
    localidades.clear();
    localidades.seekg(0, std::ios::beg);
    while(!localidades.eof()){
        getline(localidades, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            std::cout << entrada << std::endl;
        }
    }     
}

void lerArestas(std::istream &arestas){
    std::string linha;   
    std::string entrada;
    arestas.clear();
    arestas.seekg(0, std::ios::beg);
    while(!arestas.eof()){
        getline(arestas, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            std::cout << entrada << std::endl;
        }
    } 
}