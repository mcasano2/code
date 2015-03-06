--
-- VHDL Architecture ece411.ID_EX.untitled
--
-- Created:
--          by - baker30.ews (evrt-252-21.ews.illinois.edu)
--          at - 22:28:29 03/12/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY ID_EX IS
   PORT( 
      CLK             : IN     STD_LOGIC;
      LOAD_IDEX       : IN     STD_LOGIC;
      RESET_L         : IN     STD_LOGIC;
      id_ADJ6_out     : IN     LC3B_WORD;
      id_IR_in        : IN     LC3B_WORD;
      id_PC_in        : IN     LC3B_WORD;
      id_PCadj_out    : IN     LC3B_WORD;
      id_REGa_out     : IN     LC3B_WORD;
      id_REGb_out     : IN     LC3B_WORD;
      id_SEXT5_out    : IN     LC3B_WORD;
      id_SEXT6_out    : IN     LC3B_WORD;
      id_ZEXT8_out    : IN     LC3B_WORD;
      id_controls_out : IN     CONTROL_WORD;
      ex_ADJ6_in      : OUT    LC3B_WORD;
      ex_IR_in        : OUT    LC3B_WORD;
      ex_PC_in        : OUT    LC3B_WORD;
      ex_PCadj_in     : OUT    LC3B_WORD;
      ex_REGa_in      : OUT    LC3B_WORD;
      ex_REGb_in      : OUT    LC3B_WORD;
      ex_SEXT5_in     : OUT    LC3B_WORD;
      ex_SEXT6_in     : OUT    LC3B_WORD;
      ex_ZEXT8_in     : OUT    LC3B_WORD;
      ex_controls_in  : OUT    CONTROL_WORD;
      id_DR_out       : IN     LC3B_REG;
      id_REGaNum_out  : IN     LC3B_REG;
      id_REGbNum_out  : IN     LC3B_REG;
      ex_REGaNum_in   : OUT    LC3B_REG;
      ex_REGbNum_in   : OUT    LC3B_REG;
      ex_DR_in        : OUT    LC3B_REG;
      RESET_IDEX_L    : IN     std_logic
   );

-- Declarations

END ID_EX ;

--
ARCHITECTURE untitled OF ID_EX IS
  
SIGNAL IR_ff : LC3B_WORD;
SIGNAL PC_ff : LC3B_WORD;
SIGNAL ADJ6_ff : LC3B_WORD;
SIGNAL PCadj_ff : LC3B_WORD;
SIGNAL REGa_ff : LC3B_WORD;
SIGNAL REGb_ff : LC3B_WORD;
SIGNAL SEXT5_ff : LC3B_WORD;
SIGNAL SEXT6_ff : LC3B_WORD;
SIGNAL ZEXT8_ff : LC3B_WORD;
SIGNAL controls_ff : CONTROL_WORD;
SIGNAL DR_ff : LC3B_REG;
SIGNAL REGaNum_ff : LC3B_REG;
SIGNAL REGbNum_ff : LC3B_REG;


