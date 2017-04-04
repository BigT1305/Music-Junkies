----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/02/2017 05:34:28 PM
-- Design Name: 
-- Module Name: Adder4 - Behavioral
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



entity Adder4 is
    GENERIC(CONSTANT N: INTEGER := 4);
    PORT(
    a:  IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);  --intput a[3..0]
    b:  IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);  --input  b[3..0]
    cOut:   OUT STD_LOGIC;
    sum:    OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0) --Output  sum[3..0]
    );
end Adder4;

architecture Behavioral of Adder4 is
    COMPONENT Adder1
        PORT(
        a,b,cIn : IN STD_LOGIC;
        cOut,sum : OUT STD_LOGIC);
    END COMPONENT;
    SIGNAL carry_sig: STD_LOGIC_VECTOR(N DOWNTO 0);

begin
    carry_sig(0) <= '0';
    generate_adders: for i in 0 to 3 generate
        first_adder : if i = 0 generate
            first_cell : Adder1 port map(a(0), b(0), carry_sig(0), carry_sig(i+1),sum(i));
        end generate first_adder;
        
        middle_adders : if i > 0 and i < 3 generate
            middle_cells : Adder1 port map(a(i), b(i), carry_sig(i), carry_sig(i+1),sum(i));
        end generate middle_adders;
        
        fourth_adder : if i = 3 generate
            fourth_cell : Adder1  port map(a(i),b(i),carry_sig(i),cOut,sum(i));
        end generate fourth_adder;
   end generate generate_adders;

end Behavioral;
