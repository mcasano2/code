--
-- VHDL Architecture ece411.IReadDelay.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 00:27:28 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY IReadDelay IS
   PORT( 
      CLK       : IN     STD_LOGIC;
      Load       : IN     STD_LOGIC;
      RESET     : IN     std_logic;
      I_MREAD_L : OUT    STD_LOGIC
   );

-- Declarations

END IReadDelay ;

--
ARCHITECTURE untitled OF IReadDelay IS
SIGNAL PRE_OUT : std_logic;
BEGIN
 	PROCESS (CLK, Load)
	BEGIN
		IF (RESET = '0') THEN
			PRE_OUT <= '0';
		ELSIF Load = '1' THEN	
	   	IF CLK'EVENT AND CLK = '1' THEN
				  PRE_OUT <= '0';
		  Else
		      Pre_out <= '0';
		  END IF;
		END IF;
	END PROCESS;
	I_MREAD_L <= PRE_OUT AFTER 15 ns;
END ARCHITECTURE untitled;

