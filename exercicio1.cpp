#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdio>

using namespace std;

struct Passageiro
{
    string nome;
    string cpf;
    float idade;

};


struct Data_Hora 
{
    int dia;
    int mes;
    int ano = 365;
    string hora;
};

struct Passagem 
{
    float valor = 80;
    int assento = 0;
    int tipoViagem;
    Passageiro passageiro;
    Data_Hora data_hora;
    string cidade;

};
void valorArrecadado(vector<Passagem>& passagem);
void valorArrecadadoMes(vector<Passagem>& passagem);
void nomePassageiro(vector<Passagem>& passagem);
void horariosMaisRentaveis(vector<Passagem>& passagem);
void mediaIdades(vector<Passagem>& passagem);
void menu(vector<Passagem>& passagem);

int main() {
    vector<Passagem> viagens;
    Passagem novaPassagem;

    char tempString;
    bool continuar = true;

        
    while(continuar) {
                cout << "Digite seu nome: ";
                getline(cin >> ws,novaPassagem.passageiro.nome);
                cout << "Digite seu cpf: ";
                getline(cin >> ws, novaPassagem.passageiro.cpf);
                cout << "Digite sua idade: ";
                cin >> novaPassagem.passageiro.idade;
                cout << "Digite o dia: ";
                cin >> novaPassagem.data_hora.dia;
                cout << "Digite o mes: ";
                cin >> novaPassagem.data_hora.mes;
                cout << "1 - IDA | 2 - VOLTA | 3 - IDA E VOLTA\n";
                cout << "Digite tipo de percurso: \n";
                cin >> novaPassagem.tipoViagem;
                cout << "Digite a cidade[RJ / SP ?]: ";
                getline(cin >> ws, novaPassagem.cidade);
                cout << "Horários: 06:00 | 10:00 | 14:00 | 17:00 | 21:00\n";
                cout << "Digite o horario: ";
                getline(cin >> ws, novaPassagem.data_hora.hora);
                cout << "Digite o numero da poltrona: ";
                cin >> novaPassagem.assento;
                viagens.push_back(novaPassagem);
                cout << "\nContinuar(s/n)? \n";
                cin >> tempString;
                continuar = tempString == 's'|| tempString == 'S'? true : false;
    }
        
    //valorArrecadado(viagens);
    //valorArrecadadoMes(viagens);
    //nomePassageiro(viagens);
    //horariosMaisRentaveis(viagens);

    menu(viagens);
    
    return 0;
}

void menu(vector<Passagem>& passagem) {
    int opcao;
    

    char tempString;
    bool continuar = true;

    system("clear");

    while(continuar) {
        cout << "Menu de Escolha: ";
        cout << "1- Total arrecadado por uma viagem\n";
        cout << "2- Total arrecadado por um Mês\n";
        cout << "3- Qual o nome do passageiro na poltrona\n";
        cout << "4- Qual o horário mais rentável\n";
        cout << "5- Qual a média de idade dos passageiros\n";
        cout << "0- SAIR\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            valorArrecadado(passagem);
            break;
        case 2:
            valorArrecadadoMes(passagem);
            break;
        case 3:
            nomePassageiro(passagem);
            break;
        case 4:
            horariosMaisRentaveis(passagem);
            break;
        case 5:
            mediaIdades(passagem);
            break;
        case 0:
            cout << "Até logo..." << endl;
            break;
        
        default:
            cout << "Opção inválida!" << endl;
            break;
        }

        cout << "Deseja continuar(s/n)? ";
        cin >> tempString;
        continuar = tempString == 's'|| tempString == 'S'? true : false;

    }

};


void valorArrecadado(vector<Passagem>& passagem) {
   
    float result = 0;
    int conte = 0;
    
    
    for(auto it=passagem.begin(); it!=passagem.end(); it++) {
        if(it->tipoViagem == 1 || it->tipoViagem == 2) {
            conte++;
            
        }else if(it->tipoViagem == 3) {
            conte+=2;
            result += 2 * it->valor;
        }

    }   
        cout << "\nForam vendidas " <<  conte << " poltronas" << endl;
        cout << fixed << setprecision(2) <<  "Total arrecadado: R$ " <<  result << endl;
};

