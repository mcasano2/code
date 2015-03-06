--
-- VHDL Architecture ece411.WB_CntrlStrip.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 02:45:53 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY WB_CntrlStrip IS
   PORT( 
      wb_controls_in  : IN      CONTROL_WORD;
      wb_regWrite     : OUT     std_logic;
 	    ByteMUXSel		    : out     std_logic;
 	    wb_regWrite_Out : OUT     std_logic;
		  RegDataMuxSel	  : out     LC3B_4MUXSEL;
		  wb_DRMUXSel_out : out     std_logic
   );

-- Declarations

END WB_CntrlStrip ;

--
ARCHITECTURE untitled OF WB_CntrlStrip IS
BEGIN
 	  ByteMUXSel <= wb_controls_in.wb.ByteMUXSel;
		RegDataMuxSel <= wb_controls_in.wb.RegDataMuxSel;
		wb_regWrite <= wb_controls_in.wb.Write;
		wb_regWrite_Out <= wb_controls_in.RegWrite;
		wb_DRMUXSel_out <= wb_controls_in.id.DRMUXSel;
END ARCHITECTURE untitled;

