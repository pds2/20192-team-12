#ifndef OPERADOR_H
#define OPERADOR_H

#include <"modal.hpp">

/*
Esta classe representa o Operador Nacional que realiza a logística
do transporte de cargas.

Dado um pedido de transporte de uma certa quantidade entre duas localidades
o Operador Nacional calcula a rota que minimiza os custos financeiros e a
rota que minimiza o tempo gasto.
*/

class Operador {
    private: 
        Modal **matriz;
    	
    public:

    	Operador();
        Operador(int);
        ~Operador();

    	void obter_rota();
};

#endif