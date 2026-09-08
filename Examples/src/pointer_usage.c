/** @file pointer_usage.c
 * @author Austin Harrison
 * @brief Examples of pointers and their use (src).
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include "pointer_usage.h"

#if RUN==2
    #include "log.h"

    int run (void) {

      int8_t    var_int8_t     = (int8_t)   0x5a;
      int16_t   var_int16_t    = (int16_t)  0xDEAD;
      int32_t   var_int32_t    = (int32_t)  0xDEADBEEF;
      uint8_t   var_uint8_t    = (uint8_t)  0x5A;
      uint16_t  var_uint16_t   = (uint16_t) 0xDEAD;
      uint32_t  var_uint32_t   = (uint32_t) 0xDEADBEEF;
      float     var_float      = 3.14159f;
      double    var_double     = 2.71828;

      PU_LOG_INT8(var_int8_t);
      PU_LOG_INT16(var_int16_t);
      PU_LOG_INT32(var_int32_t);
      PU_LOG_UINT8(var_uint8_t);
      PU_LOG_UINT16(var_uint16_t);
      PU_LOG_UINT32(var_uint32_t);
      PU_LOG_FLOAT(var_float);
      PU_LOG_DOUBLE(var_double);
      return 0;
    }

#endif /* RUN==2*/

/** @brief This function shall only be called with a helper macro that satisfies REG_EX: PU_LOG_\w+\d+ */
void pu_print(primitive_types_t T, void* d) {
  switch (T) {
    case(E_INT8):
      printf("Printing T=E_INT8    => %10d (decimal)  --  0x%08x (hex)\n", *(int8_t*)d, *(int8_t*)d);
      break;
    case(E_INT16):
      printf("Printing T=E_INT16   => %10d (decimal)  --  0x%08x (hex)\n", *(int16_t*)d, *(int16_t*)d);
      break;
    case(E_INT32):
      printf("Printing T=E_INT32   => %10d (decimal)  --  0x%08x (hex)\n", *(int32_t*)d, *(int32_t*)d);
      break;
    case(E_UINT8):
      printf("Printing T=E_UINT8   => %10d (decimal)  --  0x%08x (hex)\n", *(uint8_t*)d, *(uint8_t*)d);
      break;
    case(E_UINT16):
      printf("Printing T=E_UINT16  => %10d (decimal)  --  0x%08x (hex)\n", *(uint16_t*)d, *(uint16_t*)d);
      break;
    case(E_UINT32):
      printf("Printing T=E_UINT32  => %10d (decimal)  --  0x%08x (hex)\n", *(uint32_t*)d, *(uint32_t*)d);
      break;
    case(E_FLOAT):
      printf("Printing T=E_FLOAT   => %2.7f\n", *((float*) d));
      break;
    case(E_DOUBLE):
      printf("Printing T=E_DOUBLE  => %2.7f\n", *((double*) d));
      break;
  }
}
