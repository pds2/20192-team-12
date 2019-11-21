#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cctype>
#include <string> 
#include <vector>
#include "../include/tools.hpp"
#include "../include/modal.hpp"
#include "../include/solicitacao.hpp"
#include "../include/localidade.hpp"

std::string Tipo::getTipo(std::string){
    return "string";
}
std::string Tipo::getTipo(int){
    return "int";
}
std::string Tipo::getTipo(float){
    return "float";
}
std::string Tipo::getTipo(double){
    return "double";
}
std::string Tipo::getTipo(bool){
    return "boolean";
}
std::string Tipo::getTipo(std::ifstream){
    return "ifstream";
}
std::string Tipo::getTipo(std::istream){
    return "istream";
}
std::string getTipo(Ferroviario){
    return "ferroviario";
}
std::string getTipo(Rodoviario){
    return "rodoviario";
}
std::string getTipo(Aquaviario){
    return "aquaviario";
}
std::string getTipo(Aereo){
    return "aereo";
}

Screen::Screen(std::vector <Localidade> &vector){
    this->_vector = vector;
}
Screen::~Screen(){}
void Screen::setBarSize(unsigned int tamanho){
    this->_bar_size = tamanho;
}
void Screen::setPadding(unsigned int padding){
    this->_padding = padding;
}
void Screen::setColumns(unsigned int columns){
    this->_columns = columns;
}
void Screen::setSpaces(unsigned int spaces){
    this->_spaces = spaces;
}

unsigned int Screen::getPadding(){
    return this->_padding;
}
unsigned int Screen::getColumns(){
    return this->_columns;
}
unsigned int Screen::getSpaces(){
    return this->_spaces;
}
void Screen::setVector(std::vector <Localidade> &vector){
    this->_vector = vector;
}


void Screen::showMainMenu(Screen *tela){
    // int padding = 20;
    // int columns = 4;
    // int tamanho = 100;
    // int spaces = 100;
    int entrada = -1;
    std::string title;
    int cls = std::system("clear");
    this->setPadding((unsigned int)this->_spaces + title.size()/2);
    title = "SISTEMA DE ALOCACAO DE DEMANDA POR TRANSPORTES";
    this->showTitle(title, "*");
    title = "MENU";
    this->showTitle(title, "=");
    // this->showWarning( "MENU:\n\n");
    this->showWarning("1. Gerar uma solicitacao de transporte;\n");
    this->showWarning("2. Sair.\n\n");
    this->showWarning("Digite uma opcao do menu: ");   
    entrada = -1;
    while (entrada < 1 || entrada >2){
        char c ;
        if ( !( std::cin >> entrada) || ( std::cin.get(c) && !std::isspace(c))){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            this->showWarning("ATENCAO! Digite uma opcao valida.\n");
            this->showWarning("Digite uma opcao do menu: ");
            entrada = -1;
        }else if(entrada < 1 || (entrada > 2)){
            this->showWarning("ATENCAO! Digite uma opcao valida.\n");
            this->showWarning("Digite uma opcao do menu: ");            
        }
    }
    if ( entrada == 1){
        this->showSubMenu();
    }else{
        
        delete tela;
        this->showWarning("Programa finalizado com sucesso!\n"); 
        exit(1);
        // return;
    }
    // return entrada;
}
// 

