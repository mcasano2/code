--
-- VHDL Architecture ece411.Forwarding_Unit.untitled
--
-- Created:
--          by - mcasano2.ews (gelib-057-03.ews.illinois.edu)
--          at - 00:50:36 04/05/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY Forwarding_Unit IS
   PORT( 
      CLK              : IN     STD_LOGIC;
      ex_REGaNum_in    : IN     LC3B_REG;
      ex_REGbNum_in    : IN     LC3B_REG;
      mem_DR_in        : IN     LC3B_REG;
      mem_RegWrite_out : IN     STD_LOGIC;
      wb_DR            : IN     LC3B_REG;
      wb_regWrite_Out  : IN     std_logic;
      ForwardAMuxSel   : OUT    LC3B_4MUX_SEL;
      ForwardBMuxSel   : OUT    LC3B_4MUX_SEL
   );

-- Declarations

END Forwarding_Unit ;

--
ARCHITECTURE untitled OF Forwarding_Unit IS
  
  SIGNAL ForwardA_sig : LC3B_4MUX_SEL;
  SIGNAL ForwardB_sig : LC3B_4MUX_SEL;
  
BEGIN
  PROCESS(ex_REGaNum_in, ex_REGbNum_in, mem_DR_in, mem_RegWrite_out, wb_DR, wb_regWrite_Out)
  BEGIN
    ForwardA_sig <= "00";
    ForwardB_sig <= "00";
    
    IF((mem_RegWrite_out = '1') AND (ex_REGaNum_in = mem_DR_in) ) THEN
      ForwardA_sig <= "10";
    END IF;
    IF((mem_RegWrite_out = '1') AND (ex_REGbNum_in = mem_DR_in) ) THEN
      ForwardB_sig <= "10";
    END IF;
      
    IF(((wb_regWrite_Out = '1') AND (ex_REGaNum_in = wb_DR) AND 
      NOT ((mem_RegWrite_out = '1') AND (ex_REGaNum_in = mem_DR_in)))) THEN
        ForwardA_sig <= "01";
    END IF;
    IF(((wb_regWrite_Out = '1') AND (ex_REGbNum_in = wb_DR) AND 
      NOT ((mem_RegWrite_out = '1') AND (ex_REGbNum_in = mem_DR_in)))) THEN
        Forwardb_sig <= "01";
    END IF;
  
  END PROCESS;
  
  ForwardAMuxSel <= Forwarda_sig;
  ForwardBMuxSel <= Forwardb_sig;
         
END ARCHITECTURE untitled;

