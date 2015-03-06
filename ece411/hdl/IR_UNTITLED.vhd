--
-- VHDL Architecture ece411.IR.UNTITLED
--
-- Created:
--          by - baker30.ews (siebl-0220-06.ews.illinois.edu)
--          at - 03:35:41 01/22/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY IR IS
   PORT( 
      LoadIR    : IN     std_logic;
      clk       : IN     std_logic;
      Opcode    : OUT    LC3b_opcode;
      SrcA      : OUT    LC3b_reg;
      SrcB      : OUT    LC3b_reg;
      index6    : OUT    LC3b_index6;
      offset9   : OUT    LC3b_offset9;
      offset11  : OUT    LC3b_offset11;
      IRout     : OUT    LC3b_word;
      imm5in    : OUT    LC3b_imm5;
      dest      : OUT    LC3b_reg;
      TRAPVect8 : OUT    LC3b_TRAPVECT8;
      MDRout    : IN     LC3b_word
   );

-- Declarations

END IR ;

--
ARCHITECTURE UNTITLED OF IR IS
SIGNAL VAL_IR : LC3B_WORD;
BEGIN
	------------------------------
	VHDL_REG_IR : PROCESS (CLK, LoadIR, MDRout)
	------------------------------
	BEGIN
		IF (CLK'EVENT AND (CLK = '1') AND (CLK'LAST_VALUE = '0')) THEN
			IF (LOADIR = '1') THEN
				VAL_IR <= MDRout AFTER DELAY_REG;
			END IF;
		END IF;
	END PROCESS VHDL_REG_IR;
	Opcode <= VAL_IR(15 DOWNTO 12);
	SrcA <= VAL_IR(8 DOWNTO 6);
	SrcB <= VAL_IR(2 DOWNTO 0);
	dest <= VAL_IR(11 DOWNTO 9);
	offset9 <= VAL_IR(8 DOWNTO 0);
	offset11 <= VAL_IR(10 DOWNTO 0);
	Index6 <= VAL_IR(5 DOWNTO 0);
	imm5in <= VAL_IR(4 DOWNTO 0);
	IRout <= VAL_IR(15 DOWNTO 0);
	TRAPVect8 <= VAL_IR(7 DOWNTO 0);
END UNTITLED;

