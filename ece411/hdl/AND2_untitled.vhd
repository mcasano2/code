--
-- VHDL Architecture ece411.AND2.untitled
--
-- Created:
--          by - baker30.ews (evrt-252-34.ews.illinois.edu)
--          at - 22:25:51 02/14/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY AND2 IS
   PORT( 
      A : IN     std_logic;
      B : IN     std_logic;
      F : OUT    std_logic
   );

-- Declarations

END AND2 ;

--
ARCHITECTURE untitled OF AND2 IS
BEGIN
  F <= (A AND B) AFTER DELAY_LOGIC2;
END ARCHITECTURE untitled;

