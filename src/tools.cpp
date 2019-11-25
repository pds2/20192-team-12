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

Screen::Screen(std::vector <Localidade> &vector){
    /**
     * Construtor da classe Screen\n
     * Argumentos:
     *  - vector: vector para armazenamento das localidades;
    */ 
    this->_vector = vector;
}
Screen::~Screen(){
    /** Destrutor da classe Screen
    */
}

void Screen::setPadding(unsigned int padding){
    /** Atribui o valor do tamanho do padding.\n
     *  Argumento:
     *      - tamanho: tamanho da padding em número de caracteres;
     * .
     *  Exceção:
     *      - o valor deve ser maior que zero;
    */     
    this->_padding = padding;
}

void Screen::showMainMenu(Screen *tela){
    /**
     * O método showMainMenu mostra o menu inicial do sistema.\n
     * Argumento:
     *  - tela: objeto do tipo Screen
     * .
     * Exceções:
     *   - argumento vazio
    */
    int entrada; // variável de entrada para controle
    std::string titulo; // título do menu
    // estabelece os espaços para centralizar o título
    this->setPadding((unsigned int)this->_spaces + titulo.size()/2); 
    titulo = "SISTEMA DE ALOCACAO DE DEMANDA POR TRANSPORTES";
    this->showTitle(titulo, "*"); // mostra na tela o título principal
    titulo = "MENU";
    this->showTitle(titulo, "="); // mostra na tela o título secundário 
    this->showWarning("1. Gerar uma solicitacao de transporte;\n"); // mostra um aviso na tela
    this->showWarning("2. Sair.\n\n"); // mostra um aviso na tela
    this->showWarning("Digite uma opcao do menu: "); // mostra um aviso na tela   
    entrada = -1;
    while (entrada < 1 || entrada >2){
        // Escolhe as opções do Menu
        char c ;
        // verifica se as entradas sao validas
        if (!(std::cin >> entrada) || (std::cin.get(c) && !std::isspace(c))){
            // Checa se o argumento contém espaços em branco
            std::cin.clear();// limpa terminal
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // limite máximo de inteiros
            this->showWarning("ATENCAO! Digite uma opcao valida.\n");// mostra um aviso na tela 
            this->showWarning("Digite uma opcao do menu: ");// mostra um aviso na tela 
            entrada = -1;
        }else if(entrada < 1 || (entrada > 2)){
            // somente os numeros 1 e 2 sao validos
            this->showWarning("ATENCAO! Digite uma opcao valida.\n");// mostra um aviso na tela 
            this->showWarning("Digite uma opcao do menu: ");   // mostra um aviso na tela          
        }
    }
    if (entrada == 1){
        // opcao 1: mostra o submenu com as localidades
        this->showSubMenu();
        
    }else{
        // opcao 2: finaliza o programa
        delete tela;
        this->showWarning("Programa finalizado com sucesso!\n"); // mostra um aviso na tela 
        exit(1); // sai do progrma
    }
    // return entrada;
}
// 

