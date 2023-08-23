# Embedded_Interview_T8
## C PROGRAMING LANGUAGE

<details><summary>BASIC C </summary>
	
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
### DataTypes in C

- The data types in C can be classified as follows:

	| Types | Description |
	|:------:|:--------:|
	| Primitive Data Types | Primitive data types are the most basic data types that are used for representing simple values such as integers, float, characters, etc. |
	| User Defined Data Types | The user-defined data types are defined by the user himself. |
	| Derived Types | The data types that are derived from the primitive or built-in datatypes are referred to as Derived Data Types. |


![image](https://github.com/ManhPhung/Embedded_Interview_T8/assets/141265486/32310e46-effd-4824-b992-171777c9b5fe)



- Primitive Data Types :

	| Data Type | Size (bytes) | Range | Format Specifier |
	|:---------:|:------------:|:-----:|:----------------:|
	| short int | 2 | -32,768 to 32,767 | %hd |
	| unsigned short int | 2 | 0 to 65,535 | %hu | 
	| unsigned int | 4 | 0 to 4,294,967,295 | %u |
	|int | 4 | -2,147,483,648 to 2,147,483,647 | %d | 
	| long int | 4 | -2,147,483,648 to 2,147,483,647 | %ld | 
	| unsigned long int | 4 | 0 to 4,294,967,295 | %lu |
	| long long int | 8 | -(2^63) to (2^63)-1 | %lld |
	| unsigned long long int | 8 | 0 to 18,446,744,073,709,551,615 | %llu | 
	| signed char | 1 | -128 to 127 | %c | 
	| unsigned char | 1 | 0 to 255 | %c | 
	| float | 4 | 1.2E-38 to 3.4E+38 | %f |
	| double | 8 | 1.7E-308 to 1.7E+308 | %lf |
	| long double | 16 | 3.4E-4932 to 1.1E+4932 | %Lf |
</details>

	
<details><summary>BITMASK </summary>

### What is bitmask in C programing language

	In computer programming, the process of modifying and utilizing binary representations of numbers or any other data is known as bitmasking
	The idea for bit masking is based on boolean logic. For those not familiar, boolean logic is the manipulation of 'true' (1) and 'false' (0) through logical operations (that take 0s and 1s as their argument). We are concerned with the following operations:

	- NOT a - the final value is the opposite of the input value (1 -> 0, 0 -> 1)
	- a AND b - if both values are 1, the final value is 1, otherwise the final value is 0
	- a OR b - if either value is 1, the final value is 1, otherwise the final value is 0
	- a XOR b - if one value is 1 and the other value is 0, the final value is 1, otherwise the final value is 0

 	Bit masks are often used when setting flags. Flags are values that can be in two states, such as 'on/off' and 'moving/stationary'.
  

### Setting bit n

	Setting bit n is as simple as ORing the value of the storage variable with the value 2^n.
	
	storage |= 1 << n;
	
	As an example, here is the setting of bit 3 where storage is a char (8 bits):
	
		01000010 
 	OR 	00001000 
  	----------------
	 	01001010
	
	The 2^n logic places the '1' value at the proper bit in the mask itself, allowing access to that same bit in the storage variable.

### Clearing bit n

	Clearing bit n is the result of ANDing the value of the storage variable with the inverse (NOT) of the value 2^n:
	
	storage &= ~(1 << n);
	
	Here's the example again:
	
		01001010 
  	AND 	11110111
   	----------------
   		01000010

### Flipping bit n

	Flipping bit n is the result of XORing the value of the storage variable with 2^n:
	
	storage ^= 1 << n;
	
		01000010 01001010 
  	XOR	00001000 00001000
   	-------------------------
   		01001010 01000010

### Checking bit n

	Checking a bit is ANDing the value of 2^n with the bit storage:
	
	bit = storage & (1 << n);
	
		01000010 01001010
 	AND	00001000 00001000
  	-------------------------
  		00000000 00001000
</details>

## C++ PROGRAMING LANGUAGE

<details><summary>INTRODURING </summary>

- C++ is a general-purpose programming language that was developed as an enhancement of the C language to include object-oriented paradigm. It is an imperative and a compiled language.
	
</details>

<details><summary>CLASS </summary>

- Class in C++ is the building block that leads to Object-Oriented programming. It is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object.
	- A Class is a user-defined data type that has data members and member functions.
	- Data members are the data variables and member functions are the functions used to manipulate these variables together, these data members and member functions define the properties and behavior of the objects in a Class.
	- In the above example of class Car, the data member will be speed limit, mileage, etc, and member functions can be applying brakes, increasing speed, etc.
- An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.
### Defining Class and Declaring Objects

- A class is defined in C++ using the keyword class followed by the name of the class. The body of the class is defined inside the curly brackets and terminated by a semicolon at the end.
	![image](https://github.com/ManhPhung/Embedded_Interview_T8/assets/141265486/cb347c61-0435-4045-8385-16f8df3d43a3)
	Example :
```c++
class SinhVien					// Declare a class that has name SinhVien
{
	Private :				// Member variables ID , Name , age class have access specifier Private
		string ID ; 			
		string Name ;
		unsigned int Age ;
		string Class ;
	Public :				// Member Function get...(), set...() have access specifier Public
		string ID ; 			
		setID();
		setName();
		setAge();
		setClass();
		getID();
		getName();
		getAge();
		getClass();
}
```
### Declaring Objects
When a class is defined, only the specification for the object is defined; no memory or storage is allocated. To use the data and access functions defined in the class, you need to create objects.
```c++
SinhVien sv ;
```
</details>

	 