void Screen::showSubMenu(){
    std::string title;


    std::cout << "Para gerar uma solicitacao, execute os seguintes passos:\n\n";
    std::cout << "1. Digite o numero da localidade de origem;\n";
    std::cout << "2. Digite o numero da localidade de destino e a quantidade ser transportada;\n";
    std::cout << "3. Digite a quantidade de carga a ser transportada; e\n";
    std::cout << "4. Tecle ENTER.\n";
    
    title = "LOCALIDADES";
    this->showTitle(title, "-");
    // this->showBar("-");
    // std::cout << "LOCALIDADES:\n";
    // this->showBar("-");

    this->showVector(this->_columns);
    // std::cout << std::endl;
}
void Screen::showEntradaDados(float &quantidade, int &cod_origem, int &cod_destino, int &num_solicitacoes, int num_localidades){
        std::string aviso;
        std::string title = "SOLICITACOES";
        this->showTitle(title, "*");
        title = "SOLICITACAO Nº " + std::to_string(++num_solicitacoes);
        this->showTitle(title, "=");

        quantidade = -1;
        this->showWarning("1. Digite a quantidade da carga em toneladas: ");
        while (quantidade < 1){
            char c ;
            if ( !( std::cin >> quantidade) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                this->showWarning("ATENCAO! A quantidade deve ser um valor numerico.\n");
                this->showWarning("1. Digite novamente a quantidade da carga em toneladas: ");
                quantidade = -1;
            }else if(quantidade < 1){
                this->showWarning("ATENCAO! A quantidade deve ser um valor positivo.\n");
                this->showWarning("1. Digite novamente a quantidade da carga em toneladas: ");            
            }
        }
        this->showBar("-");

        cod_origem = -1;
        std::cout << "2. Digite o codigo da localidade de origem da carga: ";    
        while (cod_origem < 1 ||cod_origem >= num_localidades){
            char c ;
            if ( !( std::cin >> cod_origem) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                this->showWarning("ATENCAO! O codigo da localidade de origem deve ser um valor numerico.\n");
                this->showWarning("2. Digite novamente o codigo da origem: ");
                cod_origem = -1;
            }else if(cod_origem < 1 || (cod_origem >= num_localidades)){
                aviso = "ATENCAO! O codigo da localidade de origem deve ser um valor positivo, menor que " + 
                                std::to_string(num_localidades) + ".\n";
                this->showWarning(aviso);
                this->showWarning("2. Digite novamente o codigo da origem: ");            
            }
        } 
        this->showBar("-");

        cod_destino = -1;
        std::cout << "3. Digite o codigo da localidade de destino da carga: ";    
        while (cod_destino < 1 || cod_destino >= num_localidades){
            char c ;
            if ( !( std::cin >> cod_destino) || ( std::cin.get(c) && !std::isspace(c))){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                this->showWarning("ATENCAO! O codigo da localidade de destino deve ser um valor numerico.\n");
                this->showWarning("3. Digite novamente o codigo da destino: ");
                cod_destino = -1;
            }else if(cod_destino < 1 || (cod_destino >= num_localidades)){
                aviso = "ATENCAO! O codigo da localidade de destino deve ser um valor positivo, menor que " + 
                                std::to_string(num_localidades) + ".\n";
                this->showWarning(aviso);
                this->showWarning("3. Digite novamente o codigo da destino: ");            
            }
        }    
}
void Screen::showSolicitacao(int cod_origem, int cod_destino, float quantidade, std::vector <Localidade> vec_local){
    std::string title = "DADOS DA SOLICITACAO\n";
    this->showTitle(title, "-");    
    Localidade origem = searchMunicipio(cod_origem, vec_local);
    Localidade destino = searchMunicipio(cod_destino, vec_local);
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
    this->showTitle(title, "-");
}
std::string Screen::formattString(std::string texto){
    return "\x1B[0;37m" + texto + "\033[0m";
}
void Screen::showWarning(std::string aviso){
    // std::string formatted_warning = formattString(aviso); //"\x1B[0;37m" + aviso + "\033[0m";
    // std::cout << formatted_warning;
    // std::cout << formattString(aviso);
    std::cout << aviso;
}
void Screen::showTitle(std::string title, std::string symbol){
    std::cout << std::endl;
    int desloc = (this->_spaces + title.size())/2;
    // int padding = (this->_spaces + title.size())/2;
    this->showBar(symbol);
    // std::cout << std::internal << title << std::endl;
    // std::string formatted_title = formattString(title); //"\x1B[0;37m" + title + "\033[0m";
    // std::cout << std::setw(desloc) << std::internal << formattString(title) << std::endl;
    std::cout << std::setw(desloc) << std::internal << title << std::endl;
    // std::cout << std::setw(spaces) << std::right << title << std::endl;
    this->showBar(symbol);
    std::cout << std::endl;
}

