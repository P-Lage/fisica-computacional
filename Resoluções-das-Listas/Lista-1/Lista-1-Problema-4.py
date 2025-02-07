import math

# Função a ser integrada


def f(x):
    return math.sin(x) / (x + 0.1)

# Método de Simpson para integrar a função f de a até b com N subintervalos


def simpson(a, b, N):
    h = (b - a) / N
    sum = f(a) + f(b)

    for i in range(1, N):
        x = a + i * h
        if i % 2 == 0:
            sum += 2 * f(x)
        else:
            sum += 4 * f(x)

    return (h / 3) * sum


# Entrada do usuário
a = float(input("Digite o limite inferior de integração (a): "))
b = float(input("Digite o limite superior de integração (b): "))
N = int(input("Digite o número de subintervalos (N): "))

result = simpson(a, b, N)
print(f"O valor da integral é: {result}")


def find_stable_N(a, b, tolerance=1e-6):
    N = 10
    previous_result = simpson(a, b, N)
    while True:
        N *= 2
        current_result = simpson(a, b, N)
        if abs(current_result - previous_result) < tolerance:
            break
        previous_result = current_result
    return N, current_result


a = float(input("Digite o limite inferior de integração (a): "))
b = float(input("Digite o limite superior de integração (b): "))

N, result = find_stable_N(a, b)
print(f"O valor de N requerido é: {N}")
print(f"O valor da integral é: {result}")
