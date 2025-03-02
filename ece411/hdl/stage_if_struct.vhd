-- VHDL Entity ece411.Stage_if.interface
--
-- Created:
--          by - mcasano2.ews (gelib-057-26.ews.illinois.edu)
--          at - 00:31:45 04/11/13
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY Stage_if IS
   PORT( 
      CLK            : IN     STD_LOGIC;
      I_DATAIN       : IN     LC3B_WORD;
      I_MRESP_H      : IN     STD_LOGIC;
      LOAD_IF        : IN     std_logic;
      RESET_L        : IN     STD_LOGIC;
      ex_DR_in       : IN     LC3B_REG;
      ex_PCadj_in    : IN     LC3B_WORD;
      ex_ZEXT8_in    : IN     LC3B_WORD;
      ex_controls_in : IN     CONTROL_WORD;
      mem_NZP_in     : IN     LC3B_CC;
      I_ADDRESS      : OUT    LC3B_WORD;
      I_MREAD_L      : OUT    STD_LOGIC;
      if_IR_out      : OUT    LC3B_WORD;
      if_PC_out      : OUT    LC3B_WORD
   );

-- Declarations

END Stage_if ;

--
-- VHDL Architecture ece411.Stage_if.struct
--
-- Created:
--          by - mcasano2.ews (gelib-057-26.ews.illinois.edu)
--          at - 00:31:45 04/11/13
--
-- Generated by Mentor Graphics' HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;


ARCHITECTURE struct OF Stage_if IS

   -- Architecture declarations

   -- Internal signal declarations
   SIGNAL Const_NOP     : LC3b_word;
   SIGNAL F             : lc3b_word;
   SIGNAL F1            : LC3b_word;
   SIGNAL IAddrMuxSel   : std_logic;
   SIGNAL IR            : lc3b_word;
   SIGNAL IROutMuxSel   : std_logic;
   SIGNAL NZP_eval      : STD_LOGIC;
   SIGNAL RESET_DELAYED : std_logic;
   SIGNAL Sel           : lc3b_4mux_sel;
   SIGNAL output        : LC3b_word;

   -- Implicit buffer signal declarations
   SIGNAL if_PC_out_internal : LC3B_WORD;


   -- Component Declarations
   COMPONENT D_Latch
   PORT (
      Data_In  : IN     lc3b_word ;
      Enable   : IN     std_logic ;
      data_out : OUT    lc3b_word 
   );
   END COMPONENT;
   COMPONENT IFCntrlStrip
   PORT (
      CLK            : IN     STD_LOGIC ;
      RESET_DELAYED  : IN     std_logic ;
      ex_controls_in : IN     CONTROL_WORD ;
      IROutMuxSel    : OUT    std_logic ;
      IAddrMuxSel    : OUT    std_logic ;
      Sel            : OUT    lc3b_4mux_sel 
   );
   END COMPONENT;
   COMPONENT IReadDelay
   PORT (
      CLK       : IN     STD_LOGIC;
      Load      : IN     STD_LOGIC;
      RESET     : IN     std_logic;
      I_MREAD_L : OUT    STD_LOGIC
   );
   END COMPONENT;
   COMPONENT NZP_Check
   PORT (
      ex_DR_in   : IN     LC3B_REG;
      mem_NZP_in : IN     LC3B_CC;
      NZP_eval   : OUT    STD_LOGIC
   );
   END COMPONENT;
   COMPONENT PLUS2
   PORT (
      PCout         : IN     LC3b_word;
      RESET_DELAYED : IN     std_logic;
      clk           : IN     std_logic;
      PCPlus2out    : OUT    LC3b_word
   );
   END COMPONENT;
   COMPONENT Reg16
   PORT (
      Input  : IN     LC3b_word ;
      RESET  : IN     std_logic ;
      clk    : IN     std_logic ;
      load   : IN     std_logic ;
      Output : OUT    LC3b_word 
   );
   END COMPONENT;
   COMPONENT ResetDelay
   PORT (
      CLK           : IN     STD_LOGIC ;
      RESET_L       : IN     STD_LOGIC ;
      RESET_DELAYED : OUT    std_logic 
   );
   END COMPONENT;
   COMPONENT WordMux2
   PORT (
      A   : IN     LC3b_word ;
      B   : IN     LC3b_word ;
      Sel : IN     std_logic ;
      F   : OUT    LC3b_word 
   );
   END COMPONENT;
   COMPONENT WordMux4
   PORT (
      A   : IN     lc3b_word ;
      B   : IN     lc3b_word ;
      C   : IN     lc3b_word ;
      D   : IN     lc3b_word ;
      Sel : IN     lc3b_4mux_sel ;
      F   : OUT    lc3b_word 
   );
   END COMPONENT;

   -- Optional embedded configurations
   -- pragma synthesis_off
   FOR ALL : D_Latch USE ENTITY ece411.D_Latch;
   FOR ALL : IFCntrlStrip USE ENTITY ece411.IFCntrlStrip;
   FOR ALL : IReadDelay USE ENTITY ece411.IReadDelay;
   FOR ALL : NZP_Check USE ENTITY ece411.NZP_Check;
   FOR ALL : PLUS2 USE ENTITY ece411.PLUS2;
   FOR ALL : Reg16 USE ENTITY ece411.Reg16;
   FOR ALL : ResetDelay USE ENTITY ece411.ResetDelay;
   FOR ALL : WordMux2 USE ENTITY ece411.WordMux2;
   FOR ALL : WordMux4 USE ENTITY ece411.WordMux4;
   -- pragma synthesis_on


