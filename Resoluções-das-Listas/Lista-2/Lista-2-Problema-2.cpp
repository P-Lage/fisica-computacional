#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double m = 1.0; // Massa (kg)
const double k = 0.5; // Constante elástica (N/m)
const double b = 0.1; // Coeficiente de arrasto (kg/s)

// Funções para as equações diferenciais
double dxdt(double v)
{
    return v;
}

double dvdt(double x, double v)
{
    return -(k / m) * x - (b / m) * v;
}

// Função para calcular a energia mecânica
double energy(double x, double v)
{
    return 0.5 * m * v * v + 0.5 * k * x * x;
}

// Método de Runge-Kutta de 4ª ordem
void rungeKutta(double &x, double &v, double dt)
{
    double k1_x, k2_x, k3_x, k4_x;
    double k1_v, k2_v, k3_v, k4_v;

    k1_x = dxdt(v);
    k1_v = dvdt(x, v);

    k2_x = dxdt(v + 0.5 * dt * k1_v);
    k2_v = dvdt(x + 0.5 * dt * k1_x, v + 0.5 * dt * k1_v);

    k3_x = dxdt(v + 0.5 * dt * k2_v);
    k3_v = dvdt(x + 0.5 * dt * k2_x, v + 0.5 * dt * k2_v);

    k4_x = dxdt(v + dt * k3_v);
    k4_v = dvdt(x + dt * k3_x, v + dt * k3_v);

    x += (dt / 6.0) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x);
    v += (dt / 6.0) * (k1_v + 2 * k2_v + 2 * k3_v + k4_v);
}

int main()
{
    double x = 1.0;      // Posição inicial (m)
    double v = 0.0;      // Velocidade inicial (m/s)
    double dt = 0.01;    // Passo de tempo (s)
    double t = 0.0;      // Tempo inicial (s)
    double t_max = 50.0; // Tempo máximo (s)

    ofstream file("data.txt");

    while (t <= t_max)
    {
        double E = energy(x, v);
        file << t << " " << x << " " << v << " " << E << endl;

        rungeKutta(x, v, dt);
        t += dt;
    }

    file.close();
    cout << "Dados salvos em data.txt" << endl;

    return 0;
}