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

/*  
    ------EM DESENVOLVIMENTO
    FAZER:
    1. INCLUIR TESTES DOS MODULOS:
        - LOCALIDADES; em andamento
        - TOOLS;
        - OPERADOR;
    2. INCLUIR SAIDA DO MODULO OPERADOR NA TELA

    3. REFATORAR:
        - EXCLUIR REPETICOES;
        - BAD SMELLS;
    4. COMENTAR CODIGO;
    5. LIMPAR CODIGO;
    6. DOCUMENTACAO;
    7. FAZER INTERFACE GRAFICA, SE DER TEMPO.

*/
int main(){
    std::string linha;
    // std::vector <std::string> vec_local2; // matriz para armazenar os dados de entrada
    std::vector <Localidade> vec_local; // matriz para armazenar os dados de entrada
    std::vector <std::string> vec_arestas; // matriz para armazenar os dados de entrada
    // std::string nome_usr, senha;
    // Usuario usr = new Usuario(nome, );
    // obtem o nome do arquivo do argumento e abre o arquivo
    std::string caminho = "./data/";
    std::ifstream arq_local(caminho + "localidades.txt");
    std::ifstream arq_arestas(caminho + "arestas.txt");
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
    if (!arq_local.is_open() || !arq_arestas.is_open()){
        std::cout << "Pasta ou arquivo nao encontrado.\n";
        // return 1;
    }else{
        lerArquivo(arq_arestas, vec_arestas);
        // lerArquivo(arq_local, vec_local2);
        lerLocalidades(arq_local, vec_local);
    }  

    // INICIO BLOCO
    // limpando a tela
    num_localidades = (int) vec_local.size();
    Screen *tela = new Screen(vec_local);
    tela->showMainMenu(tela);
    
    while(entrada != 2){
        /*
        ENTRADA DE DADOS
        */
        tela->showEntradaDados(quantidade, cod_origem, cod_destino, num_solicitacoes, num_localidades);
        tela->showSolicitacao(cod_origem, cod_destino, quantidade, vec_local);
        Solicitacao s(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade); 
        Operador operador = Operador();
        operador.addSolicitacao(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade);
        
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
    arq_arestas.close();

    tela->showWarning("Programa finalizado com sucesso!\n"); 
    delete tela;

    // FIM BLOCO

    /*
    EXCLUIR????
    | | | | |
    V V V V V
    ENTRADA DO USUARIO
    std::cout << "Digite o login do usuario: ";
    std::cout << std::endl;
    std::cout << "Digite a senha: ";
    std::cin >> senha;
    std::cout << std::endl;
    usr->setNome(nome);
    usr->setLogin(login);
    usr->setSenha(senha);
    usr->cadastrarUsuario();
    std::cout << (caminho + "localidades.txt") << std::endl;
    std::cout << (caminho + "arestas.txt") << std::endl;
    */
    /*
        LEITURA DOS ARQUIVOS
    */     
    // std::ofstream file;
    // file.open(caminho + "localidades.txt");
    // file.seekp (0, file.end);
    // std::string str = std::to_string(41) + "|TESTE|" + "AUS" + "|AUSTRALIA|" +  std::to_string(-33.875935) +  std::to_string(151.251827)+"\n";
    // file <<  str;


        // Rodoviario *r = new Rodoviario();
        // std::cout << "Pedagio: " << r->getValorPedagio() << "\n";
        // // delete r;
    // delete usr;
    // std::cout << vec_local.size() << "\n";
    // for (unsigned int i = 0; i < vec_local.size(); i++){
    //     std::cout << vec_local[i] << "\n";
    // }

    return 1;
}