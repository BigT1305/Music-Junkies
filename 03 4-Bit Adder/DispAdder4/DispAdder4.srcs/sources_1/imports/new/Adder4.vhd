LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY Adder4 IS
	GENERIC (CONSTANT N: INTEGER := 4);
	PORT(
		a: IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);   --input a[3..0]
		b: IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);   --input b[3..0]

		cOut: OUT STD_LOGIC;                    --output cOut
		sum: OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0) --output sum[3..0]
	);
END Adder4;
ARCHITECTURE behavioral OF Adder4 IS
	COMPONENT Adder1
		PORT(
			a, b, cIn : IN STD_LOGIC;
			cOut,sum: OUT STD_LOGIC);
	END COMPONENT;
	SIGNAL carry_sig: STD_LOGIC_VECTOR(N DOWNTO 0);

	----------------------------------------------- 
BEGIN
carry_sig(0) <= '0';
	cell1 : Adder1 
		port map(a(0), b(0), carry_sig(0), carry_sig(1),sum(0));
		
	cell2 : Adder1 
				port map(a(1), b(1), carry_sig(1), carry_sig(2), sum(1));
				
    cell3 : Adder1 
				port map(a(2), b(2), carry_sig(2), carry_sig(3), sum(2));
						
	cell4 : Adder1  
		   		port map(a(3), b(3), carry_sig(3), cOut,sum(3));
		   		

END behavioral; 