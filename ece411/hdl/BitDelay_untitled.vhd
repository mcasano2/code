--
-- VHDL Architecture ece411.BitDelay.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-18.ews.illinois.edu)
--          at - 01:58:48 02/28/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY BitDelay IS
   PORT( 
      inBit : IN     std_logic;
      outBit : OUT    std_logic
   );

-- Declarations

END BitDelay ;

--
ARCHITECTURE untitled OF BitDelay IS
BEGIN
  outBit <= inBit after 30ns;
END ARCHITECTURE untitled;

