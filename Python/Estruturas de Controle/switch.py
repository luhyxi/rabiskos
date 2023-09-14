def get_dia_semana(dia):
    dias = {
        1 : 'Domingo',
        2 : 'Segunda',
        3 : 'Terça',
        4 : 'Quarta',
        5 : 'Quinta',
        6 : 'Sexta',
        7 : 'Sabado'
    }
    return dias.get(dia, 'INVÁLIDO')

if __name__ == '__main__':
    for dia in range(1,9):
        print(f'{dia} : {get_dia_semana(dia)}')