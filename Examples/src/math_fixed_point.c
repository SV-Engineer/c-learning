/** @file math_fixed_point.c
 * @author Austin
 * @brief SRC Modeling floats with fixed point math.
 *
 */

#include "log.h"
#include "math_fixed_point.h"

#if RUN==4
  int run(void) {
    CREATE_LOG_INSTANCE("RUN%0d", RUN);

    mfp_number_t A = MFP_NUMBER_INIT_TO_ZERO;
    float        a = 0.0;
    // mfp_number_t B = MFP_NUMBER_INIT_TO_ZERO;

    A = mfp_float_to_fixed_point(3.14159f, E_MFP_10p22);
    a = mfp_fixed_point_to_float(A);

    LOG_I("A.d=%0d  --  A.q=%0d and a=%03.5f", A.d, A.q, a);

    KILL_ALL_LOG_INSTANCES();

    return 0;
  }
#endif

/** @brief Convert a floating point number to a fixed point number */
mfp_number_t mfp_float_to_fixed_point(float value, mfp_precision_t precision) {
  mfp_number_t result = MFP_NUMBER_INIT_TO_ZERO;

  result.q = precision;
  result.d = (int32_t) (value * ((double)(0x1U << precision)));
  return result;
}

/** @brief Convert a fixed point number to a floating point number */
float mfp_fixed_point_to_float(mfp_number_t value) {
  float result = 0.0f;

  result = ((float) value.d) / ((float) (0x1U << value.q));

  return result;
}

/** @brief Convert a number from one precision to another. */
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

/** @brief Add one fixed point number to another */
mfp_number_t mfp_add(mfp_number_t A, mfp_number_t B) {
  if (A.q != B.q) {
    LOG_SE("A.q (%0d) != B.q (%0d)", A.q, B.q);
    LOG_I("Try making a call to mfp_convert to change the order of magnitude first");
    return MFP_NUMBER_INIT_TO_ZERO;
  }
  else {
    mfp_number_t result = MFP_NUMBER_INIT_TO_ZERO;

    result.d = A.d-B.d;
    result.q = A.q;
    return result;
  }
}

