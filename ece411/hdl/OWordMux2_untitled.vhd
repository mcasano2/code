--
-- VHDL Architecture ece411.OWordMux2.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-21.ews.illinois.edu)
--          at - 02:10:16 02/14/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY OWordMux2 IS
   PORT( 
      A   : IN     LC3b_oword;
      B   : IN     LC3b_oword;
      Sel : IN     std_logic;
      F   : OUT    LC3b_oword
   );

-- Declarations

END OWordMux2 ;

--
ARCHITECTURE untitled OF OWordMux2 IS
BEGIN
  PROCESS (A, B, Sel)
    variable state : LC3b_oword;
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
