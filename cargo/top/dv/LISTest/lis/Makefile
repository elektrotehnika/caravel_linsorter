# ---- Test patterns ----

.SUFFIXES:
.SILENT: clean all

PATTERNS = BIST_LISInput_POUT BIST_LISFixed_POUT BIST_LISFIFO_POUT PIN_LISInput_POUT PIN_LISFixed_POUT PIN_LISFIFO_POUT

all:  ${PATTERNS}
	for i in ${PATTERNS}; do \
		( cd $$i && make -f Makefile $${i}.vcd &> verify.log && grep Monitor verify.log) ; \
	done

clean:  ${PATTERNS}
	for i in ${PATTERNS}; do \
		rm -f verify.log; \
		( cd $$i && make clean ) ; \
	done

.PHONY: clean all
