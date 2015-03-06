--
-- VHDL Architecture ece411.IR_SPlit.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 00:35:59 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY IR_SPlit IS
   PORT( 
      id_IR_in : IN     LC3B_WORD;
      DR       : OUT    lc3b_reg;
      OpCode   : OUT    lc3b_opcode;
      SR1_BR   : OUT    lc3b_reg;
      SR2      : OUT    lc3b_reg;
      imm5     : OUT    lc3b_imm5;
      off11    : OUT    lc3b_offset11;
      off6     : OUT    lc3b_offset6;
      off9     : OUT    lc3b_offset9;
      trap8    : OUT    lc3b_trapvect8
   );

-- Declarations

END IR_SPlit ;

--
ARCHITECTURE untitled OF IR_SPlit IS
BEGIN
 	Opcode <= id_IR_in(15 DOWNTO 12);
	SR1_BR <= id_IR_in(8 DOWNTO 6);
	SR2 <= id_IR_in(2 DOWNTO 0);
	DR <= id_IR_in(11 DOWNTO 9);
	off9 <= id_IR_in(8 DOWNTO 0);
	off11 <= id_IR_in(10 DOWNTO 0);
	off6 <= id_IR_in(5 DOWNTO 0);
	imm5 <= id_IR_in(4 DOWNTO 0);
	trap8 <= id_IR_in(7 DOWNTO 0);
END ARCHITECTURE untitled;

