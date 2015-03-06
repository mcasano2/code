--
-- VHDL Architecture ece411.D_Latch.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 00:20:44 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY D_Latch IS
   PORT( 
      Data_In  : IN     lc3b_word;
      Enable   : IN     std_logic;
      data_out : OUT    lc3b_word
   );

-- Declarations

END D_Latch ;

--
ARCHITECTURE untitled OF D_Latch IS
BEGIN
    process(data_in, enable)
    begin
        if (enable='1') then
	    	  data_out <= data_in;  
		    end if;
    end process;
END ARCHITECTURE untitled;

