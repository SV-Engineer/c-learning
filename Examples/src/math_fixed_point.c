/** @file math_fixed_point.c
 * @author Austin
 * @brief SRC Modeling floats with fixed point math.
 *
 */

#include "math_fixed_point.h"

#if RUN==4
  int run(void) {
    const char* MODULE_NAME = sprintf("RUN%0d\0", RUN);
    CREATE_LOG_INSTANCE(MODULE_NAME);

    return 0;
  }
#endif

void mfp_convert(mfp_number_t* value, mfp_precision_t precision) {
  // In the case of equal, they bit-shift will be zero.
  if (value->q >= precision) {
    value->d >>= (value->q-precision);
    value->q   = precision;
  }

  else {
    value->d <<= (precision-value->q);
    value->q   = precision;
  }
}
