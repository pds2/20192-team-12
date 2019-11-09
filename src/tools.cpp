#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cctype>
#include <vector>
#include "tools.hpp"
#include "modal.hpp"
#include "solicitacao.hpp"

std::string Tipo::getTipo(std::string){
    return "string";
}
std::string Tipo::getTipo(int){
    return "int";
}
std::string Tipo::getTipo(float){
    return "float";
}
std::string Tipo::getTipo(double){
    return "double";
}
std::string Tipo::getTipo(std::ifstream){
    return "ifstream";
}
std::string Tipo::getTipo(std::istream){
    return "istream";
}
std::string getTipo(Ferroviario){
    return "ferroviario";
}
std::string getTipo(Rodoviario){
    return "rodoviario";
}
std::string getTipo(Aquaviario){
    return "aquaviario";
}
std::string getTipo(Aereo){
    return "aereo";
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
    
void menu(std::vector <std::string> vec_local){
    int origem, // localidade de origem
        destino; // localidade de destino
    float quantidade; // quantidade a ser transportada
    int padding = 20;
    int columns = 4;
    Tipo tipo;
    std::system("clear");
    std::cout << "\n*******************************************************************************************\n";
    std::cout << "                     SISTEMA DE ALOCACAO DE DEMANDA POR TRANSPORTES\n";
    std::cout << "*******************************************************************************************\n\n\n";    
    std::cout << "Para gerar uma solicitacao, execute os seguintes passos:\n\n";
    std::cout << "1. Digite o numero da localidade de origem;\n";
    std::cout << "2. Digite o numero da localidade de destino e a quantidade ser transportada;\n";
    std::cout << "3. Digite a quantidade de carga a ser transportada; e\n";
    std::cout << "4. Tecle ENTER.\n\n";
    std::cout << "LOCALIDADES:\n\n";

    for (int i = 0; i < vec_local.size(); i++){
        std::cout << std::setw(2) << std::right << i << " - " << std::setw(padding) << std::left << vec_local[i];
        if((i + 1) % columns == 0){
            std::cout << std::endl;
        }
        // else{
        //     std::cout << std::setw(2) << std::right << i << " - " << std::setw(25) << std::left << vec_local[i];
        // }
    }
    std::cout << std::endl;
    /*
    ENTRADA DE DADOS
    */
    std::cout << "\n*******************************************************************************************\n";
    std::cout << "                                 ENTRADA DOS DADOS DA SOLICITACAO\n";
    std::cout << "*******************************************************************************************\n";   
    quantidade = -1;
    std::cout << "1. Digite a quantidade da carga em toneladas: ";
    while (quantidade < 1){
        char c ;
        if ( !( std::cin >> quantidade) || ( std::cin.get(c) && !std::isspace(c))){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ATENCAO! A quantidade deve ser um valor numerico.\n";
            std::cout << "1. Digite novamente a quantidade da carga em toneladas: ";
            quantidade = -1;
        }else if(quantidade < 1){
            std::cout << "ATENCAO! A quantidade deve ser um valor positivo.\n";
            std::cout << "1. Digite novamente a quantidade da carga em toneladas: ";            
        }
    }
    origem = -1;
    std::cout << "\n-------------------------------------------------------------------------------------------\n";    
    std::cout << "2. Digite o codigo da localidade de origem da carga: ";    
    while (origem < 1 || origem >= vec_local.size()){
        char c ;
        if ( !( std::cin >> origem) || ( std::cin.get(c) && !std::isspace(c))){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ATENCAO! O codigo da localidade de origem deve ser um valor numerico.\n";
            std::cout << "2. Digite novamente o codigo da origem: ";
            origem = -1;
        }else if(origem < 1 || (origem >= vec_local.size())){
            std::cout << "ATENCAO! O codigo da localidade de origem deve ser um valor positivo, menor que " + 
                            std::to_string(vec_local.size()) + ".\n";
            std::cout << "2. Digite novamente o codigo da origem: ";            
        }
    } 
    destino = -1;
    std::cout << "\n-------------------------------------------------------------------------------------------\n";    
    std::cout << "3. Digite o codigo da localidade de destino da carga: ";    
    while (destino < 1 || destino >= vec_local.size()){
        char c ;
        if ( !( std::cin >> destino) || ( std::cin.get(c) && !std::isspace(c))){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ATENCAO! O codigo da localidade de destino deve ser um valor numerico.\n";
            std::cout << "3. Digite novamente o codigo da destino: ";
            destino = -1;
        }else if(destino < 1 || (destino >= vec_local.size())){
            std::cout << "ATENCAO! O codigo da localidade de destino deve ser um valor positivo, menor que " + 
                            std::to_string(vec_local.size()) + ".\n";
            std::cout << "3. Digite novamente o codigo da destino: ";            
        }
    } 
    std::cout << "\n*******************************************************************************************\n";
    std::cout << "                                 DADOS DA SOLICITACAO\n";
    std::cout << "*******************************************************************************************\n";
    std::cout << "Origem: " << origem << "\nDestino: " << destino  << "\nQuantidade (toneladas): " << quantidade <<  std::endl;
    std::cout << "\n*******************************************************************************************\n";
    std::cout << "                                 RESULTADO DA SOLICITACAO\n";
    std::cout << "*******************************************************************************************\n";
    std::cout << "Rota 1: localidade1 -> localidade2 -> localidade3 - preco1 - tempo1" << std::endl;   
    std::cout << "Rota 2: localidade1 -> localidade4 -> localidade3 - preco2 - tempo2" << std::endl;
    Solicitacao s(origem, destino, quantidade);    
}