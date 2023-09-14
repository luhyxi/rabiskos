// Tentar com strtok????

#include <stdio.h> 
#include <string.h>
#include <stdbool.h>

#define MAXLEN 300

void wordPattern(char * s){
    char ch_pattern[MAXLEN];
    int i = 0;

    while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
    putchar(s[i]); i++;}
}

int main(){
    char string[] = "Buceta e pau";
    wordPattern(string);
    return 0;
}