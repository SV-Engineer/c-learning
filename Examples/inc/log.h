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

  // Forward declaration to resolve circular dependency.
  typedef struct LOG log_t;

  /** @brief Typedef for logging function poitners. the initialization input is the ID.*/
  typedef void (*log_function_ptr_t)(log_t*, const char*);

  /** @brief The data structure for logging */
  typedef struct LOG {
    char name[LOG_NAME_MAX_LENGTH];
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

  /** @group log_api
   * @brief "API-Like" macros that expect a struct instance with symbol name "log"
   *
   */

  /** @ingroup log_api @{ */
  #define CREATE_LOG_INSTANCE(N)     log_t* log = initialize_logger(((const char*) N))

  #define LOG_I(S)                   log->INFORMATION(log,    ((const char*) S))
  #define LOG_W(S)                   log->WARNING(log,        ((const char*) S))
  #define LOG_SE(S)                  log->ERROR_SOFT(log,     ((const char*) S))
  #define LOG_CE(S)                  log->ERROR_CRITICAL(log, ((const char*) S))
  #define KILL_ALL_LOG_INSTANCES     delete_all_logger_instances
  /** @} */

#endif /* LOG_H_ */
