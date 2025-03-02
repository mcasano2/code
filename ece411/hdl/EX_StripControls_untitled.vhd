--
-- VHDL Architecture ece411.EX_StripControls.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 03:16:00 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY EX_StripControls IS
   PORT( 
      ex_controls_in : IN     CONTROL_WORD;
      aluop          : OUT    LC3B_ALUOP;
      ALUMUXSel      : OUT    LC3B_4MUXSEL;
      LoadNZP        : OUT    std_logic;
      GenCCMuxSel    : OUT    std_logic;
      ex_MemRead_out       : OUT    std_logic
   );

-- Declarations

END EX_StripControls ;

--
ARCHITECTURE untitled OF EX_StripControls IS
BEGIN
 	  aluop 		<= ex_controls_in.ex.aluop;
		ALUMUXSel	<= ex_controls_in.ex.ALUMUXSel;
		LoadNZP		<= ex_controls_in.ex.LoadNZP;
		ex_MemRead_out <= ex_controls_in.mem.DRead_L;
		GenCCMuxSel <= ex_controls_in.ex.GenCCMuxSel;
END ARCHITECTURE untitled;

