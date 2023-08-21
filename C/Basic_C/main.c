#include <stdio.h>

int a = 10;

void display(){
    int a = 20;
    printf("value of a is: %d\n",a);
    return;
}

int main(){

    display();

    printf("value of a is: %d\n",a);
    printf("Hello World!!!\n");

    return 0;
}