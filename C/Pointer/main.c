#include <stdio.h>

/*
    Pointer is a variable that store the address of another varible.
*/

int main(){

    int a = 10;
    
    int *ptra = &a; // Create a pointer has name is ptra that store the address of variable a

    printf("Value of Variable a is : %d \n", *ptra);
    printf("Address of Variable a is : %p \n", ptra);

    return 0;
}