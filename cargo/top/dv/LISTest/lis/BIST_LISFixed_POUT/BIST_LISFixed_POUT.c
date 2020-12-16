#include "../../defs.h"
#include "../../stub.c"

#include "../../lisDefs.h"

/*
	LIS Test:
*/


void main()
{
	// Configure GPIO pins
        reg_mprj_io_24 = GPIO_MODE_USER_STD_INPUT_PULLUP;
        reg_mprj_io_23 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_22 = GPIO_MODE_USER_STD_OUTPUT;

        reg_mprj_io_21 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_20 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_19 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_18 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_17 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_16 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_15 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_14 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_13 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_12 = GPIO_MODE_USER_STD_OUTPUT;
        reg_mprj_io_11 = GPIO_MODE_USER_STD_INPUT_PULLDOWN;

        reg_mprj_io_10 = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_9  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_8  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_7  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_6  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_5  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_4  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_3  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_2  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_1  = GPIO_MODE_USER_STD_INPUT_PULLDOWN;
        reg_mprj_io_0  = GPIO_MODE_USER_STD_OUTPUT;

        /* Apply configuration */
        reg_mprj_xfer = 1;
        while (reg_mprj_xfer == 1);

        bistAddress_reg(2*BEATBYTES) = 0x1; // configure counter to be active
        bistAddress_reg(3*BEATBYTES) = 0x1; // configure counter to be up counter
  
        lisFixedMuxAddress0_reg(0) = 0x0;
        lisFixedAddress_reg(4*BEATBYTES) = LIS_SIZE/2;

        lisFIFOMuxAddress0_reg(BEATBYTES) = 0x0;
        lisInputMuxAddress0_reg(BEATBYTES) = 0x0;
        
        // configure fixed -> outMux
        outMuxAddress_reg(0) = 0x2;
        // configure bist_split -> out_mux
        outMuxAddress_reg(2*BEATBYTES) = 0x3;
  
        // enable bist
        bistAddress_reg(0) =  0x1; 
}