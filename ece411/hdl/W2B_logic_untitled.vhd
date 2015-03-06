--
-- VHDL Architecture ece411.W2B_logic.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-20.ews.illinois.edu)
--          at - 19:31:06 02/24/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY W2B_logic IS
   PORT( 
      Offset0  : IN     std_logic;
      NewByteH : OUT    LC3B_Byte;
      NewByteL : OUT    LC3B_BYTE;
      DATAOUT  : IN     LC3b_word
   );

-- Declarations

END W2B_logic ;

--
ARCHITECTURE untitled OF W2B_logic IS
BEGIN
  PROCESS (DATAOUT, Offset0)
    variable state : LC3b_byte;
  BEGIN
    case Offset0 is
    when '0' =>
      state := DATAOUT(15 DOWNTO 8);
    when '1' =>
      state := DATAOUT(7 DOWNTO 0);
    when others =>
      state := (OTHERS => 'X');
    end case;
    
    NewByteH <= state after DELAY_MUX2;
    NewByteL <= DATAOUT(7 DOWNTO 0);
  END PROCESS;
END ARCHITECTURE untitled;

