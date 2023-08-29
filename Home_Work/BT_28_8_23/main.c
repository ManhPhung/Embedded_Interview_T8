#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *firstChar;
    uint8_t lengthOfChar;
}Words;

void handleString(char string[])
{

    int index = 0;
    int size = 1;
    while(string[index] != '\0')
    {
        if(string[index] == ' ')
        {
            ++size;
        }
        ++index;
    }
    printf("Size : %d", size);
    Words * singleWord = malloc(size * sizeof(Words));
}

int strLen(char string[])
{
    int length = 0;
    int i = 0;
    while(string[i]!='0') i++;
    length = i;
    return length;
}

void upCase(char string[])
{
    int thresHold = 0;
    int index = 0;

    char tempString[strLen(string)];
    while (string[index] != '\0')
    {
        tempString[index] = string[index];
        index++;
    }
    index = 0;

    while(tempString[index]!='.')   index++;
    thresHold = index;
    index = 0;

    while(tempString[index]!='\0')
    {
        if(index>thresHold && tempString[index]!=' ')
        {
            tempString[index] = tempString[index] - 32;
        }
        index++;
    }
    printf("%s\n", tempString);
}


int main()
{
    char string[] = "to help people around the world learn how to do anything. today we learn about that";

    upCase(string);
//    handleString(string);

    return 0;
}