#include <iostream>  // Biblioteca para entrada e saída padrão
#include <fstream>   // Biblioteca para manipulação de arquivos
#include <cmath>     // Biblioteca para funções matemáticas (ex.: exp, abs)

using namespace std;

// Função que define a EDO dy/dx = f(x, y)
double f(double x, double y) {
    return x + y;  // dy/dx = x + y
}

// Função que retorna a solução exata da EDO
double solucaoExata(double x) {
    return -x - 1 + 2 * exp(x);  // Solução exata: y(x) = -x - 1 + 2e^x
}

int main() {
    // Condições iniciais
    double x = 0;       // Valor inicial de x
    double y = 1;       // Valor inicial de y (condição inicial y(0) = 1)
    double h = 0.1;     // Tamanho do passo (passo de integração)
    double xmax = 2;    // Valor máximo de x para o qual a solução será calculada
    double e;           // Variável para armazenar o erro relativo

    // Abre um arquivo para salvar os resultados
    ofstream arq;       // Cria um objeto para manipulação de arquivos
    arq.open("euler_problema1.dat");  // Abre o arquivo "euler_problema1.dat" para escrita

    // Verifica se o arquivo foi aberto corretamente
    if (!arq.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;  // Encerra o programa com código de erro
    }

    // Cabeçalho do arquivo (opcional, para organização)
    arq << "x\t y_num\t y_exato\t erro_relativo" << endl;

    // Loop principal: avança a solução passo a passo
    while (x <= xmax) {
        // Calcula a solução exata no ponto x
        double y_exato = solucaoExata(x);

        // Calcula o erro relativo em relação à solução exata
        e = abs((y - y_exato) / y_exato);

        // Salva os valores de x, y (numérico), y (exato) e o erro relativo no arquivo
        arq << x << "\t" << y << "\t" << y_exato << "\t" << e << endl;

        // Atualiza o valor de y usando o método de Euler
        y = y + f(x, y) * h;  // y_{n+1} = y_n + h * f(x_n, y_n)

        // Atualiza o valor de x para o próximo passo
        x += h;  // x_{n+1} = x_n + h
    }

    // Fecha o arquivo após a escrita
    arq.close();

    // Mensagem de conclusão
    cout << "Cálculo concluído! Os resultados foram salvos em 'euler_problema1.dat'." << endl;

    return 0;  // Encerra o programa com sucesso
}