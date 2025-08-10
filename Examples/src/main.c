/** @file main.c
 * @author Austin Harrison
 * @brief MAIN.
 * 
 * @verbatim
 * rm ./build/a.out &&  gcc -I ./Examples/inc/ ./Examples/src/main.c ./Examples/src/recursion_with_switch_statements.c -o ./build/a.out && ./build/a.out
 * @endverbatim
 */

#include <stdio.h>
// #include "recursion_with_switch_statements.h"
// #include "log.h"

// #define NUM_INPUTS 6

// const char FN_INPUTS[NUM_INPUTS] = {
//   'S',
//   'A',
//   'B',
//   'C',
//   'D',
//   'E'
// };

int main (int argc, char* argv[])
{
  // bit_fields_t bit_fields = {0};
  
  // // Pre-iteration the data structure is 0
  // DELINEATE;
  // log_bit_fields((bit_fields_t*) &bit_fields);

  // // Notice how on the console iteration '1' sets all the bitfields to their values.
  // // The data structure is reset to 0 and each iteration post '1' shows only the bit-field in use set.
  // for (int i = 0; i < NUM_INPUTS; i++) {
  //   DELINEATE;
  //   INFO("Iteration: %0d", i+1);
  //   modify_multiple_fields(FN_INPUTS[i], (bit_fields_t*) &bit_fields);
  //   log_bit_fields((bit_fields_t*) &bit_fields);

  //   // Reset fields to 0
  //   bit_fields.w[0] = 0;
  //   bit_fields.w[1] = 0;
  // }

  printf("HELLO WORLD!");
  return 0;
}
