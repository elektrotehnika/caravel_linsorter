#ifndef _LISDEF_H_
#define _LISDEF_H_

#include <stdint.h>
#include <stdbool.h>

// Helper functions
#define _AC(X,Y)        (X##Y)

#define _REG32(p, i) (*(volatile uint32_t *) ((p) + (i)))

#define BEATBYTES 4

#define inSplitAddress       _AC(0x30000000,UL)
#define lisFIFOAddress       _AC(0x30001000,UL)
#define lisFIFOMuxAddress0   _AC(0x30001100,UL)
#define lisFixedAddress      _AC(0x30002000,UL)
#define lisFixedMuxAddress0  _AC(0x30002100,UL)
#define lisInputAddress      _AC(0x30003000,UL)
#define lisInputMuxAddress0  _AC(0x30003100,UL)
#define bistAddress          _AC(0x30004000,UL)
#define bistSplitAddress     _AC(0x30004100,UL)
#define outMuxAddress        _AC(0x30005000,UL)
#define outSplitAddress      _AC(0x30005010,UL)
#define uartParams           _AC(0x30006000,UL)
#define uRxSplitAddress      _AC(0x30006100,UL)


#define inSplitAddress_reg(offset)         _REG32(inSplitAddress, offset)
#define lisFIFOAddress_reg(offset)         _REG32(lisFIFOAddress, offset)
#define lisFIFOMuxAddress0_reg(offset)     _REG32(lisFIFOMuxAddress0, offset)
#define lisFixedAddress_reg(offset)        _REG32(lisFixedAddress, offset)
#define lisFixedMuxAddress0_reg(offset)    _REG32(lisFixedMuxAddress0, offset)
#define lisInputAddress_reg(offset)        _REG32(lisInputAddress, offset)
#define lisInputMuxAddress0_reg(offset)    _REG32(lisInputMuxAddress0, offset)
#define bistAddress_reg(offset)            _REG32(bistAddress, offset)
#define bistSplitAddress_reg(offset)       _REG32(bistSplitAddress, offset)
#define outMuxAddress_reg(offset)          _REG32(outMuxAddress, offset)
#define outSplitAddress_reg(offset)        _REG32(outSplitAddress, offset)
#define uartParams_reg(offset)             _REG32(uartParams, offset)
#define uRxSplitAddress_reg(offset)        _REG32(uRxSplitAddress, offset)

/* Register offsets */
#define uart_txfifo     0x00
#define uart_rxfifo 	0x04
#define uart_txctrl 	0x08
#define uart_txmark 	0x0a
#define uart_rxctrl 	0x0c
#define uart_rxmark		0x0e

#define uart_ie     	0x10
#define uart_ip    		0x14
#define uart_div    	0x18
#define uart_parity		0x1c
#define uart_wire4		0x20
#define uart_either8or9 0x24

#define mux_output_0    0x0*BEATBYTES
#define mux_output_1    0x1*BEATBYTES
#define mux_output_2    0x2*BEATBYTES

#define spl_ctrl        0x0*BEATBYTES
#define spl_mask        0x1*BEATBYTES

// --------------------------------------------------------
#endif
