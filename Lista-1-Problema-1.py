import math

g = 9.81

v0 = float(input("Digite a velocidade inicial (m/s): "))
theta = float(input("Digite o ângulo inicial (graus): "))

theta_rad = math.radians(theta)

h_max = (v0 ** 2 * (math.sin(theta_rad) ** 2)) / (2 * g)

alcance = (v0 ** 2 * math.sin(2 * theta_rad)) / g

tempo_total = (2 * v0 * math.sin(theta_rad)) / g

print(f"Altura máxima: {h_max} m")
print(f"Alcance horizontal: {alcance} m")
print(f"Tempo de movimento: {tempo_total} s")

with open("trajetoria.txt", "w") as arquivo:
    t = 0.0
    dt = 0.01
    while t <= tempo_total:
        x = v0 * math.cos(theta_rad) * t
        y = v0 * math.sin(theta_rad) * t - 0.5 * g * t ** 2
        arquivo.write(f"{x} {y}\n")
        t += dt

print("Trajetória salva em 'trajetoria.txt'")