void valorArrecadadoMes(vector<Passagem>& passagem) {
    int mes;
    float result = 0;
    int conte = 0;
    
    cout << "Favor digitar o mês: ";
    cin >> mes;
    for(auto it=passagem.begin(); it!=passagem.end(); it++) {
        if(it->data_hora.mes == mes) {

            if(it->tipoViagem == 1 || it->tipoViagem == 2) {

                conte++;
                result += it->valor;
            }else if(it->tipoViagem == 3) {
                conte+=2;
                result += 2 * it->valor;            
            }
        }
    }
        if(conte) {
            cout << "No Mês: " << mes << " foram encontrados os seguintes registros: " << endl;
            cout << "\nForam vendidas " <<  conte << " poltronas" << endl;
            cout << fixed << setprecision(2) <<  "Total arrecadado: R$ " <<  result << endl;

        }else {
            cout << "Mês não encontrado!" << endl;
        }
       
};

void nomePassageiro(vector<Passagem>& passagem) {
    int assento;
    cout << "Favor digitar a número do assento: ";
    cin >> assento;
    cout << "\n---------------------------------------------------------------------------------------\n";
    
    for(auto it=passagem.begin(); it!=passagem.end(); it++) {
        if(it->assento == assento) {
            cout << "Número do assento: " << it->assento << endl;
            cout << "O passageito localizado foi: " << it->passageiro.nome << endl;
            cout << "CPF: " << it->passageiro.cpf << endl;
            cout << "Tipo da passgem Escolhida: " << it->tipoViagem << endl;
            cout << "-----------------------------------------------------\n";
            cout << "(* Tipos: 1 - IDA | 2 - VOLTA | 3 - IDA E VOLTA *) \n";
            cout << "horario escolhido: " << it->data_hora.hora << " Data: " << it->data_hora.dia << "-" << it->data_hora.mes << endl;

        }
    }
    
};

void horariosMaisRentaveis(vector<Passagem>& passagem) {
    float conteSeis = 0;
    float conteDez = 0;
    float conteQuatorze = 0;
    float conteDezessete = 0;
    float conteVinte = 0;
    //vector<int>melhorConte;
    //float maiorConte = melhorConte[0]; 
    
    for(auto it=passagem.begin(); it!=passagem.end(); it++) {
        if(it->tipoViagem == 1 || it->tipoViagem == 2) {
            if(it->data_hora.hora == "06:00") {
                conteSeis+= it->valor ;
            }else if(it->data_hora.hora == "10:00") {
                conteDez+= it->valor;
            }else if(it->data_hora.hora == "14:00") {
                conteQuatorze+= it->valor;
            }else if(it->data_hora.hora == "17:00") {
                conteDezessete+= it->valor;
            }else if(it->data_hora.hora == "21:00") {
                conteVinte+= it->valor;
            }
        
        }else if(it->tipoViagem == 3) {
            
            if(it->data_hora.hora == "06:00") {
                conteSeis+= 2 * it->valor ;
            }else if(it->data_hora.hora == "10:00") {
                conteDez+= 2 * it->valor;
            }else if(it->data_hora.hora == "14:00") {
                conteQuatorze+= 2 * it->valor;
            }else if(it->data_hora.hora == "17:00") {
                conteDezessete+= 2 * it->valor;
            }else if(it->data_hora.hora == "21:00") {
                conteVinte+= 2 * it->valor;
            }
        }

    cout << fixed << setprecision(2) << "Horário da 06:00: R$ " << conteSeis << endl;
    cout << fixed << setprecision(2) << "Horário da 10:00: R$ " << conteDez << endl;
    cout << fixed << setprecision(2) << "Horário da 14:00: R$ " << conteQuatorze << endl;
    cout << fixed << setprecision(2) << "Horário da 17:00: R$ " << conteDezessete << endl;
    cout << fixed << setprecision(2) << "Horário da 21:00: R$ " << conteVinte << endl;

        
    
    }
};

void mediaIdades(vector<Passagem>& passagem) {
    float somar, media;
    int i = 1;

    for(auto it=passagem.begin(); it!=passagem.end(); it++, i++) {
        somar += it->passageiro.idade;
    }

    media = somar / i;
    cout << fixed << setprecision(2) << " A média das idades dos passageiros é: "  << media << endl;
};