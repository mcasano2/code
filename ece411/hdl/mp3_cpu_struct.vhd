-- VHDL Entity ece411.mp3_CPU.symbol
--
-- Created:
--          by - mcasano2.ews (gelib-057-26.ews.illinois.edu)
--          at - 03:37:41 04/11/13
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY mp3_CPU IS
   PORT( 
      RESET_L : IN     STD_LOGIC
   );

-- Declarations

END mp3_CPU ;

--
-- VHDL Architecture ece411.mp3_CPU.struct
--
-- Created:
--          by - mcasano2.ews (gelib-057-26.ews.illinois.edu)
--          at - 03:37:42 04/11/13
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;


ARCHITECTURE struct OF mp3_CPU IS

   -- Architecture declarations

   -- Internal signal declarations
   SIGNAL CLK         : STD_LOGIC;
   SIGNAL D_ADDRESS   : LC3B_WORD;
   SIGNAL D_DATAIN    : LC3B_WORD;
   SIGNAL D_DATAOUT   : LC3B_WORD;
   SIGNAL D_MREAD_L   : STD_LOGIC;
   SIGNAL D_MRESP_H   : STD_LOGIC;
   SIGNAL D_MWRITEH_L : STD_LOGIC;
   SIGNAL D_MWRITEL_L : STD_LOGIC;
   SIGNAL I_ADDRESS   : LC3B_WORD;
   SIGNAL I_DATAIN    : LC3B_WORD;
   SIGNAL I_MREAD_L   : STD_LOGIC;
   SIGNAL I_MRESP_H   : STD_LOGIC;


   -- Component Declarations
   COMPONENT CLKgen
   PORT (
      clk : INOUT  std_logic  := '0'
   );
   END COMPONENT;
   COMPONENT PipeMemory
   PORT (
      CLK         : IN     STD_LOGIC ;
      D_ADDRESS   : IN     LC3B_WORD ;
      D_DATAOUT   : IN     LC3B_WORD ;
      D_MREAD_L   : IN     STD_LOGIC ;
      D_MWRITEH_L : IN     STD_LOGIC ;
      D_MWRITEL_L : IN     STD_LOGIC ;
      I_ADDRESS   : IN     LC3B_WORD ;
      I_MREAD_L   : IN     STD_LOGIC ;
      RESET_L     : IN     STD_LOGIC ;
      D_DATAIN    : OUT    LC3B_WORD ;
      D_MRESP_H   : OUT    STD_LOGIC ;
      I_DATAIN    : OUT    LC3B_WORD ;
      I_MRESP_H   : OUT    STD_LOGIC 
   );
   END COMPONENT;
   COMPONENT PipelineDP
   PORT (
      CLK         : IN     STD_LOGIC ;
      D_DATAIN    : IN     LC3B_WORD ;
      I_DATAIN    : IN     LC3B_WORD ;
      I_MRESP_H   : IN     STD_LOGIC ;
      RESET_L     : IN     STD_LOGIC ;
      d_mresp_h   : IN     STD_LOGIC ;
      D_ADDRESS   : OUT    LC3B_WORD ;
      D_DATAOUT   : OUT    LC3B_WORD ;
      D_MREAD_L   : OUT    STD_LOGIC ;
      D_MWRITEH_L : OUT    STD_LOGIC ;
      D_MWRITEL_L : OUT    STD_LOGIC ;
      I_ADDRESS   : OUT    LC3B_WORD ;
      I_MREAD_L   : OUT    STD_LOGIC 
   );
   END COMPONENT;

   -- Optional embedded configurations
   -- pragma synthesis_off
   FOR ALL : CLKgen USE ENTITY ece411.CLKgen;
   FOR ALL : PipeMemory USE ENTITY ece411.PipeMemory;
   FOR ALL : PipelineDP USE ENTITY ece411.PipelineDP;
   -- pragma synthesis_on


BEGIN

   -- Instance port mappings.
   I0 : CLKgen
      PORT MAP (
         clk => CLK
      );
   PipeMem : PipeMemory
      PORT MAP (
         CLK         => CLK,
         D_ADDRESS   => D_ADDRESS,
         D_DATAOUT   => D_DATAOUT,
         D_MREAD_L   => D_MREAD_L,
         D_MWRITEH_L => D_MWRITEH_L,
         D_MWRITEL_L => D_MWRITEL_L,
         I_ADDRESS   => I_ADDRESS,
         I_MREAD_L   => I_MREAD_L,
         RESET_L     => RESET_L,
         D_DATAIN    => D_DATAIN,
         D_MRESP_H   => D_MRESP_H,
         I_DATAIN    => I_DATAIN,
         I_MRESP_H   => I_MRESP_H
      );
   aPipelineDP : PipelineDP
      PORT MAP (
         CLK         => CLK,
         D_DATAIN    => D_DATAIN,
         D_MRESP_H   => D_MRESP_H,
         I_DATAIN    => I_DATAIN,
         I_MRESP_H   => I_MRESP_H,
         RESET_L     => RESET_L,
         D_ADDRESS   => D_ADDRESS,
         D_DATAOUT   => D_DATAOUT,
         D_MREAD_L   => D_MREAD_L,
         D_MWRITEH_L => D_MWRITEH_L,
         D_MWRITEL_L => D_MWRITEL_L,
         I_ADDRESS   => I_ADDRESS,
         I_MREAD_L   => I_MREAD_L
      );

END struct;
