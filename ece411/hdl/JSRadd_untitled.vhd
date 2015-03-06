--
-- VHDL Architecture ece411.JSRadd.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-11.ews.illinois.edu)
--          at - 18:56:03 02/05/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY JSRadd IS
   PORT( 
      SEXT11out : IN     LC3b_word;
      PCout    : IN     LC3b_word;
      clk       : IN     std_logic;
      JSRaddout : OUT    LC3b_word
   );

-- Declarations

END JSRadd ;

--
ARCHITECTURE untitled OF JSRadd IS
BEGIN
    JSRaddout <= std_logic_vector( unsigned(SEXT11out) + unsigned(PCout) ) AFTER DELAY_MUX2;
END ARCHITECTURE untitled;

