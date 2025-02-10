#include <iostream> // Biblioteca para entrada e saída padrão
#include <fstream>  // Biblioteca para manipulação de arquivos
#include <cmath>    // Biblioteca para funções matemáticas (ex.: exp, abs)

using namespace std;

// Função que define a EDO dT/dt = f(t, T)
double f(double t, double T, double k, double T_amb)
{
    return -k * (T - T_amb); // dT/dt = -k(T - T_amb)
}

// Função que retorna a solução exata da EDO
double solucaoExata(double t, double T0, double k, double T_amb)
{
    return T_amb + (T0 - T_amb) * exp(-k * t); // Solução exata: T(t) = T_amb + (T0 - T_amb)e^(-kt)
}

int main()
{
    // Parâmetros do problema
    double k = 0.1;      // Constante de resfriamento
    double T_amb = 25.0; // Temperatura ambiente (°C)
    double T0 = 100.0;   // Temperatura inicial do objeto (°C)

    // Condições iniciais
    double t = 0;       // Tempo inicial (s)
    double T = T0;      // Temperatura inicial do objeto (T(0) = T0)
    double h = 0.1;     // Tamanho do passo (passo de integração)
    double tmax = 50.0; // Tempo máximo de simulação (s)
    double e;           // Variável para armazenar o erro relativo

    // Abre um arquivo para salvar os resultados
    ofstream arq;                        // Cria um objeto para manipulação de arquivos
    arq.open("resfriamento_newton.dat"); // Abre o arquivo "resfriamento_newton.dat" para escrita

    // Verifica se o arquivo foi aberto corretamente
    if (!arq.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1; // Encerra o programa com código de erro
    }

    // Cabeçalho do arquivo (opcional, para organização)
    arq << "t\t T_num\t T_exato\t erro_relativo" << endl;

    // Loop principal: avança a solução passo a passo
    while (t <= tmax)
    {
        // Calcula a solução exata no tempo t
        double T_exato = solucaoExata(t, T0, k, T_amb);

        // Calcula o erro relativo em relação à solução exata
        e = abs((T - T_exato) / T_exato);

        // Salva os valores de t, T (numérico), T (exato) e o erro relativo no arquivo
        arq << t << "\t" << T << "\t" << T_exato << "\t" << e << endl;

        // Atualiza o valor de T usando o método de Euler
        T = T + f(t, T, k, T_amb) * h; // T_{n+1} = T_n + h * f(t_n, T_n)

        // Atualiza o valor de t para o próximo passo
        t += h; // t_{n+1} = t_n + h
    }

    // Fecha o arquivo após a escrita
    arq.close();

    // Mensagem de conclusão
    cout << "Simulação concluída! Os resultados foram salvos em 'resfriamento_newton.dat'." << endl;

    return 0; // Encerra o programa com sucesso
}