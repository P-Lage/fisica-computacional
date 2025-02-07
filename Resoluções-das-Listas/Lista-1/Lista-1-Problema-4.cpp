#include <iostream>
#include <cmath>

using namespace std;

// Função a ser integrada
double f(double x)
{
    return sin(x) / (x + 0.1);
}

// Método de Simpson para integrar a função f de a até b com N subintervalos
double simpson(double a, double b, int N)
{
    double h = (b - a) / N;
    double sum = f(a) + f(b);

    for (int i = 1; i < N; i++)
    {
        double x = a + i * h;
        if (i % 2 == 0)
        {
            sum += 2 * f(x);
        }
        else
        {
            sum += 4 * f(x);
        }
    }

    return (h / 3) * sum;
}

int main()
{
    double a, b;
    int N;

    cout << "Digite o limite inferior de integração (a): ";
    cin >> a;
    cout << "Digite o limite superior de integração (b): ";
    cin >> b;
    cout << "Digite o número de subintervalos (N): ";
    cin >> N;

    double result = simpson(a, b, N);
    cout << "O valor da integral é: " << result << endl;

    return 0;
}