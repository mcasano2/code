--
-- VHDL Architecture ece411.TagMux2.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-18.ews.illinois.edu)
--          at - 01:25:04 02/28/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY TagMux2 IS
   PORT( 
      A   : IN     LC3B_C_TAG;
      B   : IN     LC3B_C_TAG;
      Sel : IN     std_logic;
      F   : OUT    LC3B_C_TAG
   );

-- Declarations

END TagMux2 ;

--
ARCHITECTURE untitled OF TagMux2 IS
BEGIN
  PROCESS (A, B, Sel)
    variable state : LC3b_C_TAG;
  BEGIN
    case Sel is
      when '0' =>
        state := A;
      when '1' =>
        state := B;
      when others =>
        state := (OTHERS => 'X');
    end case;
    F <= state after delay_MUX2;
  END PROCESS;
END ARCHITECTURE untitled;

