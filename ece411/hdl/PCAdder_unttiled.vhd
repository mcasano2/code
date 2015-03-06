--
-- VHDL Architecture ece411.PCAdder.unttiled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 01:11:42 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY PCAdder IS
   PORT( 
      PCADDMuxOUT : IN     LC3b_word;
      id_PC_in    : IN     LC3B_WORD;
      PCPlus      : OUT    LC3b_word
   );

-- Declarations

END PCAdder ;

--
ARCHITECTURE unttiled OF PCAdder IS
BEGIN
  PCPlus <= std_logic_vector( unsigned(PCADDMuxOUT) + unsigned(id_PC_in) ) AFTER DELAY_MUX2;
END ARCHITECTURE unttiled;

