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
    CHECK_NOTHROW(Rodoviario(-1, false, -1));
	
	Rodoviario *r = new Rodoviario();
	
	CHECK_NOTHROW(r->setCapacidade(-1));
    CHECK_NOTHROW(r->setPreco(-1));
    CHECK_NOTHROW(r->setVelocidade(-1));
    CHECK_NOTHROW(r->setDistancia(-1));
    CHECK_NOTHROW(r->setPedagio(-1));
    CHECK_NOTHROW(r->setValorPedagio(-1));
	
	// delete r;

    CHECK_NOTHROW(Aquaviario()); // argumento vazio
    CHECK_NOTHROW(Aquaviario(-1, -1));

	Aquaviario *aq = new Aquaviario();

    CHECK_NOTHROW(aq->setCapacidade(-1));
    CHECK_NOTHROW(aq->setPreco(-1));
    CHECK_NOTHROW(aq->setVelocidade(-1));
    CHECK_NOTHROW(aq->setDistancia(-1));
    CHECK_NOTHROW(aq->setValorTerminal(-1));
	
	// delete aq;
	
    CHECK_NOTHROW(Aereo()); // argumento vazio
    CHECK_NOTHROW(Aereo(-1, -1));
	
	Aereo *ar = new Aereo();

    CHECK_NOTHROW(ar->setCapacidade(-1));
    CHECK_NOTHROW(ar->setPreco(-1));
    CHECK_NOTHROW(ar->setVelocidade(-1));
    CHECK_NOTHROW(ar->setDistancia(-1));
    CHECK_NOTHROW(ar->setValorTerminal(-1));
	// delete ar;
}
TEST_CASE("02 - Testando setters e getters"){

	// Testando a classe Ferroviario
	Ferroviario *f = new Ferroviario();

	CHECK(f->getTipoModal() == "ferroviario");
	CHECK(f->getPreco() == (float) 0.05);
	CHECK(f->getCapacidade() == 70000);
	CHECK(f->getVelocidade() == 20);

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
	std::cout << "Here\n";

	// Testando a classe Aquaviario
	Aquaviario *aq = new Aquaviario();

	CHECK(aq->getTipoModal() == "aquaviario");
	CHECK(aq->getPreco() == (float) 0.04375);
	CHECK(aq->getCapacidade() == 1000);
	CHECK(aq->getVelocidade() == 40);

	// Testando a classe Aereo
	Aereo *ar = new Aereo();

	CHECK(ar->getTipoModal() == "aereo");
	CHECK(ar->getPreco() == (float) 0.1);
	CHECK(ar->getCapacidade() == 100);
	CHECK(ar->getVelocidade() == 800);
}