void Screen::showBar(std::string simbolo){
    std::string barra = "";
    for (unsigned int i = 0; i < this->_bar_size; i++){
        barra += simbolo;
    }
    // std::string formatted_bar = formattString(barra); //"\x1B[0;37m" + barra + "\033[0m";
    std::cout << barra << std::endl;
    // std::cout << formattString(barra) << std::endl;
}
void Screen::showVector(int columns){
    this->_padding = 20;
    int rows = (int) this->_vector.size();    
    for (int i = 0; i < rows; i++){
        
        std::cout << std::setw(2) << std::right 
                  << std::to_string(this->_vector[i].getCodigoMunicipio())<< " - "
                  << std::setw(this->_padding) << std::left
                  << this->_vector[i].getMunicipio();
        if((i + 1) % columns == 0){
            std::cout << std::endl;
        }
    }    
}
void lerArquivo(std::istream &arquivo, std::vector <std::string> &vector){
    std::string linha;   
    std::string entrada;
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);
    int counter = 0;
    int rows = 0, columns = 0;
    while(!arquivo.eof()){
        getline(arquivo, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            // std::cout << entrada.substr(0,1)<< " " << entrada << " ";
            if (counter == 0){
                rows = std::stoi(entrada);
            }
            if (counter == 1){
                columns = std::stoi(entrada);
                std::cout << std::endl;
            }
            if (counter != 0 && counter != 1){
                std::string str;
                if (entrada.substr(0,1) == "|"){
                    str = "";
                    int espacos = 0;
                    while (entrada.substr(entrada.size() - 1, 1) != "|"){
                        str = str + entrada + " ";
                        espacos++;
                        iss_linha >> entrada;
                    }
                    str = str + entrada;
                    str = str.substr(1, str.size() - 2);
                    // std::cout << str << std::endl;

                    entrada = str;
                    if ((counter - 2) % columns == 1) {
                            vector.push_back(entrada);
                    }
                }
                // if (entrada.substr(entrada.size() - 1, 1) == "|"){
                // std::cout << " " << entrada;

                // }                
                if( (counter - 2) % columns == (columns - 1)){
                    // std::cout << std::endl;
                }
            }            
            counter++;
        }
    }    
}
void lerLocalidades(std::istream &arquivo, std::vector  <Localidade> &vector){
    std::string linha;   
    std::string entrada;
    arquivo.clear();
    arquivo.seekg(0, std::ios::beg);
    int counter = 0;
    int rows = 0,
        column = 0,
        columns = 0;
    Localidade local;

    while(!arquivo.eof()){
        getline(arquivo, linha);
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            // std::cout << entrada.substr(0,1)<< " " << entrada << " ";
            if (counter == 0){
                rows = std::stoi(entrada);
            }
            if (counter == 1){
                columns = std::stoi(entrada);
                std::cout << std::endl;
            }
            if (counter != 0 && counter != 1){
                std::string str;
                if (entrada.substr(0,1) == "|"){
                    str = "";
                    int espacos = 0;
                    while (entrada.substr(entrada.size() - 1, 1) != "|"){
                        str = str + entrada + " ";
                        espacos++;
                        iss_linha >> entrada;
                    }
                    str = str + entrada;
                    str = str.substr(1, str.size() - 2);
                    // std::cout << str << std::endl;

                    entrada = str;
                }
                column = (counter - 2) % columns;
                // std::cout << "column: " << column << " " << entrada << "\n";
                if (column == 0){
                    local.setCodigoMunicipio(std::stoi(entrada));
                }
                if (column == 1){
                    local.setMunicipio(entrada);
                }
                if (column == 2){
                    local.setEstado(entrada);
                }
                if (column == 3){
                    local.setPais(entrada);
                }
                if (column == 4){
                    local.setLat(std::stof(entrada));
                }
                if (column == 5){
                    local.setLong(std::stof(entrada));
                    vector.push_back(local);   
                }               
            }
            counter++;
        }
    }

    // for (int i = 0; i < vector.size(); i++){
    //     std::cout << vector[i].getCodigoMunicipio() << " "
    //               << vector[i].getMunicipio() << " "
    //               << vector[i].getEstado() << " "
    //               << vector[i].getPais() << " "
    //               << vector[i].getLat() << " "
    //               << vector[i].getLong() << "\n";

    // }
}
Localidade searchMunicipio(int codigo, std::vector  <Localidade> &vector){
    Localidade local_pivot;
    for( auto v: vector){
        if ( v.getCodigoMunicipio() == codigo){
            local_pivot = v;
            break;
        }
    }
    return local_pivot;
}
// EXCLUIR
// void Screen::showMenu(){
//     int padding = 20;
//     int columns = 4;
//     // int tamanho = 100;
//     int spaces = 100;
//     std::string title;
//     std::system("clear");
//     title = "SISTEMA DE ALOCACAO DE DEMANDA POR TRANSPORTES";
//     this->showTitle(title, 100, "*");
//     // this->showBar("*");
//     // std::cout << std::setw(spaces/2) << std::right << "SISTEMA DE ALOCACAO DE DEMANDA POR TRANSPORTES\n";
//     // this->showBar("*");

