--
-- VHDL Architecture ece411.IFCntrlStrip.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 00:16:29 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY IFCntrlStrip IS
   PORT( 
      CLK            : IN     STD_LOGIC;
      RESET_DELAYED  : IN     std_logic;
      ex_controls_in : IN     CONTROL_WORD;
      IROutMuxSel    : OUT    std_logic;
      IAddrMuxSel    : OUT    std_logic;
      Sel            : OUT    lc3b_4mux_sel
   );

-- Declarations

END IFCntrlStrip ;

--
ARCHITECTURE untitled OF IFCntrlStrip IS
BEGIN
  process(ex_controls_in, RESET_DELAYED)
    begin
    if(RESET_DELAYED = '1') then
      Sel <= ex_controls_in.fetch.pcmuxsel;
      IROutMuxSel <= ex_controls_in.fetch.IROutMuxSel;
      IAddrMuxSel <= ex_controls_in.fetch.IAddrMuxSel;
    else
      Sel <= "00";
      IROutMuxSel <= '0';
      IAddrMuxSel <= '0';
    end if;
  end process;
END ARCHITECTURE untitled;

