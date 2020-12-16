CARAVEL_PATH = ./../../../../../..

FIRMWARE_PATH = ../..
RTL_PATH = $(CARAVEL_PATH)/verilog/rtl
IP_PATH = $(CARAVEL_PATH)/verilog/ip
BEHAVIOURAL_MODELS = ../../ 

CARGO_PATH   = $(CARAVEL_PATH)/cargo
WB2AXI_PATH  = $(CARAVEL_PATH)/cargo/wb2axip/rtl
PROJECT_PATH = $(CARAVEL_PATH)/cargo/lis/rtl/LISTest
TOP_PATH     = $(CARAVEL_PATH)/cargo/top/rtl/LISTest

GCC_PATH?=$(RISCV32)/bin
GCC_PREFIX?=riscv32-unknown-elf
PDK_PATH?=$(PDK_ROOT)/sky130A

LIS_SIZE?=24 # Pass fft size to testbench and c code

.SUFFIXES:

PATTERN = PIN_LISInput_POUT

all:  ${PATTERN:=.vcd}

hex:  ${PATTERN:=.hex}

%.vvp: %_tb.v %.hex
	iverilog -DFUNCTIONAL -DSIM -DLIS_SIZE=$(LIS_SIZE) -I $(BEHAVIOURAL_MODELS) \
	-I $(WB2AXI_PATH)  \
	-I $(PROJECT_PATH) \
	-I $(TOP_PATH) \
	-I $(PDK_PATH) -I $(IP_PATH) -I $(RTL_PATH) \
	$< -o $@

%.vcd: %.vvp
	vvp $<

%.elf: %.c $(FIRMWARE_PATH)/sections.lds $(FIRMWARE_PATH)/start.s
	${GCC_PATH}/${GCC_PREFIX}-gcc -march=rv32imc -mabi=ilp32 -Wl,-Bstatic,-T,$(FIRMWARE_PATH)/sections.lds,--strip-debug -ffreestanding -nostdlib -DLIS_SIZE=$(LIS_SIZE) -o $@ $(FIRMWARE_PATH)/start.s $<

%.hex: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objcopy -O verilog $< $@ 
	# to fix flash base address
	sed -i 's/@10000000/@00000000/g' $@

%.bin: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objcopy -O binary $< /dev/stdout | tail -c +1048577 > $@

# ---- Clean ----

clean:
	rm -f *.elf *.hex *.bin *.vvp *.vcd *.log *.txt

.PHONY: clean hex all
