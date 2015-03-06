--
-- VHDL Architecture ece411.mem_resp_gen.untitled
--
-- Created:
--          by - mcasano2.ews (gelib-057-26.ews.illinois.edu)
--          at - 03:03:50 04/11/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY mem_resp_gen IS
   PORT( 
      CLK       : IN     STD_LOGIC;
      d_mresp_h : IN     STD_LOGIC;
      ldi       : IN     STD_LOGIC;
      state     : IN     STD_LOGIC;
      sti       : IN     STD_LOGIC;
      mem_mresp : OUT    std_logic
   );

-- Declarations

END mem_resp_gen ;

--
ARCHITECTURE untitled OF mem_resp_gen IS
BEGIN
  process(d_mresp_h, ldi, sti, state)
  begin
  if(((ldi = '1')OR(sti = '1'))AND (state = '0')) then
    mem_mresp <= '0';
  else
    mem_mresp <= d_mresp_h;
  end if;
  end process;
END ARCHITECTURE untitled;

