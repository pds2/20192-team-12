#include <iostream>
#include <iomanip>
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
    std::cout << "Iniciando teste" << std::endl;
    std::string linha;
    std::vector <std::string> vec_local; // matriz para armazenar os dados de entrada
    std::vector <std::string> vec_arestas; // matriz para armazenar os dados de entrada
    // std::string nome_usr, senha;
    // Usuario usr = new Usuario(nome, );
    // obtem o nome do arquivo do argumento e abre o arquivo
    std::string caminho = "./data/";
    std::ifstream arq_local(caminho + "localidades.txt");
    std::ifstream arq_arestas(caminho + "arestas.txt");
    
    float quantidade;
    int origem,
        destino;
    // int teste;
    Tipo tipo;
    // std::cout << "teste: " << (typeid(origem).name() != typeid(teste).name() )<< std::endl;
    std::cout << "string: " << tipo.getTipo(linha)<< std::endl;
    // std::cout << "arquivo: " << tipo.getTipo(arq_local) << std::endl;
    std::cout << "float: " << tipo.getTipo(quantidade) << std::endl;
    std::cout << "int: " << tipo.getTipo(origem) << std::endl;
    // std::string nome, login, senha;
    // Usuario *usr = new Usuario;
    /*

    */
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
    if (!arq_local.is_open() || !arq_arestas.is_open()){
        std::cout << "Pasta ou arquivo nao encontrado.\n";
        // return 1;
    }else{
        lerArquivo(arq_arestas, vec_arestas);
        lerArquivo(arq_local, vec_local);
    }  
    // std::cout << "tamanho: " <<  vec_local.size() << std::endl;
    // std::cout.width(50);
    // limpando a tela
    
    menu(vec_local);// Chamando o menu 

    std::cout << std::endl;
    arq_local.close();
    arq_arestas.close();
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