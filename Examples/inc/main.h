/** @file main.h
 * @author Austin Harrison
 * @brief MAIN Header
 * 
 */

#ifndef MAIN_H_
  #define MAIN_H_

  /** @brief Used to call the desired function via CMake defines */
  // typedef int (*int_return_function_ptr_t)(void);

  /* Conditionally compiled Function prototype based on CLI switch -DRUN=<Arbitrarily assigned number here> */
  int run(void);

#endif /* MAIN_H_ */
