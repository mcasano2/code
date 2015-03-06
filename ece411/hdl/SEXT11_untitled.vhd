--
-- VHDL Architecture ece411.SEXT11.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-11.ews.illinois.edu)
--          at - 18:48:27 02/05/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY SEXT11 IS
   PORT( 
      offset11  : IN     LC3b_offset11;
      SEXT11out : OUT    LC3b_word
   );

-- Declarations

END SEXT11 ;

--
ARCHITECTURE untitled OF SEXT11 IS
BEGIN
  SEXT11out <= offset11(10) & offset11(10) & offset11(10) & offset11(10) & offset11 & '0' AFTER DELAY_MUX2;
END ARCHITECTURE untitled;

