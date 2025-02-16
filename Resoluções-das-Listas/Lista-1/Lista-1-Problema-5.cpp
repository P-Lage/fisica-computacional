#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double funcao_densidade(double x) {
    double pi = acos(-1.0);
    double constante = 4.0 * sqrt(125.0 / pi);
    return constante * x * x * exp(-5.0 * x * x);
}

double metodo_simpson(double a, double b, int N) {
    double h = (b - a) / N;
    double soma = funcao_densidade(a) + funcao_densidade(b);
    for (int i = 1; i < N; ++i) {
        double x = a + i * h;
        if (i % 2 == 1)
            soma += 4.0 * funcao_densidade(x);
        else
            soma += 2.0 * funcao_densidade(x);
    }
    return soma * h / 3.0;
}

double derivada(double x) {
    double h = 1e-5;
    return (funcao_densidade(x + h) - funcao_densidade(x - h)) / (2 * h);
}

double metodo_bissecao(double a, double b, double tol = 1e-6, int max_iter = 100) {
    double fa = derivada(a);
    double fb = derivada(b);
    
    if (fa * fb >= 0) {
        cerr << "O método da bisseção requer sinais opostos em a e b." << endl;
        return NAN;
    }
    
    double c;
    for (int i = 0; i < max_iter; ++i) {
        c = (a + b) / 2;
        double fc = derivada(c);
        
        if (abs(fc) < tol)
            break;
        
        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
    return c;
}

int main() {
    cout << fixed << setprecision(6);
    double probabilidade = metodo_simpson(0.2, 0.5, 20);
    cout << "Probabilidade: " << probabilidade << endl;
    
    double x_maximo = metodo_bissecao(0.3, 0.6);
    cout << "Máximo em x: " << x_maximo << endl;
    
    return 0;
}