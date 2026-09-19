/** @file console.h
 * @author Austin
 * @brief INC Console Logging with C std library and function pointers
 *
 * @note This header MUST ONLY be included in source files. Stuff will break if it is included in other headers.
 */

#ifndef CONSOLE_H_
  #define CONSOLE_H_
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include <stdint.h>

  #ifndef CONSOLE_NAME_MAX_LENGTH
    #define CONSOLE_NAME_MAX_LENGTH         32
  #endif

  /** @brief Counts for final console dump. */
  typedef struct CONSOLE_COUNTERS {
    int __WARNINGS;
    int __ERRORS;
  } console_counters_t;

  /** @brief Counter initialization */
  #define CONSOLE_COUNTERS_INITIALIZE             (console_counters_t) {.__WARNINGS=0, .__ERRORS=0}

  // Forward declaration to resolve circular dependency.
  typedef struct CONSOLE console_t;

  typedef void (*console_delineate_ptr_t)(console_t*, const char*);
  /** @brief Typedef for console function poitners. the initialization input is the ID.*/
  typedef void (*console_function_ptr_t)(console_t*, const char*, int);

  /** @brief The data structure for console */
  typedef struct CONSOLE {
    char name[CONSOLE_NAME_MAX_LENGTH];
    console_delineate_ptr_t DELINEATE;
    console_function_ptr_t  INFORMATION;
    console_function_ptr_t  WARNING;
    console_function_ptr_t  ERROR_SOFT;
    console_function_ptr_t  ERROR_CRITICAL;
    console_counters_t*     __COUNTERS;
  } console_t;

  //! @brief Constant to subtract from a lower case ASCII character to make an upper case.
  #define UPPER_TO_LOWER_DIFF      (((uint8_t) 'a') - ((uint8_t) 'A'))


  /// @brief Prints some info, there is likely a better way to do this but this works well enough.
  #define INFO(S, ...)  printf("INFO - ");      \
                        printf(S, __VA_ARGS__); \
                        printf("\n")


  console_t* initialize_console(const char* name);
  void   delete_all_console_instances(console_t* console);

  /** @group console_api
   * @brief "API-Like" macros that expect a struct instance with symbol name "console"
   *
   */

  /** @ingroup console_api @{ */

  /// @brief Delineation in console
  #define CONSOLE_D(...)                  memset(console_buffer, 0, sizeof(console_buffer));                            \
                                          sprintf((char*) console_buffer, __VA_ARGS__);                                 \
                                          console->DELINEATE(console, ((const char*) console_buffer))

  /// @brief Information console
  #define CONSOLE_I(...)                  memset(console_buffer, 0, sizeof(console_buffer));                            \
                                          sprintf((char*) console_buffer, __VA_ARGS__);                                 \
                                          console->INFORMATION(console,((const char*) console_buffer), __LINE__)

  /// @brief Warning console
  #define CONSOLE_W(...)                  memset(console_buffer, 0, sizeof(console_buffer));                            \
                                          sprintf((char*) console_buffer, __VA_ARGS__);                                 \
                                          console->WARNING(console, ((const char*) console_buffer), __LINE__)

  /// @brief Soft Error console
  #define CONSOLE_SE(...)                 memset(console_buffer, 0, sizeof(console_buffer));                            \
                                          sprintf((char*) console_buffer, __VA_ARGS__);                                 \
                                          console->ERROR_SOFT(console, ((const char*) console_buffer), __LINE__)

  /// @brief Critical Error console
  #define CONSOLE_CE(...)                 memset(console_buffer, 0, sizeof(console_buffer));                            \
                                          sprintf((char*) console_buffer, __VA_ARGS__);                                 \
                                          console->ERROR_CRITICAL(console, ((const char*) console_buffer), __LINE__)


  /// @brief Frees all malloc-ed console data structures
  #define KILL_ALL_CONSOLE_INSTANCES(...) delete_all_console_instances(console)

  /// @brief Creates console data structures
  #define CREATE_CONSOLE_INSTANCE(...)    sprintf(console_buffer, __VA_ARGS__);                                         \
                                          console = initialize_console(((const char*) console_buffer));                 \
                                          CONSOLE_D("Initialization done");                                             \
                                          memset(console_buffer, 0, sizeof(console_buffer))

  /** @} */

#endif /* CONSOLE_H_ */

/** @par  Note 1
 *         &nbsp;&nbsp;
 *         This is not in the header guard because it must be copied to each source file that includes it. Is this not all that great of a practice? Yes.
 *         Working within the limitations of C is difficult and sometimes we need to acknowledge that the way we want to implement something doesn't work
 *         well. This is a great example. I wanted to imitate object oriented programming and create dynamically allocated console structures per module in C.
 *         As it turns out, I need to do some rather sketchy stuff to imitate OOP. This repository is for learning. So this abomination stays as a
 *         reminder. <br><br> &nbsp;&nbsp;
 *
 * @par Note 2
 *         Also, the use of pragma to hide the warning of unused variables as some source files will not use the buffer and console. Not only is this super 
 *         inefficient, it reduces cross-compilation compatibility. If GNU is not used, this will throw a warning. Don't do this in production code. <br>
 */
#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wunused-variable"
  static console_t* console;
  static char console_buffer[256];
  #pragma GCC diagnostic pop
#endif
