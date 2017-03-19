@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.4\\bin
call %xv_path%/xelab  -wto 2e95b57a45f544119b86d10263ab2d79 -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L secureip --snapshot and2_tb_behav xil_defaultlib.and2_tb -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
