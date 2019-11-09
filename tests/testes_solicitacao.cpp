#include "doctest.h"
#include "solicitacao.hpp"
// #include <string>
/* EM DESENVOLVIMENTO */

TEST_CASE("01 - Testes de contorno") {
    CHECK_NOTHROW(Solicitacao()); // argumento vazio
    CHECK_NOTHROW(Solicitacao(-1, 1, 2)); // argumento negativo
    // CHECK_NOTHROW(Embarcador("a", 1, 2)); // quantidade literal  (VERIFICAR)

    Solicitacao s(1000, 1, 2);

    CHECK_NOTHROW(s.setOrigem(-1));
    CHECK_NOTHROW(s.setDestino(-1));
    CHECK_NOTHROW(s.setQuantidade(-1));
}
TEST_CASE("02 - Testando setters e getters"){

    Solicitacao s(1000, 1, 2);

    s.setQuantidade(100);
    s.setOrigem(2);
    s.setDestino(3);

    CHECK(s.getQuantidade() == 100);
    CHECK(s.getOrigem() == 2);
    CHECK(s.getDestino() == 3);
}
