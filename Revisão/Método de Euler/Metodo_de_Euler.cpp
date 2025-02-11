#include <iostream> // Biblioteca para entrada e saída padrão
#include <fstream>  // Biblioteca para manipulação de arquivos
#include <cmath>    // Biblioteca para funções matemáticas (ex.: abs)

using namespace std;

// Função que define a EDO dy/dx = f(x, y)
double f(double x, double y)
{
    return -y / x; // Exemplo: dy/dx = -y/x
}

int main()
{
    // Condições iniciais
    double x = 1;    // Valor inicial de x
    double y = 0.5;  // Valor inicial de y (condição inicial y(1) = 0.5)
    double h = 0.01; // Tamanho do passo (passo de integração)
    double xmax = 5; // Valor máximo de x para o qual a solução será calculada
    double e;        // Variável para armazenar o erro relativo

    // Abre um arquivo para salvar os resultados
    ofstream arq;              // Cria um objeto para manipulação de arquivos
    arq.open("euler_eq1.dat"); // Abre o arquivo "euler_eq1.dat" para escrita

    // Verifica se o arquivo foi aberto corretamente
    if (!arq.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1; // Encerra o programa com código de erro
    }

    // Loop principal: avança a solução passo a passo
    while (x <= xmax)
    {
        // Calcula o erro relativo em relação à solução exata y = 0.5/x
        e = abs((y - 0.5 / x) / (0.5 / x));

        // Salva os valores de x, y e o erro relativo no arquivo
        arq << x << "\t" << y << "\t" << e << endl;

        // Atualiza o valor de y usando o método de Euler
        y = y + f(x, y) * h; // y_{n+1} = y_n + h * f(x_n, y_n)

        // Atualiza o valor de x para o próximo passo
        x += h; // x_{n+1} = x_n + h
    }

    // Fecha o arquivo após a escrita
    arq.close();

    // Mensagem de conclusão
    cout << "Cálculo concluído! Os resultados foram salvos em 'euler_eq1.dat'." << endl;

    return 0; // Encerra o programa com sucesso
}