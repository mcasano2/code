--
-- VHDL Architecture ece411.MEM_WB.untitled
--
-- Created:
--          by - baker30.ews (evrt-252-21.ews.illinois.edu)
--          at - 22:28:48 03/12/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY MEM_WB IS
   PORT( 
      CLK             : IN     STD_LOGIC;
      LOAD_MEMWB      : IN     STD_LOGIC;
      RESET_L         : IN     STD_LOGIC;
      mem_ALU_in      : IN     LC3B_WORD;
      mem_DATAIN_out  : IN     LC3B_WORD;
      mem_IR_in       : IN     LC3B_WORD;
      mem_PC_in       : IN     LC3B_WORD;
      mem_controls_in : IN     CONTROL_WORD;
      wb_ALU_in       : OUT    LC3B_WORD;
      wb_DATAIN_in    : OUT    LC3B_WORD;
      wb_IR_in        : OUT    LC3B_WORD;
      wb_controls_in  : OUT    CONTROL_WORD;
      mem_PCadj_in    : IN     LC3B_WORD;
      wb_PC_in        : OUT    LC3B_WORD;
      wb_PCadj_in     : OUT    LC3B_WORD;
      mem_DR_in       : IN     LC3B_REG
   );

-- Declarations

END MEM_WB ;

--
ARCHITECTURE untitled OF MEM_WB IS
SIGNAL IR_ff : LC3B_WORD;
SIGNAL PC_ff : LC3B_WORD;
SIGNAL PCadj_ff : LC3B_WORD;
SIGNAL ALU_ff : LC3B_WORD;
SIGNAL DATAIN_ff : LC3B_WORD;
SIGNAL controls_ff : CONTROL_WORD;
  
BEGIN
  PROCESS(mem_IR_in, mem_PC_in, mem_ALU_in, mem_PCadj_in, mem_DATAIN_out, mem_controls_in, clk, RESET_L)
  BEGIN
		IF RESET_L = '0' THEN
			IR_ff <= (OTHERS => '0');
			PC_ff <= (OTHERS => '0');
      PCadj_ff <= (OTHERS => '0');
      ALU_ff <= (OTHERS => '0');
      DATAIN_ff <= (OTHERS => '0');
		  controls_ff.fetch.PCMuxSel <= (OTHERS => '0');
	    controls_ff.id <= (OTHERS => '0');
		  controls_ff.ex.aluop  <= (OTHERS => '0');
		  controls_ff.ex.ALUMuxSel  <= (OTHERS => '0');
		  controls_ff.ex.LoadNZP  <= '0';
		  controls_ff.mem <= (OTHERS => '0');
		  controls_ff.wb.RegDataMuxSel <= (OTHERS => '0');
		  controls_ff.wb.ByteMUXSel <= '0';
		  controls_ff.wb.Write <= '0';       
		ELSIF CLK'EVENT AND CLK = '1' THEN
		  IF (LOAD_MEMWB = '1') THEN
		   IR_ff    <= mem_IR_in;
		   PC_ff    <= mem_PC_in;
		   ALU_ff   <= mem_ALU_in;
		   PCadj_ff <= mem_PCadj_in;
		   DATAIN_ff <= mem_DATAIN_out;
		   controls_ff <= mem_controls_in;
 
		   
			END IF;
		END IF;
	END PROCESS;
	
  wb_IR_in <= IR_ff AFTER DELAY_REG;
  wb_PC_in <= PC_ff AFTER DELAY_REG;
  wb_ALU_in <= ALU_ff AFTER DELAY_REG;
  wb_PCadj_in <= PCadj_ff AFTER DELAY_REG;
  wb_DATAIN_in <= DATAIN_ff AFTER DELAY_REG;
  wb_controls_in <= controls_ff  AFTER DELAY_REG;
	
END ARCHITECTURE untitled;

