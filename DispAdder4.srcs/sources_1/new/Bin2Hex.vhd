----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/02/2017 07:32:21 PM
-- Design Name: 
-- Module Name: Bin2Hex - Behavioral
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

entity Bin2Hex is
    port(
        bin:    IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        hex:    OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
        );
END Bin2Hex;       


architecture Behavioral of Bin2Hex is

begin
     WITH bin SELECT hex  <= 
            "1000000" when "0000", -- 0
            "1111001" when "0001", -- 1
            "0100100" when "0010", -- 2
            "0110000" when "0011", -- 3
            "0011001" when "0100", -- 4
            "0010010" when "0101", -- 5
            "0000010" when "0110", -- 6
            "1111000" when "0111", -- 7
            "0000000" when "1000", -- 8
            "0010000" when "1001", -- 9
            "0001000" when "1010", -- A
            "0000011" when "1011", -- B
            "1000110" when "1100", -- C
            "0100001" when "1101", -- D
            "0000110" when "1110", -- E
            "0001110" when "1111", -- F
            "1111110" when others; 


end Behavioral;
