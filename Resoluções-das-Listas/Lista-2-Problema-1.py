import numpy as np
import matplotlib.pyplot as plt

# Parâmetros do sistema
k = 0.5  # Constante elástica (N/m)
b = 0.1  # Coeficiente de arrasto (kg/s)
m = 1.0  # Massa (kg)
dt = 0.01  # Passo de tempo (s)
t_max = 50.0  # Tempo máximo de simulação (s)


def euler_modificado(x0, v0, filename):
    t = 0.0
    x, v = x0, v0
    data = []

    while t <= t_max:
        # Derivadas no início do intervalo
        dxdt = v
        dvdt = (-k * x - b * v) / m

        # Estimativas no final do intervalo
        x_est = x + dxdt * dt
        v_est = v + dvdt * dt

        # Derivadas no final do intervalo
        dxdt_est = v_est
        dvdt_est = (-k * x_est - b * v_est) / m

        # Média das derivadas
        dxdt_avg = (dxdt + dxdt_est) / 2
        dvdt_avg = (dvdt + dvdt_est) / 2

        # Atualização das variáveis
        x += dxdt_avg * dt
        v += dvdt_avg * dt

        # Energia mecânica
        E = 0.5 * m * v**2 + 0.5 * k * x**2

        # Salva os dados
        data.append([t, x, v, E])

        t += dt

    # Salva os dados em um arquivo
    np.savetxt(filename, data, header="t x v E", comments="")


# Caso 1: x(0) = 1 m, v(0) = 0 m/s
euler_modificado(1.0, 0.0, "dados_caso1_py.txt")

# Caso 2: x(0) = 0.5 m, v(0) = 2 m/s
euler_modificado(0.5, 2.0, "dados_caso2_py.txt")
