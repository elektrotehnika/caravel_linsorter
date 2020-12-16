LIS_PATH = ./lis
TOP_TEST_PATH = ./top/dv/LISTest/lis

SIZE?=24
export LIS_SIZE=$(SIZE)

move_user_proj_example:
	mv ../verilog/rtl/user_proj_example.v ./user_proj_example.v

move_back_user_proj_example:
	mv ./user_proj_example.v ../verilog/rtl/user_proj_example.v 
	
verilog_lis:
	cd $(LIS_PATH); sbt -J-Xmx2048m -J-XX:MaxMetaspaceSize=2048m "runMain lis.LISTestApp"; cd -;

test_lis:
	cd $(LIS_PATH);sbt -J-Xmx2048m -J-XX:MaxMetaspaceSize=2048m "testOnly lis.LISTestSpec"; cd -;

.PHONY: test_top
test_top:
	make move_user_proj_example
	make verilog_lis
	make test_lis
	cd $(TOP_TEST_PATH); make all; cd -;
	make move_back_user_proj_example

clean_top:
	cd $(TOP_TEST_PATH); make clean; cd -;
	
