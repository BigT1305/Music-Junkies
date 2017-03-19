----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/07/2017 08:07:18 PM
-- Design Name: 
-- Module Name: DispAdder4_tb - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity DispAdder4_tb is
END DispAdderr_tb;

architecture simulate of DispAdder4_tb is
	COMPONENT Adder4 --4-bit full adder (Adder4.vhd)
	PORT(
		a: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		b: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		cOut: OUT STD_LOGIC;
		sum: OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END COMPONENT;

COMPONENT Bin2Hex --4-bit binary inputs to 7-segment hex display (Bin2Hex.vhd)
	PORT(
			bin: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
			hex: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
		);
END COMPONENT;
	SIGNAL carry_sig:	STD_LOGIC_VECTOR(3 DOWNTO 0);
	SIGNAL sum_sig:		STD_LOGIC_VECTOR(3 DOWNTO 0);
	SIGNAL hex_sig:		STD_LOGIC_VECTOR(6 DOWNTO 0);
	SIGNAL cOut:		STD_LOGIC;
BEGIN

 	adder : Adder4 port map(a,b,carry_sig(0),sum_sig);
 	BinaryToHex: Bin2Hex port map(sum_sig,hex);
	
	uut: Adder4 PORT MAP (a, b, cOut, sum);
	
 stimulus: PROCESS
	  
	  BEGIN
	        -- test bench stimulus code
	        a     <= "0000";     b     <= "0101";   -- 0 + 5 => 05 (0 0101)
	 WAIT;
   END PROCESS;  
END simulate;