BEGIN
  PROCESS(id_IR_in, id_PC_in, id_ADJ6_out, id_PCadj_out, id_REGa_out, id_REGb_out, id_SEXT5_out, id_SEXT6_out, id_ZEXT8_out, id_controls_out, clk, RESET_L, RESET_IDEX_L)
  BEGIN
		IF (RESET_L = '0') THEN
			IR_ff <= (OTHERS => '0');
			PC_ff <= (OTHERS => '0');
			ADJ6_ff <= (OTHERS => '0');
      PCadj_ff <= (OTHERS => '0');
      REGa_ff <= (OTHERS => '0');
      REGb_ff <= (OTHERS => '0');
      SEXT5_ff <= (OTHERS => '0');
      SEXT6_ff <= (OTHERS => '0');
      ZEXT8_ff <= (OTHERS => '0');
		  controls_ff.fetch.PCMuxSel <= (OTHERS => '0');
		  controls_ff.fetch.IAddrMuxSel <= '0';
		  controls_ff.fetch.IROutMuxSel <= '0';
	    controls_ff.id <= (OTHERS => '0');
		  controls_ff.ex.aluop  <= (OTHERS => '0');
		  controls_ff.ex.ALUMuxSel  <= (OTHERS => '0');
		  controls_ff.ex.LoadNZP  <= '0';
		  controls_ff.mem.DRead_L <= '1';
		  controls_ff.mem.LoadMAR <= '0';
		  controls_ff.mem.DWriteL_L <= '1';
		  controls_ff.mem.DWriteH_L <= '1';
		  controls_ff.wb.RegDataMuxSel <= (OTHERS => '0');
		  controls_ff.wb.ByteMUXSel <= '0';
		  controls_ff.wb.Write <= '0';  
		  REGaNum_ff <= (OTHERS => 'X');
		  REGbNum_ff <= (OTHERS => 'X');
  		  DR_ff <= (OTHERS => 'X');
	        
      
		ELSIF CLK'EVENT AND CLK = '1' THEN
		  IF (LOAD_IDEX = '1') THEN
			 IR_ff <= id_IR_in;
			 PC_ff <= id_PC_in;
			 ADJ6_ff <= id_ADJ6_out;
       PCadj_ff <= id_PCadj_out;
       REGa_ff <= id_REGa_out;
       REGb_ff <= id_REGb_out;
       SEXT5_ff <= id_SEXT5_out;
       SEXT6_ff <= id_SEXT6_out;
       ZEXT8_ff <= id_ZEXT8_out;
       controls_ff <= id_controls_out;
       REGaNum_ff <= id_REGaNum_out;
		   REGbNum_ff <= id_REGbNum_out;
		   DR_ff <= id_DR_out;
		   
			END IF;
			
		  IF (RESET_IDEX_L = '0') THEN
			IR_ff <= (OTHERS => '0');
			PC_ff <= (OTHERS => '0');
			ADJ6_ff <= (OTHERS => '0');
      PCadj_ff <= (OTHERS => '0');
      REGa_ff <= (OTHERS => '0');
      REGb_ff <= (OTHERS => '0');
      SEXT5_ff <= (OTHERS => '0');
      SEXT6_ff <= (OTHERS => '0');
      ZEXT8_ff <= (OTHERS => '0');
		  controls_ff.fetch.PCMuxSel <= (OTHERS => '0');
	    controls_ff.id <= (OTHERS => '0');
		  controls_ff.ex.aluop  <= (OTHERS => '0');
		  controls_ff.ex.ALUMuxSel  <= (OTHERS => '0');
		  controls_ff.ex.LoadNZP  <= '0';
		  controls_ff.mem.DRead_L <= '1';
		  controls_ff.mem.LoadMAR <= '0';
		  controls_ff.mem.DWriteL_L <= '1';
		  controls_ff.mem.DWriteH_L <= '1';
		  controls_ff.wb.RegDataMuxSel <= (OTHERS => '0');
		  controls_ff.wb.ByteMUXSel <= '0';
		  controls_ff.wb.Write <= '0';  
		  REGaNum_ff <= (OTHERS => 'X');
		  REGbNum_ff <= (OTHERS => 'X');
  		  DR_ff <= (OTHERS => 'X');
		  END IF;
		END IF;
	END PROCESS;
	
	ex_IR_in     <= IR_ff AFTER DELAY_REG;
	ex_PC_in     <= PC_ff AFTER DELAY_REG;	
  ex_ADJ6_in   <= ADJ6_ff AFTER DELAY_REG;
  ex_PCadj_in  <= PCadj_ff AFTER DELAY_REG;
  ex_REGa_in   <= REGa_ff AFTER DELAY_REG;
  ex_REGb_in   <= REGb_ff AFTER DELAY_REG;
  ex_SEXT5_in  <= SEXT5_ff AFTER DELAY_REG;
  ex_SEXT6_in  <= SEXT6_ff AFTER DELAY_REG;
  ex_ZEXT8_in  <= ZEXT8_ff AFTER DELAY_REG;
  ex_controls_in <= controls_ff AFTER DELAY_REG;
  ex_DR_in      <= DR_ff AFTER DELAY_REG;
  ex_REGaNum_in <= REGaNum_ff AFTER DELAY_REG;
  ex_REGbNum_in <= REGbNum_ff AFTER DELAY_REG;

	
END ARCHITECTURE untitled;

