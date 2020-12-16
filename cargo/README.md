
LINSORTER - LinearINsertion SORTER 
=======================================================

Block diagram of the LinearINsertion SORTER is given below and detailed explanation of the each block is given inside submodules `lis` and `wb2axip`.

![Global block scheme of the LINSORTER](./doc/images/LinearSorters.svg)

This directory contains following submodules and directories:

* Submodule `lis` -  contains a linear insertion sorter (LIS) generator written in [Chisel ](http://www.chisel-lang.org) hardware design language. It comprises description of three types of the linear insertion sorter, parameter definition, setup explanation and many other useful information related to blocks that are depicted at presented global block scheme.
* Submodule  `wb2axip` - contains wishbone to AXI4 bridge. Current submodule is forked version of the [ZipCPU/wb2axip](https://github.com/ZipCPU/wb2axip). While all blocks inside LINSORTER use AXI4 memory mapped bus, this bridge was necessary to attach so that correct connection between processor and linear insertion sorters is established.
* `doc` - contains global block scheme of the LINSORTER in svg and png format.
* `top/dv/LISTest` - contains verilog testbenches mostly, together with .c files.
* `top/rtl/LISTest` - contains `user_proj_example.v`.
* Makefile - have targets for verilog generation (module LISTest) and for running scala tests described  inside `lis` submodule.

