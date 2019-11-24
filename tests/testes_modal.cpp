#include "doctest.h"
#include "modal.hpp"

TEST_CASE("01 - Testes de contorno") {
    // Testar numero no 1o argumento
    CHECK_NOTHROW(Ferroviario()); // argumento vazio
    CHECK_THROWS(Ferroviario(-1));
	
	Ferroviario *f = new Ferroviario();
	
	CHECK_THROWS(f->setCapacidade(-1));
    CHECK_THROWS(f->setPreco(-1));
    CHECK_THROWS(f->setVelocidade(-1));
    CHECK_THROWS(f->setDistancia(-1));

	delete f;
	
    CHECK_NOTHROW(Rodoviario()); // argumento vazio
    CHECK_THROWS(Rodoviario(-1, false, -1));
	
	Rodoviario *r = new Rodoviario();
	
	CHECK_THROWS(r->setCapacidade(-1));
    CHECK_THROWS(r->setPreco(-1));
    CHECK_THROWS(r->setVelocidade(-1));
    CHECK_THROWS(r->setDistancia(-1));
    CHECK_THROWS(r->setPedagio(-1));
    CHECK_THROWS(r->setValorPedagio(-1));
	
	// delete r;

    CHECK_NOTHROW(Aquaviario()); // argumento vazio
    CHECK_THROWS(Aquaviario(-1, -1));

	Aquaviario *aq = new Aquaviario();

    CHECK_THROWS(aq->setCapacidade(-1));
    CHECK_THROWS(aq->setPreco(-1));
    CHECK_THROWS(aq->setVelocidade(-1));
    CHECK_THROWS(aq->setDistancia(-1));
    CHECK_THROWS(aq->setValorTerminal(-1));
	
	// delete aq;
	
    CHECK_NOTHROW(Aereo()); // argumento vazio
    CHECK_THROWS(Aereo(-1, -1));
	
	Aereo *ar = new Aereo();

    CHECK_THROWS(ar->setCapacidade(-1));
    CHECK_THROWS(ar->setPreco(-1));
    CHECK_THROWS(ar->setVelocidade(-1));
    CHECK_THROWS(ar->setDistancia(-1));
    CHECK_THROWS(ar->setValorTerminal(-1));
	// delete ar;
}
TEST_CASE("02 - Classe Ferroviario - Teste positivo"){

	// Testando a classe Ferroviario
	Ferroviario *f = new Ferroviario();

	CHECK(f->getTipoModal() == "ferroviario");
	CHECK(f->getPreco() == (float) 0.05);
	CHECK(f->getCapacidade() == 70000);
	CHECK(f->getVelocidade() == 20);
}
TEST_CASE("03 - Classe Rodoviario - Teste positivo"){

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

}
TEST_CASE("04 - Classe Aquaviario - Teste positivo"){

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
TEST_CASE("05 - Classe Aereo - Teste positivo"){

	// Testando a classe Aereo
	Aereo *ar = new Aereo();

	CHECK(ar->getTipoModal() == "aereo");
	CHECK(ar->getPreco() == (float) 0.1);
	CHECK(ar->getCapacidade() == 100);
	CHECK(ar->getVelocidade() == 800);

	
}