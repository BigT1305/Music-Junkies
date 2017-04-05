----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/04/2017 03:26:18 PM
-- Design Name: 
-- Module Name: Alu4 - simulate
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


entity Alu4_tb is
end Alu4_tb;

architecture simulate of Alu4_tb is
COMPONENT Alu1
	PORT(
		a, b: IN STD_LOGIC;
		carryIn: IN STD_LOGIC;
		control: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		carryOut: OUT STD_LOGIC;
		result: OUT STD_LOGIC
	);
END COMPONENT;
	

    signal result_sig:       STD_LOGIC_VECTOR(3 DOWNTO 0);
    signal carry_sig :       STD_LOGIC_VECTOR(4 DOWNTO 0);
begin

  WITH control SELECT
    carry_sig(0) <=
    '1'     WHEN    "01",
    '0'     WHEN    Others;
    
    ALU_1 : ALU1 port map(a(0) , b(0), carry_sig(0), control(1 DOWNTO 0), carry_sig(1), result_sig(0));
    ALU_2 : ALU1 port map(a(1) , b(1), carry_sig(1), control(1 DOWNTO 0), carry_sig(2), result_sig(1));
    ALU_3 : ALU1 port map(a(2) , b(2), carry_sig(2), control(1 DOWNTO 0), carry_sig(3), result_sig(2));
    ALU_4 : ALU1 port map(a(3) , b(3), carry_sig(3), control(1 DOWNTO 0), carry_sig(4), result_sig(3));
    
    
    carryOut <= carry_sig(4);
    result <= result_sig;
    
    with result_sig select
        zero <= '1' when "0000",
                '0' when others;
       
    overflow <= carry_sig(3) xor carry_sig(4); 
    
    stimulus: process
    
            BEGIN 
            
            ---test bencbh stimulus code---
            
            a <= "0000";    b <= "0000";    control <= "00";
            WAIT FOR 60ns;
            
            a <= "0111";    b <= "0001";    control <= "00";
            WAIT FOR 60ns;
                        
            a <= "0111";    b <= "1111";    control <= "00";
            WAIT FOR 60ns;
                                    
            a <= "1111";    b <= "0111";    control <= "00";
            WAIT FOR 60ns;
            
            a <= "1000";    b <= "0001";    control <= "00";
            WAIT FOR 60ns;
            
            a <= "1000";    b <= "1111";    control <= "00";
            WAIT FOR 60ns;
            
                     
               a <= "0000";    b <= "0000";    control <= "01";
               WAIT FOR 60ns;
               
               a <= "0111";    b <= "0001";    control <= "01";
               WAIT FOR 60ns;
                           
               a <= "0111";    b <= "1111";    control <= "01";
               WAIT FOR 60ns;
                                       
               a <= "1111";    b <= "0111";    control <= "01";
               WAIT FOR 60ns;
               
               a <= "1000";    b <= "0001";    control <= "01";
               WAIT FOR 60ns;
               
               a <= "1000";    b <= "1111";    control <= "01";
               WAIT FOR 60ns;
               
                           
               a <= "0000";    b <= "0000";    control <= "10";
               WAIT FOR 60ns;
               
               a <= "0111";    b <= "0001";    control <= "10";
               WAIT FOR 60ns;
                           
               a <= "0111";    b <= "1111";    control <= "10";
               WAIT FOR 60ns;
                                       
               a <= "1111";    b <= "0111";    control <= "10";
               WAIT FOR 60ns;
               
               a <= "1000";    b <= "0001";    control <= "10";
               WAIT FOR 60ns;
               
               a <= "1000";    b <= "1111";    control <= "10";
               WAIT FOR 60ns;
               
                        
                  a <= "0000";    b <= "0000";    control <= "11";
                  WAIT FOR 60ns;
                  
                  a <= "0111";    b <= "0001";    control <= "11";
                  WAIT FOR 60ns;
                              
                  a <= "0111";    b <= "1111";    control <= "11";
                  WAIT FOR 60ns;
                                          
                  a <= "1111";    b <= "0111";    control <= "11";
                  WAIT FOR 60ns;
                  
                  a <= "1000";    b <= "0001";    control <= "11";
                  WAIT FOR 60ns;
                  
                  a <= "1000";    b <= "1111";    control <= "11";
                  WAIT FOR 60ns;
                           
                        
    end process;            
end simulate;
