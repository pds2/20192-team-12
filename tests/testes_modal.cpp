#include "doctest.h"
#include "../include/modal.hpp"

/* EM DESENVOLVIMENTO */

TEST_CASE("01 - Testes de contorno") {
    // Modal::Modal(std::string nome_modal, float preco, float capacidade, float velocidade)
    // CHECK_NOTHROW(Modal()); // argumento vazio
    // CHECK_NOTHROW(Modal("rodoviario", -1, -1, -1));
    // Testar numero no 1o argumento

    CHECK_NOTHROW(Rodoviario()); // argumento vazio
    CHECK_NOTHROW(Rodoviario(-1, -1));

    CHECK_NOTHROW(Aquaviario()); // argumento vazio
    CHECK_NOTHROW(Aquaviario(-1));

    CHECK_NOTHROW(Aereo()); // argumento vazio
    CHECK_NOTHROW(Aereo(-1));
}
TEST_CASE("02 - Testando setters e getters"){

	// Modal f("ferroviario", 0.05, 70000, 20);
	// Rodoviario r("rodoviario", 0.075, 35, 60);
	// Aquaviario aq("aquaviario", 04375, 1000, 40);
	// Aereo ae("aereo", 0.1, 100, 800);

	// Testando a classe Modal
	Modal *f = new Modal();
	// f->setTipoModal("rodoviario");
	// f->setPreco(0.075);
	// f->setCapacidade(35);
	// f->setVelocidade(60);

	CHECK(f->getTipoModal() == "ferroviario");
	CHECK(f->getPreco() == (float) 0.05);
	CHECK(f->getCapacidade() == 70000);
	CHECK(f->getVelocidade() == 20);

	delete f;

	// Testando a classe Rodoviario
	Rodoviario *r = new Rodoviario();

	r->setPedagio(true);
	r->setValorPedagio(30);

	CHECK(r->getTipoModal() == "rodoviario");
	CHECK(r->getPreco() == (float) 0.075);
	CHECK(r->getCapacidade() == 35);
	CHECK(r->getVelocidade() == 60);
	CHECK(r->isPedagio() == true);
	CHECK(r->getValorPedagio() == 30);
	
	delete r;

	// Testando a classe Modal
	Aquaviario *aq = new Aquaviario();
	// aq->setTipoModal("aquaviario");
	// aq->setPreco(0.075);
	// aq->setCapacidade(35);
	// aq->setVelocidade(60);

	CHECK(aq->getTipoModal() == "aquaviario");
	CHECK(aq->getPreco() == (float) 0.04375);
	CHECK(aq->getCapacidade() == 1000);
	CHECK(aq->getVelocidade() == 40);

	delete aq;

	// Testando a classe Modal
	Modal *ar = new Aereo();
	// ar->setTipoModal("rodoviario");
	// ar->setPreco(0.075);
	// ar->setCapacidade(35);
	// ar->setVelocidade(60);

	CHECK(ar->getTipoModal() == "aereo");
	CHECK(ar->getPreco() == (float) 0.1);
	CHECK(ar->getCapacidade() == 100);
	CHECK(ar->getVelocidade() == 800);

	delete ar;

}
