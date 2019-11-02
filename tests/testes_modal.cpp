#include "doctest.h"

#include "../include/modal.hpp"

/* EM DESENVOLVIMENTO */

TEST_CASE("01 - Testes de contorno") {
    // Modal::Modal(std::string nome_modal, float preco, float capacidade, float velocidade)
    CHECK_NOTHROW(Modal()); // argumento vazio
    CHECK_NOTHROW(Modal("rodoviario", -1, -1, -1));


// Rodoviario::Rodoviario(): Rodoviario(0, 0 ){};
// Rodoviario::Rodoviario(bool pedagio, float valor_pedagio): _pedagio(pedagio), _valor_pedagio(valor_pedagio)
    CHECK_NOTHROW(Rodoviario()); // argumento vazio
    CHECK_NOTHROW(Rodoviario(-1, -1));
    // CHECK_NOTHROW(Embarcador("a", 1, 2)); // quantidade literal  (VERIFICAR)

 //    Embarcador e(1000, 1, 2);

 //    CHECK_NOTHROW(e.setOrigem(-1));
	// CHECK_NOTHROW(e.setDestino(-1));
	// CHECK_NOTHROW(e.setQuantidade(-1));
}
// TEST_CASE("02 - Testando setters e getters"){

// 	Embarcador e(1000, 1, 2);

// 	e.setQuantidade(100);
// 	e.setOrigem(2);
// 	e.setDestino(3);

// 	CHECK(e.getQuantidade() == 100);
// 	CHECK(e.getOrigem() == 2);
// 	CHECK(e.getDestino() == 3);
// }
