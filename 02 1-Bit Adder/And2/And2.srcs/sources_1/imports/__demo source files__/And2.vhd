----------------------------------------------------------------------------------
-- Description:   2-input And Gate
-- Project:       And2 
-- Program-ID:    And2.vhd
-- Author:        Kuo-pao Yang 
-- Package:       Xilinx Nexys4 DDR Board 
-- Device:        Artix-7 FPGA (XC7A100TCSG324-1) 
-- Software:      Vivado Design Suite
----------------------------------------------------------------------------------
-- test
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY And2 IS
    PORT ( a : IN STD_LOGIC;
           b : IN STD_LOGIC;
           c : OUT STD_LOGIC);
END And2;

ARCHITECTURE behavioral OF And2 IS
BEGIN

    c <= a AND b;

END behavioral;
