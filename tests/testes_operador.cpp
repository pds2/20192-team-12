#include "doctest.h"
#include "operador.hpp"

/*

EM DESENVOLVIMENTO
TESTAR OBTER CUSTO PARA TODAS AS CLASSES
*/

TEST_CASE("01 - Testes de contorno") {
    // Testar numero no 1o argumento
    CHECK_NOTHROW(Operador()); // argumento vazio
    CHECK_THROWS(Operador(0)); // argumento zero
    CHECK_THROWS(Operador(-1)); // argumento negativo

    Operador *o = new Operador();

	CHECK_NOTHROW(o->popularMatriz());
    CHECK_THROWS(o->dijkstra(-1, -1, -1)); // argumentos negativo
    CHECK_THROWS(o->dijkstra(0, 0, 0)); // argumentos negativo
    CHECK_THROWS(o->addSolicitacao(-1, -1, -1)); // argumentos negativo
    CHECK_THROWS(o->addSolicitacao(0, 0, 0)); // argumentos negativo

    delete o;
}
TEST_CASE("02 - Testes positivos"){

	// Em implementacao

    Operador *o = new Operador();
	CHECK_NOTHROW(o->addSolicitacao(2, 3, 100));
	CHECK_NOTHROW(o->dijkstra(2, 3, 100));
}
