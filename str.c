#include "str.h"
#include <string.h>
#include <stdlib.h>

// Implementação parcial do TAD Str, visto em aula
// Não implementa suporte a UTF8

// uma Str está sendo implementada como somente um ponteiro para a
//   área que contém a string. Poderia manter outros dados aqui,
//   para simplificar ou acelerar a implementação de alguma operação
//   (tamanho da string, por exemplo)

#define _TAMSTR_ = 20

struct _str
{
    char *bytes;
};

///
///      *FUNÇÕES MAIORES*
///
///

// função auxiliar que retorna o valor de 'a', ajustado entre min e max
int ajusta(int a, int min, int max)
{
    if (a < min)
        return min;
    if (a > max)
        return max;
    return a;
}

Str str_cria(char *s)
{
    Str novo;
    novo = malloc(sizeof(struct _str));
    if (novo != NULL)
    {
        novo->bytes = malloc(strlen(s) + 1);
        if (novo->bytes != NULL)
        {
            strcpy(novo->bytes, s);
        }
        else
        {
            free(novo);
            novo = NULL;
        }
    }
    return novo;
}

Str str_cria_linha(FILE *arq)
{
    Str res = str_cria("");
    const int tam = 20;
    char s[tam];
    bool achei_o_fim_da_linha = false;
    while (!achei_o_fim_da_linha && fgets(s, tam, arq) != NULL)
    {
        int n = strlen(s);
        if (s[n - 1] == '\n')
        {
            s[n - 1] = '\0';
            achei_o_fim_da_linha = true;
        }
        Str tmp = str_cria(s);
        str_altera(res, -1, 0, tmp);
        str_destroi(tmp);
    }
    if (!achei_o_fim_da_linha && str_tam(res) == 0)
    {
        str_destroi(res);
        return NULL;
    }
    return res;
}

///
///   *FUNÇÕES MENORES*
///

void str_destroi(Str s)
{
    if (s != NULL)
    {
        free(s->bytes);
        free(s);
    }
}

int str_tam(Str s)
{
    return strlen(s->bytes);
}

// TIRADO DO "t.2":
// retorna o número de bytes usados por um caractere codificado em UTF8 iniciando pelo byte em 'b'
//
//
//
int utf8_num_bytes(char b)
{
    // se o byte for 0xxxxxxx, o caractere ocupa só um byte (código entre 0000 e 007F)
    if ((b & 0b10000000) == 0b00000000)
        return 1;
    // se o byte for 110xxxxx, o caractere ocupa 2 bytes, 5 bits no primeiro e 6 no segundo (0080 a 07FF)
    if ((b & 0b11100000) == 0b11000000)
        return 2;
    // se o byte for 1110xxxx, o caractere ocupa 3 bytes, 4 bits no primeiro e 6 nos outros (0800 a FFFF)
    if ((b & 0b11110000) == 0b11100000)
        return 3;
    // se o byte for 11110xxx, o caractere ocupa 4 bytes, 3 bits no primeiro e 6 nos outros (10000 a 10FFFF)
    if ((b & 0b11111000) == 0b11110000)
        return 4;
    // se começar com outra coisa, temos um problema
    return 0;
}



//
// *ESTRUTURA QUE TORNA UTF-8 PARA UNICODE* 
//
// (SERÁ QUE É POSSÍVEL PULAR TAL ESTRUTURA?)
// 
//
//
// retorna o código do caractere armazenado em UTF-8 a partir de 'p'
int utf8_para_codigo_unicode(char *p)
{
    int n = utf8_num_bytes(p[0]);
    if (n == 0)
        return 0; // erro!
    if (n == 1)
        return p[0];
    if (n == 2)
        return ((p[0] & 0b00011111) << 6) | (p[1] & 0b00111111);
    if (n == 3)
        return ((p[0] & 0b00001111) << 12) | ((p[1] & 0b00111111) << 6) | (p[2] & 0b00111111);
    if (n == 4)
        return ((p[0] & 0b00000111) << 18) | ((p[1] & 0b00111111) << 12) | ((p[2] & 0b00111111) << 6) | (p[3] & 0b00111111);
    // erro se chegar aqui
}

///

///
///    CARACTER ["ã"]   --->  [DATA]
/// 
///        a gente vai ter que printar o "char s"
///
///      coloquei o w para "ligar os dois códigos", ainda pareciam
///    desligados de alguma forma????
///
// converte o código do caractere 'c' para string UTF-8 a partir de 's' (que tem que ter espaço para 5 char)
void utf8_de_codigo_unicode(int c, char s[5])
{

    //// int w = utf8_para_codigo_unicode(c);

    if (c <= 0x007F)
    {
        s[0] = c;
        s[1] = '\0';
    }
    else if (c <= 0x07FF)
    {
        s[0] = (c >> 6) | 0b11000000;
        s[1] = (c & 0b00111111) | 0b10000000;
        s[2] = '\0';
    }
    else if (c <= 0xFFFF)
    {
        s[0] = (c >> 12) | 0b11100000;
        s[1] = ((c >> 6) & 0b00111111) | 0b10000000;
        s[2] = (c & 0b00111111) | 0b10000000;
        s[3] = '\0';
    }
    else if (c <= 0x10FFFF)
    {
        s[0] = (c >> 18) | 0b11110000;
        s[1] = ((c >> 12) & 0b00111111) | 0b10000000;
        s[2] = ((c >> 6) & 0b00111111) | 0b10000000;
        s[3] = (c & 0b00111111) | 0b10000000;
        s[4] = '\0';
    }
    else
    {
        // erro!
        s[0] = '\0';
    }
}

