#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// Função f(x) = e^(-x) * cos(x)
double f(double x)
{
    return exp(-x) * cos(x);
}

// Derivada numérica progressiva
double derivada_progressiva(double x, double h)
{
    return (f(x + h) - f(x)) / h;
}

// Derivada numérica centrada
double derivada_centrada(double x, double h)
{
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main()
{
    double x_min, x_max, h;
    ofstream arquivo("resultados.txt");

    // Solicita os valores de x_min, x_max e h
    cout << "Digite o valor de x_min: ";
    cin >> x_min;
    cout << "Digite o valor de x_max: ";
    cin >> x_max;
    cout << "Digite o valor de h: ";
    cin >> h;

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    // Escreve os resultados no arquivo
    arquivo << "x\tProgressiva\tCentrada" << endl;
    for (double x = x_min; x <= x_max; x += h)
    {
        double dp = derivada_progressiva(x, h);
        double dc = derivada_centrada(x, h);
        arquivo << x << "\t" << dp << "\t" << dc << endl;
    }

    arquivo.close();
    cout << "Resultados escritos em 'resultados.txt'" << endl;

    return 0;
}