import math

# Função f(x) = e^(-x) * cos(x)


def f(x):
    return math.exp(-x) * math.cos(x)

# Derivada numérica progressiva


def derivada_progressiva(x, h):
    return (f(x + h) - f(x)) / h

# Derivada numérica centrada


def derivada_centrada(x, h):
    return (f(x + h) - f(x - h)) / (2 * h)


def main():
    # Solicita os valores de x_min, x_max e h
    x_min = float(input("Digite o valor de x_min: "))
    x_max = float(input("Digite o valor de x_max: "))
    h = float(input("Digite o valor de h: "))

    # Abre o arquivo para escrita
    with open("resultados.txt", "w") as arquivo:
        # Escreve os resultados no arquivo
        arquivo.write("x\tProgressiva\tCentrada\n")
        x = x_min
        while x <= x_max:
            dp = derivada_progressiva(x, h)
            dc = derivada_centrada(x, h)
            arquivo.write(f"{x}\t{dp}\t{dc}\n")
            x += h

    print("Resultados escritos em 'resultados.txt'")
