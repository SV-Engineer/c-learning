/** @file log.c
 * @author Austin
 * @brief SRC Logging with C std library and function pointers
 *
 * @note It appears to get this to work the way I want, I need to write some x86 assembly and then cast it to a funtion pointer. What 
 * an interesting problem.
 */

#include <stdbool.h>
#include "log.h"

#ifndef MAX_NUMBER_OF_LOG_INSTANCES
  /** @brief No idea what this should be yet. */
  #define MAX_NUMBER_OF_LOG_INSTANCES   10
#endif

const char* LOG_INFORMATION            = "#INFORMATION    --  ";
const char* LOG_WARNING                = "#WARNING        --  ";
const char* LOG_ERROR_SOFT             = "#ERROR_SOFT     --  ";
const char* LOG_ERROR_CRITICAL         = "#ERROR_CRITICAL --  ";

// Forward declarations
static void __log_information(log_t* log, const char* data);
static void __log_warning(log_t* log, const char* data);
static void __log_soft_error(log_t* log, const char* data);
static void __log_critical_error(log_t* log, const char* data);

// FORWARD DECLARED DATA TYPE
typedef struct LOG_LINKED_LINKED_LIST log_instances_t;

//! @brief Just for fun.
typedef struct LOG_LINKED_LINKED_LIST {
  int              ID;
  log_t*           log_instance;
  log_instances_t* next;
  log_instances_t* previous;
} log_instances_t;

//! @brief This is static because there is no need for this to be linked to outside of this compilation unit.
static log_instances_t* __log_instances;

// Need to make sure the logging works.
#if RUN==3
  int run(void) {
    const char* MODULE_NAME = "RUN3\0";
    CREATE_LOG_INSTANCE(MODULE_NAME);

    if (log != NULL) {
      printf("%slog was NOT NULL\n", LOG_INFORMATION);
      LOG_I("TEST I");
      LOG_W("TEST W");
      LOG_SE("TEST ES");
      LOG_CE("TEST EC");
      LOG_I("Killing all log instances...");
      KILL_ALL_LOG_INSTANCES();
    }

    else {
      printf("Log was NULL\n");
    }

    return 0;
  }
#endif


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
  log_t*           log                = (log_t*) malloc(sizeof(log_t));
  log_instances_t* instance_node      = (log_instances_t*) malloc(sizeof(log_instances_t));
  bool             is_null_terminated = false;

  (void) memset((void*) &(log->name), 0, LOG_NAME_MAX_LENGTH);

  // Check for NULL terminator first so the "else-if" printf statement doesn't break.
  for (int i = 0; i < LOG_NAME_MAX_LENGTH; i++) {
    if (name[i] == '\0') {
      is_null_terminated = true;
      break;
    }
  }

  if (!is_null_terminated) {
    printf("%sProvided name is not terminated with NULL: '\\0'\n",     LOG_ERROR_SOFT);
    free(log);
    log = NULL;
  }

  else if (log == NULL) {
    printf("%sHeap Space unavailable to allocate log with name: %s\n", LOG_ERROR_CRITICAL, name);
  }

  else {
    static int       __instance_id = 0;

    printf("%sProvided name is valid and memory is allocated\n",       LOG_INFORMATION);
    strcpy((char*) &(log->name), name);
    log->INFORMATION    = (log_function_ptr_t) &__log_information;
    log->WARNING        = (log_function_ptr_t) &__log_warning;
    log->ERROR_SOFT     = (log_function_ptr_t) &__log_soft_error;
    log->ERROR_CRITICAL = (log_function_ptr_t) &__log_critical_error;

    // I start at 0
    if (__instance_id > 0) {
      // After 0th case, new entries to the linked list are needed.
      log_instances_t* list_ptr      = __log_instances;
      bool             invalid_exit  = false;

      printf("Instantiate instance with instance ID: %0d\n", __instance_id);

      list_ptr = list_ptr->previous;
      instance_node->ID           = __instance_id++;
      instance_node->log_instance = log;
      // Insert new node at the "end"
      // Honestly I don't think this needs to be a circularly linked list, but
      // meh I'm enjoying the implementation. It makes way more sense to just
      // iterate through next until NULL is found. I may change my opinion once
      // I get to the implementation of freeing all the memory.
      instance_node->previous     = list_ptr;
      instance_node->next         = list_ptr->next;
      list_ptr->next              = instance_node;

    }
    else {
      printf("Instantiate 0th instance with instance ID: %0d\n", __instance_id);
      __log_instances               = instance_node;
      // 0th case it needs to point to itself until more instances are added.
      __log_instances->ID           = __instance_id++; // Increment to 1
      __log_instances->log_instance = log;
      __log_instances->next         = __log_instances;
      __log_instances->previous     = __log_instances;
    }
  }

  return log;
}

/** @fn void delete_all_logger_instances(void)
 * @brief Deletes all logger instances.
 *
 * @return void
 */
void delete_all_logger_instances(void) {
  log_instances_t* list_ptr      = __log_instances;

  if (list_ptr != NULL) {
    printf("List PTR is not NULL with ID: %0d\n", list_ptr->ID);
    list_ptr = list_ptr->previous;
    while (list_ptr->ID > 0) {
      // Free last "non-null instance"
      printf("Free instance ID: %0d\n", list_ptr->ID);
      free(list_ptr->log_instance);
      list_ptr->log_instance = NULL;
      list_ptr->next         = NULL;
      list_ptr->ID           = -1;

      // By back tracking through the cirularly linked list, we can free the "next" node whose log instance we just freed.
      // Doing so will guarantee that when we get to the statically allocated 0th node, all dynamically allocated nodes are delete.
      list_ptr       = list_ptr->previous;

      // Free then re-assign to NULL to enable NULL checking.
      free(list_ptr->next);
      list_ptr->next = NULL;
    }

    // Free the last one
    printf("Free last instance ID: %0d\n", list_ptr->ID);
    free(list_ptr);
    __log_instances = NULL;
    list_ptr        = NULL;
  }

  printf("All Log instances freed and NULLified");
}

// Sub-task functions to print once logger instance is resolved.
static void __log_information(log_t* log, const char* data) {
  printf("%s(%s)  --  %s\n", LOG_INFORMATION, log->name, data);
}

// Sub-task functions to print once logger instance is resolved.
static void __log_warning(log_t* log, const char* data) {
  printf("%s(%s)  --  %s\n", LOG_WARNING, log->name, data);
}

// Sub-task functions to print once logger instance is resolved.
static void __log_soft_error(log_t* log, const char* data) {
  printf("%s(%s)  --  %s\n", LOG_ERROR_SOFT, log->name, data);
}

// Sub-task functions to print once logger instance is resolved.
static void __log_critical_error(log_t* log, const char* data) {
  printf("%s(%s)  --  %s\n", LOG_ERROR_CRITICAL, log->name, data);
}
