
#include <iostream>
#include "../include/operador.hpp"
#include <stdexcept>
#include <cmath>

//Contrutores da classe Operador
Operador::Operador() {}

Operador::Operador(int V){
    if (V <= 0){
        throw std::invalid_argument("Matriz deve ter numero de vertices positivo!");
    }

    this->graph = new Modal*[V];
    for(int i = 0; i < V; i++){ 
        this->graph[i] = new Modal[V]; 
    }
}

Operador::~Operador(){
    for (int i = 0; i < V; ++i)
        delete [] this->graph[i];
    delete [] this->graph;
}

//Metodos da classe Operador
void Operador::obterRota(int src, int dest, float quantidade) {}