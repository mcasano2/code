--
-- VHDL Architecture ece411.ADDRSplit.untitled
--
-- Created:
--          by - baker30.ews (evrt-252-34.ews.illinois.edu)
--          at - 22:46:25 02/14/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY ADDRSplit IS
   PORT( 
      ADDRESS : IN     LC3b_word;
      Tag     : OUT    LC3B_C_TAG;
      INDEX   : OUT    LC3B_C_INDEX;
      Offset  : OUT    LC3B_C_OFFSET;
      Offset3 : OUT    LC3B_8MUX_SEL;
      Offset0 : OUT    std_logic
   );

-- Declarations

END ADDRSplit ;

--
ARCHITECTURE untitled OF ADDRSplit IS
BEGIN
  Tag <= ADDRESS(15 DOWNTO 7);
  INDEX <= ADDRESS(6 DOWNTO 4);
  Offset <= ADDRESS(3 DOWNTO 0);
  Offset3 <= ADDRESS (3 DOWNTO 1 );
  Offset0 <= ADDRESS (0);
  
END ARCHITECTURE untitled;

