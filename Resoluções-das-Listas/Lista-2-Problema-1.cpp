#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double k = 0.5;      // Constante elástica (N/m)
const double b = 0.1;      // Coeficiente de arrasto (kg/s)
const double m = 1.0;      // Massa (kg)
const double dt = 0.01;    // Passo de tempo (s)
const double t_max = 50.0; // Tempo máximo de simulação (s)

void euler_modificado(double x0, double v0, const string &filename)
{
    ofstream file(filename);
    double x = x0, v = v0;
    double t = 0.0;

    while (t <= t_max)
    {
        // Derivadas no início do intervalo
        double dxdt = v;
        double dvdt = (-k * x - b * v) / m;

        // Estimativas no final do intervalo
        double x_est = x + dxdt * dt;
        double v_est = v + dvdt * dt;

        // Derivadas no final do intervalo
        double dxdt_est = v_est;
        double dvdt_est = (-k * x_est - b * v_est) / m;

        // Média das derivadas
        double dxdt_avg = (dxdt + dxdt_est) / 2;
        double dvdt_avg = (dvdt + dvdt_est) / 2;

        // Atualização das variáveis
        x += dxdt_avg * dt;
        v += dvdt_avg * dt;

        // Energia mecânica
        double E = 0.5 * m * v * v + 0.5 * k * x * x;

        // Salva os dados no arquivo
        file << t << " " << x << " " << v << " " << E << endl;

        t += dt;
    }

    file.close();
}

int main()
{
    // Caso 1: x(0) = 1 m, v(0) = 0 m/s
    euler_modificado(1.0, 0.0, "dados_caso1.txt");

    // Caso 2: x(0) = 0.5 m, v(0) = 2 m/s
    euler_modificado(0.5, 2.0, "dados_caso2.txt");

    return 0;
}