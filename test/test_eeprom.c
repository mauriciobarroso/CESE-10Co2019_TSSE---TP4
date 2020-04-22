/*===inclusions=================================*/

#include "unity.h"
#include "eeprom.h"
#include "mock_i2c.h"
#include <string.h>

/*===macros=====================================*/

/*===data declaration===========================*/

/* EEPROM virtual */
uint8_t virtual_eeprom[ EEPROM_SIZE ];

/* dirección de memroria de la EEPROM virtual */
uint16_t address;

/*===functions==================================*/

/* */
static void mock_read( uint16_t address, uint8_t *data, uint8_t data_len, int num_calls )
{
    memcpy( data, &virtual_eeprom[ address ], data_len );
}

/* */
static void mock_write( uint16_t address, uint8_t *data, uint8_t data_len, int num_calls )
{
    memcpy( &virtual_eeprom[ address ], data, data_len );
}

/*  */
void setUp( void )
{
    i2c_write_register_StubWithCallback( mock_write );
    i2c_read_register_StubWithCallback( mock_read );
}

void tearDown( void )
{

}
/*===tests======================================*/

/* se puede leer un dato de 8 bits de la EEPROM */
void test_eeprom_read8( void )
{
    /* se declaran datos iniciales */
    address = 0;
    uint8_t read_data = 0;
    uint8_t write_data = 0xFF;

    /* se escribe directamente en la EEPROM virtual el dato de 32 bits */
    virtual_eeprom[ address ] = write_data;

    /* se ejecuta la función de lectura de 8 bits de la EEPROM */
    eeprom_read8( address, &read_data );

    /* se verifica si el valor leído es igual al valor escrito */
    TEST_ASSERT_EQUAL_HEX8( write_data, read_data );
}

/* se puede escribir un dato de 8 bits en la EEPROM */
void test_eeprom_write8( void )
{
    /* se declaran datos iniciales */
    address = 0x3;   
    uint8_t read_data = 0;
    uint8_t write_data = 0xF1;

    /* se ejecuta la función de escritura de 8 bits de la EEPROM */
    eeprom_write8( address, &write_data );

    /* se ejecuta la función de lectura de 8 bits de la EEPROM */
    eeprom_read8( address, &read_data );

    /* se verifica si el valor leído es igual al valor escrito */
    TEST_ASSERT_EQUAL_HEX8( write_data, read_data );
}

/* se puede leer un dato de 16 bits de la EEPROM */
void test_eeprom_read16( void )
{
    /* se declaran datos iniciales */
    address = 0x3;   
    uint16_t read_data = 0;
    uint16_t write_data = 0xABCD;

    /* se escribe directamente en la EEPROM virtual el dato de 16 bits */
    virtual_eeprom[ address ] = ( uint8_t )( ( write_data & 0xFF00 ) >> 8 );
    virtual_eeprom[ address + 1 ] = ( uint8_t )( write_data & 0xFF );

    /* se ejecuta la función de lectura de 16 bits de la EEPROM */
    eeprom_read16( address, &read_data );

    /* se verifica si el valor leído es igual al valor escrito */
    TEST_ASSERT_EQUAL_HEX16( write_data, read_data );
}

/* se puede escribir un dato de 16 bits en la EEPROM */
void test_eeprom_write16( void )
{
    /* se declaran datos iniciales */
    address = 0xFFE;   
    uint16_t read_data = 0;
    uint16_t write_data = 0x1234;

    /* se ejecuta la función de escritura de 16 bits de la EEPROM */
    eeprom_write16( address, &write_data );

    /* se ejecuta la función de lectura de 16 bits de la EEPROM */
    eeprom_read16( address, &read_data );

    /* se verifica si el valor leído es igual al valor escrito */
    TEST_ASSERT_EQUAL_HEX16( write_data, read_data );
}