//     std::cout << "Para gerar uma solicitacao, execute os seguintes passos:\n\n";
//     std::cout << "1. Digite o numero da localidade de origem;\n";
//     std::cout << "2. Digite o numero da localidade de destino e a quantidade ser transportada;\n";
//     std::cout << "3. Digite a quantidade de carga a ser transportada; e\n";
//     std::cout << "4. Tecle ENTER.\n";
    
//     title = "LOCALIDADES";
//     this->showTitle(title, 100, "-");
//     // this->showBar("-");
//     // std::cout << "LOCALIDADES:\n";
//     // this->showBar("-");

//     this->showVector(columns, padding);
//     // std::cout << std::endl;
// }
// void menu(std::vector <std::string> &vector){
//     int origem, // localidade de origem
//         destino; // localidade de destino
//     float quantidade; // quantidade a ser transportada
//     int padding = 20;
//     int columns = 4;
//     // int tamanho = 100;
//     int spaces = 40;

//     int rows = (int) vector.size();
//     Screen *tela = new Screen(vector);
//     // Tipo tipo;
//     std::system("clear");
//     this->showBar("*");
//     std::cout << std::setw(spaces/2) << std::right << "SISTEMA DE ALOCACAO DE DEMANDA POR TRANSPORTES\n";
//     this->showBar("*");

//     std::cout << "Para gerar uma solicitacao, execute os seguintes passos:\n\n";
//     std::cout << "1. Digite o numero da localidade de origem;\n";
//     std::cout << "2. Digite o numero da localidade de destino e a quantidade ser transportada;\n";
//     std::cout << "3. Digite a quantidade de carga a ser transportada; e\n";
//     std::cout << "4. Tecle ENTER.\n";
    
//     this->showBar("-");
//     std::cout << "LOCALIDADES:\n";
//     this->showBar("-");

//     this->showVector(vector, columns, padding);
   
//     /*
//     for (int i = 0; i < rows; i++){
//         std::cout << std::setw(2) << std::right << i << " - " << std::setw(padding) << std::left << vector[i];
//         if((i + 1) % columns == 0){
//             std::cout << std::endl;
//         }
//     }
//     */
//     std::cout << std::endl;
//     /*
//     ENTRADA DE DADOS
//     */
//     this->showBar("*");
//     std::cout << std::setw(spaces) << std::right << "ENTRADA DOS DADOS DA SOLICITACAO\n";
//     this->showBar("*");

