#include <iostream>
#include "../include/operador.hpp"
#include <stdexcept>
#include <cmath>
#include <limits.h>
#include <stdio.h> 
#include <iostream>
#include <fstream>

/*
O algoritmo Dijsktra's single source shortest path algorithm está disponível em:
<https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/>

E foi parcialmente alterado para responder às necessidades do 
Sistema de Alocação de Transporte.

O algoritmo para impressão do caminho mínimo está disponível em:
<https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/>
*/


//Contrutores da classe Operador
Operador::Operador() {}

Operador::Operador(int V){
    if (V <= 0){
        throw std::invalid_argument("Matriz deve ter numero de vertices positivo!");
    }

    this->_graph = new Modal*[V];
    for(int i = 0; i < V; i++){ 
        this->_graph[i] = new Modal[V]; 
    }
}

Operador::~Operador(){
    for (int i = 0; i < _V; ++i)
        delete [] this->_graph[i];
    delete [] this->_graph;
}

//Metodos da classe Operador
void Operador::popularMatriz() {

    std::ifstream infile("../data/arestas.txt");

    int row, col;
    std::string tipo_modal;
    float preco;
    float capacidade;
    float velocidade;
    bool pedagio;
    float valor_pedagio;
    float valor_terminal;
    int distancia;

    while(infile >> row >> col) {
        infile >> tipo_modal;
        infile >> preco;
        infile >> capacidade;
        infile >> velocidade;
        infile >> pedagio;
        infile >> valor_pedagio;
        infile >> valor_terminal;
        infile >> distancia;

        if(tipo_modal == "ferroviario") {
            this->_graph[row][col] = Ferroviario(distancia);
        }else{
            if(tipo_modal == "rodoviario") {
                this->_graph[row][col] = Rodoviario(distancia, pedagio, valor_pedagio);
            }else{
                if(tipo_modal == "aereo") {
                    this->_graph[row][col] = Aereo(distancia, valor_terminal);
                }else{
                    this->_graph[row][col] = Aquaviario(distancia, valor_terminal);    
                }
            }
        }
    }
}


// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int Operador::minDistance(int *dist, bool *sptSet) { 
    // Initialize min value 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < this->_V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 

    return min_index; 
} 

// A utility function to print the constructed distance array 
void Operador::printSolution(int *dist)  { 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < this->_V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

// Function to print shortest path from source to j using parent array 
void Operador::printPath(int *parent, int j) { 
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    Operador::printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 
  
// A utility function to print the constructed distance array 
void Operador::printSolutionPath(int *dist, int *parent, int src) { 
    printf("Vertex\t Distance\tPath"); 
    for (int i = 1; i < this->_V; i++) { 
        printf("\n%d -> %d \t\t %d\t\t%d ", 
                      src, i, dist[i], src); 
        printPath(parent, i); 
    } 
    printf("\n");
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void Operador::dijkstra(int src, int dest, float quantidade) { 
    int *dist = new int[this->_V]; // The output array. dist[i] will hold the shortest 
    // distance from src to i 

    bool *sptSet = new bool[this->_V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 

    // Parent array to store shortest path tree 
    int *parent = new int[this->_V]; 

    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < this->_V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 

    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 

    // Parent of root (or source vertex) is -1. 
    parent[src] = -1; 

    // Find shortest path for all vertices 
    for (int count = 0; count < this->_V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = Operador::minDistance(dist, sptSet); 

        // Mark the picked vertex as processed 
        sptSet[u] = true; 

        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < this->_V; v++) 

            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && _graph[u][v].getDistancia() && dist[u] != INT_MAX 
                && dist[u] + _graph[u][v].getDistancia() < dist[v]) {
                dist[v] = dist[u] + _graph[u][v].getDistancia();     
                parent[v] = u;
            }
    } 

    // print the constructed distance array 
    Operador::printSolution(dist); 
    Operador::printSolutionPath(dist, parent, src); 

    delete[] dist;
    delete[] sptSet;
    delete[] parent;
} 

void Operador::addSolicitacao(int src, int dest, float quantidade) {
    this->_lista_solicitacao.push_back(src, dest, quantidade);
}