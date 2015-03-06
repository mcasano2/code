--
-- VHDL Architecture ece411.BitArray.untitled
--
-- Created:
--          by - baker30.ews (gelib-057-21.ews.illinois.edu)
--          at - 02:51:20 02/14/13
--
-- using Mentor Graphics HDL Designer(TM) 2012.1 (Build 6)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;
LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY BitArray IS
   PORT( 
      Reset_L  : IN     std_logic;
      BitWrite : IN     std_logic;
      Index    : IN     LC3B_C_INDEX;
      BitIn    : IN     std_logic;
      BitOut   : OUT    std_logic
   );
-- Declarations
END BitArray ;

--
ARCHITECTURE untitled OF BitArray IS
	TYPE BitArray IS array (7 downto 0) of std_logic;
	SIGNAL Bit : BitArray;
	BEGIN
		--------------------------------------------------------------
		ReadFromBitArray : PROCESS (Bit, Index)
		--------------------------------------------------------------
    
			VARIABLE BitIndex : integer;
			BEGIN
				BitIndex := to_integer(unsigned(Index));
				BitOut <= Bit(BitIndex) after 20 ns;
		
		END PROCESS ReadFromBitArray;
	
		--------------------------------------------------------------
		WriteToBitArray : PROCESS (RESET_L, Index, BitWrite, BitIn)
		-------------------------------------------------------	------	
			VARIABLE BitIndex : integer;
			BEGIN
				BitIndex := to_integer(unsigned(Index));
			IF RESET_L = '0' THEN
				Bit(0) <= '0';--(OTHERS => 'X');
				Bit(1) <= '0';--(OTHERS => 'X');
				Bit(2) <= '0';--(OTHERS => 'X');
				Bit(3) <= '0';--(OTHERS => 'X');
				Bit(4) <= '0';--(OTHERS => 'X');
				Bit(5) <= '0';--(OTHERS => 'X');
				Bit(6) <= '0';--(OTHERS => 'X');
				Bit(7) <= '0';--(OTHERS => 'X');
			END IF;

			IF (BitWrite = '1') THEN
				Bit(BitIndex) <= BitIn;
			END IF;
		
		END PROCESS WriteToBitArray;
END ARCHITECTURE untitled;