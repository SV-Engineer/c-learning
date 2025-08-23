/** @file recursion_with_switch_statements.c
 * @author Austin Harrison
 * @brief Example of using recursion with switch statements to avoid repeated code.
 * 
 */

#if RUN==1
  #include <stdint.h>
  #include <stdio.h>
  #include "recursion_with_switch_statements.h"

  #define NUM_INPUTS 6

  const char FN_INPUTS[NUM_INPUTS] = {
    'S',
    'A',
    'B',
    'C',
    'D',
    'E'
  };


  static __inline int __to_upper(char* c);

  int run (void) {
    DELINEATE;
    INFO("RUN#%0d - RECURSION WITH SWITCH STATEMENTS", RUN);

    bit_fields_t bit_fields = {0};

    // Pre-iteration the data structure is 0
    DELINEATE;
    log_bit_fields((bit_fields_t*) &bit_fields);

    // Notice how on the console iteration '1' sets all the bitfields to their values.
    // The data structure is reset to 0 and each iteration post '1' shows only the bit-field in use set.
    for (int i = 0; i < NUM_INPUTS; i++) {
      DELINEATE;
      INFO("Iteration: %0d", i+1);
      modify_multiple_fields(FN_INPUTS[i], (bit_fields_t*) &bit_fields);
      log_bit_fields((bit_fields_t*) &bit_fields);

      // Reset fields to 0
      bit_fields.w[0] = 0;
      bit_fields.w[1] = 0;
    }

    return 0;
  }

  static __inline int __to_upper(char* c) {
    if (((uint8_t) (*c)) >= 'a' && ((uint8_t) (*c)) <= 'z') {
      *c = (char) (((uint8_t) *c) - UPPER_TO_LOWER_DIFF);
      return 0;
    }

    else {
      return 0;
    }
  }

  void modify_multiple_fields (char selection, bit_fields_t* bit_fields) {
    char sel = selection;

    if (__to_upper((char*) &sel) > -1) {
      INFO("%c input in use", sel);
      switch (sel) {
        case 'S': // Set All bitfields
          modify_multiple_fields('A', bit_fields);
          modify_multiple_fields('B', bit_fields);
          modify_multiple_fields('C', bit_fields);
          modify_multiple_fields('D', bit_fields);
          modify_multiple_fields('E', bit_fields);
          break;

        case 'A':
          bit_fields->b.A = 0xA;
          break;

        case 'B':
          bit_fields->b.B = 0xB;
          break;

        case 'C':
          bit_fields->b.C = 0xC;
          break;

        case 'D':
          bit_fields->b.D = 0xD;
          break;

        case 'E':
          bit_fields->b.E = 0xE;
          break;
        
        default:
          INFO("%c is an invalid input to modify_multiple_fields function", sel);
          break;
      }
    }
  }

  void log_bit_fields (bit_fields_t* bit_fields) {
    INFO("BITFIELD A == 0x%04x", bit_fields->b.A);
    INFO("BITFIELD B == 0x%04x", bit_fields->b.B);
    INFO("BITFIELD C == 0x%04x", bit_fields->b.C);
    INFO("BITFIELD D == 0x%04x", bit_fields->b.D);
    INFO("BITFIELD E == 0x%04x", bit_fields->b.E);
  }

#endif /* RUN == 1*/
