--
-- VHDL Architecture ece411.convertWord.untitled
--
-- Created:
--          by - baker30.ews (dcl-l440-22.ews.illinois.edu)
--          at - 18:07:24 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY convertWord IS
   PORT( 
      A   : IN     LC3B_WORD;
      F   : OUT    lc3b_word
   );

-- Declarations

END convertWord ;

--
ARCHITECTURE untitled OF convertWord IS
BEGIN
  F <= A;
END ARCHITECTURE untitled;

