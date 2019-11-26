#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <limits.h>
#include <stdio.h> 
#include <fstream>
#include <sstream>
#include <string>
#include "../include/operador.hpp"

/*
O código que implementa o algoritmo Dijsktra's single source 
shortest path algorithm está disponível em:
<https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/>

O código para impressão do caminho mínimo está disponível em:
<https://www.geeksforgeeks.org/printing-paths-dijkstras-shortest-path-algorithm/>

O código que implementa o algoritmo Breadth First Search está disponível em:
<https://www.geeksforgeeks.org/implementation-of-bfs-using-adjacency-matrix/>

Todos os códigos foram parcialmente alterados para responder às necessidades do 
Sistema de Alocação de Transporte.
*/


//Contrutores da classe Operador
Operador::Operador(int V){
    /** Contrutor da classe Operador
     * Sem argumentos.
    */
    if (V <= 0){
        throw std::invalid_argument("Matriz deve ter numero de vertices positivo!");
    }

    this->_graph = new Modal*[V];
    for(int i = 0; i < V; i++){ 
        this->_graph[i] = new Modal[V]; 
    }
    this->_V = V;
}

Operador::~Operador(){
    /** Destrutor da classe Operador
     * Sem argumentos.
    */
    for (int i = 0; i < _V; ++i)
        delete [] this->_graph[i];
    delete [] this->_graph;
}

