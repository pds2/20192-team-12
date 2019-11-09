
#include <iostream>
#include "../include/operador.hpp"
#include <stdexcept>
#include <cmath>
#include <limits.h>
#include <stdio.h> 
#include <iostream>
#include <fstream>

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
    for (int i = 0; i < V; ++i)
        delete [] this->_graph[i];
    delete [] this->_graph;
}

//Metodos da classe Operador
void Operador::popularMatriz() {

    std::ifstream infile("../data/arestas.txt");

    int row, col;
    while(infile >> row >> col) {
        infile >> tipo_modal;
        infile >> preco;
        infile >> capacidade;
        infile >> velocidade;
        infile >> pedagio;
        infile >> valor_pedagio;
        infile >> valor_terminal;
        infile >> distancia;

        switch(tipo_modal) {
            case_when(tipo_modal == "rodoviario"):
                this->_graph[row][col] = Rodoviario::Rodoviario(tipo_modal, preco, capacidade, velocidade, distancia, pedagio, valor_pedagio);
            
            case_when(tipo_modal == "aereo"):
                this->_graph[row][col] = Aereo::Aereo(tipo_modal, preco, capacidade, velocidade, distancia, valor_terminal);
            
            case_when(tipo_modal == "aquaviario"):
                this->_graph[row][col] = Aquaviario::Aquaviario(tipo_modal, preco, capacidade, velocidade, distancia, pedagio, valor_pedagio);
        }   
    }
}


// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int Operador::minDistance(int dist[], bool sptSet[]) { 
    // Initialize min value 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < this->_V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 

    return min_index; 
} 

// A utility function to print the constructed distance array 
int Operador::printSolution(int dist[])  { 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < this->_V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

// Function to print shortest path from source to j using parent array 
void Operador::printPath(int parent[], int j) { 
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    Operador::printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 
  
// A utility function to print the constructed distance array 
int Operador::printSolutionPath(int dist[], int parent[], int src) { 
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
    int dist = new int[this->_V]; // The output array. dist[i] will hold the shortest 
    // distance from src to i 

    bool sptSet = new bool[this->_V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 

    // Parent array to store shortest path tree 
    int parent = new int[this->_V]; 

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
            if (!sptSet[v] && graph[u][v]._distancia && dist[u] != INT_MAX 
                && dist[u] + graph[u][v]._distancia < dist[v]) {
                dist[v] = dist[u] + graph[u][v]._distancia;     
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

void Operador::obterRota(int src, int dest, float quantidade) {
    Operador::dijkstra(src, dest, quantidade);
}