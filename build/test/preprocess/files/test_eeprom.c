#include "build/temp/_test_eeprom.c"
#include "build/test/mocks/mock_i2c.h"
#include "src/eeprom.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"


















uint8_t virtual_eeprom[ 4096 ];





uint16_t address;









static void mock_read( uint16_t address, uint8_t *data, uint8_t data_len, int num_calls )

{

    memcpy( data, &virtual_eeprom[ address ], data_len );

}





static void mock_write( uint16_t address, uint8_t *data, uint8_t data_len, int num_calls )

{

    memcpy( &virtual_eeprom[ address ], data, data_len );

}





void setUp( void )

{

    i2c_write_register_Stub( mock_write );

    i2c_read_register_Stub( mock_read );

}



void tearDown( void )

{



}







void test_eeprom_read8( void )

{



    address = 0;

    uint8_t read_data = 0;

    uint8_t write_data = 0xFF;





    virtual_eeprom[ address ] = write_data;





    eeprom_read8( address, &read_data );





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((write_data)), (UNITY_INT)(UNITY_INT8 )((read_data)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_HEX8);

}





void test_eeprom_write8( void )

{



    address = 0x3;

    uint8_t read_data = 0;

    uint8_t write_data = 0xF1;





    eeprom_write8( address, &write_data );





    eeprom_read8( address, &read_data );





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((write_data)), (UNITY_INT)(UNITY_INT8 )((read_data)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX8);

}





void test_eeprom_read16( void )

{



    address = 0x3;

    uint16_t read_data = 0;

    uint16_t write_data = 0xABCD;





    virtual_eeprom[ address ] = ( uint8_t )( ( write_data & 0xFF00 ) >> 8 );

    virtual_eeprom[ address + 1 ] = ( uint8_t )( write_data & 0xFF );





    eeprom_read16( address, &read_data );





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((write_data)), (UNITY_INT)(UNITY_INT16)((read_data)), (

   ((void *)0)

   ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_HEX16);

}





void test_eeprom_write16( void )

{



    address = 0xFFE;

    uint16_t read_data = 0;

    uint16_t write_data = 0x1234;





    eeprom_write16( address, &write_data );





    eeprom_read16( address, &read_data );





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((write_data)), (UNITY_INT)(UNITY_INT16)((read_data)), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_HEX16);

}





void test_eeprom_read32( void )

{



    address = 0xA;

    uint32_t read_data = 0;

    uint32_t write_data = 0x12345678;





    virtual_eeprom[ address ] = ( uint8_t )( ( write_data & 0xFF000000 ) >> 24 );

    virtual_eeprom[ address + 1 ] = ( uint8_t )( ( write_data & 0x00FF0000 ) >> 16 );

    virtual_eeprom[ address + 2 ] = ( uint8_t )( ( write_data & 0x0000FF00 ) >> 8 );

    virtual_eeprom[ address + 3 ] = ( uint8_t )( write_data & 0x000000FF );





    eeprom_read32( address, &read_data );





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((write_data)), (UNITY_INT)(UNITY_INT32)((read_data)), (

   ((void *)0)

   ), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_HEX32);

}





void test_eeprom_write32( void )

{



    address = 0x1F;

    uint32_t read_data = 0;

    uint32_t write_data = 0x01010102;





    eeprom_write32( address, &write_data );





    eeprom_read32( address, &read_data );





    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((write_data)), (UNITY_INT)(UNITY_INT32)((read_data)), (

   ((void *)0)

   ), (UNITY_UINT)(154), UNITY_DISPLAY_STYLE_HEX32);

}





void test_eeprom_address_less_than_initial_address( void )

{



    address = 0x0 - 1;





    uint8_t read_data8 = 0x0;

    uint8_t write_data8 = 0xFF;





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_read8( address, &read_data8 ))), (

   ((void *)0)

   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_write8( address, &write_data8 ))), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_UINT8);





    uint16_t read_data16 = 0x0;

    uint16_t write_data16 = 0xFFFF;





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_read16( address, &read_data16 ))), (

   ((void *)0)

   ), (UNITY_UINT)(176), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_write16( address, &write_data16 ))), (

   ((void *)0)

   ), (UNITY_UINT)(177), UNITY_DISPLAY_STYLE_UINT8);





    uint16_t read_data32 = 0x0;

    uint16_t write_data32 = 0xFFFFFFFF;





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_read32( address, &read_data32 ))), (

   ((void *)0)

   ), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_write32( address, &write_data32 ))), (

   ((void *)0)

   ), (UNITY_UINT)(185), UNITY_DISPLAY_STYLE_UINT8);

}





void test_eeprom_address_greater_than_eeprom_size( void )

{



    address = 4096 - sizeof( uint8_t ) + 1;





    uint8_t read_data8 = 0x0;

    uint8_t write_data8 = 0xFF;





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_read8( address, &read_data8 ))), (

   ((void *)0)

   ), (UNITY_UINT)(199), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_write8( address, &write_data8 ))), (

   ((void *)0)

   ), (UNITY_UINT)(200), UNITY_DISPLAY_STYLE_UINT8);





    address = 4096 - sizeof( uint16_t ) + 3;





    uint16_t read_data16 = 0x0;

    uint16_t write_data16 = 0xFFFF;





    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_read16( address, &read_data16 ))), (

   ((void *)0)

   ), (UNITY_UINT)(210), UNITY_DISPLAY_STYLE_UINT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((

   0

   )), (UNITY_INT)(UNITY_UINT8 )((eeprom_write16( address, &write_data16 ))), (

   ((void *)0)

   ), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_UINT8);

}
