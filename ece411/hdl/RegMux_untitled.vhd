--
-- VHDL Architecture ece411.RegMux.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 00:54:12 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY RegMux IS
   PORT( 
      A            : IN     LC3b_reg;
      Sel         : IN     std_logic;
      B           : IN     LC3b_reg;
      F         : OUT    LC3b_reg
   );

-- Declarations

END RegMux ;

--
ARCHITECTURE untitled OF RegMux IS
BEGIN
	PROCESS (A, B, Sel)
	VARIABLE STATE : LC3B_reg;
	BEGIN
		CASE Sel IS
			WHEN '0' =>
				STATE := A;
			WHEN '1' =>
				STATE := B;
			WHEN OTHERS =>
				STATE := (OTHERS => 'X');
		END CASE;
	F <= STATE AFTER DELAY_MUX2;
	END PROCESS;
END ARCHITECTURE untitled;

