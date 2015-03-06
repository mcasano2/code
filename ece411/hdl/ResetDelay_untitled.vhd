--
-- VHDL Architecture ece411.ResetDelay.untitled
--
-- Created:
--          by - baker30.ews (dcl-l440-22.ews.illinois.edu)
--          at - 19:30:28 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY ResetDelay IS
   PORT( 
      CLK           : IN     STD_LOGIC;
      RESET_L       : IN     STD_LOGIC;
      RESET_DELAYED : OUT    std_logic
   );

-- Declarations

END ResetDelay ;

--
ARCHITECTURE untitled OF ResetDelay IS
BEGIN
  RESET_DELAYED <= RESET_L AFTER HALF_CLOCK_PERIOD;
END ARCHITECTURE untitled;

