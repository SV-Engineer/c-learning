# Lesson 1 Practice Solutions

## Definitions
| Term | Defintion |
|----------------------------|--------------------------------------------------------|
| **compile-time** | When invoking the command `gcc`, the compiler activates and reads your code. It then turns your code into instructions that the computer can understand. The duration in which this process takes places is called **compile-time**|
| **run-time** | When calling the executable produced by invoking the `gcc` command, the computer takes the instructions that the compiler put together and performs the provided operations. The duration for which this occurs is called **run-time**|
| **MSB** | Most Significant Bit; the highest indexed bit in the vector that represents a binary number. Indexing starts at 0. A 32-bit number has a **MSB** of bit31. A 16-bit number has a **MSB** of bit15. |

## Practice
### Practice 1 Question
Modify the example1.c file to declare the variable `A` without an initial value (delete the "= 0" portion). Compile and run the output with `gcc L1_example.c -o practice1.exe` then `practice1.exe`. What is the output? Run it twice more. Was the output the same each time?

### Practice 1 Explanation
When declaring a variable, the code at **run-time** will pick somewhere in RAM that is available to be used. The memory address that is picked is not persistent between executable calls. Thus from a human's point of view, the address selected is random. Computers do not zero out data in the RAM unless explicitly told to. Therefore some other program may or may not have recently used the random RAM address selected and had data stored there that is no longer in use. If you declare a variable without an initializer, it will contain an "artifact" from some other process.


### Practice 2 Question
Modify the example1.c file to declare the variable `A` with an initial value of 4294967295 (This is 2<sup>32</sup> - 1). Compile and run the output with `gcc L1_example.c -o practice2.exe` then `practice2.exe`. Is the output what you expected?

### Practice 2 Explanation
This behavior is due to how the computer treats negative numbers. It is known as two's complement. A short rundown is that numbers are composed of binary values stored in a sort of vector where each entry in the vector is a bit and each bit can only be 1 or 0. (This is where 2 raised to a power comes from). The signed number could look like as follows:

|  S | 30 | 29 | 28 | 27 | 26 | 25 | 24 | 23 | 22 | 21 | 20 | 19 | 18 | 17 | 16 | 15 | 14 | 13 | 12 | 11 | 10 |  9 |  8 |  7 |  6 |  5 |  4 |  3 |  2 |  1 |  0 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 0 | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 0 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 1 | 0 | 1 | 0 | 1 | 01|

The **MSB** of the number represents the sign. Where a 1 is negative and a 0 is positive. The rest of the bits are the magnitude; the value of the number. To find the negation of a number, 2's complement definition tells us to make all the 0's in the number a 1 and all the 1's in the number a 0.

### Practice 2 Explanation Example
Lets take an 8-bit value for simplicities sake. This implies bit7, the **MSB**, is the sign bit.
```int8_t number = 3;```

The binary representation of '3' is `0b0000_0011`. If we use the definition of 2's complement as described previously, then the steps look like:
  1. `0b0000_0011` --> Invert all bits -->
  2. `0b1111_1100` --> Add One -->
  3. `0b1111_1101` or -3 in decimal

However, what if we accidentally (or purposefully) tell the computer to treat the -3 as an unsigned number? If that is the case, the **MSB** is no longer a sign bit but rather part of the magnitude. Recall that 3 in binary is represented as `0b0000_0011`. If we interpret the value -3 (`0b1111_1101`) as an unsigned number, then we would get a value of 253, not 3. This is not a complete explanation and the full explanation is beyond the scope of this lesson. A future lesson will be dedicated to binary math and how a computer uses 2's complement to interpret numbers.

### Practice 3 Question
Modify the example1.c file to declare the variable `UA` with an initial value of -1. Compile and run the output with `gcc L1_example.c -o practice3.exe` then `practice3.exe`. What is the output here? (More on why in the solutions.md file).

### Practice 3 Explanation
A: The explanation for practice three is the reverse of the explanation for practice 2. The -1 is represented in 2's complement format as `0b1111_1111_1111_1111_1111_1111_1111_1111`. Since the data type is unsigned, then the computer interprets it as 4294967295 instead of -1.
