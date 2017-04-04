----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/02/2017 07:38:48 PM
-- Design Name: 
-- Module Name: DispAdder4 - Behavioral
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

entity DispAdder4 is
    port(
      a: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      b: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      led: OUT STD_LOGIC;
      an:  OUT STD_LOGIC_VECTOR(7 DOWNTO 0);  --Output AN[7..0]: '0' enabled
      hex: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)   --Output HEX[6..0);
      );
END DispAdder4;

architecture Behavioral of DispAdder4 is
    COMPONENT Adder4
        PORT(
            a: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            b: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            cOut: OUT STD_LOGIC;
            sum: OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
          );
    END COMPONENT;
    COMPONENT Bin2Hex
        PORT(
            bin: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            hex: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
            );
    END COMPONENT;
    
    SIGNAL carry_sig: STD_LOGIC;
    SIGNAL sum_sig: STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL hex_sig: STD_LOGIC_VECTOR(6 DOWNTO 0);

begin

    Adder_4 : Adder4 port map(a, b, carry_sig, sum_sig);
    BinToHex : Bin2Hex port map(sum_sig, hex_sig);
    hex <= hex_sig;
    led <= carry_sig;
     an <= "11111110";

end Behavioral;
