#include <iostream>
#include <fstream>
#include <sstream>

void lerLocalidades(std::istream &localidades){}

void lerArestas(std::istream &arestas){
    std::string linha;   
    std::string entrada;
    arestas.clear();
    arestas.seekg(0, std::ios::beg);
    while(!arestas.eof()){
        getline(arestas, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            int valor = std::stoi(entrada);
            // if (num_entradas == 0){
            //     gasto_max = valor;
            //     // gasto_max = valor/100;
            // }else if(num_entradas == 1){
            //     total_ilhas = valor;
            // }else{
            //     if(num_entradas % 2 == 0){
            //         custo = valor;
            //         // custo = valor/100;
            //     }else{
            //         pontos = valor;
            //         matriz_entrada.push_back({custo, pontos});
            //     }
            // }
            // num_entradas++;
        }
    } 
}