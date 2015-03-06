--
-- VHDL Architecture ece411.Pipeline_Control.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-20.ews.illinois.edu)
--          at - 21:59:25 03/26/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY Pipeline_Control IS
   PORT( 
      CLK            : IN     STD_LOGIC;
      D_MREAD_L      : IN     STD_LOGIC;
      d_mresp_h      : IN     STD_LOGIC;
      D_MWRITEH_L    : IN     STD_LOGIC;
      D_MWRITEL_L    : IN     STD_LOGIC;
      I_MREAD_L      : IN     STD_LOGIC;
      I_MRESP_H      : IN     STD_LOGIC;
      RESET_L        : IN     STD_LOGIC;
      ex_DR_in       : IN     LC3B_REG;
      ex_MemRead_out : IN     std_logic;
      id_REGaNum_out : IN     LC3B_REG;
      id_REGbNum_out : IN     LC3B_REG;
      LOAD_EXMEM     : OUT    STD_LOGIC;
      LOAD_IDEX      : OUT    STD_LOGIC;
      LOAD_IF        : OUT    std_logic;
      LOAD_IFID      : OUT    STD_LOGIC;
      LOAD_MEMWB     : OUT    STD_LOGIC;
      RESET_IDEX_L   : OUT    std_logic;
      state          : IN     STD_LOGIC;
      mem_mresp      : IN     std_logic
   );

-- Declarations

END Pipeline_Control ;

--
ARCHITECTURE untitled OF Pipeline_Control IS
  signal L_EXMEM : std_logic;
  signal L_IDEX : std_logic;
  signal L_IFID : std_logic;
  signal L_IF   : std_logic;
  signal L_MEMWB : std_logic;
  signal L_RESET_IDEX_L : std_logic;
BEGIN
  PROCESS(D_MRESP_H, I_MRESP_H, CLK, RESET_L, I_MREAD_L, D_MREAD_L , D_MWRITEH_L, D_MWRITEL_L)
  BEGIN
    IF (RESET_L = '0') THEN
      L_EXMEM  <= '1';
      L_IDEX   <= '1';
      L_IFID   <= '1';
      L_IF     <= '1';
      L_MEMWB  <= '1';
      L_RESET_IDEX_L <= '1';
      
      
    ELSE --CLK'EVENT AND CLK = '1' THEN
        L_EXMEM  <= '1';
        L_IDEX   <= '1';
        L_IFID   <= '1';
        L_IF     <= '1';
        L_MEMWB  <= '1';
        L_RESET_IDEX_L <= '1';
      IF((I_MREAD_L = '0') AND (I_MRESP_H = '0')) THEN
          L_EXMEM  <= '0';
          L_IDEX   <= '0';
          L_IFID   <= '0';
          L_IF     <= '0';
          L_MEMWB  <= '0';
      END IF;
      IF((D_MREAD_L = '0' OR D_MWRITEL_L = '0' OR D_MWRITEH_L = '0') AND (D_MRESP_H = '0')) THEN
          L_EXMEM  <= '0';
          L_IDEX   <= '0';
          L_IFID   <= '0';
          L_IF     <= '0';
          L_MEMWB  <= '0';    
      END IF;
      IF((ex_MemRead_out = '0') AND ((ex_DR_in = id_REGaNum_out) OR (ex_DR_in = id_REGbNum_out))) THEN
          L_IF            <= '0';
          L_IFID          <= '0';
          L_IDEX          <= '0';
          L_RESET_IDEX_L  <= '0';
          L_EXMEM         <= '1';
          L_MEMWB         <= '1';    
      END IF;
      --IF(state = '1') THEN
      --    L_EXMEM  <= '0';
      --    L_IDEX   <= '0';
      --    L_IFID   <= '0';
      --    L_IF     <= '0';
      --    L_MEMWB  <= '0';    
      --END IF;
   END IF;
    
  END PROCESS;
  LOAD_EXMEM  <= L_EXMEM after 1ns;
  LOAD_IDEX   <= L_IDEX after 1ns;
  LOAD_IFID   <= L_IFID after 1ns;
  LOAD_IF     <= L_IF after 1ns;
  LOAD_MEMWB  <= L_MEMWB after 1ns; 
  RESET_IDEX_L <= L_RESET_IDEX_L after 1ns;
END ARCHITECTURE untitled;

