#include <vector>
#include  "../third_party/doctest.h"
#include "../include/solicitacao.hpp"
#include "../include/localidade.hpp"
#include "../include/tools.hpp"

TEST_CASE("01 - Testes de contorno") {
    CHECK_NOTHROW(Solicitacao()); // argumento vazio
    CHECK_THROWS(Solicitacao(-1, -1, 2)); // argumento negativo

    Solicitacao s(1000, 1, 2);

    CHECK_THROWS(s.setOrigem(-1)); // argumento negativo
    CHECK_THROWS(s.setDestino(-1));// argumento negativo
    CHECK_THROWS(s.setQuantidade(-1));// argumento negativo

}
TEST_CASE("03 - Testando setters e getters"){
    // Teste positivo
    Solicitacao s(1000, 1, 2);

    s.setQuantidade(100);
    s.setOrigem(2);
    s.setDestino(3);

    CHECK(s.getQuantidade() == 100);
    CHECK(s.getOrigem() == 2);
    CHECK(s.getDestino() == 3);
}
