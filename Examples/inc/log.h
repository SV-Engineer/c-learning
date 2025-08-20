

#ifndef LOG_H_
  #define LOG_H_
  #include <stdio.h>
  #include <string.h>

  //! @brief Constant to subtract from a lower case ASCII character to make an upper case.
  #define UPPER_TO_LOWER_DIFF      (((uint8_t) 'a') - ((uint8_t) 'A'))

  /// @brief Delineation in logging
  #define DELINEATE     printf("=================================================================\n")

  /// @brief Prints some info, there is likely a better way to do this but this works well enough.
  #define INFO(S, ...)  printf("INFO - ");      \
                        printf(S, __VA_ARGS__); \
                        printf("\n")

#endif /* LOG_H_ */
