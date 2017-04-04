LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY DispAlu4 IS
	port(
		a:			IN STD_LOGIC_VECTOR(3 DOWNTO 0);	-- Input SW[7..4]: a[3..0]
		b:			IN STD_LOGIC_VECTOR(3 DOWNTO 0);	-- Input SW[3..0]: b[3..0]
		control:	IN STD_LOGIC_VECTOR(1 DOWNTO 0);	-- Input SW[15..14]: control[1..0]
		led15:		OUT STD_LOGIC;						-- Output LED[15]: overflow
		led17:		OUT STD_LOGIC;						-- Output LED[17]: zero
		led16:		OUT STD_LOGIC;						-- Output LED[16]: carryOut
		an:			OUT STD_LOGIC_VECTOR(7 DOWNTO 0);	-- Output AN[7..0]: '0' enabled
		hex:		OUT STD_LOGIC_VECTOR(6 DOWNTO 0)	-- Output HEX[6..0]: result[3..0]
	);
END DispAlu4;

ARCHITECTURE behavioral OF DispAlu4 IS 

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

END behavioral;