#include <stdio.h>
#include <stdint.h>

// ^ This assigns the symbol "int32_t" to represent "int" and "uint32_t" to represent "unsigned int".

int main (int argc, char** argv)
{
  int32_t  A  = 0;
  uint32_t UA = 0;
  printf("The value of A is %0d and the value of UA is %0u", A, UA);
}
