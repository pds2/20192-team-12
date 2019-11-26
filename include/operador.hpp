#ifndef OPERADOR_H
#define OPERADOR_H

#include "../include/modal.hpp"
#include "../include/solicitacao.hpp"
#include "../include/localidade.hpp"
#include "../include/tools.hpp"
#include <vector>

/**
A classe Operador representa o Operador Nacional que realiza a logística
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
        /** número de vértices da matriz de adjacências*/
    	int _V;
        /** Representação em matriz de adjacência */
        Modal **_graph;
        /** Vetor com as solicitações de tranporte */
        std::vector<Solicitacao> _lista_solicitacoes;
        /* Método privado para imprimir o caminho ótimo */
        void printPath(int*, int, int, std::vector  <Localidade>&);
        /* Método privado para imprimir a solução */
        void printSolutionPath(int*, int*, int, int, std::vector <Localidade>&);
        /* Método que retorna a menor distância*/
        int minDistance(int*, bool*);
    	
    public:

    	/** Contrutor da classe Operador*/
        Operador(int);
        /** Destrutor da classe Operador*/
        ~Operador();

        /** Constroi a matriz de adjacencias*/
        void popularMatriz();

        /** Algoritmo Dijkstra para caminho mínimo entre vértice origem e destino */
        void dijkstra(int, int, float, std::vector  <Localidade>&);

        /** Detecta se há um caminho entre dois vértices (origem e destino) */
        bool ehAlcancavel(int, int);

        /** Adiciona uma solicitação de transporte*/
        void addSolicitacao(int, int, float);
};

#endif

