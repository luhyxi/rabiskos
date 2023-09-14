#include <stdio.h>
#include <malloc.h>

struct s {
    int arraySize;
    int array[];
};


/*
int main() {
    int desiredSize = 5;
    struct s *ptr;

    ptr = malloc(sizeof(struct s ) + desiredSize * sizeof(int));
    return 0;
}
*/

/* !!! CHALLENGE !!!*/


struct myArray {
    int arrayLenght;
    int array[];
};

int main() {
    int desiredSize;
    struct s *ptr = NULL;

    scanf("%d", &desiredSize);
    size_t size = sizeof(struct myArray);
    ptr = malloc(size + (sizeof (int) * desiredSize));
    return 0;
}