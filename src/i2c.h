#ifndef _I2C_H_
#define _I2C_H_

#include <stdint.h>

void i2c_read_register( uint16_t address, uint8_t *data, uint8_t data_len );
void i2c_write_register( uint16_t address, uint8_t *data, uint8_t data_len );

#endif // _I2C_H_