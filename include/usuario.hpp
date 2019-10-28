#include <iostream>
class Usuario {
    private:
        std::string _nome_usr;
        std::string _login;
        std::string _senha;
    public:
        Usuario(): Usuario("nome", "login", "123456"){}
        Usuario(std::string nome_usr, std::string login, std::string senha): _nome_usr(nome_usr),
                                                                             _login(login),
                                                                             _senha(senha){}
        ~Usuario();
        void setNome(std::string nome);
        void setLogin(std::string login);
        void setSenha(std::string senha);
        std::string getNome();
        std::string getLogin();
        void cadastraUsuario(std::string nome, std::string login, std::string senha);
        void verificaUsuario(std::string login, std::string senha);
        
};