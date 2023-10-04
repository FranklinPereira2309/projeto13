#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


struct Produto {
    string codigo;
    string nome;
    double preco;
};

const int maxProd= 300;
Produto produtos[maxProd];
int numProdutos = 0;


void InserirProduto() {
    system("clear");
    if (numProdutos < maxProd) {
        cout << "Informe o código do produto (13 caracteres numéricos): ";
        cin >> produtos[numProdutos].codigo;

        
        for (int i = 0; i < numProdutos; i++) {
            if (produtos[i].codigo == produtos[numProdutos].codigo) {
                cout << "Código já existe. Não é possível cadastrar o produto." << endl;
                return;
            }
        }

        cout << "Informe o nome do produto (até 20 caracteres): ";
        getline(cin >> ws, produtos[numProdutos].nome);

        cout << "Informe o preço do produto: ";
        cin >> produtos[numProdutos].preco;

        numProdutos++;
        cout << "Produto cadastrado com sucesso!" << endl;
    } else {
        cout << "Limite máximo de produtos atingido. Não é possível cadastrar mais produtos." << endl;
    }
}


void ExcluirProduto() {
    system("clear");
    string codigo;
    cout << "Informe o código do produto a ser excluído: ";
    cin >> codigo;

    bool encontrado = false;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            
            for (int j = i; j < numProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            numProdutos--;
            encontrado = true;
            cout << "Produto excluído com sucesso!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Produto não encontrado." << endl;
    }
}


void ListarProdutos() {
     
    cout << "Lista de produtos cadastrados:" << endl;
    for (int i = 0; i < numProdutos; i++) {
        cout << "Código: " << produtos[i].codigo << ", Nome: " << produtos[i].nome << ", Preço: R$" << fixed << setprecision(2) << produtos[i].preco << endl;
    }

   
}

void ConsultarPreco() {
    system("clear");
    string codigo;
    cout << "Informe o código do produto para consulta de preço: ";
    cin >> codigo;

    bool encontrado = false;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            cout << "Preço do produto " << produtos[i].nome << ": R$" << fixed << setprecision(2) << produtos[i].preco << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Produto não encontrado." << endl;
    }
}

int main() {
    int opcao;

    
    do {
        cout << "\nMenu de Opções:" << endl;
        cout << "1. Inserir um produto" << endl;
        cout << "2. Excluir um produto" << endl;
        cout << "3. Listar produtos" << endl;
        cout << "4. Consultar o preço" << endl;
        cout << "5. Sair" << endl;
        cout << "Selecionar uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                InserirProduto();
                break;
            case 2:
                ExcluirProduto();
                break;
            case 3:
                ListarProdutos();
                break;
            case 4:
                ConsultarPreco();
                break;
            case 5:
                cout << "Obrigado..." << endl;
                break;
            default:
                cout << "Opção inválida!." << endl;
        }

    } while (opcao != 5);

    return 0;
}
