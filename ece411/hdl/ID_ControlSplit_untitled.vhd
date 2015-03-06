--
-- VHDL Architecture ece411.ID_ControlSplit.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 03:19:51 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY ID_ControlSplit IS
   PORT( 
      id_controls_out : IN     CONTROL_WORD;
      PCAddMUXSel     : OUT    std_logic;
      IDPCMUXSel      : OUT    std_logic;
      DRMUXSel        : OUT    std_logic;
      SRAMUXSel       : OUT    std_logic;
      SRBMuxSel       : OUT    std_logic
   );

-- Declarations

END ID_ControlSplit ;

--
ARCHITECTURE untitled OF ID_ControlSplit IS
BEGIN
      PCAddMUXSel     <= id_controls_out.id.PCAddMUXSel;
      IDPCMUXSel      <= id_controls_out.id.IDPCMUXSel;
      DRMUXSel        <= id_controls_out.id.DRMUXSel;
      SRAMUXSel       <= id_controls_out.id.SRAMUXSel;
      SRbMUXSel       <= id_controls_out.id.SRbMUXSel;
END ARCHITECTURE untitled;