//     quantidade = -1;
//     std::cout << "1. Digite a quantidade da carga em toneladas: ";
//     while (quantidade < 1){
//         char c ;
//         if ( !( std::cin >> quantidade) || ( std::cin.get(c) && !std::isspace(c))){
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "ATENCAO! A quantidade deve ser um valor numerico.\n";
//             std::cout << "1. Digite novamente a quantidade da carga em toneladas: ";
//             quantidade = -1;
//         }else if(quantidade < 1){
//             std::cout << "ATENCAO! A quantidade deve ser um valor positivo.\n";
//             std::cout << "1. Digite novamente a quantidade da carga em toneladas: ";            
//         }
//     }
//     this->showBar("-");

//     origem = -1;
//     std::cout << "2. Digite o codigo da localidade de origem da carga: ";    
//     while (origem < 1 || origem >= rows){
//         char c ;
//         if ( !( std::cin >> origem) || ( std::cin.get(c) && !std::isspace(c))){
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "ATENCAO! O codigo da localidade de origem deve ser um valor numerico.\n";
//             std::cout << "2. Digite novamente o codigo da origem: ";
//             origem = -1;
//         }else if(origem < 1 || (origem >= rows)){
//             std::cout << "ATENCAO! O codigo da localidade de origem deve ser um valor positivo, menor que " + 
//                             std::to_string(rows) + ".\n";
//             std::cout << "2. Digite novamente o codigo da origem: ";            
//         }
//     } 
//     this->showBar("-");

//     destino = -1;
//     std::cout << "3. Digite o codigo da localidade de destino da carga: ";    
//     while (destino < 1 || destino >= rows){
//         char c ;
//         if ( !( std::cin >> destino) || ( std::cin.get(c) && !std::isspace(c))){
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             std::cout << "ATENCAO! O codigo da localidade de destino deve ser um valor numerico.\n";
//             std::cout << "3. Digite novamente o codigo da destino: ";
//             destino = -1;
//         }else if(destino < 1 || (destino >= rows)){
//             std::cout << "ATENCAO! O codigo da localidade de destino deve ser um valor positivo, menor que " + 
//                             std::to_string(rows) + ".\n";
//             std::cout << "3. Digite novamente o codigo da destino: ";            
//         }
//     } 
//     this->showBar("*");
//     std::cout << std::setw(spaces) << std::right << "DADOS DA SOLICITACAO\n";
//     this->showBar("*");

//     std::cout << "Origem: " << origem << "\nDestino: " << destino  << "\nQuantidade (toneladas): " << quantidade <<  std::endl;

//     this->showBar("*");
//     std::cout << std::setw(spaces) << std::right << "RESULTADO DA SOLICITACAO\n";
//     this->showBar("*");

//     std::cout << "Rota 1: localidade1 -> localidade2 -> localidade3 - preco1 - tempo1" << std::endl;   
//     std::cout << "Rota 2: localidade1 -> localidade4 -> localidade3 - preco2 - tempo2" << std::endl;
//     Solicitacao s(origem, destino, quantidade); 
//     delete tela;   
// }
// void Screen::showContinueMenu(Screen *tela){
//     int padding = 20;
//     int columns = 4;
//     // int tamanho = 100;
//     int spaces = 100;
//     int entrada = -1;
//     std::string title;
//     std::system("clear");

//     title = "MENU";
//     this->showTitle(title, 100, "=");
//     this->showWarning("Digite 1 para criar uma nova solicitacao ou 2 para sair");   
//     entrada = -1;
//     while (entrada < 1 || entrada >2){
//         char c ;
//         if ( !( std::cin >> entrada) || ( std::cin.get(c) && !std::isspace(c))){
//             std::cin.clear();
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//             this->showWarning("ATENCAO! Digite uma opcao valida.\n");
//             this->showWarning("Digite uma opcao do menu: ");
//             entrada = -1;
//         }else if(entrada < 1 || (entrada > 2)){
//             this->showWarning("ATENCAO! Digite uma opcao valida.\n");
//             this->showWarning("Digite uma opcao do menu: ");            
//         }
//     }
//     if ( entrada == 1){
//         this->showSubMenu();

//     }else{
//         delete tela;
//         this->showWarning("Programa finalizado com sucesso!\n"); 
//         exit(1);
//         // return;
//     }
// }