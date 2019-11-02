#include "doctest.h"

#include "../include/solicitacao.hpp"
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
// TEST_CASE("02 - Testando setters e getters"){

//     Embarcador e(1000, 1, 2);

//     e.setQuantidade(100);
//     e.setOrigem(2);
//     e.setDestino(3);

//     CHECK(e.getQuantidade() == 100);
//     CHECK(e.getOrigem() == 2);
//     CHECK(e.getDestino() == 3);
// }