/* se puede leer un dato de 32 bits de la EEPROM */
void test_eeprom_read32( void )
{
    /* se declaran datos iniciales */
    address = 0xA;   
    uint32_t read_data = 0;
    uint32_t write_data = 0x12345678;

    /* se escribe directamente en la EEPROM virtual el dato de 32 bits */
    virtual_eeprom[ address ] = ( uint8_t )( ( write_data & 0xFF000000 ) >> 24 );
    virtual_eeprom[ address + 1 ] = ( uint8_t )( ( write_data & 0x00FF0000 ) >> 16 );
    virtual_eeprom[ address + 2 ] = ( uint8_t )( ( write_data & 0x0000FF00 ) >> 8 );
    virtual_eeprom[ address + 3 ] = ( uint8_t )( write_data & 0x000000FF );

    /* se ejecuta la función de lectura de 32 bits de la EEPROM */
    eeprom_read32( address, &read_data );

    /* se verifica si el valor leído es igual al valor escrito */
    TEST_ASSERT_EQUAL_HEX32( write_data, read_data );
}

/* se puede escribir un dato de 32 bits en la EEPROM */
void test_eeprom_write32( void )
{
    /* se declaran datos iniciales */
    address = 0x1F;   
    uint32_t read_data = 0;
    uint32_t write_data = 0x01010102;

    /* se ejecuta la función de escritura de 32 bits de la EEPROM */
    eeprom_write32( address, &write_data );

    /* se ejecuta la función de lectura de 32 bits de la EEPROM */
    eeprom_read32( address, &read_data );

    /* se verifica si el valor leído es igual al valor escrito */
    TEST_ASSERT_EQUAL_HEX32( write_data, read_data );
}

/* se detecta si se escribe o lee de una dirección de la EEPROM por debajo del rango permitido */
void test_eeprom_address_less_than_initial_address( void )
{
    /* se define una dirección de memoria por debajo del rango inferior */
    address = EEPROM_INITIAL_ADDRESS - 1;

    /* se declaran los datos a ser escritos y leídos de 8 bits */
    uint8_t read_data8 = 0x0;    
    uint8_t write_data8 = 0xFF;    

    /* se verifica si el valor obtenido por las funciones de lectura y escritura es false */
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_read8( address, &read_data8 ) );
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_write8( address, &write_data8 ) );

    /* se declaran los datos a ser escritos y leídos de 16 bits */
    uint16_t read_data16 = 0x0;    
    uint16_t write_data16 = 0xFFFF;    

    /* se verifica si el valor obtenido por las funciones de lectura y escritura es false */
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_read16( address, &read_data16 ) );
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_write16( address, &write_data16 ) );

    /* se declaran los datos a ser escritos y leídos de 32 bits */
    uint32_t read_data32 = 0x0;    
    uint32_t write_data32 = 0xFFFFFFFF;    

    /* se verifica si el valor obtenido por las funciones de lectura y escritura es false */
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_read32( address, &read_data32 ) );
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_write32( address, &write_data32 ) );
}

/* se detecta si se escribe o lee de una dirección de la EEPROM por encima del rango permitido */
void test_eeprom_address_greater_than_eeprom_size( void )
{
    /* se define una dirección de memoria por encima del rango permitido para 8 bits */
    address = EEPROM_SIZE - sizeof( uint8_t ) + 1;

    /* se declaran los datos a ser escritos y leídos de 8 bits */
    uint8_t read_data8 = 0x0;    
    uint8_t write_data8 = 0xFF;    

    /* se verifica si el valor obtenido por las funciones de lectura y escritura es false */
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_read8( address, &read_data8 ) );
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_write8( address, &write_data8 ) );
    
    /* se define una dirección de memoria por encima del rango permitido para 16 bits */
    address = EEPROM_SIZE - sizeof( uint16_t ) + 1;

    /* se declaran los datos a ser escritos y leídos de 16 bits */
    uint16_t read_data16 = 0x0;    
    uint16_t write_data16 = 0xFFFF;    

    /* se verifica si el valor obtenido por las funciones de lectura y escritura es false */
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_read16( address, &read_data16 ) );
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_write16( address, &write_data16 ) );

    /* se define una dirección de memoria por encima del rango permitido para 32 bits */
    address = EEPROM_SIZE - sizeof( uint32_t ) + 1;

    /* se declaran los datos a ser escritos y leídos de 32 bits */
    uint32_t read_data32 = 0x0;    
    uint32_t write_data32 = 0xFFFFFFFF;    

    /* se verifica si el valor obtenido por las funciones de lectura y escritura es false */
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_read32( address, &read_data32 ) );
    TEST_ASSERT_EQUAL_UINT8( false, eeprom_write32( address, &write_data32 ) );
}