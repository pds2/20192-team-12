#ifndef OPERADOR_H
#define OPERADOR_H

#include "../include/modal.hpp"
#include "../include/solicitacao.hpp"
#include "../include/localidade.hpp"
#include "../include/tools.hpp"
#include <vector>


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
        // Representação em matriz de adjacência
        Modal **_graph;
        std::vector<Solicitacao> _lista_solicitacoes;
   
        void printPath(int*, int, std::vector  <Localidade>&);
        void printSolutionPath(int*, int*, int, int, std::vector <Localidade>&);

        int minDistance(int*, bool*);
    	
    public:

    	Operador();
        Operador(int);
        ~Operador();
        void popularMatriz();

        // Origem, destino e quantidade
        void dijkstra(int, int, float, std::vector  <Localidade>&);

        // Origem, destino e quantidade
        void addSolicitacao(int, int, float);
};

#endif

