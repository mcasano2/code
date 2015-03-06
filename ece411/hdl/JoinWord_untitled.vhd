--
-- VHDL Architecture ece411.JoinWord.untitled
--
-- Created:
--          by - baker30.ews (linux5.ews.illinois.edu)
--          at - 23:29:11 02/21/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY JoinWord IS
   PORT( 
      ADDRESS   : IN     LC3b_word;
      PMADDRESS : OUT    LC3B_WORD
   );

-- Declarations

END JoinWord ;

--
ARCHITECTURE untitled OF JoinWord IS
BEGIN
  PMADDRESS <= ADDRESS;
END ARCHITECTURE untitled;

