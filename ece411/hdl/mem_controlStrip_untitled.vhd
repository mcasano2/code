--
-- VHDL Architecture ece411.mem_controlStrip.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-15.ews.illinois.edu)
--          at - 02:29:27 03/13/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY mem_controlStrip IS
   PORT( 
      mem_controls_in  : IN     CONTROL_WORD;
      RESET_L          : IN     std_logic;
      CLK              : IN     std_logic;
      MARMUXSel        : OUT    std_logic;
      LoadMAR          : OUT    std_logic;
      D_MWRITEH_L      : OUT    STD_LOGIC;
      D_MWRITEL_L      : OUT    STD_LOGIC;
      d_MREAD_L        : OUT    STD_LOGIC;
      ldi              : OUT    STD_LOGIC;
      sti              : OUT    STD_LOGIC;
      mem_RegWrite_out : OUT    STD_LOGIC
   );

-- Declarations

END mem_controlStrip ;

--
ARCHITECTURE untitled OF mem_controlStrip IS
BEGIN
  	PROCESS (CLK, mem_controls_in, RESET_L)
  	begin
 	IF RESET_L = '0' then
 	    MARMUXSel	<= '0';
	 	  LoadMAR		<= '0';
		  d_MREAD_L		<= '1';
		  D_MWriteL_L	<= '1';
		  D_MWriteH_L	<= '1'; 	  
  ELSIF (CLK'EVENT AND CLK = '1') THEN
 	    --MARMUXSel	<= '0';
	 	  --LoadMAR		<= '0';
		  --d_MREAD_L		<= '1';
      --D_MWriteL_L	<= '1';
		  --D_MWriteH_L	<= '1';
  Elsif (clk = '1') then
 	    MARMUXSel	<= mem_controls_in.mem.MARMUXSel;
	 	  LoadMAR		<= mem_controls_in.mem.LoadMAR after 20 ns;
		  d_MREAD_L		<= mem_controls_in.mem.DRead_L after 26 ns;
		  D_MWriteL_L	<= mem_controls_in.mem.DWriteL_L after 26 ns;
		  D_MWriteH_L	<= mem_controls_in.mem.DWriteH_L after 26 ns;
		  mem_RegWrite_out <= mem_controls_in.RegWrite;
		  ldi <= mem_controls_in.mem.ldi;
		  sti <= mem_controls_in.mem.sti;
		  
  End if;
  end process;

  
END ARCHITECTURE untitled;

