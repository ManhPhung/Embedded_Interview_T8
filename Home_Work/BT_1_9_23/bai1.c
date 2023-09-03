#include <stdio.h>
#include <stdlib.h>

void reverseWords(char *str) {
    // Tìm chiều dài của chuỗi
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Tạo một mảng tạm thời để lưu trữ từng từ
    char *tempWord = (char *)malloc(length + 1);

    int i = length - 1;
    int start, end;

    while (i >= 0) 
    {
        // Bỏ qua khoảng trắng ở cuối chuỗi
        while (i >= 0 && str[i] == ' ') 
        {
            i--;
        }

        // Gán vị trí cuối cùng của từ
        end = i;

        // Tìm vị trí đầu tiên của từ
        while (i >= 0 && str[i] != ' ') 
        {
            i--;
        }

        // Gán vị trí đầu của từ
        start = i + 1;

        // Sao chép từ vào mảng tạm thời
        int wordLength = end - start + 1;
        for (int j = 0; j < wordLength; j++) 
        {
            tempWord[j] = str[start + j];
        }
        tempWord[wordLength] = '\0';

        // In từ ra màn hình
        printf("%s ", tempWord);
    }

    free(tempWord);
}

int main() {
    char string[] = "xuan ha thu dong";
    reverseWords(string);
    printf("\n");

    return 0;
}
