--
-- VHDL Architecture ece411.IMM5.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-33.ews.illinois.edu)
--          at - 23:53:09 01/29/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY SIMM5 IS
   PORT( 
      imm5in  : IN     LC3b_imm5;
      IMM5out : OUT    LC3b_word
   );

-- Declarations

END SIMM5 ;

--
ARCHITECTURE untitled OF SIMM5 IS
BEGIN
  	IMM5out <= IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in(4) & IMM5in AFTER DELAY_MUX2;
END ARCHITECTURE untitled;

