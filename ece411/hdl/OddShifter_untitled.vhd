--
-- VHDL Architecture ece411.OddShifter.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-17.ews.illinois.edu)
--          at - 19:12:48 03/02/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY OddShifter IS
   PORT( 
      DATAINe : IN     LC3b_word;
      Offset0    : IN     std_logic;
      DATAIN  : OUT    LC3b_word
   );

-- Declarations

END OddShifter ;

--
ARCHITECTURE untitled OF OddShifter IS
BEGIN
  PROCESS (DATAINe, DATAIN, Offset0)
    variable state : LC3b_word;
  BEGIN
    case Offset0 is
      when '0' =>
        state := DATAINe;
      when '1' =>
        state := x"00" & DATAINe( 15 DOWNTO 8);
      when others =>
        state := (OTHERS => 'X');
    end case;
    DATAIN <= state after delay_MUX2;
  END PROCESS;
END ARCHITECTURE untitled;

