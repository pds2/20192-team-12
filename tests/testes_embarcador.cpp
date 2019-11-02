#include "doctest.h"

#include "../include/embarcador.hpp"
// #include <string>
/* EM DESENVOLVIMENTO */

TEST_CASE("01 - Testando o construtor sem parâmetros") {
    CHECK_NOTHROW(Embarcador()); // argumento vazio
    CHECK_NOTHROW(Embarcador(1000, 1, 2)); // com argumentos
    CHECK_NOTHROW(Embarcador(-1, 1, 2)); // argumento negativo
    // CHECK_NOTHROW(Embarcador("a", 1, 2)); // quantidade literal  (VERIFICAR)
}
