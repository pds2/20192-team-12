#ifndef OPERADOR_H
#define OPERADOR_H

#include <"modal.hpp">

/*
Esta classe representa o Operador Nacional que realiza a logística
do transporte de cargas.

Dado uma solicitação de transporte (class Solicitação) de uma certa quantidade entre duas localidades,
o Operador Nacional calcula a rota que minimiza os custos financeiros e a rota que minimiza o tempo gasto.

Resposta:
1) Caso haja uma rota entre as duas localidades, a rota que apresenta
o menor custo financeiro e a rota que apresenta o menor
tempo necessário;
2) Caso não haja uma rota entre as duas localidades, apresenta
um informativo de que não é possível transportar o produto entre
as duas localidades desejadas
*/

class Operador {
    private: 
    	int _V;
        Modal **_graph;

        void popularMatriz();
   
        int printSolution(*int);
        void printPath(*int, int);
        int printSolutionPath(*int, *int, int);

        int minDistance(*int, *bool);

        void dijkstra(int, int, float);
    	
    public:

    	Operador();
        Operador(int);
        ~Operador();

        // origem, destino, quantidade
    	void obterRota(int, int, float);
};

#endif