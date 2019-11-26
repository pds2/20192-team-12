#include <vector>
#include "../third_party/doctest.h"
#include "../include/operador.hpp"
/*

EM DESENVOLVIMENTO
TESTAR OBTER CUSTO PARA TODAS AS CLASSES
*/

TEST_CASE("01 - Testes de contorno") {
    // Testar numero no 1o argumento
    CHECK_THROWS(Operador(0)); // argumento zero
    CHECK_THROWS(Operador(-1)); // argumento negativo

    Operador operador0 = Operador(-1);// argumento negativo

    std::vector <Localidade> vec_local;
    Operador operador1 = Operador(vec_local.size());// argumento negativo
    
	CHECK_THROWS(operador1.popularMatriz());
    CHECK_THROWS(operador1.dijkstra(-1, -1, -1, vec_local)); // argumentos negativo
    CHECK_THROWS(operador1.dijkstra(0, 0, 0, vec_local)); // argumentos com valor zero
    CHECK_THROWS(operador1.addSolicitacao(-1, -1, -1)); // argumentos negativo
    CHECK_THROWS(operador1.addSolicitacao(0, 0, 0)); // argumentos com valor zero

}
TEST_CASE("02 - Testes positivos"){

    std::vector <Localidade> vec_local; 
    std::ifstream arq_local("./data/localidades.txt");
    lerArquivoLocalidades(arq_local, vec_local);

    Operador o = Operador(vec_local.size());
	CHECK_NOTHROW(o.addSolicitacao(0,1,100));
    CHECK_NOTHROW(o.addSolicitacao(4,5,1));
    CHECK_NOTHROW(o.addSolicitacao(6,7,35));
    CHECK_NOTHROW(o.addSolicitacao(8,9,36));
    CHECK_NOTHROW(o.addSolicitacao(10,11,50));
    CHECK_NOTHROW(o.addSolicitacao(12,13,70));
    CHECK_NOTHROW(o.addSolicitacao(14,15,80));
    CHECK_NOTHROW(o.addSolicitacao(16,17,90));
    CHECK_NOTHROW(o.addSolicitacao(18,19,100));
    CHECK_NOTHROW(o.addSolicitacao(20,21,110));
    CHECK_NOTHROW(o.addSolicitacao(22,23,120));
    CHECK_NOTHROW(o.addSolicitacao(2,3,100000));

    CHECK_NOTHROW(o.dijkstra(2,3,1, vec_local));
    CHECK_NOTHROW(o.dijkstra(4,7,10, vec_local));
    CHECK_NOTHROW(o.dijkstra(6,11,100, vec_local));
    CHECK_NOTHROW(o.dijkstra(8,15,200, vec_local));
    CHECK_NOTHROW(o.dijkstra(10,19,1000, vec_local));
    CHECK_NOTHROW(o.dijkstra(12,23,2000, vec_local));
    CHECK_NOTHROW(o.dijkstra(14,27,10000, vec_local));
    CHECK_NOTHROW(o.dijkstra(16,31,50000, vec_local));
    CHECK_NOTHROW(o.dijkstra(18,35,100000, vec_local));

}
