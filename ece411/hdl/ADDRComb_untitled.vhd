--
-- VHDL Architecture ece411.ADDRComb.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-18.ews.illinois.edu)
--          at - 01:18:21 02/28/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY ADDRComb IS
   PORT( 
      INDEX     : IN     LC3B_C_INDEX;
      TagOld    : IN     LC3B_C_TAG;
      BuiltADDR : OUT    LC3B_WORD
   );

-- Declarations

END ADDRComb ;

--
ARCHITECTURE untitled OF ADDRComb IS
BEGIN
  BuiltADDR <= TagOld & INDEX & "0000";
END ARCHITECTURE untitled;

