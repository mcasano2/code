--
-- VHDL Architecture ece411.NOT2.untitled
--
-- Created:
--          by - baker30.ews (linux6.ews.illinois.edu)
--          at - 20:45:29 02/21/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
ENTITY NOT2 IS
   PORT (
      A : IN     std_logic;
      F : OUT    std_logic
   );
END NOT2;

--
ARCHITECTURE untitled OF NOT2 IS
BEGIN
  F<= Not A after DELAY_LOGIC2;
END ARCHITECTURE untitled;

