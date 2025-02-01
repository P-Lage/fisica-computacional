#include <iostream>
#include <fstream>
#include <cmath>

const double g = 9.81;

using namespace std;

int main()
{
    double v0, theta;

    cout << "Digite a velocidade inicial (m/s): ";
    cin >> v0;

    cout << "Digite o ângulo inicial (graus): ";
    cin >> theta;

    double theta_rad = theta * M_PI / 180.0;

    double h_max = (v0 * v0 * pow(sin(theta_rad), 2)) / (2 * g);

    double alcance = (v0 * v0 * sin(2 * theta_rad)) / g;

    double tempo_total = (2 * v0 * sin(theta_rad)) / g;

    cout << "Altura máxima: " << h_max << " m" << std::endl;
    cout << "Alcance horizontal: " << alcance << " m" << std::endl;
    cout << "Tempo de movimento: " << tempo_total << " s" << std::endl;

    ofstream arquivo("trajetoria.txt");
    if (arquivo.is_open())
    {
        double t = 0.0;
        double dt = 0.01;
        while (t <= tempo_total)
        {
            double x = v0 * cos(theta_rad) * t;
            double y = v0 * sin(theta_rad) * t - 0.5 * g * t * t;
            arquivo << x << " " << y << std::endl;
            t += dt;
        }
        arquivo.close();
        std::cout << "Trajetória salva em 'trajetoria.txt'" << std::endl;
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo para escrita." << std::endl;
    }

    return 0;
}