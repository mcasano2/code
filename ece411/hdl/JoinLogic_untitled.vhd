--
-- VHDL Architecture ece411.JoinLogic.untitled
--
-- Created:
--          by - baker30.ews (linux5.ews.illinois.edu)
--          at - 23:33:25 02/21/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY JoinLogic IS
   PORT( 
      hit     : IN     std_logic;
      MRESP_H : OUT    std_logic
   );

-- Declarations

END JoinLogic ;

--
ARCHITECTURE untitled OF JoinLogic IS
BEGIN
  MRESP_H <= HIT;
END ARCHITECTURE untitled;

