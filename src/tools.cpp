#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "../include/tools.hpp"
std::string Type::get_type(std::string){
    return "std::string";
}
std::string Type::get_type(int){
    return "int";
}
std::string Type::get_type(float){
    return "float";
}
std::string Type::get_type(double){
    return "double";
}
std::string Type::get_type(std::ifstream){
    return "istream_file";
}
void lerArquivo(std::istream &arquivo, std::vector <std::string> &vector){
    std::string linha;   
    std::string entrada;
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);
    int counter = 0;
    int rows, columns;
    while(!arquivo.eof()){
        getline(arquivo, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            // std::cout << entrada.substr(0,1)<< " " << entrada << " ";
            if (counter == 0){
                rows = std::stoi(entrada);
            }
            if (counter == 1){
                columns = std::stoi(entrada);
                std::cout << std::endl;
            }
            if (counter != 0 && counter != 1){
                std::string str;
                if (entrada.substr(0,1) == "|"){
                    str = "";
                    int espacos = 0;
                    while (entrada.substr(entrada.size() - 1, 1) != "|"){
                        str = str + entrada + " ";
                        espacos++;
                        iss_linha >> entrada;
                    }
                    str = str + entrada;
                    str = str.substr(1, str.size() - 2);
                    // std::cout << str << std::endl;

                    entrada = str;
                    if ((counter - 2) % columns == 1) {
                            vector.push_back(entrada);
                    }
                }
                // if (entrada.substr(entrada.size() - 1, 1) == "|"){
                // std::cout << " " << entrada;

                // }                
                if( (counter - 2) % columns == (columns - 1)){
                    // std::cout << std::endl;
                }
            }            
            counter++;
        }

    }    
}
    
