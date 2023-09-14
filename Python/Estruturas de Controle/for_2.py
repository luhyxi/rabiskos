Palavra = 'paralelepipedo'

for letra in Palavra:
    print(letra, end = '')

aprovados = ['Rafaela', 'Pedro', 'Renato', 'Maria']
for nome in aprovados:
    print(nome)


for posição, nome in enumerate(aprovados):
    print(f'{posição + 1}', nome)

for numero in {1,2,3,4,5,6}:
    print(numero)