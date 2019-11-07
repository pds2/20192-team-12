#include "doctest.h"
#include "../include/modal.hpp"

/*

EM DESENVOLVIMENTO

*/

TEST_CASE("01 - Testes de contorno") {
    // Modal::Modal(std::string nome_modal, float preco, float capacidade, float velocidade)
    // CHECK_NOTHROW(Modal()); // argumento vazio
    // CHECK_NOTHROW(Modal("rodoviario", -1, -1, -1));
    // Testar numero no 1o argumento
    CHECK_NOTHROW(Ferroviario()); // argumento vazio
    CHECK_NOTHROW(Ferroviario(-1));
	
	Ferroviario *f = new Ferroviario();
	
	CHECK_NOTHROW(f->setCapacidade(-1));
    CHECK_NOTHROW(f->setPreco(-1));
    CHECK_NOTHROW(f->setVelocidade(-1));
    CHECK_NOTHROW(f->setDistancia(-1));

	delete f;
	
    CHECK_NOTHROW(Rodoviario()); // argumento vazio
    CHECK_NOTHROW(Rodoviario("rodoviario", -1, -1, -1, -1, false, -1));
	
	Rodoviario *r = new Rodoviario();
	
	CHECK_NOTHROW(r->setCapacidade(-1));
    CHECK_NOTHROW(r->setPreco(-1));
    CHECK_NOTHROW(r->setVelocidade(-1));
    CHECK_NOTHROW(r->setDistancia(-1));
    CHECK_NOTHROW(r->setPedagio(-1));
    CHECK_NOTHROW(r->setValorPedagio(-1));
	
	// delete r;

    CHECK_NOTHROW(Aquaviario()); // argumento vazio
    CHECK_NOTHROW(Aquaviario("aquaviario", -1, -1, -1, -1, -1));

	Aquaviario *aq = new Aquaviario();

    CHECK_NOTHROW(aq->setCapacidade(-1));
    CHECK_NOTHROW(aq->setPreco(-1));
    CHECK_NOTHROW(aq->setVelocidade(-1));
    CHECK_NOTHROW(aq->setDistancia(-1));
    CHECK_NOTHROW(aq->setValorTerminal(-1));
    // CHECK_NOTHROW(aq->setTipoModal("rodoviario"));
	
	// delete aq;
	
    CHECK_NOTHROW(Aereo()); // argumento vazio
    CHECK_NOTHROW(Aereo("aereo", -1, -1, -1, -1, -1));
	
	Aquaviario *ar = new Aquaviario();

    CHECK_NOTHROW(ar->setCapacidade(-1));
    CHECK_NOTHROW(ar->setPreco(-1));
    CHECK_NOTHROW(ar->setVelocidade(-1));
    CHECK_NOTHROW(ar->setDistancia(-1));
    CHECK_NOTHROW(ar->setValorTerminal(-1));
	// delete ar;
}
TEST_CASE("02 - Testando setters e getters"){

	// Modal f("ferroviario", 0.05, 70000, 20);
	// Rodoviario r("rodoviario", 0.075, 35, 60);
	// Aquaviario aq("aquaviario", 04375, 1000, 40);
	// Aereo ae("aereo", 0.1, 100, 800);

	// Testando a classe Modal
	Ferroviario *f = new Ferroviario();
	// f->setTipoModal("rodoviario");
	// f->setPreco(0.075);
	// f->setCapacidade(35);
	// f->setVelocidade(60);

	CHECK(f->getTipoModal() == "ferroviario");
	CHECK(f->getPreco() == (float) 0.05);
	CHECK(f->getCapacidade() == 70000);
	CHECK(f->getVelocidade() == 20);

	// delete f;

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
	
	// delete r;

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

	// delete aq;

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

	// delete ar;

}
