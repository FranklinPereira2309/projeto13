#include <iostream>

using namespace std;

struct Passageiro
{
    string nome;
    string cpf;
    int idade;

};

struct Passagem {
    float valor;
    int assento;

};

struct Data_Hora {
    int dia;
    int mes;
    int ano;
    int hora;
};

int main() {
    Passageiro p1;
    Passagem p1;
    Data_Hora p1;
    
    return 0;
}


