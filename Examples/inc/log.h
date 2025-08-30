/** @file log.h
 * @author Austin
 * @brief INC Logging with C std library and function pointers
 *
 * @note This header MUST ONLY be included in source files. Stuff will break if it is included in other headers.
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
  typedef void (*log_function_ptr_t)(log_t*, const char*, int);

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
  #define CREATE_LOG_INSTANCE(N)     log = initialize_logger(((const char*) N))

  #define LOG_I(S)                   log->INFORMATION(log,    ((const char*) S), __LINE__)
  #define LOG_W(S)                   log->WARNING(log,        ((const char*) S), __LINE__)
  #define LOG_SE(S)                  log->ERROR_SOFT(log,     ((const char*) S), __LINE__)
  #define LOG_CE(S)                  log->ERROR_CRITICAL(log, ((const char*) S), __LINE__)
  #define KILL_ALL_LOG_INSTANCES     delete_all_logger_instances
  /** @} */

#endif /* LOG_H_ */

/** @par  ATTENTION!!!
          This is not in the header guard because it must be copied to each source file that includes it. Is this not all that great of a practice? Yes. Working within the limitations of C is difficult and sometimes we need to acknowledge that the way we want to implement something doesn't work well. This is a great example. I wanted to imitate object oriented programming and create dynamically allocated logging structures per module in C. As it turns out, I need to do some rather sketchy stuff to imitate OOP. This repository is for learning. So this ugliness stays as a reminder.
 */
static log_t* log;
