--
-- VHDL Architecture ece411.ByteCompar.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-21.ews.illinois.edu)
--          at - 01:52:59 02/14/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY ByteCompar IS
   PORT( 
      A : IN     lc3b_C_TAG;
      B : IN     lc3b_C_TAG;
      F : OUT    std_logic
   );

-- Declarations

END ByteCompar ;

--
ARCHITECTURE untitled OF ByteCompar IS
BEGIN
  F <= '1' when (A=B) else '0' after DELAY_COMPARE16;
END ARCHITECTURE untitled;

