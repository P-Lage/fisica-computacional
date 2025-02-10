#include <iostream>  // Biblioteca para entrada e saída padrão
#include <fstream>   // Biblioteca para manipulação de arquivos
#include <cmath>     // Biblioteca para funções matemáticas (ex.: exp, abs)

using namespace std;

// Função que define a EDO dV/dt = f(t, V)
double f(double t, double V, double RC) {
    return -V / RC;  // dV/dt = -V/(RC)
}

// Função que retorna a solução exata da EDO
double solucaoExata(double t, double V0, double RC) {
    return V0 * exp(-t / RC);  // Solução exata: V(t) = V0 * e^(-t/(RC))
}

int main() {
    // Parâmetros do circuito RC
    double R = 1.0;        // Resistência (Ohms)
    double C = 1.0;        // Capacitância (Farads)
    double RC = R * C;     // Constante de tempo RC
    double V0 = 5.0;       // Tensão inicial no capacitor (Volts)

    // Condições iniciais
    double t = 0;          // Tempo inicial (s)
    double V = V0;         // Tensão inicial no capacitor (V(0) = V0)
    double h = 0.1;        // Tamanho do passo (passo de integração)
    double tmax = 5.0;     // Tempo máximo de simulação (s)
    double e;              // Variável para armazenar o erro relativo

    // Abre um arquivo para salvar os resultados
    ofstream arq;          // Cria um objeto para manipulação de arquivos
    arq.open("circuito_rc.dat");  // Abre o arquivo "circuito_rc.dat" para escrita

    // Verifica se o arquivo foi aberto corretamente
    if (!arq.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;  // Encerra o programa com código de erro
    }

    // Cabeçalho do arquivo (opcional, para organização)
    arq << "t\t V_num\t V_exato\t erro_relativo" << endl;

    // Loop principal: avança a solução passo a passo
    while (t <= tmax) {
        // Calcula a solução exata no tempo t
        double V_exato = solucaoExata(t, V0, RC);

        // Calcula o erro relativo em relação à solução exata
        e = abs((V - V_exato) / V_exato);

        // Salva os valores de t, V (numérico), V (exato) e o erro relativo no arquivo
        arq << t << "\t" << V << "\t" << V_exato << "\t" << e << endl;

        // Atualiza o valor de V usando o método de Euler
        V = V + f(t, V, RC) * h;  // V_{n+1} = V_n + h * f(t_n, V_n)

        // Atualiza o valor de t para o próximo passo
        t += h;  // t_{n+1} = t_n + h
    }

    // Fecha o arquivo após a escrita
    arq.close();

    // Mensagem de conclusão
    cout << "Simulação concluída! Os resultados foram salvos em 'circuito_rc.dat'." << endl;

    return 0;  // Encerra o programa com sucesso
}