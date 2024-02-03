## Table of Contents
- [Includes](#includes)
    - [stdio.h](#stdioh)
    - [stdbool.h](#stdboolh)
    - [math.h](#mathh)
- [Strings and Variables](#strings-and-variables)
    - [Strings](#strings)
    - [Variables](#variables)
    - [Integers](#integers)
- [Functions](#functions)
    - [Basic Functions](#basic-functions)
        - [printf](#printf)
        - [scanf](#scanf)
- [Useage of the Funtions](#useage-of-the-funtions)
  - [Basic useage](#basic-useage)
    - [printf()](#printf-1)
## Includes
### stdio.h
This is needed for the printf and scanf functions
```c
#include <stdio.h>
```
### stdbool.h
This is needed for the bool type
```c
#include <stdbool.h>
```
### math.h
This is needed for the math functions (sqrt, pow, etc.)
```c
#include <math.h>
```

## Strings and Variables
### Strings
In Python we would do this:
```python
string = "Hello"
```
That would create a string with a value of "Hello".
In C we have to do it a bit differently.
Strings are a sequence of characters. <br>
They are declared like this:
```c
char string[10];
```
this creates a string with a length of 10 characters. Which we can later use to assign a value to.<br>
You can also initialize it with a value like this:
```c
char string[10] = "Hello";
```
This creates a string with a length of 10 characters and a value of "Hello". <br>
You can also do this:
```c
char string[] = "Hello";
```
This creates a string with a length of 6 characters and a value of "Hello". <br>
The length is 6 because the compiler automatically adds a null character at the end of the string.

### Variables
Variables are used to store values. <br>
They are declared like this:
```c
int x;
```
This creates an integer variable called x. <br>
You can also initialize it with a value like this:
```c
int x = 5;
```
This creates an integer variable called x with a value of 5. <br>
You can also do this:
```c
int x;
x = 5;
```
This creates an integer variable called x and thn later set the value to 5.

### Integers
Integers are whole numbers. <br>
They are declared like this:
```c
int x;
```
This creates an integer variable called x. <br>
You can also initialize it with a value like this:
```c
int x = 5;
```
This creates an integer variable called x with a value of 5. <br>
You can also do this:
```c
int x;
x = 5;
```
This creates an integer variable called x and thn later set the value to 5.

# Functions
## Basic Functions

### printf
This function is used to print text to the console. It is declared like this:
```c
printf("Hello World!"); // This prints "Hello World!" to the console
```
### scanf
This one is to get input from the user, just like input() from python. It is declared like this:
```c
int x; //We define the variable x first because scanf needs a variable to store the input
scanf("%d", &x); // This gets input from the user and stores it in x
```
#### Formats for scanf
To get thn set the data taken from scanf we need to do something like this: 
```c
scanf("%format", data);
```
here the type is the format for example "d" is for int, so if the data we get the from the user is to be handle as an integar we use `scanf("%d", data)` this will make so the data is stored as an int. <br>
Like so for each datatype the format is different and needs to be defined. The formats are as follows: <br>

| Data Type | Size (bytes) | Format Specifier |
|:---------:|:------------:|:----------------:|
|    int    |      4       |        %d        |
|   char    |      1       |        %c        |
|   float   |      4       |        %f        |
|  double   |      8       |       %lf        |


In Python we wouldn't use format nor define the variable and its datatype rather do this:
```python
x = input()
```
The compiler would do it by itself.<br>
But in C we have to define the variable first and then use scanf to get the input and store it in the variable.<br>

# Useage of the Funtions
## Basic useage

### printf()
As we know this is to show the user something, like greetings and such.
But to show data like strings or variables we need to use the same format thing like `scanf()`. <br>
Lets say we have a integar stored in the variable named `age`, and we want to print that. For python we would just do `print(age)`, this would tell the compiler that its a value of somesort. But for C we need cant do that, rather we would have to do this:
```c
printf("%d", age);
```
This will tell the compiler that age is a `int`, and that will print the value. And we use the format defined in the [scanf](#scanf) for the datatypes accordingly. <br>
We can user multiple data like this, as well multiple datatypes:
```c
// The ";" is important after each line
char name[] = "name";
int age = 20;

printf("%c %d", name, age);
```
The output would be: **name 20**
```c
printf("Name: %c \nAge: %d", name, age); // The \n is to go to a new line
```
The output would be:<br> 
**Name: name <br>
Age: 20**