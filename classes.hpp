#include <vector>
#include <iostream>
#include <string>

using namespace std;

// Classe Fletcher16 inicializada por um construtor usando um valor de entrada e 2 coeficientes de uma outra classe
class Fletcher16{
    public:
    // Construtor
    Fletcher16(string value, int c0, int c1){
        int V = stoi(value);
        C_0 = (c0 + V)  % 255;
        C_1 = (c1+ C_0) % 255;
    };
    // Destrutor
    ~Fletcher16(){};
    // Funções de moficação, retorno de valores e impressão:
    int get_C0(){ return C_0; };
    int get_C1(){ return C_1; };
    void set_C0(int c0){ C_0 = c0; };
    void set_C1(int c1){ C_1 = c1; };
    void print_c(){
        cout << "[C_0]: " << C_0 << "  [C_1]: " << C_1 << endl;
    };

    // atributos da classe:
    private:
    int C_0;                // Coeficiente 0
    int C_1;                // Coeficiente 1
    
};

/*
    Classe Message inicializada por uma string enviada pelo cliente ao servidor, pela string transformam-se os valores 
    em inteiro armazena-os e gera os coeficientes de Fletcher por meio da inicialização de elementos da classe Fletcher16
*/
class Message{
    public:
    // Construtor
    Message(string m){
        msg = m; 
        tamanho = m.size();
        string aux; aux.clear();
        for(int i = 0; i < msg.size(); i++){
            if((m[i] == ' ') && (aux.size() > 0)){
                valores.push_back(aux);
                aux.clear();
            }
            else if((i == msg.size()) &&(aux.size() > 0)){
                valores.push_back(aux);
                aux.clear();
            }else{
                aux.push_back(m[i]);
            }
        }
        for(int i = 0; i < valores.size(); i++){
            if(i == 0){
                checksum.push_back(new Fletcher16 (valores[i], 0, 0)); 
            }else{
                checksum.push_back(new Fletcher16 (valores[i], checksum[i-1]->get_C0(), checksum[i-1]->get_C1())); 
            }
        }
        valores.clear();
    };
    // Destrutor
    ~Message(){};

    // Função que adiciona uma mensagem à classe já que o cliente enviaria mais de uma mensagem ao servidor 
    void add_msg(string m){
       string aux; aux.clear();
       int tam = valores.size();
       for(int i = 0; i < m.size(); i++){
            if((m[i] == ' ') && (aux.size() > 0)){
                valores.push_back(aux);
                aux.clear();
            }
            else if((i == msg.size()) &&(aux.size() > 0)){
                valores.push_back(aux);
                aux.clear();
            }else{
                aux.push_back(m[i]);
            }
        }
        for (int i = 0; i < (valores.size() - tam); i++){
            checksum.push_back(new Fletcher16 (valores[i], checksum[checksum.size() - 1]->get_C0(), checksum[checksum.size() - 1]->get_C1()));
        }
        tamanho = tamanho + m.size();
        msg = msg + m;
    };
    // Imprime os coeficientes de Fletcher de acordo com seu bloco de dados
    void print_checksum(){
        for(int i = 0; i < checksum.size(); i++){
            cout << "Bloco " << to_string(i+1) << "  -  "; checksum[i]->print_c(); cout << endl;
       }
    };
    // Retorna o tamanho dos dados enviados pelo cliente
    int get_tam(){ return tamanho; };
    // Retorna o tamanho dos dados enviados pelo cliente mais o tamanho dos coeficientes usados
    int get_tamc(){ return (tamanho + checksum.size()*2); };
    // Limpa a mensagem armazenada na classe
    void clear_msg(){ msg.clear(); };
    // Adiciona um byte na mensagem
    void add_byte(int b){
        if((b >= 0) &&(b <= 255)){
            valores.push_back(to_string(b));
            msg = msg + to_string(b) + ' ';
            checksum.push_back(new Fletcher16 (valores[valores.size() - 1], checksum[checksum.size() - 1]->get_C0(), checksum[checksum.size() - 1]->get_C1()));
        }else{
            cout << "Erro ao adicionar byte! " << endl;
        }
    };
    // Retorna uma string cópia da mensagem
    string cpy_msg(){ return msg; };

    // Atributos da classe:
    private:
    string msg;                                 // Mensagem armazenada
    int tamanho;                                // Tamanho da mensagem armazenada
    vector <Fletcher16*> checksum;              // Vetor de classes Fletcher16 contendo os coeficientes da mensagem
    vector <string> valores;                    // Vetor de string contendo os valores, em string, passados pela mensagem 
};
