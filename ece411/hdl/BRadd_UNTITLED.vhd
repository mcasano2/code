--
-- VHDL Architecture ece411.BRadd.UNTITLED
--
-- Created:
--          by - baker30.ews (siebl-0220-06.ews.illinois.edu)
--          at - 04:14:58 01/22/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY BRadd IS
   PORT( 
      PCAddrout : IN     LC3b_word;
      PCout     : IN     LC3b_word;
      clk       : IN     std_logic;
      BRaddout  : OUT    LC3b_word
   );

-- Declarations

END BRadd ;

--
ARCHITECTURE UNTITLED OF BRadd IS
BEGIN
  BRaddout <= std_logic_vector( unsigned(PCAddrout) + unsigned(PCout) ) AFTER DELAY_MUX2;
END ARCHITECTURE UNTITLED;

