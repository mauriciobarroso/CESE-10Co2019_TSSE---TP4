/* Copyright 2020, Mauricio Barroso
 * All rights reserved.
 *
 * This file is part of EMMON.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/* Date: 05/01/20 */

#ifndef _EEPROM_H_
#define _EEPROM_H_

/*==================[inclusions]=============================================*/

#include <stdint.h>
#include <stdbool.h>

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

#define EEPROM_SIZE				4096	// EEPROM size in bytes (32Kbits)
#define EEPROM_INITIAL_ADDRESS	0x0		// EEPROM initial addres

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

/**
 * @brief Function to read a 8-bit value of an EEPROM address
 *
 * @param address[in] EEPROM address to be read
 * @param data[out] Pointer to varible that stores the 8-bit value to be read 
 * 					of the EEPROM
 * 
 * @return
 * 		- true Parameters whithin range
 * 		- false Parameters out of range
 */
uint8_t eeprom_read8( uint16_t address, uint8_t *data );

/**
 * @brief Function to read a 16-bit value of an EEPROM address
 *
 * @param address[in] EEPROM address to be read
 * @param data[out] Pointer to varible that stores the 16-bit value to be read 
 * 					of the EEPROM
 * 
 * @return
 * 		- true Parameters whithin range
 * 		- false Parameters out of range
 */
uint8_t eeprom_read16( uint16_t address, uint16_t *data );

/**
 * @brief Function to read a 32-bit value of an EEPROM address
 *
 * @param address[in] EEPROM address to be read
 * @param data[out] Pointer to varible that stores the 32-bit value to be read 
 * 					of the EEPROM
 * 
 * @return
 * 		- true Parameters whithin range
 * 		- false Parameters out of range
 */
uint8_t eeprom_read32( uint16_t address, uint32_t *data );

/**
 * @brief Function to write a 8-bit value to an EEPROM address
 *
 * @param address[in] EEPROM address to be written
 * @param data[in] Pointer to varible that stores the 8-bit value to be written 
 * 				   in the EEPROM
 * 
 * @return
 * 		- true Parameters whithin range
 * 		- false Parameters out of range
 */
uint8_t eeprom_write8( uint16_t address, uint8_t *data );

/**
 * @brief Function to write a 16-bit value to an EEPROM address
 *
 * @param address[in] EEPROM address to be written
 * @param data[in] Pointer to varible that stores the 16-bit value to be written 
 * 				   in the EEPROM
 * 
 * @return
 * 		- true Parameters whithin range
 * 		- false Parameters out of range
 */
uint8_t eeprom_write16( uint16_t address, uint16_t *data );

/**
 * @brief Function to write a 32-bit value to an EEPROM address
 *
 * @param address[in] EEPROM address to be written
 * @param data[in] Pointer to varible that stores the 32-bit value to be written 
 * 				   in the EEPROM
 * 
 * @return
 * 		- true Parameters whithin range
 * 		- false Parameters out of range
 */
uint8_t eeprom_write32( uint16_t address, uint32_t *data );

/*==================[cplusplus]==============================================*/

#ifdef __cplusplus
}
#endif

/** @} doxygen end group definition */
/*==================[end of file]============================================*/

#endif /* #ifndef _EEPROM_H_ */