# Embedded_Interview_T8
## C PROGRAMING LANGUAGE
<details>	
<summary>BASIC C </summary>
	
### Variable
- A variable in C is a memory location with some name that helps store some form of data and retrieves it when required. We can store different types of data in the variable and reuse the same variable for storing some other data any of times.
  
- C variable Syntax :

```c
      data_type variable_name = value; // defining single variable
      data_type variable_name1, variable_name2; // defining mutilple variable
``` 
  Example :

```c
	int a = 10; // Create a variable is a that have data type is int and value is 10.
	float b,c; // Create two variables are a and b that have data type is float and value is uninitialized.
```
### Type of data in C

- The data types in C can be classified as follows:

| Types | Description |
|:------:|:--------:|
| Primitive Data Types | Primitive data types are the most basic data types that are used for representing simple values such as integers, float, characters, etc. |
| User Defined Data Types | The user-defined data types are defined by the user himself. |
| Derived Types | The data types that are derived from the primitive or built-in datatypes are referred to as Derived Data Types. |

| Data Type | Size (bytes) | Range | Format Specifier |
|:---------:|:------------:|:-----:|:----------------:|
| short int | 2 | -32,768 to 32,767 | %hd |
| unsigned short int | 2 | 0 to 65,535 | %hu | 
| unsigned int | 4 | 0 to 4,294,967,295 | %u |
|int | 4 | -2,147,483,648 to 2,147,483,647 | %d | 
| long int | 4 | -2,147,483,648 to 2,147,483,647 | %ld | 
| unsigned long int | 4 | 0 to 4,294,967,295 | %lu |
| long long int | 8 | -(2^63) to (2^63)-1 | %lld |
 


