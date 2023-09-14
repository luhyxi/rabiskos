def get_dia_semana(dia):
    match dia:
        case 1:
            return 'Domingo'
        case 2:
            return 'Segunda'
        case 3:
            return 'Terça'
        case 4:
            return 'Quarta'
        case 5:
            return 'Quinta'
        case 6:
            return 'Sexta'
        case 7:
            return 'Sabado'
        case _:
            return '** inválido **'
            
    
 
if __name__ == '__main__':
    for dia in range(0, 9):
        print(f'{dia}: {get_dia_semana(dia)}')


###########
### LUL ###
###########



def get_tipo_dia(dia):
    match dia:
        case 2 | 3 | 4 | 5 | 6 :
            return 'Dia de semana'
        case 1 | 7:
            return 'Fim de semana'
        case _:
            return '** inválido **'
            
 
 
if __name__ == '__main__':
    for dia in range(0, 9):
        print(f'{dia}: {get_tipo_dia(dia)}')