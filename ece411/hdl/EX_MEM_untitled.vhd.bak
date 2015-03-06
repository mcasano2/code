--
-- VHDL Architecture ece411.EX_MEM.untitled
--
-- Created:
--          by - baker30.ews (evrt-252-21.ews.illinois.edu)
--          at - 22:28:38 03/12/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY EX_MEM IS
   PORT( 
      CLK             : IN     STD_LOGIC;
      LOAD_EXMEM      : IN     STD_LOGIC;
      RESET_L         : IN     STD_LOGIC;
      ex_ALU_out      : IN     LC3B_WORD;
      ex_IR_in        : IN     LC3B_WORD;
      ex_PC_in        : IN     LC3B_WORD;
      ex_PCadj_in     : IN     LC3B_WORD;
      ex_ZEXT8_in     : IN     LC3B_WORD;
      ex_controls_in  : IN     CONTROL_WORD;
      mem_ALU_in      : OUT    LC3B_WORD;
      mem_IR_in       : OUT    LC3B_WORD;
      mem_PC_in       : OUT    LC3B_WORD;
      mem_ZEXT8_in    : OUT    LC3B_WORD;
      mem_controls_in : OUT    CONTROL_WORD;
      mem_PCadj_in    : OUT    LC3B_WORD;
      ex_nzp_out      : IN     LC3B_CC;
      mem_NZP_in      : OUT    LC3B_CC;
      mem_REGb_in     : OUT    LC3B_WORD;
      ex_DR_in        : IN     LC3B_REG;
      mem_DR_in       : OUT    LC3B_REG;
      ex_regb_out     : IN     LC3b_word
   );

-- Declarations

END EX_MEM ;

--
ARCHITECTURE untitled OF EX_MEM IS

SIGNAL IR_ff : LC3B_WORD;
SIGNAL PC_ff : LC3B_WORD;
SIGNAL PCadj_ff : LC3B_WORD;
SIGNAL ALU_ff : LC3B_WORD;
SIGNAL ZEXT8_ff : LC3B_WORD;
SIGNAL controls_ff : CONTROL_WORD;
SIGNAL nzp_ff : LC3B_CC;
SIGNAL regb_ff : lc3b_word;
SIGNAL DR_ff : lc3b_reg;
  
BEGIN
  PROCESS(ex_IR_in, ex_PC_in, ex_ALU_out, ex_PCadj_in, ex_ZEXT8_in, ex_controls_in, ex_nzp_out, clk, RESET_L)
  BEGIN
		IF (RESET_L = '0') THEN
			IR_ff <= (OTHERS => '0');
			PC_ff <= (OTHERS => '0');
      PCadj_ff <= (OTHERS => '0');
      ALU_ff <= (OTHERS => '0');
      ZEXT8_ff <= (OTHERS => '0');
		  controls_ff.fetch.PCMuxSel <= (OTHERS => '0');
	    controls_ff.id <= (OTHERS => '0');
		  controls_ff.ex.aluop  <= (OTHERS => '0');
		  controls_ff.ex.ALUMuxSel  <= (OTHERS => '0');
		  controls_ff.ex.LoadNZP  <= '0';
		  controls_ff.mem <= (OTHERS => '0');
		  controls_ff.wb.RegDataMuxSel <= (OTHERS => '0');
		  controls_ff.wb.ByteMUXSel <= '0';
		  controls_ff.wb.Write <= '0';    
      nzp_ff <= (OTHERS => '0');
      regb_ff <= (OTHERS => '0');
      DR_ff <= (OTHERS => 'X');
      
		ELSIF CLK'EVENT AND CLK = '1' THEN
		  IF (LOAD_EXMEM = '1') THEN
		   IR_ff    <= ex_IR_in;
		   PC_ff    <= ex_PC_in;
		   ALU_ff   <= ex_ALU_out;
		   PCadj_ff <= ex_PCadj_in;
		   ZEXT8_ff <= ex_ZEXT8_in;
		   controls_ff <= ex_controls_in;
		   nzp_ff <= ex_nzp_out;
		   regb_ff <= ex_REGb_out;
		   DR_ff <= ex_DR_in;
		   
			END IF;
		END IF;
	END PROCESS;
	
  mem_IR_in <= IR_ff AFTER DELAY_REG;
  mem_PC_in <= PC_ff AFTER DELAY_REG;
  mem_ALU_in <= ALU_ff AFTER DELAY_REG;
  mem_PCadj_in <= PCadj_ff AFTER DELAY_REG;
  mem_ZEXT8_in <= ZEXT8_ff AFTER DELAY_REG;
  mem_controls_in <= controls_ff  AFTER DELAY_REG;
  mem_nzp_in <= nzp_ff AFTER DELAY_REG;
  mem_REGb_in <= regb_ff AFTER DELAY_REG;
  mem_DR_in  <= DR_ff AFTER DELAY_REG;
	
END untitled;
