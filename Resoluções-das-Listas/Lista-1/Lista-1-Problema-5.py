import math

def funcao_densidade(x):
    constante = 4 * math.sqrt(125 / math.pi)
    return constante * x**2 * math.exp(-5 * x**2)

def metodo_simpson(a, b, N):
    h = (b - a) / N
    soma = funcao_densidade(a) + funcao_densidade(b)
    for i in range(1, N):
        x = a + i * h
        soma += 4 * funcao_densidade(x) if i % 2 else 2 * funcao_densidade(x)
    return soma * h / 3

def derivada(x, h=1e-5):
    return (funcao_densidade(x + h) - funcao_densidade(x - h)) / (2 * h)

def metodo_bissecao(a, b, tol=1e-6, max_iter=100):
    fa, fb = derivada(a), derivada(b)
    if fa * fb >= 0:
        raise ValueError("A função não muda de sinal no intervalo [a, b]")
    for _ in range(max_iter):
        c = (a + b) / 2
        fc = derivada(c)
        if abs(fc) < tol:
            return c
        if fa * fc < 0:
            b, fb = c, fc
        else:
            a, fa = c, fc
    return c

print(f"Probabilidade: {metodo_simpson(0.2, 0.5, 20):.6f}")

print(f"Máximo em x: {metodo_bissecao(0.3, 0.6):.6f}")