BEGIN
   -- Architecture concurrent statements
   -- HDL Embedded Text Block 1 eb1
   Const_NOP <= "0000000000000000";


   -- Instance port mappings.
   IRlatch : D_Latch
      PORT MAP (
         Data_In  => I_DATAIN,
         Enable   => I_MRESP_H,
         data_out => IR
      );
   U_0 : IFCntrlStrip
      PORT MAP (
         CLK            => CLK,
         RESET_DELAYED  => RESET_DELAYED,
         ex_controls_in => ex_controls_in,
         IROutMuxSel    => IROutMuxSel,
         IAddrMuxSel    => IAddrMuxSel,
         Sel            => Sel
      );
   U_3 : IReadDelay
      PORT MAP (
         CLK       => CLK,
         Load      => LOAD_IF,
         RESET     => RESET_L,
         I_MREAD_L => I_MREAD_L
      );
   U_4 : NZP_Check
      PORT MAP (
         ex_DR_in   => ex_DR_in,
         mem_NZP_in => mem_NZP_in,
         NZP_eval   => NZP_eval
      );
   PCPlus2 : PLUS2
      PORT MAP (
         PCout         => output,
         clk           => CLK,
         RESET_DELAYED => RESET_DELAYED,
         PCPlus2out    => if_PC_out_internal
      );
   PCReg : Reg16
      PORT MAP (
         Input  => F,
         RESET  => RESET_L,
         clk    => CLK,
         load   => LOAD_IF,
         Output => output
      );
   U_6 : ResetDelay
      PORT MAP (
         CLK           => CLK,
         RESET_L       => RESET_L,
         RESET_DELAYED => RESET_DELAYED
      );
   IAddrMux : WordMux2
      PORT MAP (
         A   => output,
         B   => ex_ZEXT8_in,
         Sel => IAddrMuxSel,
         F   => I_ADDRESS
      );
   IROutMux : WordMux2
      PORT MAP (
         A   => IR,
         B   => Const_NOP,
         Sel => IROutMuxSel,
         F   => if_IR_out
      );
   U_5 : WordMux2
      PORT MAP (
         A   => if_PC_out_internal,
         B   => ex_PCadj_in,
         Sel => NZP_eval,
         F   => F1
      );
   PCMUX : WordMux4
      PORT MAP (
         A   => if_PC_out_internal,
         B   => IR,
         C   => F1,
         D   => ex_PCadj_in,
         Sel => Sel,
         F   => F
      );

   -- Implicit buffered output assignments
   if_PC_out <= if_PC_out_internal;

END struct;
