@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.4\\bin
call %xv_path%/xelab  -wto a4c7e75cab5c48c1950195e532922dae -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot Adder1_tb_behav xil_defaultlib.Adder1_tb -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
