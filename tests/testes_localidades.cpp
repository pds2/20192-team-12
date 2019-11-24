#include "doctest.h"
#include "localidade.hpp"
// #include <string>
/* EM DESENVOLVIMENTO */

TEST_CASE("01 - Testes de contorno") {
    CHECK_NOTHROW(Localidade()); // argumento vazio
    CHECK_THROWS(Localidade(-1, "BELO HORIZONTE", -1, -1,"MG", "BRASIL")); // codigo do municipio negativo
    CHECK_THROWS(Localidade(-1, "", -1, -1 ,"", "")); // nome do municipio, estado e pais vazios
 
    Localidade l;

    CHECK_THROWS(l.setCodigoMunicipio(-1));
    CHECK_THROWS(l.setMunicipio(""));
    CHECK_THROWS(l.setEstado(""));
    CHECK_THROWS(l.setPais(""));
}
TEST_CASE("02 - Testando setters e getters"){
    // Teste positivo
    Localidade l;

    l.setCodigoMunicipio(10);
    l.setEstado("BA");
    l.setMunicipio("SALVADOR");
    l.setPais("BRASIL");
    l.setLat(-22.00);
    l.setLong(-46.00);

    CHECK(l.getCodigoMunicipio() == 10);
    CHECK(l.getEstado() == "BA");
    CHECK(l.getMunicipio() == "SALVADOR");
    CHECK(l.getPais() == "BRASIL");
    CHECK(l.getLat() == -22.00);
    CHECK(l.getLong() == -46.00);
}
