#include "doctest.h"

#include "../include/modal.hpp"

/* EM DESENVOLVIMENTO */

// #include "../include/embarcador.hpp"
// #include "../include/tools.hpp"
// #include <string>

// TEST_CASE("01 - Testando o construtor sem parâmetros") {
//     CHECK_NOTHROW(Embarcador()); // argumento vazio
//     CHECK_NOTHROW(Embarcador(1000, 1, 2)); // argumento 
//     CHECK_NOTHROW(Modal(1000, 1, 2)); // argumento 


// }

	
// TEST_CASE("02 - Testando a inserção de pacotes e o custo total por usuário") {
//     Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
//     Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
//     Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
//     Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
//     Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
//     DestinationPackages pacotes;
//     CHECK_NOTHROW(pacotes.add_package(p1));
//     CHECK_NOTHROW(pacotes.add_package(p2));
//     CHECK_NOTHROW(pacotes.add_package(p3));
//     CHECK_NOTHROW(pacotes.add_package(p4));
//     CHECK_NOTHROW(pacotes.add_package(p5));
    
//     CHECK(pacotes.custo_total("Josias") == 15);
//     CHECK(pacotes.custo_total("Maria") == 30);
//     CHECK(pacotes.custo_total("Carlos") == 25);
    
//     delete p1;
//     delete p2;
//     delete p3;
//     delete p4;
//     delete p5;
// }

// TEST_CASE("03 - Testando o cálculo de custo total de pacotes") {
//     Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
//     Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
//     Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
//     Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
//     Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
//     DestinationPackages pacotes;
//     CHECK_NOTHROW(pacotes.add_package(p1));
//     CHECK_NOTHROW(pacotes.add_package(p2));
//     CHECK_NOTHROW(pacotes.add_package(p3));
//     CHECK_NOTHROW(pacotes.add_package(p4));
//     CHECK_NOTHROW(pacotes.add_package(p5));
    
//     CHECK(pacotes.custo_total() == 70);
    
//     delete p1;
//     delete p2;
//     delete p3;
//     delete p4;
//     delete p5;
// }

// TEST_CASE("04 - Checando um custo nulo para uma chave não presente no map; e para um map vazio") {
//     Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
//     Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
//     Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
//     Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
//     Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
//     DestinationPackages pacotes;
//     DestinationPackages pacotes2;
//     CHECK_NOTHROW(pacotes.add_package(p1));
//     CHECK_NOTHROW(pacotes.add_package(p2));
//     CHECK_NOTHROW(pacotes.add_package(p3));
//     CHECK_NOTHROW(pacotes.add_package(p4));
//     CHECK_NOTHROW(pacotes.add_package(p5));
    
//     CHECK(pacotes.custo_total("Marcos") == 0);
//     CHECK(pacotes2.custo_total()==0);
    
//     delete p1;
//     delete p2;
//     delete p3;
//     delete p4;
//     delete p5;
// }


// TEST_CASE("05 - Inserção de membros de classes derivadas e cálculo de custo polimorficamente") {
    
//     Package *p1 = new OverNightPackage(2, 5, 7, "Maria", "Rio");
//     Package *p2 = new OverNightPackage(3, 2, 1, "Paulo", "Juazeiro");
//     Package *p3 = new TwoDayPackage(5, 2, 4, "Josias", "Juazeiro");
//     Package *p4 = new TwoDayPackage(2, 5, 3, "Maria", "Juazeiro");
//     Package *p5 = new Package(5, 7, "Paulo", "Juazeiro");

//     DestinationPackages pacotes;
//     CHECK_NOTHROW(pacotes.add_package(p1));
//     CHECK_NOTHROW(pacotes.add_package(p2));
//     CHECK_NOTHROW(pacotes.add_package(p3));
//     CHECK_NOTHROW(pacotes.add_package(p4));
//     CHECK_NOTHROW(pacotes.add_package(p5));
    
//     CHECK(pacotes.custo_total("Josias") == 14);
//     CHECK(pacotes.custo_total("Maria") == 37);
//     CHECK(pacotes.custo_total("Paulo") == 44);
//     CHECK(pacotes.custo_total() == 95);
    
//     delete p1;
//     delete p2;
//     delete p3;
//     delete p4;
//     delete p5;
// }