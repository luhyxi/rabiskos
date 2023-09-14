/* PUTA QUE PARIU QUE PROGRAMA FEIO!!!!!!!!!
    PROGRAMA MAIS FEIO QUE EU JÁ ESCREVI!! */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50000

int lengthOfLongestSubstring(char * s){
    int s_Len = strlen(s); int i;
    int size_Sub = 0; int Array_s[MAXLEN];
    
    // Alocar as substrings (como int) dentro de um array
    int n = 0;
    for (i = 0; i < s_Len; i++){
        if (s[i] != s[i]){
            size_Sub ++; } else {
            size_Sub = 1;}
        Array_s[n] = size_Sub; n++;}



    // Encontra a maior Substring
    int max = Array_s[0];
    for (i = 1; i < n; i++)
        if (Array_s[i] > max)
            max = Array_s[i]; return max;
}