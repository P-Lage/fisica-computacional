#include <iostream>
#include <fstream>
#include <cmath>

const double k = 10.0;     // Constante da mola (N/m)
const double m = 0.2;      // Massa do bloco (kg)
const double mu_k = 0.1;   // Coeficiente de atrito cinético
const double g = 9.81;     // Aceleração devido à gravidade (m/s²)
const double dt = 0.01;    // Passo de tempo (s)
const double t_max = 10.0; // Tempo máximo de simulação (s)

double dxdt(double v)
{
    return v;
}

double dvdt(double x, double v)
{
    return -(k / m) * x - mu_k * g * v;
}

void euler_modificado(double &x, double &v, double dt)
{
    double v_half = v + 0.5 * dt * dvdt(x, v);
    double x_half = x + 0.5 * dt * dxdt(v);

    x += dt * dxdt(v_half);
    v += dt * dvdt(x_half, v_half);
}

void runge_kutta_4(double &x, double &v, double dt)
{
    double k1_x = dxdt(v);
    double k1_v = dvdt(x, v);

    double k2_x = dxdt(v + 0.5 * dt * k1_v);
    double k2_v = dvdt(x + 0.5 * dt * k1_x, v + 0.5 * dt * k1_v);

    double k3_x = dxdt(v + 0.5 * dt * k2_v);
    double k3_v = dvdt(x + 0.5 * dt * k2_x, v + 0.5 * dt * k2_v);

    double k4_x = dxdt(v + dt * k3_v);
    double k4_v = dvdt(x + dt * k3_x, v + dt * k3_v);

    x += (dt / 6.0) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x);
    v += (dt / 6.0) * (k1_v + 2 * k2_v + 2 * k3_v + k4_v);
}

int main()
{
    double x = 1.0; // Posição inicial (m)
    double v = 0.0; // Velocidade inicial (m/s)

    std::ofstream file("data.txt");

    for (double t = 0; t <= t_max; t += dt)
    {
        double force = -k * x - mu_k * m * g * v;

        file << t << " " << x << " " << v << " " << force << std::endl;

        // Escolha um dos métodos abaixo para simular
        // euler_modificado(x, v, dt);
        runge_kutta_4(x, v, dt);
    }

    file.close();

    return 0;
}