#include <iostream>
#include <stdexcept>
#include <fstream>
#include "../include/usuario.hpp"

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
void Usuario::cadastraUsuario(std::string nome, std::string login, std::string senha){
    /*
    escreve os dados do usuario no arquivo
    abre arquivo
    insere os dados do usuario
    */
   try {
    std::cout << "Cadastro realizado com Sucesso" << std::endl;
   }catch (std::exception &e) {
    std::cout << e.what();
   }
}
void Usuario::verificaUsuario(std::string login, std::string senha){
    /*
    abre arquivo
    procura usuario
    verifica senha 
    */
}