// TIRADO DO "chuc.c"
//
//
//

bool utf8_prim_valido(char b)
{
    return utf8_num_bytes(b) > 1;
}

///

int str_numbytes(Str s, int c)
{
    int c = str_substr;
    if (c != NULL)
    {
        // aqui tem que criar um parametro "[]" para que
        // o código detecte  a existencia de uma condicional para
        //a produção de uma string, nessse exercício é necessário
        // para medir o tamanho byte de strings Unicode 

        strncpy ();
    }
    
    return strlen(s->bytes);
}

int str_char(Str s, int i)
{
    int t = str_tam(s);
    if (i < 0)
    {
        i += t;
    }
    if (i >= t || i < 0)
        return -1;
    return s->bytes[i];
}

// p é uma posição em s, podendo ser positiva (medida a partir do início)
//   ou negativa (medida a partir do final)
// n é o tamanho de uma substring a partir de p
// esta função corrige p para ser positivo e estar em uma posição
//   existente de s, e n para representar um tamanho válido em s
static void ajeita_pos_e_tam_de_substr(Str s, int *p, int *n)
{
    int t = str_tam(s);
    if (*p < 0)
    {
        // converte posições negativas no equivalente positivo
        //   se p for -1, vira t; se for -2, vira t-1 etc
        *p = *p + t + 1;
    }
    // faz p ficar nos limites da string (entre 0 e t)
    *p = ajusta(*p, 0, t); // este era o bug em aula, faltava ajustar p
    // faz n ficar nos limites da string
    *n = ajusta(*n, 0, t - *p);
}

Str str_substr(Str s, int p, int n)
{
    // cria uma nova Str para conter a substring
    Str sub = malloc(sizeof(struct _str));
    if (sub == NULL)
        return NULL;

    // corrige p e n para ficarem nos limites de s
    ajeita_pos_e_tam_de_substr(s, &p, &n);

    // aloca memória para os n caracteres mais o '\0'
    sub->bytes = malloc(sizeof(char) * (n + 1));
    if (sub->bytes == NULL)
    {
        free(sub);
        return NULL;
    }

    // copia n bytes, a partir da posição p de s para sub
    strncpy(sub->bytes, s->bytes + p, n);
    // põe o terminador no final de sub
    sub->bytes[n] = '\0';

    return sub;
}

// retorna a posição da primeira ocorrência do caractere 'c' em 's' ou -1
int str_poschar(Str s, int c)
{
    for (int i = 0;; i++)
    {
        int ci = str_char(s, i);
        if (ci == '\0')
            break;
        if (ci == c)
            return i;
    }
    return -1;
}

// retorna 'true' se 's' e 'o' forem iguais
bool str_igual(Str s, Str o)
{
    return strcmp(s->bytes, o->bytes) == 0;
}

// altera 's', substituindo os 'n' caracteres a partir de 'p' pelo conteúdo de 'o'
// valores negativos de 'n' são tratados como 0
// se 'p' além do final de 's', deve ser tratado como logo após o final
// se 'p' antes do início de 's', deve ser tratado cono logo antes do início
// valores negativos de 'p' referem-se ao final de 's' (-1 é logo após o final de 's',
//  -2 logo antes do último caractere, etc.)
void str_altera(Str s, int p, int n, Str o)
{
    // corrige p e n para ficarem nos limites de s
    ajeita_pos_e_tam_de_substr(s, &p, &n);

    // calcula alguns tamanhos
    int tam_org = str_tam(s);
    int tam_ini = p;                     // caracteres a copiar do início de s
    int tam_ins = str_tam(o);            // caracteres a copiar de o
    int tam_fim = tam_org - tam_ini - n; // caracteres do final de s
    int tam_novo = tam_ini + tam_ins + tam_fim;

    // aloca memória para a string resultante
    char *b = malloc(tam_novo + 1);
    if (b == NULL)
    {
        return; // xi, quem chama não tem como saber que deu errado
    }
    // copia tam_novo bytes para a nova região:
    //   tam_ini bytes do início de s
    //   tam_ins bytes de o e
    //   tam_fim bytes do final de s
    strncpy(b, s->bytes, tam_ini);
    strncpy(b + tam_ini, o->bytes, tam_ins);
    strncpy(b + tam_ini + tam_ins, s->bytes + tam_ini + n, tam_fim);
    b[tam_novo] = '\0';

    // substitui a string original
    free(s->bytes);
    s->bytes = b;
}

#include <assert.h>

int main()
{
    Str s1, s2;
    s1 = str_cria("ação");
    s2 = str_cria("ã");
    
    printf ("\n \n \n \n %d", (str_numbytes(s1)));
    printf ("\n \n \n \n %d", (str_numbytes (s2)));   



    printf ("\n \n \n \n %d", str_numbytes(&s1[0]));

}
