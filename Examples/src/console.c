/** @file console.c
 * @author Austin
 * @brief SRC Console logging with C std library and function pointers
 *
 * @note It appears to get this to work the way I want, I need to write some x86 assembly and then cast it to a funtion pointer. What 
 * an interesting problem.
 */

#include <stdbool.h>
#include "console.h"


#define DELINEATE_SPACING(...)                      printf("\n=================================================================\n")

static const char*    __CONSOLE_INFORMATION        = "#INFORMATION    --  ";
static const char*    __CONSOLE_WARNING            = "#WARNING        --  ";
static const char*    __CONSOLE_ERROR_SOFT         = "#ERROR_SOFT     --  ";
static const char*    __CONSOLE_ERROR_CRITICAL     = "#ERROR_CRITICAL --  ";
static console_counters_t __COUNTERS               = CONSOLE_COUNTERS_INITIALIZE;

// Forward declarations
static void __console_information    (console_t* console, const char* data, int line_number);
static void __console_warning        (console_t* console, const char* data, int line_number);
static void __console_soft_error     (console_t* console, const char* data, int line_number);
static void __console_critical_error (console_t* console, const char* data, int line_number);
static void __console_delineation    (console_t* console, const char* data);
static void __console_dump           (console_counters_t* counters);

// FORWARD DECLARED DATA TYPE
typedef struct CONSOLE_LINKED_LINKED_LIST console_instances_t;

//! @brief Just for fun.
typedef struct CONSOLE_LINKED_LINKED_LIST {
  int                  ID;
  console_t*           console_instance;
  console_instances_t* next;
  console_instances_t* previous;
} console_instances_t;

//! @brief This is static because there is no need for this to be linked to outside of this compilation unit.
static console_instances_t* __console_instances;
static int                 __latest_first_instance_id = -2;

// Need to make sure the console CONSOLE logging works.
#if RUN==3
  int run(void) {
    // RUN 3-1
    CREATE_CONSOLE_INSTANCE("RUN%0d", RUN);

    if (console != NULL) {
      printf("%sconsole was NOT NULL\n", __CONSOLE_INFORMATION);
      CONSOLE_I("TEST I");
      CONSOLE_W("TEST W");
      CONSOLE_SE("TEST ES");
      CONSOLE_CE("TEST EC");
      CONSOLE_I("Killing all console instances...");
      KILL_ALL_CONSOLE_INSTANCES();

    // RUN 3-2
      CREATE_CONSOLE_INSTANCE("RUN%0d", RUN);
      CONSOLE_I("TEST I");
      CONSOLE_W("TEST W");
      CONSOLE_SE("TEST ES");
      CONSOLE_CE("TEST EC");
      CONSOLE_I("Killing all console instances...");
      KILL_ALL_CONSOLE_INSTANCES();

    }

    else {
      printf("%sConsole was NULL\n", __CONSOLE_ERROR_CRITICAL);
    }

    return 0;
  }
#endif


/** @fn console_t* initialize_console(const char* name)
 * @brief Creates a console.
 *
 * @param name
 * A null terminated character array of length @ref CONSOLE_NAME_MAX_LENGTH
 *
 * @return NULL
 * Failure to malloc or bad name provided
 *
 * @return console_t*
 * A data structure that exists to console with provided name.
 */
console_t* initialize_console(const char* name) {
  console_t*           console       = (console_t*) malloc(sizeof(console_t));
  console_instances_t* instance_node = (console_instances_t*) malloc(sizeof(console_instances_t));

  (void) memset((void*) &(console->name), 0, CONSOLE_NAME_MAX_LENGTH);

  if (console == NULL) {
    printf("%sHeap Space unavailable to allocate console with name: %s\n", __CONSOLE_ERROR_CRITICAL, name);
  }

  else {
    static int       __instance_id = 0;

    printf("%sProvided name is valid and memory is allocated\n", __CONSOLE_INFORMATION);
    strcpy((char*) &(console->name), name);
    console->DELINEATE      = (console_delineate_ptr_t) &__console_delineation;
    console->INFORMATION    = (console_function_ptr_t)  &__console_information;
    console->WARNING        = (console_function_ptr_t)  &__console_warning;
    console->ERROR_SOFT     = (console_function_ptr_t)  &__console_soft_error;
    console->ERROR_CRITICAL = (console_function_ptr_t)  &__console_critical_error;
    console->__COUNTERS     = (console_counters_t*)     &__COUNTERS;


    // TODO: What happens when the delete function is called and another instance is initialized?
    // I start at 0
    if (__console_instances != NULL) {
      // After 0th case, new entries to the linked list are needed.
      console_instances_t* list_ptr      = __console_instances;

      printf("%sInstantiate instance with instance ID: %0d\n", __CONSOLE_INFORMATION, __instance_id);

      list_ptr = list_ptr->previous;
      instance_node->ID           = __instance_id++;
      instance_node->console_instance = console;
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
      printf("%sInstantiate new set of instances with first instance ID: %0d\n", __CONSOLE_INFORMATION, __instance_id);
      __console_instances               = instance_node;
      // 0th case it needs to point to itself until more instances are added.
      __console_instances->ID           = __instance_id++; // Increment to 1
      __console_instances->console_instance = console;
      __console_instances->next         = __console_instances;
      __console_instances->previous     = __console_instances;
      __latest_first_instance_id    = __instance_id - 1; // 1-1=0 the first time around. Instantiating and killing many times means this is non-zero at some point.
    }

  }

  return console;
}

