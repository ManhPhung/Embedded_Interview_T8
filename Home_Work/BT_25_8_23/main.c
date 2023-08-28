#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    char *firstChar;
    uint8_t Lengh;
}Word;

char array[] = "mot hai ba, mot hai hai mot, ba bon, bon ba nam";

Word *splitString(char array[]){

    int i = 0;
    int size = 1;

    while( array[i] != '\0')
    {    
        if(array[i]==' '){
            size++;
        }    
        i++;
    }

    i = 0;
    int index = 0;
    int count = 0;
    Word *word = malloc( size *sizeof(Word));
    word[index].firstChar = array;

    while( array[i] != '\0')
    {    
        if(array[i]==' '|| array[i]==','){
            word[index].Lengh = count ;
            word[++index].firstChar = array+i+1;       
            count = 0;
        } 
        else{
            count++;
        }   
        i++;
    }

    word[index].Lengh = count;

    return word;
}

bool equalWord(Word word1, Word word2){

    if(word1.Lengh != word2.Lengh)
    {
        return false;
    }
    else{
        for(int i = 0; i< word1.Lengh; i++)
        {
            if(word1.firstChar[i]!=word2.firstChar[i])
            {
                return false;
            }
        }
        return true;

    }
}

int countRepeat(Word *word, int iCompare){

    int count = 0;
    for(int i; i < 15; i++){
        if(equalWord(word[iCompare], word[i])==1)
        {
            count++;
        }        
    }
    return count;
}

void display(Word word){
    for(int i = 0; i< word.Lengh; i++)
    {
        printf("%c", word.firstChar[i]);
    }
}


int main(){

    Word *word = splitString(array);

    // printf("%d",countRepeat(word, 0));
    int wordCompare = 12;
    int count = 0;
    for(int i = 0;i <16; i++)
    {
        if(equalWord(word[wordCompare], word[i])== true)
        {
            count++;
        }
    }
    printf("%d",count);

}

