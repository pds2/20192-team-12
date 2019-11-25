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
// #include "usuario.hpp"
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
/*  
    ------EM DESENVOLVIMENTO
    FAZER:
    1. INCLUIR TESTES DOS MODULOS:
        - LOCALIDADES; em andamento
        - TOOLS;
        - OPERADOR;
    2. INCLUIR SAIDA DO MODULO OPERADOR NA TELA

    3. REFATORAR:
        - INCLUIR CONSTANTES NO LUGAR DE NUMEROS MÁGICOS (valores default de preço, modal, etc)    
        - EXCLUIR REPETICOES;
        - BAD SMELLS;
    4. COMENTAR CODIGO;
    5. LIMPAR CODIGO;
    6. DOCUMENTACAO;
    7. FAZER INTERFACE GRAFICA, SE DER TEMPO.

*/
int main(){
    std::string linha;
    std::vector <Localidade> vec_local; // vetor para armazenar os dados de entrada
    // std::vector <std::string> vec_arestas; // matriz para armazenar os dados de entrada

    // obtem o nome do arquivo do argumento e abre o arquivo
    std::string caminho = "./data/";
    std::ifstream arq_local(caminho + "localidades.txt");
    int cod_origem, // codigo da localidade de origem
        cod_destino; // codigo da localidade de destino
    Localidade origem,  // localidade de origem
               destino;  // localidade de destino
    float quantidade; // quantidade a ser transportada
    // int spaces = 100; // elemento da tela
    std::string aviso; // elemento da tela
    std::string title; // elemento da tela
    int num_localidades; // numero de localidades
    int num_solicitacoes = 0; // numero de solicitacoes realizadas
    int entrada = 1; // verifica entrada
    // if (!arq_local.is_open() || !arq_arestas.is_open()){
    if (!arq_local.is_open()){
        std::cout << "Pasta ou arquivo nao encontrado.\n";
        return 0;
        // return 1;
    }else{
        // lerArquivo(arq_arestas, vec_arestas);
        // lerArquivo(arq_local, vec_local2);
        lerArquivoLocalidades(arq_local, vec_local);
    }  
    num_localidades = (int) vec_local.size();
    Screen *tela = new Screen(vec_local);
    tela->showMainMenu(tela);

    // INICIO BLOCO
    // limpando a tela
    
    while(entrada != 2){
        /*
        ENTRADA DE DADOS
        */
        tela->showEntradaDados(quantidade, cod_origem, cod_destino, num_solicitacoes, num_localidades);
        tela->showSolicitacao(cod_origem, cod_destino, quantidade, vec_local);
        Solicitacao s(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade); 
        Operador operador = Operador(vec_local.size());
        operador.addSolicitacao(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade);
        operador.popularMatriz();
        operador.dijkstra(cod_origem, cod_destino, quantidade);
        

        // operador.addSolicitacao()
        tela->showWarning("Rota 1: localidade1 -> localidade2 -> localidade3 - preco1 - tempo1\n");
        tela->showWarning("Rota 2: localidade1 -> localidade4 -> localidade3 - preco2 - tempo2\n");

        title = "MENU";
        tela->showTitle(title, "=");
        tela->showWarning("Digite 1 para criar uma nova solicitacao ou 2 para sair: ");   
        entrada = -1;
        // CONSERTAR LOOP INFINITO QUANO INSERE STRING AO INVES DE INT
        while (entrada < 1 || entrada > 2){
            char c ;
            if ( !( std::cin >> entrada) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! Digite uma opcao valida.\n");
                tela->showWarning("Digite uma opcao do menu: ");
                entrada = -1;
            }else if(entrada < 1 || (entrada > 2)){
                tela->showWarning("ATENCAO! Digite uma opcao valida.\n");
                tela->showWarning("Digite uma opcao do menu: ");            
            }
            // if (entrada == 2){
            //     break;
            // }
        }
    }

    std::cout << std::endl;
    arq_local.close();
    // arq_arestas.close();

    tela->showWarning("Programa finalizado com sucesso!\n"); 
    delete tela;
    return 1;
}