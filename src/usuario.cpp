#include <iostream>
#include <stdexcept>
#include <fstream>
#include "usuario.hpp"

void Usuario::setNome(std::string nome){
    this->_nome_usr = nome;
}
void Usuario::setLogin(std::string login){
    this->_login = login;
}
void Usuario::setSenha(std::string senha){
    this->_senha = senha;
}
std::string Usuario::getNome(){
    return this->_nome_usr;
}
std::string Usuario::getLogin(){
    return this->_login;
}
void Usuario::verificarUsuario(std::string login, std::string senha){
    /*
    abre arquivo
    procura usuario
    verifica senha 
    */
}
void Usuario::cadastrarUsuario() {
    /*
    escreve os dados do usuario no arquivo
    abre arquivo
    insere os dados do usuario
    */
    std::ofstream arquivo;
    std::string caminho = "./data/";
    arquivo.open(caminho + "usuarios.txt");
    /*
    try {
        std::cout << "Cadastro realizado com Sucesso" << std::endl;
    }catch (std::exception &e) {
        throw ArquivoNaoExiste();
        // std::cout << e.what();
    }
    */
    if(arquivo.is_open()){
        arquivo << this->_nome_usr << " " << this->_login << " " <<  this->_senha << "\n";
        arquivo.close();
    }else{
        std::cout << "Pasta ou arquivo nao encontrado!";
    }
}
const char* ArquivoNaoExiste::what() const noexcept {
return "Pasta ou arquivo nao encontrado!";
}
/*
void escreverArquivo(){
    Usuario dados = {"Joao Santos", "123456789", "01/01/1900"}, dados2;
    
    //Escrita no arquivo:
    ofstream arquivo_s;
    arquivo_s.open("exemplo.txt");
    
    if(arquivo_s.is_open()){
        arquivo_s << dados.nome << "\n";
        arquivo_s << dados.cpf << "\n";
        arquivo_s << dados.data << "\n";
        arquivo_s.close();
    }
    else {
        cout << "Nao foi possivel abrir o arquivo.\n";
        return EXIT_FAILURE;
    }
    
    //Leitura do arquivo:
    ifstream arquivo_e;
    arquivo_e.open("exemplo.txt");
    
    if(arquivo_e.is_open()){
        getline(arquivo_e, dados2.nome);
        getline(arquivo_e, dados2.cpf);
        getline(arquivo_e, dados2.data);
        arquivo_e.close();
    }
    else {
        cout << "Nao foi possivel abrir o arquivo.\n";
        return EXIT_FAILURE;
    }
    
    cout << dados2.nome << "\n";
    cout << dados2.cpf << "\n";
    cout << dados2.data << endl;
    
    return 0;
}
*/