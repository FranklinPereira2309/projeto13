#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Empregado {
    string nome;
    string sobrenome;
    int dtNascimento;
    string rg;
    int anoAdmissao;
    double salario;
};

void reajustaDezPorcento(Empregado empregados[], int quantidade);

int main() {
    const int maxEmpreg = 50;
    Empregado empregados[maxEmpreg];

    
    empregados[0] = {"Joao", "Silva", 1980, "123456", 2010, 3000.0};
    empregados[1] = {"Maria", "Santos", 1990, "789012", 2015, 3500.0};
    empregados[2] = {"Pedro", "Oliveira", 1985, "345678", 2020, 4000.0};

    int qtdEmpreg = 3;

      
    reajustaDezPorcento(empregados, qtdEmpreg);

    cout << "\nSalários após o reajuste:" << endl;
    for (int i = 0; i < qtdEmpreg; i++) {
        cout << empregados[i].nome << " " << empregados[i].sobrenome << ": R$ " << empregados[i].salario << endl;
    }

    return 0;
}


void reajustaDezPorcento(Empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        empregados[i].salario *= 1.10; 
    }
}