void Screen::showSubMenu(){
    /**
     * O método showSubMenu mostra o submenu com as opções de entrada de dados.\n
     * Sem argumento.
    */
    std::string titulo; // texto do titulo
    std::cout << "Para gerar uma solicitacao, execute os seguintes passos:\n\n";
    std::cout << "1. Digite o numero da localidade de origem;\n";
    std::cout << "2. Digite o numero da localidade de destino e a quantidade ser transportada;\n";
    std::cout << "3. Digite a quantidade de carga a ser transportada; e\n";
    std::cout << "4. Tecle ENTER.\n";
    
    titulo = "LOCALIDADES";
    this->showTitle(titulo, "-"); // mostra um titulo
    this->showVector(this->_columns); // mostra as localidades
}
void Screen::showEntradaDados(float &quantidade,
                              int &cod_origem,
                              int &cod_destino,
                              int &num_solicitacoes,
                              int num_localidades){
    /**
     * O método showEntradaDados mostra as solicitações de transporte e as opções de entrada de dados
     * do sistema.\n
     * Argumentos:
        - quantidade: quantidade de carga a ser transportada;
        - cod_origem: código do município de origem;
        - cod_destino: código do município de destino;
        - num_solicitacoes: número corrente de solicitações; e
        - num_localidades: número total de localidades carregadas para controle
     * .
     * Exceções:
     *   - os valores de quantidade, número de solicitações e número de localidades deve ser maior que zero;
     *   - os valores dos códigos dos municípios de origem e destino não podem ser negativos;
    */
    std::string aviso;
    std::string titulo = "SOLICITACOES";
    this->showTitle(titulo, "*");
    titulo = "SOLICITACAO Nº " + std::to_string(++num_solicitacoes);
    this->showTitle(titulo, "=");

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
    while (cod_origem < 0 ||cod_origem >= num_localidades){
        char c ;
        if ( !( std::cin >> cod_origem) || ( std::cin.get(c) && !std::isspace(c))){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            this->showWarning("ATENCAO! O codigo da localidade de origem deve ser um valor numerico.\n");
            this->showWarning("2. Digite novamente o codigo da origem: ");
            cod_origem = -1;
        }else if(cod_origem < 0 || (cod_origem >= num_localidades)){
            aviso = "ATENCAO! O codigo da localidade de origem deve ser um valor positivo, menor que " + 
                            std::to_string(num_localidades) + ".\n";
            this->showWarning(aviso);
            this->showWarning("2. Digite novamente o codigo da origem: ");            
        }
    } 
    this->showBar("-");

    cod_destino = -1;
    std::cout << "3. Digite o codigo da localidade de destino da carga: ";    
    while (cod_destino < 0 || cod_destino >= num_localidades){
        char c ;
        if ( !( std::cin >> cod_destino) || ( std::cin.get(c) && !std::isspace(c))){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            this->showWarning("ATENCAO! O codigo da localidade de destino deve ser um valor numerico.\n");
            this->showWarning("3. Digite novamente o codigo da destino: ");
            cod_destino = -1;
        }else if(cod_destino < 0 || (cod_destino >= num_localidades)){
            aviso = "ATENCAO! O codigo da localidade de destino deve ser um valor positivo, menor que " + 
                            std::to_string(num_localidades) + ".\n";
            this->showWarning(aviso);
            this->showWarning("3. Digite novamente o codigo da destino: ");            
        }
    }    
}
void Screen::showSolicitacao(int cod_origem,
                             int cod_destino,
                             float quantidade,
                             std::vector <Localidade> vec_local){
    /**
     * O método showSolicitacao mostra a solicitação na tela.\n
     * Argumentos:
        - cod_origem: código do município de origem;
        - cod_destino: código do município de destino;
        - quantidade: quantidade de carga a ser transportada; e
        - vec_local: número corrente de solicitações.
     * .
     * Exceções:
     *   - o valor de quantidade deve ser maior que zero;
     *   - os valores dos códigos dos municípios de origem e destino não podem ser negativos;
    */
    std::string titulo = "DADOS DA SOLICITACAO\n";
    this->showTitle(titulo, "-");    
    Localidade origem = searchMunicipio(cod_origem, vec_local); // busca o município pelo codigo
    Localidade destino = searchMunicipio(cod_destino, vec_local); // busca o município pelo codigo
    // Exibe na tela os dados da solicitacao
    std::cout << "Origem: " << origem.getCodigoMunicipio() << " - "
                << origem.getMunicipio() << "/" 
                << origem.getEstado() << " - "
                << origem.getPais()
                << "\nDestino: " << destino.getCodigoMunicipio() << " - "
                << destino.getMunicipio() << "/" 
                << destino.getEstado() << " - "
                << destino.getPais()
                << "\nQuantidade (toneladas): " << quantidade <<  std::endl;
    titulo = "RESULTADO DA SOLICITACAO";
    this->showTitle(titulo, "-");
}
void Screen::showWarning(std::string aviso){
    /**
     * O método showSolicitacao mostra a solicitação na tela.\n
     * Argumentos:
        - cod_origem: código do município de origem;
        - cod_destino: código do município de destino;
        - quantidade: quantidade de carga a ser transportada; e
        - vec_local: número corrente de solicitações.
     * .
     * Exceções:
     *   - o valor de quantidade deve ser maior que zero;
     *   - os valores dos códigos dos municípios de origem e destino não podem ser negativos;
    */
    std::cout << aviso;
}
void Screen::showTitle(std::string titulo, std::string simbolo){
    /**
     * O método showTitle mostra o título formatado na tela.\n
     * Argumentos:
        - title: texto do título;
        - simbolo: símbolo da barra.
     * .
     * Exceções:
     *   - os comprimentos das strings não podem ser zero;
    */
    std::cout << std::endl;
    int desloc = (this->_spaces + titulo.size())/2; // deslocamento para centralizar o titulo
    this->showBar(simbolo); // mostra a barra
    std::cout << std::setw(desloc) << std::internal<< titulo << std::endl; // imprime na tela
    this->showBar(simbolo); // mostra a barra
    std::cout << std::endl;
}

