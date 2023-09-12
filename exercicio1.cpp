#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// struct Passageiro
// {
//     string nome;
//     string cpf;
//     int idade;

// };

struct Passagem {
    float valor = 80;
    int assento;
    string nome;
    string cpf;
    int idade;
    int dia;
    int mes;
    int ano = 365;
    int hora;
    string tipoViagem;

};

// struct Data_Hora {
// };

int main() {
    vector<Passagem> viagens;
    Passagem novaPassagem;

    string tempString;
    bool continuar = true;

    float valorObtido = 0, qtdLugares = 0;
    int sair = 1;
    int conte;
    
        
     while(continuar) {
                cout << "Digite seu nome: ";
                getline(cin >> ws,novaPassagem.nome);
                cout << "Digite seu cpf: ";
                getline(cin >> ws, novaPassagem.cpf);
                cout << "Digite o dia: ";
                cin >> novaPassagem.dia;
                cout << "Digite o mes: ";
                cin >> novaPassagem.mes;
                cout << "Digite tipo de percurso (IDA/VOLTA): ";
                cin >> novaPassagem.tipoViagem;
                cout << "Digite o horario: ";
                cin >> novaPassagem.hora;
                cout << "Continuar(s/n)? ";
                viagens.push_back(novaPassagem);
                getline(cin >> ws, tempString);
                continuar = tempString == "s"? true : false;
    }
        
               
    

    // for(int i = 0 ; i < conte; i++) {
            
    //     }

    
    


    
    return 0;
}


