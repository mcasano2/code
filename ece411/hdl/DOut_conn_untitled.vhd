--
-- VHDL Architecture ece411.DOut_conn.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 02:37:46 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY DOut_conn IS
   PORT( 
      mem_ALU_in : IN     LC3B_WORD;
      D_DATAOUT  : OUT    LC3B_WORD
   );

-- Declarations

END DOut_conn ;

--
ARCHITECTURE untitled OF DOut_conn IS
BEGIN
  D_DataOUT <= mem_alu_in;
END ARCHITECTURE untitled;

