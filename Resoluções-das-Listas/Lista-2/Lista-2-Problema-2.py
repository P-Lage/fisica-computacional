import numpy as np
import matplotlib.pyplot as plt

# Parâmetros do sistema
m = 1.0    # Massa (kg)
k = 0.5    # Constante elástica (N/m)
b = 0.1    # Coeficiente de arrasto (kg/s)

# Funções para as equações diferenciais


def dxdt(v):
    return v


def dvdt(x, v):
    return -(k/m) * x - (b/m) * v

# Função para calcular a energia mecânica


def energy(x, v):
    return 0.5 * m * v**2 + 0.5 * k * x**2

# Método de Runge-Kutta de 4ª ordem


def rungeKutta(x, v, dt):
    k1_x = dxdt(v)
    k1_v = dvdt(x, v)

    k2_x = dxdt(v + 0.5 * dt * k1_v)
    k2_v = dvdt(x + 0.5 * dt * k1_x, v + 0.5 * dt * k1_v)

    k3_x = dxdt(v + 0.5 * dt * k2_v)
    k3_v = dvdt(x + 0.5 * dt * k2_x, v + 0.5 * dt * k2_v)

    k4_x = dxdt(v + dt * k3_v)
    k4_v = dvdt(x + dt * k3_x, v + dt * k3_v)

    x += (dt / 6.0) * (k1_x + 2 * k2_x + 2 * k3_x + k4_x)
    v += (dt / 6.0) * (k1_v + 2 * k2_v + 2 * k3_v + k4_v)

    return x, v


# Condições iniciais
x = 1.0  # Posição inicial (m)
v = 0.0  # Velocidade inicial (m/s)
dt = 0.01  # Passo de tempo (s)
t = 0.0  # Tempo inicial (s)
t_max = 50.0  # Tempo máximo (s)

# Listas para armazenar os resultados
times = []
positions = []
velocities = []
energies = []

while t <= t_max:
    E = energy(x, v)
    times.append(t)
    positions.append(x)
    velocities.append(v)
    energies.append(E)

    x, v = rungeKutta(x, v, dt)
    t += dt

# Salvar os dados em um arquivo
data = np.column_stack((times, positions, velocities, energies))
np.savetxt('data_python.txt', data,
           header='Time (s) Position (m) Velocity (m/s) Energy (J)', fmt='%.6f')

# Plotar os resultados
plt.figure(figsize=(12, 8))

plt.subplot(3, 1, 1)
plt.plot(times, positions, label='x(t)')
plt.xlabel('Tempo (s)')
plt.ylabel('Posição (m)')
plt.legend()

plt.subplot(3, 1, 2)
plt.plot(times, velocities, label='v(t)', color='orange')
plt.xlabel('Tempo (s)')
plt.ylabel('Velocidade (m/s)')
plt.legend()

plt.subplot(3, 1, 3)
plt.plot(times, energies, label='E(t)', color='green')
plt.xlabel('Tempo (s)')
plt.ylabel('Energia Mecânica (J)')
plt.legend()

plt.tight_layout()
plt.show()
