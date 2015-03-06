--
-- VHDL Architecture ece411.NZP_Check.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 02:13:39 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY NZP_Check IS
   PORT( 
      ex_DR_in   : IN     LC3B_REG;
      mem_NZP_in : IN     LC3B_CC;
      NZP_eval   : OUT    STD_LOGIC
   );

-- Declarations

END NZP_Check ;

--
ARCHITECTURE untitled OF NZP_Check IS
BEGIN
  NZP_eval <= ((ex_dr_in(0) and mem_nzp_in(0)) or (ex_dr_in(1) and mem_nzp_in(1)) or (ex_dr_in(2) and mem_nzp_in(2))) AFTER DELAY_COMPARE8;    
END ARCHITECTURE untitled;

