#include "classes.hpp"

using namespace std;

int main(){
    string msg = "0 1 1 3 2 3 6 10 ";
    Message *mensagem = new Message (msg);
    msg.clear();
    msg = "5 8 15 21 ";
    mensagem->add_msg(msg);
    mensagem->add_byte(30);
    mensagem->print_checksum();
    string m = mensagem->cpy_msg();
    mensagem->clear_msg();
    cout << "Mensagem armazenada: " << m << endl << endl;
    m = mensagem->cpy_msg();
    cout << "Mensagem limpa: " << m << endl << endl;
}