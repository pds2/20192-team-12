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
        - LOCALIDADES;
        - TOOLS;
        - OPERADOR;
    2. INCLUIR SAIDA DO MODULO OPERADOR NA TELA

    3. REFATORAR:
        - EXCLUIR REPETICOES;
        - BAD SMELLS;
    4. COMENTAR CODIGO;
    5. LIMPAR CODIGO;
    6. FAZER INTERFACE GRAFICA, SE DER TEMPO.

*/
int main(){
    std::string linha;
    std::vector <std::string> vec_local2; // matriz para armazenar os dados de entrada
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
        lerArquivo(arq_local, vec_local2);
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

        title = "SOLICITACOES";
        tela->showTitle(title, "*");
        title = "SOLICITACAO Nº " + std::to_string(++num_solicitacoes);
        tela->showTitle(title, "=");

        quantidade = -1;
        tela->showWarning("1. Digite a quantidade da carga em toneladas: ");
        while (quantidade < 1){
            char c ;
            if ( !( std::cin >> quantidade) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! A quantidade deve ser um valor numerico.\n");
                tela->showWarning("1. Digite novamente a quantidade da carga em toneladas: ");
                quantidade = -1;
            }else if(quantidade < 1){
                tela->showWarning("ATENCAO! A quantidade deve ser um valor positivo.\n");
                tela->showWarning("1. Digite novamente a quantidade da carga em toneladas: ");            
            }
        }
        tela->showBar("-");

        cod_origem = -1;
        std::cout << "2. Digite o codigo da localidade de origem da carga: ";    
        while (cod_origem < 1 ||cod_origem >= num_localidades){
            char c ;
            if ( !( std::cin >> cod_origem) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! O codigo da localidade de origem deve ser um valor numerico.\n");
                tela->showWarning("2. Digite novamente o codigo da origem: ");
                cod_origem = -1;
            }else if(cod_origem < 1 || (cod_origem >= num_localidades)){
                aviso = "ATENCAO! O codigo da localidade de origem deve ser um valor positivo, menor que " + 
                                std::to_string(num_localidades) + ".\n";
                tela->showWarning(aviso);
                tela->showWarning("2. Digite novamente o codigo da origem: ");            
            }
        } 
        tela->showBar("-");

        cod_destino = -1;
        std::cout << "3. Digite o codigo da localidade de destino da carga: ";    
        while (cod_destino < 1 || cod_destino >= num_localidades){
            char c ;
            if ( !( std::cin >> cod_destino) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! O codigo da localidade de destino deve ser um valor numerico.\n");
                tela->showWarning("3. Digite novamente o codigo da destino: ");
                cod_destino = -1;
            }else if(cod_destino < 1 || (cod_destino >= num_localidades)){
                aviso = "ATENCAO! O codigo da localidade de destino deve ser um valor positivo, menor que " + 
                                std::to_string(num_localidades) + ".\n";
                tela->showWarning(aviso);
                tela->showWarning("3. Digite novamente o codigo da destino: ");            
            }
        }
        title = "DADOS DA SOLICITACAO\n";
        tela->showTitle(title, "-");    
        origem = searchMunicipio(cod_origem, vec_local);
        destino = searchMunicipio(cod_destino, vec_local);
        std::cout << "Origem: " << origem.getCodigoMunicipio() << " - "
                  << origem.getMunicipio() << "/" 
                  << origem.getEstado() << " - "
                  << origem.getPais()
                  << "\nDestino: " << destino.getCodigoMunicipio() << " - "
                  << destino.getMunicipio() << "/" 
                  << destino.getEstado() << " - "
                  << destino.getPais()
                  << "\nQuantidade (toneladas): " << quantidade <<  std::endl;
        title = "RESULTADO DA SOLICITACAO";
        tela->showTitle(title, "-");
    
        Solicitacao s(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade); 
        Operador operador = Operador();
        operador.addSolicitacao(origem.getCodigoMunicipio(), destino.getCodigoMunicipio(), quantidade);
        
        tela->showWarning("Rota 1: localidade1 -> localidade2 -> localidade3 - preco1 - tempo1\n");
        tela->showWarning("Rota 2: localidade1 -> localidade4 -> localidade3 - preco2 - tempo2\n");
        // std::system("clear");

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