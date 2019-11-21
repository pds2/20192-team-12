#include <iostream>
#include "../include/operador.hpp"
#include <stdexcept>
#include <cmath>
#include <limits.h>
#include <stdio.h> 
#include <fstream>
#include <sstream>
#include <string>
// #include <iomanip>
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
    std::cout << "POPULAR MATRIZ\n"; 
    std::ifstream infile("../data/arestas.txt");
    std::string linha; 
    // int row, col; // substituido pelo codigo de origem e destino
    std::string tipo_modal;
    float preco;
    float capacidade;
    float velocidade;
    int pedagio;
    float valor_pedagio;
    float valor_terminal;
    int distancia;
    int counter = 0;
    int origem;
    int destino;
    int rows = 0; // total de arestas
    int columns = 0; // total de colunas por aresta
    int column = 0; // coluna especifica
    while(!infile.eof()){
        
        getline(infile, linha);
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
                // std::string str;

                column = (counter - 2) % columns;
                std::cout << "column: " << column << " " << entrada << "\n";
                switch (column){
                    case 0:
                        origem = std::stoi(entrada);
                    case 1:
                        destino =  std::stoi(entrada);
                    case 2:
                        tipo_modal = entrada;
                    case 3:
                        preco = std::stof(entrada);
                    case 4:
                        capacidade = std::stof(entrada);
                    case 5:
                        velocidade = std::stof(entrada);
                    case 6:
                        pedagio = std::stoi(entrada);
                    case 7:
                        valor_pedagio = std::stof(entrada);
                    case 8:
                        valor_terminal = std::stof(entrada);
                    case 9:
                        distancia = std::stoi(entrada);
                }
            }
            std::cout << origem << " "
                      << destino << " "
                      << tipo_modal << " "
                      << preco << " "
                      << capacidade << " "
                      << velocidade << " "
                      << pedagio << " "
                      << valor_pedagio << " "
                      << valor_terminal << " "
                      << distancia << std::endl;                    
            if(tipo_modal == "ferroviario") {
                Modal *f = new Ferroviario(distancia);
                this->_graph[origem][destino] = *f;
                // this->_graph[origem][destino] = Ferroviario(distancia);
            }else{
                if(tipo_modal == "rodoviario") {
                    this->_graph[origem][destino] = Rodoviario(distancia, pedagio, valor_pedagio);
                }else{
                    if(tipo_modal == "aereo") {
                        this->_graph[origem][destino] = Aereo(distancia, valor_terminal);
                    }else{
                        this->_graph[origem][destino] = Aquaviario(distancia, valor_terminal);    
                    }
                }
            }            
            counter++;
        }
    }
    /*
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
    */
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

// Function to print shortest path from source to j using parent array 
void Operador::printPath(int *parent, int j) { 
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    Operador::printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 
  
// A utility function to print the constructed distance array 
void Operador::printSolutionPath(int *dist, int *parent, int src, int dest) { 
    printf("Vertex\t Distance\tPath"); 
    printf("\n%d -> %d \t %d\t\t%d ", 
                      src, dest, dist[dest], src);
    printPath(parent, dest);
    printf("\n");
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void Operador::dijkstra(int src, int dest, float quantidade) { 
    std::cout << "DJIKSTRA\n";
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

        if(u == dest) {
            break;
        }
        
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
    Operador::printSolutionPath(dist, parent, src, dest); 

    delete[] dist;
    delete[] sptSet;
    delete[] parent;
} 

void Operador::addSolicitacao(int src, int dest, float quantidade) {
    Solicitacao s(src, dest, quantidade);
    this->_lista_solicitacoes.push_back(s);
}