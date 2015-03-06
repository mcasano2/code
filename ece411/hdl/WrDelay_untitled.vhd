--
-- VHDL Architecture ece411.WrDelay.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-04.ews.illinois.edu)
--          at - 01:03:12 03/14/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY WrDelay IS
   PORT( 
      CLK         : IN     STD_LOGIC;
      wb_regWrite : IN     std_logic;
      B           : OUT    std_logic
   );

-- Declarations

END WrDelay ;

--
ARCHITECTURE untitled OF WrDelay IS
BEGIN
  	PROCESS (CLK, B, wb_regWrite)
  	begin
  IF (CLK'EVENT AND CLK = '1') THEN
    B<='0';
  Else
    B <= wb_regWrite after 10 ns;
  End if;
  end process;
END ARCHITECTURE untitled;

