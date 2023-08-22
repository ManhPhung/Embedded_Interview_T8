# Embedded_Interview_T8
## C PROGRAMING LANGUAGE
<details>	
<summary>BASIC C </summary>
	
### VARIABLE
- A variable in C is a memory location with some name that helps store some form of data and retrieves it when required. We can store different types of data in the variable and reuse the >>>same variable for storing some other data any of times.
  
- C variable Syntax :

      data_type variable_name = value; // defining single variable
      data_type variable_name1, variable_name2; // defining mutilple variable


  
  Example :

````c
      int a = 10; // Create a variable is a that have data type is int and value is 10.
      float b,c; // Create two variables are a and b that have data type is float and value is uninitialized.
````
```c
#include <stdio.h>
void tich(int a, int b){  //Đây là hàm tich()
    printf("Tich %d va %d la %d",a, b, a*b);
}
int tong(int c, int d){ //Hàm này có kiểu trả về là int
    return c+d;
}
int main(){
    tich(2,3); // tich 2 va 3 la 6
    printf("Tong c va d la %d",tong(4,5)); //Tong c va d la 9
    return 0;
}
```
  

