# Lesson 1 - Variables
## What is a variable?
A variable is a container that stores data. There are many data types. This lesson will cover only two data type. The integer and the unsigned integer. For purposes of human readability, these look the same. However the hardware of the computer will treat them differently. First let's look at the integer type. The following code block will be eventually be covered what it means in its entirety. Just for now understand that a lot of what you are about to see is directly related to how the C language is defined.

Let's consider the following block of code (you may recognize some of this from lesson 0):
```C
#include <stdio.h>
#include <stdint.h>

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
