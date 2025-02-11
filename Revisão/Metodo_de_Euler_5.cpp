#include <iostream> // Biblioteca para entrada e saída padrão
#include <fstream>  // Biblioteca para manipulação de arquivos
#include <cmath>    // Biblioteca para funções matemáticas (ex.: exp, abs)

using namespace std;

// Função que define a EDO dN/dt = f(t, N)
double f(double t, double N, double lambda)
{
    return -lambda * N; // dN/dt = -lambda * N
}

// Função que retorna a solução exata da EDO
double solucaoExata(double t, double N0, double lambda)
{
    return N0 * exp(-lambda * t); // Solução exata: N(t) = N0 * e^(-lambda * t)
}

int main()
{
    // Parâmetros do problema
    double lambda = 0.1; // Constante de decaimento
    double N0 = 1000.0;  // Número inicial de núcleos radioativos

    // Condições iniciais
    double t = 0;       // Tempo inicial (s)
    double N = N0;      // Número inicial de núcleos (N(0) = N0)
    double h = 0.1;     // Tamanho do passo (passo de integração)
    double tmax = 50.0; // Tempo máximo de simulação (s)
    double e;           // Variável para armazenar o erro relativo

    // Abre um arquivo para salvar os resultados
    ofstream arq;                          // Cria um objeto para manipulação de arquivos
    arq.open("decaimento_radioativo.dat"); // Abre o arquivo "decaimento_radioativo.dat" para escrita

    // Verifica se o arquivo foi aberto corretamente
    if (!arq.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1; // Encerra o programa com código de erro
    }

    // Cabeçalho do arquivo (opcional, para organização)
    arq << "t\t N_num\t N_exato\t erro_relativo" << endl;

    // Loop principal: avança a solução passo a passo
    while (t <= tmax)
    {
        // Calcula a solução exata no tempo t
        double N_exato = solucaoExata(t, N0, lambda);

        // Calcula o erro relativo em relação à solução exata
        e = abs((N - N_exato) / N_exato);

        // Salva os valores de t, N (numérico), N (exato) e o erro relativo no arquivo
        arq << t << "\t" << N << "\t" << N_exato << "\t" << e << endl;

        // Atualiza o valor de N usando o método de Euler
        N = N + f(t, N, lambda) * h; // N_{n+1} = N_n + h * f(t_n, N_n)

        // Atualiza o valor de t para o próximo passo
        t += h; // t_{n+1} = t_n + h
    }

    // Fecha o arquivo após a escrita
    arq.close();

    // Mensagem de conclusão
    cout << "Simulação concluída! Os resultados foram salvos em 'decaimento_radioativo.dat'." << endl;

    return 0; // Encerra o programa com sucesso
}