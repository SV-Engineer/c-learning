/** @file math_fixed_point.c
 * @author Austin
 * @brief SRC Modeling floats with fixed point math.
 *
 */

#include "math_fixed_point.h"

void mfp_convert(mfp_number_t* value, mfp_precision_t precision) {
  // In the case of equal, they bit-shift will be zero.
  if (value->q >= precision) {
    value->d >>= (q-precision);
    value->q   = precision;
  }

  else {
    value->d <<= (precision-q);
    value->q   = precision;
  }
}
