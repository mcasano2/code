--
-- VHDL Architecture ece411.GenCC.UNTITLED
--
-- Created:
--          by - baker30.ews (siebl-0220-06.ews.illinois.edu)
--          at - 03:27:13 01/22/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY GenCC IS
   PORT( 
      RFMuxout : IN     LC3b_word;
      GenCCout : OUT    LC3b_cc
   );

-- Declarations

END GenCC ;

--
ARCHITECTURE UNTITLED OF GENCC IS
BEGIN
	VHDL_GENCC : PROCESS (RFMUXOUT)
	BEGIN    
		IF (RFMUXOUT = "0000000000000000") THEN
			GENCCOUT <= "010" AFTER DELAY_GENCC;
		ELSIF (RFMUXOUT(15) = '1') THEN
			GENCCOUT <= "100" AFTER DELAY_GENCC;
		ELSE
			GENCCOUT <= "001" AFTER DELAY_GENCC;
		END IF;
	END PROCESS VHDL_GENCC;
END UNTITLED;

