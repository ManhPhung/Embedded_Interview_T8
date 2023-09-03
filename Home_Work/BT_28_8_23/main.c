#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    bool bcheck;
    uint8_t index;
}Check;


int strLen(char string[])
{
    int length = 0;
    int i = 0;
    while(string[i]!='\0') i++;
    length = i;
    return length;
}

void findText(char string[], char stringIn[])
{
    bool checkArr = false;
    int count = 0;
    for(int i = 0; i < strLen(string); i++)
    {
        if(string[i]==stringIn[0])
        {
            bool check = true;
            for(int j = 0; j < strLen(stringIn); j++)
            {
                if(string[i+j]!=stringIn[j])    check = false;
            }
            if(check == true)
            {   
                ++count;   
                checkArr = true;
                printf("Chuoi xuan hien lan %d tai vi tri %d\n", count, i);            
            }
        }
    }
    if(checkArr == false)
    {
        printf("Chuoi ko xuat hien");
    }
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
    char string[] = "to help people around today we the world learn how to do anything. today we learn about that";

    // upCase(string);
    findText(string,"today we");
//    replaceString(string, "around the world", "to do" );

    return 0;
}