#include <vector>
#include "../third_party/doctest.h"
#include "../include/operador.hpp"
/*

EM DESENVOLVIMENTO
TESTAR OBTER CUSTO PARA TODAS AS CLASSES
*/

TEST_CASE("01 - Testes de contorno") {
    // Testar numero no 1o argumento
    // CHECK_NOTHROW(Operador()); // argumento vazio
    CHECK_THROWS(Operador(0)); // argumento zero
    CHECK_THROWS(Operador(-1)); // argumento negativo

    Operador operador0 = Operador(-1);// argumento negativo

    std::vector <Localidade> vec_local; 
    // std::ifstream arq_local("./data/localidades.txt");
    // lerArquivoLocalidades(arq_local, vec_local);
    Operador operador1 = Operador(vec_local.size());// argumento negativo
    
	// CHECK_THROWS(operador1.popularMatriz());
    CHECK_THROWS(operador1.dijkstra(-1, -1, -1, vec_local)); // argumentos negativo
    CHECK_THROWS(operador1.dijkstra(0, 0, 0, vec_local)); // argumentos com valor zero
    CHECK_THROWS(operador1.addSolicitacao(-1, -1, -1)); // argumentos negativo
    CHECK_THROWS(operador1.addSolicitacao(0, 0, 0)); // argumentos com valor zero

}
TEST_CASE("02 - Testes positivos"){

	// Em implementacao

    std::vector <Localidade> vec_local; 
    std::ifstream arq_local("./data/localidades.txt");
    lerArquivoLocalidades(arq_local, vec_local);

    Operador o = Operador(vec_local.size());
	CHECK_NOTHROW(o.addSolicitacao(2, 3, 100));
	CHECK_NOTHROW(o.dijkstra(2, 3, 100, vec_local));
}
