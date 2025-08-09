/** @file pointer_usage.c
 * @author Austin Harrison
 * @brief Examples of pointers and their use (src).
 * 
 */

#include "../inc/pointer_usage.h"


/// @brief S - String.
#define DO_INFO(S, ...)           printf("INFO - %s", S, __VA_ARGS__)

/** @fn void pointer_abuse()
 * @brief Just for funsies
 * 
 */
void pointer_abuse(void)
{
  uint8_t* values[5];

  DO_INFO("Testings %08x\n", 55);
  // for (uint8_t** i = pptr; )

}

void p_abuse_call_back(void)
{
  pointer_abuse();
}
