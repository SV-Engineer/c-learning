/** @file math_fixed_point.c
 * @author Austin
 * @brief SRC Modeling floats with fixed point math.
 *
 */

#include <stdint.h>
#include "log.h"
#include "math_fixed_point.h"

#if RUN==4
  int run(void) {
    CREATE_LOG_INSTANCE("RUN%0d", RUN);

    mfp_number_t A = MFP_NUMBER_INIT_TO_ZERO;
    mfp_number_t B = MFP_NUMBER_INIT_TO_ZERO;
    mfp_number_t C = MFP_NUMBER_INIT_TO_ZERO;
    float        a = 0.0;

    // mfp_number_t B = MFP_NUMBER_INIT_TO_ZERO;

    A              = mfp_float_to_fixed_point(3.14159f, E_MFP_10p22);
    a              = mfp_fixed_point_to_float(A);
    LOG_D("FP to Q-Format Example");
    LOG_I("A.d=%10d  --  A.q=%3d  |  a=%3.010f", A.d, A.q, a);

    A              = mfp_float_to_fixed_point(2.5, E_MFP_16p16);
    B              = mfp_float_to_fixed_point(3.0, E_MFP_25p07);
    C              = mfp_mult(A, B);
    a              = mfp_fixed_point_to_float(C);
    LOG_D("Multiply Example");
    LOG_I("A.d=%10d  --  A.q=%3d  |  B.d=%10d  --  B.q=%3d", A.d, A.q, B.d, B.q);
    LOG_I("C.d=%10d  --  C.q=%3d  |  a=%2.07f", C.d, C.q, a);


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

    result.d = A.d+B.d;
    result.q = A.q;
    return result;
  }
}

/** @brief Subtract one fixed point number from another (A-B) */
mfp_number_t mfp_sub(mfp_number_t A, mfp_number_t B) {
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

/** @fn mfp_mult
 * @brief Multiply one fixed point number with another (A*B);
 * @param A
 * The Q-Format value with the desired return value precision.
 * @param B
 * The Q-Format value with the desired post multiply right shift value.
 *
 * @return mfp_number_t
 * Returns product A*B. The end result is in the Q Format of @param A
 */
mfp_number_t mfp_mult(mfp_number_t A, mfp_number_t B) {
  int64_t      over_under_check = (int64_t) 0;
  over_under_check = (((int64_t)A.d * (int64_t)B.d) >> B.q);
  
  if (over_under_check > (int64_t)INT32_MAX) {
    LOG_W("Overflow would occur for inputs: A=%6d and B = %6d", A.d, B.d);
    over_under_check = (int64_t)INT32_MAX;
  }
  else if (over_under_check < (int64_t)INT32_MIN) {
    LOG_W("Underflow would occur for inputs: A=%6d and B = %6d", A.d, B.d);
    over_under_check = (int64_t)INT32_MIN;
  }

  mfp_number_t result           = MFP_NUMBER_INIT_TO_ZERO;
  result.d = over_under_check;
  result.q = A.q;

  return result;
}

