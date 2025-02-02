primeiro_elemento = float(input("Digite o primeiro elemento da PG: "))
razao = float(input("Digite a razão da PG: "))
num_elementos = int(input("Digite o número de elementos da PG: "))

while True:
    indice = int(
        input("Digite o índice do elemento que deseja visualizar (ou 0 para sair): "))

    if indice == 0:
        print("Programa encerrado.")
        break

    if indice < 1 or indice > num_elementos:
        print(f"Erro: Índice inválido. O índice deve estar entre 1 e {
              num_elementos}.")
    else:
        elemento = primeiro_elemento * (razao ** (indice - 1))
        print(f"O elemento na posição {indice} é: {elemento}")
