// Alocação dinâmica de um grafo com modal com leitura de arquivo.txt

// A C++ program for Dijkstra's single source shortest path algorithm. 
// The program is for adjacency matrix representation of the graph 

#include <limits.h> 
#include <stdio.h> 
#include <iostream>
#include <fstream>

// Number of vertices in the graph 
#define V 42

// Struct modal
struct modal{
	int num;
	std::string _tipo_modal;
	float _preco;
	float _capacidade;
	float _velocidade;
    bool _pedagio;
    float _valor_pedagio;
    float _valor_terminal;
    int _distancia;
};

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) { 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the constructed distance array 
int printSolution(int dist[])  { 
	printf("Vertex \t\t Distance from Source\n"); 
	for (int i = 0; i < V; i++) 
		printf("%d \t\t %d\n", i, dist[i]); 
} 

// Function to print shortest path from source to j using parent array 
void printPath(int parent[], int j) { 
      
    // Base Case : If j is source 
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j]); 
  
    printf("%d ", j); 
} 
  
// A utility function to print the constructed distance array 
int printSolutionPath(int dist[], int parent[], int src) { 
    printf("Vertex\t Distance\tPath"); 
    for (int i = 1; i < V; i++) { 
        printf("\n%d -> %d \t\t %d\t\t%d ", 
                      src, i, dist[i], src); 
        printPath(parent, i); 
    } 
    printf("\n");
} 

// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(struct modal **graph, int src) { 
	int dist[V]; // The output array. dist[i] will hold the shortest 
	// distance from src to i 

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
	// path tree or shortest distance from src to i is finalized 

	// Parent array to store shortest path tree 
    int parent[V]; 

	// Initialize all distances as INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	// Distance of source vertex from itself is always 0 
	dist[src] = 0; 

	// Parent of root (or source vertex) is -1. 
	parent[src] = -1; 

	// Find shortest path for all vertices 
	for (int count = 0; count < V - 1; count++) { 
		// Pick the minimum distance vertex from the set of vertices not 
		// yet processed. u is always equal to src in the first iteration. 
		int u = minDistance(dist, sptSet); 

		// Mark the picked vertex as processed 
		sptSet[u] = true; 

		// Update dist value of the adjacent vertices of the picked vertex. 
		for (int v = 0; v < V; v++) 

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
	printSolution(dist); 
	printSolutionPath(dist, parent, src); 
} 


// driver program to test above function 
int main()  { 

	struct modal **graph;
	graph = new struct modal*[V];
	for(int i = 0; i < V; i++){	
		graph[i] = new struct modal[V]; // (int*)malloc(V*sizeof(int));	
	}

    std::ifstream infile("arestas.txt");

    int a, b;
    while(infile >> a >> b) {
    	infile >> graph[a][b]._tipo_modal;
    	infile >> graph[a][b]._preco;
    	infile >> graph[a][b]._capacidade;
    	infile >> graph[a][b]._velocidade;
    	infile >> graph[a][b]._pedagio;
    	infile >> graph[a][b]._valor_pedagio;
    	infile >> graph[a][b]._valor_terminal;
    	infile >> graph[a][b]._distancia;
    	//std::cout << a << "\t" << b << "\t" << graph[a][b]._tipo_modal << "\t" << graph[a][b]._preco << "\t" << graph[a][b]._capacidade << "\t" << graph[a][b]._velocidade << "\t" << graph[a][b]._pedagio << "\t" << graph[a][b]._valor_pedagio << "\t" << graph[a][b]._valor_terminal << "\t" << graph[a][b]._distancia << "\n";
    }

    /*
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			printf("%d ", graph[i][j]._distancia);
		}
		printf("\n");
	}
	*/

    for(int i = 0; i < V; ++i) {
    	dijkstra(graph, i); 	
    }	
	
	for (int i = 0; i < V; ++i)
	    delete [] graph[i];
	delete [] graph;

	return 0; 
} 
