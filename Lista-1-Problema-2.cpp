#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double primeiroElemento, razao;
    int numElementos, indice;

    cout << "Digite o primeiro elemento da PG: ";
    cin >> primeiroElemento;

    cout << "Digite a razão da PG: ";
    cin >> razao;

    cout << "Digite o número de elementos da PG: ";
    cin >> numElementos;

    while (true)
    {
        cout << "Digite o índice do elemento que deseja visualizar (ou 0 para sair): ";
        cin >> indice;

        if (indice == 0)
        {
            cout << "Programa encerrado." << endl;
            break;
        }

        if (indice < 1 || indice > numElementos)
        {
            cout << "Erro: Índice inválido. O índice deve estar entre 1 e " << numElementos << "." << endl;
        }
        else
        {
            double elemento = primeiroElemento * pow(razao, indice - 1);
            cout << "O elemento na posição " << indice << " é: " << elemento << endl;
        }
    }

    return 0;
}