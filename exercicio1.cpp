#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Passageiro
{
    string nome;
    string cpf;
    int idade;

};


struct Data_Hora 
{
    int dia;
    int mes;
    int ano = 365;
    int hora;
};

struct Passagem 
{
    float valor = 80;
    int assento = 0;
    string tipoViagem;
    Passageiro passageiro;
    Data_Hora data_hora;
    string cidade;

};
void totalPorViagem(vector<Passagem>& passagem);

int main() {
    vector<Passagem> viagens;
    Passagem novaPassagem;

    char tempString;
    bool continuar = true;

    //float valorObtido = 0, qtdLugares = 0;
   
    
        
     while(continuar) {
                cout << "Digite seu nome: ";
                getline(cin >> ws,novaPassagem.passageiro.nome);
                cout << "Digite seu cpf: ";
                getline(cin >> ws, novaPassagem.passageiro.cpf);
                cout << "Digite o dia: ";
                cin >> novaPassagem.data_hora.dia;
                cout << "Digite o mes: ";
                cin >> novaPassagem.data_hora.mes;
                cout << "Digite tipo de percurso (IDA/VOLTA): ";
                cin >> novaPassagem.tipoViagem;
                cout << "Digite a cidade[RJ / SP ?]: ";
                getline(cin >> ws, novaPassagem.cidade);
                cout << "Digite o horario: ";
                cin >> novaPassagem.data_hora.hora;
                cout << "Digite o numero da poltrona: ";
                cin >> novaPassagem.assento;
                viagens.push_back(novaPassagem);
                cout << "\nContinuar(s/n)? \n";
                cin >> tempString;
                continuar = tempString == 's'|| tempString == 'S'? true : false;
    }
        
    totalPorViagem(viagens);
   
    
    return 0;
}


void totalPorViagem(vector<Passagem>& passagem) {
    string cpf;
    float result = 0;
    int conte = 0;
    
    
    getline(cin >> ws, cpf);
    for(auto it=passagem.begin(); it!=passagem.end(); it++) {
        if(it->assento > 0 && it->assento <= 40) {
        
            conte++;
            result += it->valor;

        }

    }   
        cout << "Foram vendidas " <<  conte << " poltronas" << endl;
        cout << fixed << setprecision(2) <<  "Total arrecadado: R$ " <<  result << endl;
};