void Screen::showBar(std::string simbolo){
    /**
     * O método showBar mostra a barra na tela.\n
     * Argumentos:
        - title: texto do título;
        - simbolo: símbolo da barra.
     * .
     * Exceções:
     *   - o comprimento da string simbolo não pode ser zero;
    */
    std::string barra = "";
    for (unsigned int i = 0; i < this->_bar_size; i++){
        barra += simbolo; // obtem a barra
    }
    std::cout << barra << std::endl; // imprime a string de barra na tela
}
void Screen::showVector(int columns){
    /**
     * O método showVector mostra as localidades carregadas do arquivo de localidades.\n
     * Argumentos:
        - columns: número de colunas.
     * .
     * Exceções:
     *   - o valor da variável columns de ser maior que zero;
    */
    this->_padding = 20;
    int rows = (int) this->_vector.size(); // obtem o numero de linhas  
    for (int i = 0; i < rows; i++){
        // imprime na tela as localidades
        std::cout << std::setw(2) << std::right 
                  << std::to_string(this->_vector[i].getCodigoMunicipio())<< " - "
                  << std::setw(this->_padding) << std::left
                  << this->_vector[i].getMunicipio();
        if((i + 1) % columns == 0){
            std::cout << std::endl;
        }
    }    
}

void lerArquivoLocalidades(std::istream &arquivo, std::vector  <Localidade> &vector){
    /**
     * O procedimento lerArquivoLocalidades ler o arquivo contendo os dados das localidades\n
     * Argumentos:
        - arquivo: arquivo contendo os dados das localidades de origem/destino
        - vector: vetor para armazenar os dados das localidades de origem/destino
     * .
     * Exceções:
     *   - o arquivo deve existir;
     *   - vector deve estar vazio ao ser recebido;
    */
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
        // percorre o arquivo
        getline(arquivo, linha);
        // ler a linha do arquivo
        std::istringstream iss_linha(linha);
        for(std::string entrada; iss_linha >> entrada;){
            // percorre cada entrada da linha
            if (counter == 0){
                rows = std::stoi(entrada); // total de linhas do arquivo
            }
            if (counter == 1){
                columns = std::stoi(entrada); // total de colunas do arquivo
                std::cout << std::endl;
            }
            if (counter != 0 && counter != 1){
                // restante dos dados
                std::string str;
                if (entrada.substr(0,1) == "|"){
                    // identifica o separador de strings compostas (mais de duas palavras)
                    str = "";
                    int espacos = 0;
                    while (entrada.substr(entrada.size() - 1, 1) != "|"){
                        // ler cada palavra até encontrar o identificar de fim de palavra
                        str = str + entrada + " "; // adiciona aa a string
                        espacos++;
                        iss_linha >> entrada;
                    }
                    str = str + entrada;
                    str = str.substr(1, str.size() - 2);

                    entrada = str;
                }
                column = (counter - 2) % columns;
                // atribui as variaveis codigo do municpio,
                // nome do municipio, estado, pais, latitude e longitude os respectivos valores
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
                    vector.push_back(local);// carrega o vector de localidades
                }               
            }
            counter++;
        }
    }
}
Localidade searchMunicipio(int codigo, std::vector  <Localidade> &vector){
    /**
     * O procedimento searchMunicipio busca o nome da localidade a partir do código do município\n
     * Argumentos:
        - codigo: arquivo contendo os dados das localidades de origem/destino
        - vector: vetor para armazenar os dados das localidades de origem/destino
     * .
     * Exceções:
     *   - o valor da variável código não pode ser negativo;
     *   - vector não pode estar vazio ao ser recebido;
    */
    Localidade local_pivot;
    for(auto v: vector){// busca o municicpio em vector
        if ( v.getCodigoMunicipio() == codigo){
            local_pivot = v;
            break;
        }
    }
    return local_pivot;
}