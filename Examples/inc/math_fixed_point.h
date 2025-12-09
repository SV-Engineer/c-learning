/** @file math_fixed_point.h
 * @author Austin
 * @brief INC Modeling floats with fixed point math.
 *
 */

#ifndef MATH_FIXED_POINT_H_
  #define MATH_FIXED_POINT_H_

  #include <stdint.h>

  //! @brief How many binary points of precision (less than 1.0) the number will have (MSB is always sign bit).
  typedef enum {
    E_MFP_32p00,
    E_MFP_31p01,
    E_MFP_30p02,
    E_MFP_29p03,
    E_MFP_28p04,
    E_MFP_27p05,
    E_MFP_26p06,
    E_MFP_25p07,
    E_MFP_24p08,
    E_MFP_23p09,
    E_MFP_22p10,
    E_MFP_21p11,
    E_MFP_20p12,
    E_MFP_19p13,
    E_MFP_18p14,
    E_MFP_17p15,
    E_MFP_16p16,
    E_MFP_15p17,
    E_MFP_14p18,
    E_MFP_13p19,
    E_MFP_12p20,
    E_MFP_11p21,
    E_MFP_10p22,
    E_MFP_09p23,
    E_MFP_08p24,
    E_MFP_07p25,
    E_MFP_06p26,
    E_MFP_05p27,
    E_MFP_04p28,
    E_MFP_03p29,
    E_MFP_02p30,
    E_MFP_01p31,
    E_MFP_MAX
  } mfp_precision_t;

  //! @brief A data structure to hold a number with fixed point precision.
  typedef struct MFP_NUMBER {
    int32_t         d;
    mfp_precision_t q;
  } mfp_number_t;

  #define MFP_NUMBER_INIT_TO_ZERO          ((mfp_number_t) {.d=0, .q=E_MFP_32p00})

  mfp_number_t mfp_float_to_fixed_point(float value, mfp_precision_t precision);
  float mfp_fixed_point_to_float(mfp_number_t value);
  void mfp_convert(mfp_number_t* value, mfp_precision_t precision);
  mfp_number_t mfp_add(mfp_number_t A, mfp_number_t B);
  mfp_number_t mfp_sub(mfp_number_t A, mfp_number_t B);

#endif /* MATH_FIXED_POINT_H_ */
