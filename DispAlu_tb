LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY DispAlu4 IS
END DispAlu4;

ARCHITECTURE simulate OF DispAlu4 IS 

COMPONENT Alu4
	PORT(
		a, b:		IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		control:	IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		overflow:	OUT STD_LOGIC;
		zero:		OUT STD_LOGIC;
		carryOut:	OUT STD_LOGIC;
		result:		OUT STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END COMPONENT;

COMPONENT Bin2Hex
	PORT(
		bin: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		hex: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
	);
END COMPONENT;

SIGNAL overflow_sig:	STD_LOGIC;
SIGNAL zero_sig:		STD_LOGIC;
SIGNAL carry_sig:		STD_LOGIC;
SIGNAL result_sig:		STD_LOGIC_VECTOR(3 DOWNTO 0);

BEGIN

    alu :Alu4 port map(a, b, control, overflow_sig, zero_sig, carry_sig, result_sig);
    bin : Bin2Hex port map(result_sig, hex);
    led15 <= overflow_sig;
    led17 <= zero_sig;
    led16 <= carry_sig;
    an <= "11111110";

    simulate: process
    
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
END simulate;
