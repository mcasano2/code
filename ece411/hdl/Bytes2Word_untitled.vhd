--
-- VHDL Architecture ece411.Bytes2Word.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-20.ews.illinois.edu)
--          at - 18:52:05 02/24/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY Bytes2Word IS
   PORT( 
      ByteLow     : IN     LC3B_BYTE;
      ByteHigh    : IN     LC3B_BYTE;
      OutWord     : OUT    LC3B_WORD
   );

-- Declarations

END Bytes2Word ;

--
ARCHITECTURE untitled OF Bytes2Word IS
BEGIN
  OutWord <= ByteHigh & ByteLow; -- combine bytes to make a word
END ARCHITECTURE untitled;

