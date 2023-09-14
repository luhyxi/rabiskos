#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 100

int* findPrimes(int n) {
    static int prime_n[MAX_SIZE];
    int primeIndex = 0;
    while (n %2 == 0){
        prime_n[primeIndex] = 2;
        primeIndex++;
        n = n / 2;
    } for (int i = 3; i*i <= n; i = i+2){
        while (n%i == 0){ 
            prime_n[primeIndex] = i;
            primeIndex++;
            n = n/i;}
    } if (n > 2){
        prime_n [primeIndex] = n;
        primeIndex++;}
    return prime_n;
}

bool isUgly(int n){
    int* primes = findPrimes(n);
    int array_len = sizeof primes / sizeof primes[0];
    int i = 0;
    while (i < array_len) {
        if (primes[i] == 7) {
            return false;
        }i++;
    } return true;
}