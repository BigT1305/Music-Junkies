----------------------------------------------------------------------------------
-- Description:   1-bit Adder
-- Project:       Adder1 
-- Program-ID:    Adder1.vhd
-- Authors:       Music Junkies: Chris Wunstel, Rory Avant, Tony Hoss, Chris Vasquez
-- Package:       Xilinx Nexys4 DDR Board 
-- Device:        Artix-7 FPGA (XC7A100TCSG324-1) 
-- Software:      Vivado Design Suite
----------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY Adder1 IS
   PORT (
      a, b, cIn : IN std_logic;
      cOut, sum : OUT std_logic);
END Adder1;

ARCHITECTURE behavioral OF Adder1 IS
BEGIN

	cOut <= (a and b) or ((a xor b) and cIn);
	sum <= a xor ( b xor cIn);
	
END behavioral;
