LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY Alu4 IS
	GENERIC(CONSTANT N: INTEGER := 4;							-- 4 bits ALU
			CONSTANT Z: STD_LOGIC_VECTOR(3 DOWNTO 1) := "000"	-- 3 Zeros
	);

	PORT(
		a, b:		IN STD_LOGIC_VECTOR(N-1 DOWNTO 0);
		control:	IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		overflow:	OUT STD_LOGIC;
		zero:		OUT STD_LOGIC;
		carryOut:	OUT STD_LOGIC;
		result:		OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0)
	);
END Alu4;

ARCHITECTURE behavioral OF Alu4 IS

COMPONENT Alu1
	PORT(
		a, b: IN STD_LOGIC;
		carryIn: IN STD_LOGIC;
		control: IN STD_LOGIC_VECTOR(1 DOWNTO 0);
		carryOut: OUT STD_LOGIC;
		result: OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL carry_sig: STD_LOGIC_VECTOR(N DOWNTO 0); -- carry_sig(N) = MSB carryOut
SIGNAL result_sig: STD_LOGIC_VECTOR(N-1 DOWNTO 0);

BEGIN
    WITH control SELECT
    carry_sig(0) <=
    '1'     WHEN    "01",
    '0'     WHEN    Others;
       
    ALU_1 : ALU1 port map(a(0) , b(0), carry_sig(0), control, carry_sig(1), result_sig(0));
    ALU_2 : ALU1 port map(a(0) , b(0), carry_sig(1), control(1 DOWNTO 0), carry_sig(2), result_sig(1));
    ALU_3 : ALU1 port map(a(0) , b(0), carry_sig(2), control(1 DOWNTO 0), carry_sig(3), result_sig(2));
    ALU_4 : ALU1 port map(a(0) , b(0), carry_sig(3), control(1 DOWNTO 0), carry_sig(4), result_sig(3));

carryOut <= carry_sig(4);
result <= result_sig;

with result_sig select
    zero <= '1' when "0000",
            '0' when others;
   
overflow <= carry_sig(3) xor carry_sig(4);            
--if (carry_sig(3) xor carry_sig(4)) = '1' then

--end if;


END behavioral;