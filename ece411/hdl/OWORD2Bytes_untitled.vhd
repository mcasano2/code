--
-- VHDL Architecture ece411.OWORD2Bytes.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-20.ews.illinois.edu)
--          at - 19:06:38 02/24/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY OWORD2Bytes IS
   PORT( 
      OWORDIN  : IN     LC3B_OWORD;
      byte0  : OUT    LC3B_BYTE;
      byte1  : OUT   LC3B_BYTE;
      byte2  : OUT    LC3B_BYTE;
      byte3  : OUT    LC3B_BYTE;
      byte4  : OUT    LC3B_BYTE;
      byte5  : OUT    LC3B_BYTE;
      byte6  : OUT    LC3B_BYTE;
      byte7  : OUT    LC3B_BYTE;
      byte8  : OUT    LC3B_BYTE;
      byte9  : OUT    LC3B_BYTE;
      byteA : OUT    LC3B_BYTE;
      byteB : OUT    LC3B_BYTE;
      byteC : OUT    LC3B_BYTE;
      byteD : OUT    LC3B_BYTE;
      byteE : OUT    LC3B_BYTE;
      byteF : OUT    LC3B_BYTE
   );

-- Declarations

END OWORD2Bytes ;

--
ARCHITECTURE untitled OF OWORD2Bytes IS
BEGIN
  byte0 <= OWORDIN(7 DOWNTO 0);
  byte1 <= OWORDIN(15 DOWNTO 8);
  byte2 <= OWORDIN(23 DOWNTO 16);
  byte3 <= OWORDIN(31 DOWNTO 24);
  byte4 <= OWORDIN(39 DOWNTO 32);
  byte5 <= OWORDIN(47 DOWNTO 40);
  byte6 <= OWORDIN(55 DOWNTO 48);
  byte7 <= OWORDIN(63 DOWNTO 56);
  byte8 <= OWORDIN(71 DOWNTO 64);
  byte9 <= OWORDIN(79 DOWNTO 72);
  byteA <= OWORDIN(87 DOWNTO 80);
  byteB <= OWORDIN(95 DOWNTO 88);
  byteC <= OWORDIN(103 DOWNTO 96);
  byteD <= OWORDIN(111 DOWNTO 104);
  byteE <= OWORDIN(119 DOWNTO 112);
  byteF <= OWORDIN(127 DOWNTO 120);
  
END ARCHITECTURE untitled;

