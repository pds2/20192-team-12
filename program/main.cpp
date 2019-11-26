#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include "../include/tools.hpp"
#include "../include/modal.hpp"
#include "../include/localidade.hpp"
#include "../include/solicitacao.hpp"
#include "../include/tools.hpp"
#include "../include/operador.hpp"

#define CONTINUAR 1
#define SAIR 2
/**
 * # Descrição
 * Este Trabalho Prático consiste no desenvolvimento de um sistema em linguagem C++ baseado no paradigma de 
 * Orientação à Objetos. Para modelar um sistema de alocação de demanda de transporte utilizamos de classes
 *  abstratas e conceitos de OO como modularização, polimorfismo, testes de unidade e boas práticas de 
 * programação em geral como refatoração, código comentado e versionamento de código.
 * Desenvolvemos, portanto, um sistema que, dada uma demanda de transporte de uma certa quantidade de 
 * determinado produto, para alguma localidade do Brasil ou Exterior, encontra o caminho de menor custo.
 *  O custo a ser considerado pode ser monetário ou menor distância ou tempo de percurso, considerando os 
 * preços dos serviços, tempo de transporte e capacidade dos diversos modais disponíveis 
 * (rodoviário, ferroviário, aéreo e aquaviário).
 * 
 * # Integrantes
 * Estevão de Almeida Vilela
 * Wagner Evangelist de Abreu
 * */

int main(){

    //Bloco de declaracao de variaveis
    int cod_origem, // codigo da localidade de origem
        cod_destino; // codigo da localidade de destino
    int num_localidades; // numero de localidades
    int num_solicitacoes = 0; // numero de solicitacoes realizadas
    int entrada = 1; // verifica entrada
    float quantidade; // quantidade a ser transportada

    std::string linha;
    std::string aviso; // elemento da tela
    std::string title; // elemento da tela
    std::string dir_arq_local = "./data/"; // diretorio raiz do arquivo localidades.txt
    std::vector <Localidade> vec_local; // vetor para armazenar os dados das localidades

    Localidade origem,  // localidade de origem
               destino;  // localidade de destino

    // obtem o nome do arquivo do argumento e abre o arquivo
    std::ifstream arq_local(dir_arq_local + "localidades.txt");
    // tentativa de abrir o arquivo de localidades
    // uma excecao eh lancada se a pasta nao contiver o arquivo

    try {
        lerArquivoLocalidades(arq_local, vec_local);
    }catch (std::ifstream::failure &e) {
        std::cerr << "Arquivo de localidades não foi encontrado na pasta ./data.\n";
        return 0;
    }    

    num_localidades = (int) vec_local.size(); // obtem o numero de localidades
    Screen *tela = new Screen(vec_local); // criar um objeto tela para apresentar os dados
    tela->showMainMenu(tela); // mostra o menu principal na tela
    
    while(entrada != SAIR){// 2 - Opcao para sair
        // ENTRADA DE DADOS

        // mostra as localidades de origem/destino e os respectivos codigos
        tela->showEntradaDados(quantidade, cod_origem, cod_destino, num_solicitacoes, num_localidades);
        // mostra os dados da solicitacao
        tela->showSolicitacao(cod_origem, cod_destino, quantidade, vec_local);

        // passa os dados da solicitacao para s
        // Solicitacao s(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade); 

        // cria um operador para receber a solicitacao
        Operador operador = Operador(vec_local.size());
        // adiciona a Solicitacao
        operador.addSolicitacao(origem.getCodigoMunicipio(),destino.getCodigoMunicipio(), quantidade);
        // popula a matriz de adjacencias
        operador.popularMatriz();
        // chama o metodo dijkstra para obter a rota
        operador.dijkstra(cod_origem, cod_destino, quantidade, vec_local);

        title = "MENU"; // titulo a ser mostrado na tela
        tela->showTitle(title, "="); // mostra titulo e barra
        tela->showWarning("Digite 1 para criar uma nova solicitacao ou 2 para sair: "); // emite aviso ao usuario

        entrada = -1; // parametro de controle
        
        while (entrada < CONTINUAR || entrada > SAIR){
            // enquanto o usuario nao informar uma entrada valida, o programa entra loop
            // entradas validas:
            //  - 1. para entrar;
            //  - 2. para sair.
            char c ;
            if ( !( std::cin >> entrada) || ( std::cin.get(c) && !std::isspace(c))){// controle de entrada
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limite maximo
                tela->showBar("-"); // mostra barra na tela
                tela->showWarning("ATENCAO! Digite uma opcao valida.\n");
                tela->showWarning("Digite uma opcao do menu: ");
                entrada = -1;
            }else if(entrada < 1 || (entrada > 2)){
                tela->showBar("-"); // mostra barra na tela
                tela->showWarning("ATENCAO! Digite uma opcao valida.\n");
                tela->showWarning("Digite uma opcao do menu: ");            
            }
        }
    }
    std::cout << std::endl;

    // saida do programa
    arq_local.close();
    tela->showWarning("Programa finalizado com sucesso!\n"); 
    delete tela;

    return 1;
}