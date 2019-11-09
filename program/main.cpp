#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include "tools.hpp"
#include "modal.hpp"
#include "solicitacao.hpp"
#include "tools.hpp"
// #include "usuario.hpp"

/*
    EM DESENVOLVIMENTO
*/
int main(){
    std::string linha;
    std::vector <std::string> vec_local; // matriz para armazenar os dados de entrada
    std::vector <std::string> vec_arestas; // matriz para armazenar os dados de entrada
    // std::string nome_usr, senha;
    // Usuario usr = new Usuario(nome, );
    // obtem o nome do arquivo do argumento e abre o arquivo
    std::string caminho = "./data/";
    std::ifstream arq_local(caminho + "localidades.txt");
    std::ifstream arq_arestas(caminho + "arestas.txt");
    int origem, // localidade de origem
        destino; // localidade de destino
    float quantidade; // quantidade a ser transportada
    int spaces = 100; // elemento da tela
    std::string aviso; // elemento da tela
    std::string title; // elemento da tela
    int n_local; // numero de localidades
    if (!arq_local.is_open() || !arq_arestas.is_open()){
        std::cout << "Pasta ou arquivo nao encontrado.\n";
        // return 1;
    }else{
        lerArquivo(arq_arestas, vec_arestas);
        lerArquivo(arq_local, vec_local);
    }  

    // limpando a tela
    n_local = (int) vec_local.size();
    Screen *tela = new Screen(vec_local);
    tela->showMainMenu(tela);
    unsigned int entrada = 1;
    while(entrada == 1){
        /*
        ENTRADA DE DADOS
        */

        title = "ENTRADA DOS DADOS DA SOLICITACAO";
        tela->showTitle(title, spaces, "*");

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

        origem = -1;
        std::cout << "2. Digite o codigo da localidade de origem da carga: ";    
        while (origem < 1 || origem >= n_local){
            char c ;
            if ( !( std::cin >> origem) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! O codigo da localidade de origem deve ser um valor numerico.\n");
                tela->showWarning("2. Digite novamente o codigo da origem: ");
                origem = -1;
            }else if(origem < 1 || (origem >= n_local)){
                aviso = "ATENCAO! O codigo da localidade de origem deve ser um valor positivo, menor que " + 
                                std::to_string(n_local) + ".\n";
                tela->showWarning(aviso);
                tela->showWarning("2. Digite novamente o codigo da origem: ");            
            }
        } 
        tela->showBar("-");

        destino = -1;
        std::cout << "3. Digite o codigo da localidade de destino da carga: ";    
        while (destino < 1 || destino >= n_local){
            char c ;
            if ( !( std::cin >> destino) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! O codigo da localidade de destino deve ser um valor numerico.\n");
                tela->showWarning("3. Digite novamente o codigo da destino: ");
                destino = -1;
            }else if(destino < 1 || (destino >= n_local)){
                aviso = "ATENCAO! O codigo da localidade de destino deve ser um valor positivo, menor que " + 
                                std::to_string(n_local) + ".\n";
                tela->showWarning(aviso);
                tela->showWarning("3. Digite novamente o codigo da destino: ");            
            }
        }
        title = "DADOS DA SOLICITACAO\n";
        tela->showTitle(title, spaces, "*");    

        std::cout << "Origem: " << origem << "\nDestino: " << destino  << "\nQuantidade (toneladas): " << quantidade <<  std::endl;
        title = "RESULTADO DA SOLICITACAO";
        tela->showTitle(title, spaces, "*");
    
        Solicitacao s(origem, destino, quantidade); 
        tela->showWarning("Rota 1: localidade1 -> localidade2 -> localidade3 - preco1 - tempo1\n");
        tela->showWarning("Rota 2: localidade1 -> localidade4 -> localidade3 - preco2 - tempo2\n");
        // std::system("clear");

        title = "MENU";
        tela->showTitle(title, 100, "-");
        tela->showWarning("Digite 1 para criar uma nova solicitacao ou 2 para sair: ");   
        entrada = -1;
        // CONSERTAR LOOP INFINITO QUANO INSERE STRING AO INVES DE INT
        while (entrada != 1 || entrada != 2){
            char c ;
            if ( !( std::cin >> entrada) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                tela->showWarning("ATENCAO! Digite uma opcao valida.\n");
                tela->showWarning("Digite uma opcao do menu: ");
                entrada = -1;
            }else if(entrada != 1 || (entrada != 2)){
                tela->showWarning("ATENCAO! Digite uma opcao valida.\n");
                tela->showWarning("Digite uma opcao do menu: ");            
            }
        }
    }

    std::cout << std::endl;
    arq_local.close();
    arq_arestas.close();
    /*
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
    tela->showWarning("Programa finalizado com sucesso!\n"); 
    delete tela;
    return 1;
}