/** @fn void delete_all_console_instances(console_t* console)
 * @brief Deletes all console instances.
 *
 * @return void
 */
void delete_all_console_instances(console_t* console) {
  console_instances_t* list_ptr      = __console_instances;

  if (list_ptr != NULL) {
    __console_dump((console_counters_t*) &__COUNTERS);
    printf("%sList PTR is not NULL with ID: %0d\n", __CONSOLE_INFORMATION, list_ptr->ID);
    // If only one instance was created, this will just point to itself and the while loop construct will never be entered.
    list_ptr = list_ptr->previous;
    while (list_ptr->ID > __latest_first_instance_id) {
      // Free last "non-null instance"
      printf("%sFree instance ID: %0d\n", __CONSOLE_INFORMATION, list_ptr->ID);
      free(list_ptr->console_instance);
      list_ptr->console_instance = NULL;
      list_ptr->next         = NULL;
      list_ptr->ID           = -1;

      // By back tracking through the cirularly linked list, we can free the "next" node whose console instance we just freed.
      // Doing so will guarantee that when we get to the 0th node, all allocated nodes are delete.
      list_ptr       = list_ptr->previous;

      // Free then re-assign to NULL to enable NULL checking.
      free(list_ptr->next);
      list_ptr->next = NULL;
    }

    // Free the last one
    // ??? Should this be a valid use case / edge case?
    // There is probably a way to do this by null checking in a do-while construct?
    if (list_ptr != NULL) {
      printf("%sFree last instance ID: %0d\n", __CONSOLE_INFORMATION, list_ptr->ID);
      free(list_ptr);
      __console_instances = NULL;
      list_ptr        = NULL;
    }
  }

  printf("%sAll console instances freed and NULLified\n", __CONSOLE_INFORMATION);
  DELINEATE_SPACING();
}

// Sub-task functions to print once console instance is resolved.
static void __console_information(console_t* console, const char* data, int line_number) {
  printf("%s(%s - line#%0d)  --  %s\n", __CONSOLE_INFORMATION, console->name, line_number, data);
}

// Sub-task functions to print once console instance is resolved.
static void __console_warning(console_t* console, const char* data, int line_number) {
  printf("%s(%s - line#%0d)  --  %s\n", __CONSOLE_WARNING, console->name, line_number, data);
  console->__COUNTERS->__WARNINGS++;
}

// Sub-task functions to print once console instance is resolved.
static void __console_soft_error(console_t* console, const char* data, int line_number) {
  printf("%s(%s - line#%0d)  --  %s\n", __CONSOLE_ERROR_SOFT, console->name, line_number, data);
  console->__COUNTERS->__ERRORS++;
}

// Sub-task functions to print once console instance is resolved.
static void __console_critical_error(console_t* console, const char* data, int line_number) {
  printf("%s(%s - line#%0d)  --  %s\n", __CONSOLE_ERROR_CRITICAL, console->name, line_number, data);
  console->__COUNTERS->__ERRORS++;
}

// Prints some spacing and creates sections on the console
static void __console_delineation(console_t* console, const char* data) {
  DELINEATE_SPACING();
  printf("%s  --  %s\n", console->name, data);
  DELINEATE_SPACING();
}

// Dumps info.
static void __console_dump(console_counters_t* counters) {
  DELINEATE_SPACING();
  printf("  * ERROR   COUNT: %03d\n",   counters->__ERRORS);
  printf("  * WARNING COUNT: %03d\n\n", counters->__WARNINGS);
}