//Metodos da classe Operador
void Operador::popularMatriz() {
    /** O metodo  popularMatriz povoa a matriz de adjacencias com os vaores dos modais.
     * Sem argumentos.
    */
    std::ifstream infile("./data/arestas.txt");
    std::string linha; 

    // códigos das localidades, indexação do grafo
    int row, col; 

    // contadores auxiliares
    int rows = 0; // total de arestas
    int columns = 0; // total de colunas por aresta

    // informações dos modais
    std::string tipo_modal;
    float preco;
    float capacidade;
    float velocidade;
    int pedagio;
    float valor_pedagio;
    float valor_terminal;
    int distancia;

    infile >> rows >> columns;

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

bool Operador::ehAlcancavel(int src, int dest) { 
    /** O metodo ehAlcancavel detecta se há um caminho entre dois vértices (origem e destino).\n
     * Argumentos:
     *  - src: origem
     *  - dest: destino
     * Excecao:
     *  - os valores dos argumentos devem ser maiores que zero.
    */
    if (src < 0 || dest < 0){
        std::string aviso = "Os codigos da origem, destino nao podem ser negativos.\n";
        throw std::invalid_argument(aviso);
    }
    // Base case 
    if (src == dest) {
      return true;   
    } 
      
    // Mark all the vertices as not visited 
    bool *visited = new bool[this->_V]; 
    for (int i = 0; i < this->_V; i++) {
        visited[i] = false; 
    }

    std::vector<int> q; 
    q.push_back(src); 
  
    // Set source as visited 
    visited[src] = true; 
  
    int vis; 
    while (!q.empty()) { 
        vis = q[0]; 
        q.erase(q.begin()); 
        // For every adjacent vertex to the current vertex 
        for (int i = 0; i < this->_V; i++) { 
            if (this->_graph[vis][i].getFlagAresta() == 1 && (!visited[i])) { 
                
                // If this adjacent node is the destination node, then  
                // return true 
                if (i == dest) {
                    return true; 
                }
  
                // Push the adjacent node to the queue 
                q.push_back(i); 
  
                // Set 
                visited[i] = true; 
            } 
        } 
    } 

    // If BFS is complete without visiting dest
    return false; 
} 


// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int Operador::minDistance(int *dist, bool *sptSet) {
    /** O metodo minDistance encontra o vertice com a menor distancia entre os vertices
     * .
     * Argumentos:
     *  - dist: vetor com as distâncias entres os vértices;
     *  - sptSet: vetor com vértices incluídos ou não na árvore de caminho mínimo;
    */
    // Initialize min value 
    int min = INT_MAX, min_index; 

    for (int v = 0; v < this->_V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 

    return min_index; 
} 

// Function to print shortest path from source to j using parent array 
void Operador::printPath(int *parent, int j, int src, std::vector  <Localidade> &vector) {
    /* O metodo printPath imprime o caminho encontrado.\n
     * Argumentos:
     *  - parent: árvore de caminho mínimo;
     *  - j: vértice destino;
     *  - vector: vetor de localidades;
    */    
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    Operador::printPath(parent, parent[j], src, vector); 
    std::cout << "(" <<  this->_graph[src][j].getTipoModal() << ")" << " ";
    std::cout << searchMunicipio(j, vector).getMunicipio() << " ";
} 
  
// A utility function to print the constructed distance array 
void Operador::printSolutionPath(int *dist, int *parent, int src, int dest,  std::vector  <Localidade> &vector) {
    /* O metodo printSolutionPath imprime a solucao encontrada.\n
     * Argumentos:
     *  - dist: vetor com as distâncias entre os vértices
     *  - parent: árvore de caminho mínimo
     *  - src: vértice origem
     *  - dest: vértice destino
     *  - vector: vetor de localidades
    */
    int padding = 20;
    // std::cout << std::setw(padding) << std::left<< "ORIGEM\t\tDESTINO\t\tDistance\t\tROTA" << std::endl;
    std::cout << std::setw(padding) << std::left << "ORIGEM" 
              << std::setw(padding) << std::left << "DESTINO"
              << std::setw(padding) << std::left << "TEMPO (h)"
              << std::setw(padding) << std::left << "ROTA" << std::endl;
    std::cout << std::setw(padding) << std::left << searchMunicipio(src, vector).getMunicipio()
              << std::setw(padding) << std::left << searchMunicipio(dest, vector).getMunicipio() 
              << std::setw(padding) << std::left << dist[dest]
              << searchMunicipio(src, vector).getMunicipio() << " ";

    printPath(parent, dest, src, vector);
    std::cout << std::endl;
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void Operador::dijkstra(int src, int dest, float quantidade,  std::vector  <Localidade> &vector) {
    /** O metodo dijkstra  implementa o algoritmo de Dijkstra para encontrar o menor caminho.\n 
     * Argumentos:  
     *  - src: origem;
     *  - dest: destino;
     *  - quantidade: quantidade de carga a ser transportada;
     *  - vector: vetor de localidades.
    */

    if (src < 0 || dest < 0 || quantidade <=0 || vector.size() == 0){
        std::string aviso = "VERIFIQUE UMA DAS SEGUINTES SITUACOES:\n";
        aviso += "Os codigos da origem, destino nao podem ser negativos.\n";
        aviso += " A quantidade de carga nao pode ser menor ou igual a zero.\n";
        aviso += "O vetor de localidades nao pode ser vazio";
        throw std::invalid_argument(aviso);
    }

    if(!ehAlcancavel(src, dest)) {
        std::cout << "Nao existe rota entre origem e destino" << std::endl;
    } else{
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
                if (!sptSet[v] && _graph[u][v].getFlagAresta() && dist[u] != INT_MAX 
                    && dist[u] + _graph[u][v].obterTempo() < dist[v]) {
                    dist[v] = dist[u] + _graph[u][v].obterTempo();     
                    parent[v] = u;
                }
        } 

        // print the constructed distance array 
        Operador::printSolutionPath(dist, parent, src, dest, vector); 

        delete[] dist;
        delete[] sptSet;
        delete[] parent;
    }
} 

void Operador::addSolicitacao(int src, int dest, float quantidade) {
    /** O metodo dijkstra  implementa o algoritmo de Dijkstra para encontrar o menor caminho.\n 
     * Argumentos:
     *  - src: origem
     *  - dest: destino
     *  - quantidade: quantidade de carga a ser transportada
    */
    if (src < 0 || dest < 0 || quantidade <=0 ){
        std::string aviso = "VERIFIQUE UMA DAS SEGUINTES SITUACOES:\n";
        aviso += "Os codigos da origem, destino nao podem ser negativos.\n";
        aviso += " A quantidade de carga nao pode ser menor ou igual a zero.\n";
        throw std::invalid_argument(aviso);
    }
    Solicitacao s(src, dest, quantidade);
    this->_lista_solicitacoes.push_back(s);
}