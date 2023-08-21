# include <stdio.h>

int main()
{

    int array[] = {2,5,6,8,9,10};
    int k = 15;
    int length = (sizeof(array)/sizeof(int)); // Số lượng phần tử trong chuỗi array[]
    int index = 1;  // Chỉ mục số cặp số thỏa mãn

    for(int i = 0; i < length-1; i++)
        {
            for(int j=i+1; j < length; j++)
            {
                if( (array[i] | array[j]) == k)
                {
                    printf("Cap so thu %d la : (%d;%d)\n", index, array[i], array[j]);
                    ++index;
                }
            }
        }

    return 0;

}
