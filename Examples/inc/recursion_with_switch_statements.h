/** @file recursion_with_switch_statements.h
 * @author Austin Harrison
 * @brief Example of using recursion with switch statements to avoid repeated code.
 * 
 */
 
#ifndef RECURSION_WITH_SWITCH_STATEMENTS_H_
    #define RECURSION_WITH_SWITCH_STATEMENTS_H_

    #include <stdint.h>
    #include "log.h"

    typedef union BIT_FIELDS {
        uint32_t w[2];

        // The struct is just here to log stuff;
        struct {
            uint8_t  A;
            uint8_t  B;
            uint16_t C;
            uint16_t D;
            uint16_t E;
        } b;
    } bit_fields_t;

   /** @fn modify_multiple_fields
    * @brief Setting multiple bitfields in one function call with user pre-defined choices.
    */
    void modify_multiple_fields (char, bit_fields_t*);

    /** @fn log_bit_fields
    * @brief Logs the bit fields to showcase how they change.
    */
    void log_bit_fields (bit_fields_t*);

#endif /* RECURSION_WITH_SWITCH_STATEMENTS_H_ */