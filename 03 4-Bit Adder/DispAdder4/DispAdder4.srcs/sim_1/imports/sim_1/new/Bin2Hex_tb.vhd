--------------------------------------------------------------------------------
-- Description:	Convert 4-bit binary to 7-segment hex display (Test Bench)
-- Program-ID:    Bin2Hex.vhd
-- Author:        Kuo-pao Yang 
-- Package:       Xilinx Nexys4 DDR Board 
-- Device:        Artix-7 FPGA (XC7A100TCSG324-1) 
-- Software:      Vivado Design Suite
-- Note:
-- 1. Position and index of each segment in a 7-sigment display: hex[6..0]
--       0  
--      ---  
--    5|   |1
--     | 6 |
--      ---  
--    4|   |2
--     | 3 |
--      ---  
-- hex index	6	5	4	3	2	1	0							
-- cathodes  	CG	CF	CE	CD	CC	CB	CA ('0' light on, '1' light OFF) 
-- 2. Display hexadecimal value: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, b, C, d, E, F
--------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY Bin2Hex_tb IS
END Bin2Hex_tb;

ARCHITECTURE simulate OF Bin2Hex_tb IS
   COMPONENT Bin2Hex
      PORT (
		   bin: 	IN  STD_LOGIC_VECTOR(3 DOWNTO 0);	-- Input    bin[3..0]
		   hex: 	OUT STD_LOGIC_VECTOR(6 DOWNTO 0)	   -- Output	hex[6..0] 7-sigment display 
      );
   END COMPONENT;
   SIGNAL bin: STD_LOGIC_VECTOR(3 DOWNTO 0);
   SIGNAL hex: STD_LOGIC_VECTOR(6 DOWNTO 0);   -- Hex to display

BEGIN
   uut: Bin2Hex PORT MAP (bin, hex);
    
   stimulus: PROCESS
   BEGIN
         -- test bench stimulus code
         bin   <= "0000";     -- 0
         WAIT FOR 60 ns;
         bin   <= "0001";     --1
         WAIT FOR 60 ns;
         bin   <= "0010";     -- 2
         WAIT FOR 60 ns;
         bin   <= "0011";     --3
         WAIT FOR 60 ns;
         bin   <= "0100";     -- 4
         WAIT FOR 60 ns;
         bin   <= "0101";     --5
         WAIT FOR 60 ns;
         bin   <= "0110";     -- 6
         WAIT FOR 60 ns;
         bin   <= "0111";     -- 7
         WAIT FOR 60 ns;
         bin   <= "1000";     -- 8
         WAIT FOR 60 ns;
         bin   <= "1001";     -- 9
         WAIT FOR 60 ns;
         bin   <= "1010";     -- A
         WAIT FOR 60 ns;
         bin   <= "1011";     -- b
         WAIT FOR 60 ns;
         bin   <= "1100";     -- C
         WAIT FOR 60 ns;
         bin   <= "1101";     -- d
         WAIT FOR 60 ns;
         bin   <= "1110";     -- E
         WAIT FOR 60 ns;
         bin   <= "1111";     -- F
         WAIT FOR 60 ns;
         bin   <= "0000";     -- 0
         WAIT FOR 60 ns;
          
         WAIT;
   END PROCESS;
END simulate;