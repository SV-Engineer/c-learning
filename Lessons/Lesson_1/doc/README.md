# Lesson 1 - Variables
## What is a variable?
A variable is a container that stores data. There are many data types. This lesson will cover only two data type. The integer and the unsigned integer. For purposes of human readability, these look the same. However the hardware of the computer will treat them differently. First let's look at the integer type. What the following code block means in its entirety will eventually be covered. For now, understand that a lot of what you are about to see is directly related to how the C language is defined.

### Variable Example 1 - `int`
Let's consider the following block of code (you may recognize some of this from lesson 0):
```C
#include <stdio.h>

int main (int argc, char** argv)
{
  // Declare a variable 'A'
  int A = 0;
  printf("The Value of A is %0d", A);

  // Update variable 'A'
  A = 1;
  printf("The Value of A is %0d", A);
}
```

In this code block, let us focus on the line `int A = 0;` what does this mean? This is the standard format for declaring a variable of type `int` in the C language. 

The `int` portion is telling the compiler that the variable is an `integer` or `int` type. What is the `integer` type? It is a 32-bit signed number that can represent to the computer positive and negative numbers. The domain of an `int` type is [-2147483648, 2147483647] or [-2<sup>31</sup>, 2<sup>31</sup> - 1]. More on why this is, is coming in future lessons. Just know that the limitation exists for now. From the standard integer header file, `stdint.h`, this has equivalency to int32_t. When you see this nomenclature, know they can be substituted for one another.

The `A` portion is the user defined name of the variable. The name of a variable could be anything. It is best practice to give variables meaningful names so that the code is readable later to yourself and others. In this example `A` is not a descriptive name because it is not obvious from the name what it is intended for. More on this in the next section.

>**Best Practice: Give variables meaningful names.**

The third portion `= 0` is the initial value of the variable. If this initial value were left out with the declaration `int A;` instead, then it could initially contain anything. It is considered best practice to always initialize variables to a known value upon declaration.
>**Best Practice: Always initialize variables to known values upon declaration.**

The last portion `;` is the statement termination indicator. This tells the compiler to stop evaluation of the current statement and move on to the next statement. See, coding languages are universally a description of desired behavior composed of a collection of **statements** that contain **keywords** and **symbols**; `int` is a keyword, `A` is a userdefined symbol, `=`, similarly to `;`, is a symbol reserved for the language and thus it can only be used in the expected context. In this context, we are assigning a value to `A` and thus the `=` symbol is known as the assignment operator. 

Lastly, lets look at the code snippet `A=1;`. Notice that this statement does not have the `int` keyword because we have already declared the variable to be of `int` type previously. One needs to declare a variable's type once and only once. As previously described, we are updating the data stored in the container defined as `A` in this statement.

### Variable Example 2 - `unsigned int`
Let's consider the following block of code:
```C
#include <stdio.h>

int main (int argc, char** argv)
{
  // Declare a variable 'UA'
  unsigned int UA = 0;
  printf("The Value of UA is %0d", UA);

  // Update variable 'UA'
  UA = 65000;
  printf("The Value of UA is %0d", UA);
}
```

In this code block, let us focus on the line `unsinged int A = 0;` what does this mean? This is the standard format for declaring a variable of type `unsigned int` in the C language.

The `unsigned int` portion is telling the compiler that the variable is an `unsigned integer` or `unsigned int` type. What is the `unsigned integer` type? It is a 32-bit unsigned number that can represent to the computer positive numbers only; negative numbers do not exist for this data type. The domain of an `unsigned int` type is [0, 4294967296] or [0, 2<sup>32</sup>]. More on why this is, is coming in future lessons. Just know that the limitation exists for now. From the standard integer header file, `stdint.h`, this has equivalency to uint32_t. When you see this nomenclature, know they can be substituted for one another.

The rest of the explanation is the same from Example 1. The only difference between `int` and `unsigned int` is the domain of values they can represent.

## Practice
1. Modify the example1.c file to declare the variable `A` without an initial value (delete the "= 0" portion). Compile and run the output with `gcc L1_example.c -o practice1.exe` then `practice1.exe`. What is the output? Run it twice more. Was the output the same each time? (More on why in the solutions.md file).

2. Modify the example1.c file to declare the variable `A` with an initial value of 4294967295. Compile and run the output with `gcc L1_example.c -o practice2.exe` then `practice2.exe`. Is the output what you expected? (More on why in the solutions.md file).

3. Modify the example1.c file to declare the variable `UA` with an initial value of -1. Compile and run the output with `gcc L1_example.c -o practice3.exe` then `practice3.exe`. What is the output here? (More on why in the solutions.md file).
