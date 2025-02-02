import numpy as np

# Constantes
k = 10.0       # Constante da mola (N/m)
m = 0.2        # Massa do bloco (kg)
mu_k = 0.1     # Coeficiente de atrito cinético
g = 9.81       # Aceleração devido à gravidade (m/s²)
dt = 0.01      # Passo de tempo (s)
t_max = 10.0   # Tempo máximo de simulação (s)


def dxdt(v):
    return v


def dvdt(x, v):
    return -(k/m) * x - mu_k * g * v


def euler_modificado(x, v, dt):
    v_half = v + 0.5 * dt * dvdt(x, v)
    x_half = x + 0.5 * dt * dxdt(v)

    x += dt * dxdt(v_half)
    v += dt * dvdt(x_half, v_half)
    return x, v


def runge_kutta_4(x, v, dt):
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

# Abrindo arquivo para salvar os dados
with open("data.txt", "w") as file:
    for t in np.arange(0, t_max + dt, dt):
        force = -k * x - mu_k * m * g * v

        file.write(f"{t} {x} {v} {force}\n")

        # Escolha um dos métodos abaixo para simular
        # x, v = euler_modificado(x, v, dt)
        x, v = runge_kutta_4(x, v, dt)
