--
-- VHDL Architecture ece411.DecodeOWORD.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-20.ews.illinois.edu)
--          at - 17:41:36 02/24/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;
USE ieee.std_logic_arith.all;

ENTITY DecodeOWORD IS
   PORT( 
      Offset  : IN     LC3B_C_OFFSET;
      Dec0    : OUT    std_logic;
      Dec1    : OUT    std_logic;
      Dec2    : OUT    std_logic;
      Dec3    : OUT    std_logic;
      Dec4    : OUT    std_logic;
      Dec5    : OUT    std_logic;
      Dec6    : OUT    std_logic;
      Dec7    : OUT    std_logic;
      Offset0 : OUT    std_logic
   );

-- Declarations

END DecodeOWORD ;

--
ARCHITECTURE untitled OF DecodeOWORD IS
  signal sel : std_logic_vector (2 downto 0) ;
BEGIN
  sel <= Offset (3 downto 1) ;
  Offset0 <= Offset(0);
  Dec0 <= '1' when sel = "000" else '0';
  Dec1 <= '1' when sel = "001" else '0';
  Dec2 <= '1' when sel = "010" else '0';
  Dec3 <= '1' when sel = "011" else '0';
  Dec4 <= '1' when sel = "100" else '0';
  Dec5 <= '1' when sel = "101" else '0';
  Dec6 <= '1' when sel = "110" else '0';
  Dec7 <= '1' when sel = "111" else '0' after delay_decode3;
END ARCHITECTURE untitled;

