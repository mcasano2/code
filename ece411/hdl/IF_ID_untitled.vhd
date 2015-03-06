--
-- VHDL Architecture ece411.IF_ID.untitled
--
-- Created:
--          by - baker30.ews (evrt-252-21.ews.illinois.edu)
--          at - 22:27:58 03/12/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY IF_ID IS
   PORT( 
      CLK       : IN     STD_LOGIC;
      RESET_L   : IN     STD_LOGIC;
      if_IR_out : IN     LC3B_WORD;
      if_PC_out : IN     LC3B_WORD;
      id_IR_in  : OUT    LC3B_WORD;
      id_PC_in  : OUT    LC3B_WORD;
      LOAD_IFID : IN     STD_LOGIC
   );

-- Declarations

END IF_ID ;

--
ARCHITECTURE untitled OF IF_ID IS
SIGNAL IR_ff : LC3B_WORD;
SIGNAL PC_ff : LC3B_WORD;
BEGIN
  PROCESS(if_IR_out, if_PC_out, clk, RESET_L)
  BEGIN
		IF RESET_L = '0' THEN
			IR_ff <= (OTHERS => '0');
			PC_ff <= (OTHERS => '0');
		ELSIF CLK'EVENT AND CLK = '1' THEN
		  IF (LOAD_IFID = '1') THEN
			 IR_ff <= if_IR_out;
			 PC_ff <= if_PC_out;
			END IF;
		END IF;
	END PROCESS;
	id_IR_in <= IR_ff AFTER DELAY_REG;
	id_PC_in <= PC_ff AFTER DELAY_REG;
END ARCHITECTURE untitled;

