/** @file pointer_usage.h
 * @author Austin Harrison
 * @brief Examples of pointers and their use (header).
 * 
 */

#if RUN == 2
  #ifndef POINTER_USAGE_H_
    #define POINTER_USAGE_H_
    #include <stdint.h>
    #include "log.h"
  #endif /* POINTER_USAGE_H_ */
#endif /* RUN==2*/

/** @brief Not fully comprehensive because the goal is to show case common basics. */
typedef enum{
  E_INT8,
  E_INT16,
  E_INT32,
  E_UINT8,
  E_UINT16,
  E_UINT32,
  E_FLOAT,
  E_DOUBLE
} primitive_types_t;

/** @brief Casts a simple data type to void pointer */
#define CAST_PRIMITIVE_TO_VOID_PTR(X)         (void*) &X

#define PU_LOG_INT8(X)        pu_print(E_INT8,   CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_INT16(X)       pu_print(E_INT16,  CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_INT32(X)       pu_print(E_INT32,  CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_UINT8(X)       pu_print(E_UINT8,  CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_UINT16(X)      pu_print(E_UINT16, CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_UINT32(X)      pu_print(E_UINT32, CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_FLOAT(X)       pu_print(E_FLOAT,  CAST_PRIMITIVE_TO_VOID_PTR(X))
#define PU_LOG_DOUBLE(X)      pu_print(E_DOUBLE, CAST_PRIMITIVE_TO_VOID_PTR(X))


void pu_print(primitive_types_t T, void* d);
