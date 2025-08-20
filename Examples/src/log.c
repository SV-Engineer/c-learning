/** @file log.c
 * @author Austin
 * @brief SRC Logging with C std library and function pointers
 *
 */

#include "log.h"

const char* LOG_INFORMATION            "INFORMATION     --  ";
const char* LOG_WARNING                "!WARNING        --  ";
const char* LOG_ERROR_SOFT             "!ERROR_SOFT     --  ";
const char* LOG_ERROR_CRITICAL         "!ERROR_CRITICAL --  ";

// Forward declarations
static void __log_information(log_t* log, const char* data);
static void __log_warning(log_t* log, const char* data);
static void __log_soft_error(log_t* log, const char* data);
static void __log_critical_error(log_t* log, const char* data);

/** @fn log_t* initialize_logger(const char* name)
 * @brief Creates a logger.
 *
 * @param name
 * A null terminated character array of length @ref LOG_NAME_MAX_LENGTH
 *
 * @return NULL
 * Failure to malloc or bad name provided
 *
 * @return log_t*
 * A data structure that exists to logger with provided name.
 */
log_t* initialize_logger(const char* name) {
  log_t* log = (log_t*) malloc(sizeof(log_t));

  (void) memset(&(log->name), 0, LOG_NAME_MAX_LENGTH);

  // Check for NULL terminator first so the "else-if" printf statement doesn't break.
  if (name[LOG_NAME_MAX_LENGTH-1] != '\0') {
    printf("%sProvided name is not terminated with NULL: '\\0'\n\0",     LOG_ERROR_SOFT);
    delete_logger(log);
  }

  else if (log == NULL) {
    printf("%sHeap Space unavailable to allocate log with name: %s\n\0", LOG_ERROR_CRITICAL, name);
  }

  else {
    printf("%sProvided name is valid and memory is allocated\n\0",       LOG_INFORMATION);
    strcpy(log->name, name);
    log->INFORMATION = (log_function_ptr_t) &__log_information;
    log->INFORMATION = (log_function_ptr_t) &__log_warning;
    log->INFORMATION = (log_function_ptr_t) &__log_soft_error;
    log->INFORMATION = (log_function_ptr_t) &__log_critical_error;
  }

  return log;
}

/** @fn void delete_logger(log_t log)
 * @brief Deletes a logger
 *
 * @param log
 * A heap allocated logger
 *
 * @return void
 */
static void delete_logger(log_t* log) {
  free(log);
  log = NULL;
}

static void __log_information(log_t* log, const char* data) {
  printf("TODO: INFO")
}

static void __log_warning(log_t* log, const char* data) {
  printf("TODO: WARN")
}

static void __log_soft_error(log_t* log, const char* data) {
  printf("TODO: SE")
}

static void __log_critical_error(log_t* log, const char* data) {
  printf("TODO: CE")
}
