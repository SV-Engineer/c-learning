/** @file pointer_usage.c
 * @author Austin Harrison
 * @brief Examples of pointers and their use (src).
 * 
 */

#include "pointer_usage.h"

/** @fn void pointer_abuse(uint8_t* data_ptr)
 * @brief Just for funsies
 * 
 */
void pointer_abuse(uint8_t* data_ptr)
{
  char info[1000];


  uint8_t** const pptr = (uint8_t**) &data_ptr;

  // TODO: come back and recall the correct and modern way of string handling.
  memset(info, 0, sizeof(info));
  sprintf((char*) info, "INFO - Double pointer address is: 0x%08x.\n", pptr);
  printf(info);

  memset(info, 0, sizeof(info));
  sprintf((char*) info, "INFO - Double pointer points to pointer at address: 0x%08x.\n", *pptr);
  printf(info);

  memset(info, 0, sizeof(info));
  sprintf((char*) info, "INFO - Data at pointer is: 0x%02x -- Compare to data from original pointer: 0x%02x.\n", **pptr, *data_ptr);
  printf(info);

}

void p_abuse_call_back(void)
{
  uint8_t d = (uint8_t) 0xA5;

  pointer_abuse((uint8_t*) &d);
}
