/** @file log.h
 * @author Austin
 * @brief INC Logging with C std library and function pointers
 *
 */

#ifndef LOG_H_
  #define LOG_H_
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include <stdint.h>

  #ifndef LOG_NAME_MAX_LENGTH
    #define LOG_NAME_MAX_LENGTH         16
  #endif

  /** @brief Typedef for logging function poitners. the initialization input is the ID.*/
  typedef void (*log_function_ptr_t)(const char*);

  /** @brief The data structure for logging */
  typedef struct LOG {
    const char name[LOG_NAME_MAX_LENGTH];
    log_function_ptr_t INFORMATION;
    log_function_ptr_t WARNING;
    log_function_ptr_t ERROR_SOFT;
    log_function_ptr_t ERROR_CRITICAL;
  } log_t;

  //! @brief Constant to subtract from a lower case ASCII character to make an upper case.
  #define UPPER_TO_LOWER_DIFF      (((uint8_t) 'a') - ((uint8_t) 'A'))

  /// @brief Delineation in logging
  #define DELINEATE     printf("=================================================================\n")

  /// @brief Prints some info, there is likely a better way to do this but this works well enough.
  #define INFO(S, ...)  printf("INFO - ");      \
                        printf(S, __VA_ARGS__); \
                        printf("\n")


  log_t* initialize_logger(const char* name);
  void   delete_all_logger_instances();

#endif /* LOG_H_ */
