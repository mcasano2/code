--
-- VHDL Architecture mp3lib.ControlRom.Untitled
--
-- Created:
--          by - glazesk1.stdt (eelnx30.ews.illinois.edu)
--          at - 13:57:03 01/18/11
--
-- using Mentor Graphics HDL Designer(TM) 2005.3 (Build 75)
--
LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.NUMERIC_STD.all;

LIBRARY ece411;
USE ece411.LC3b_types.all;

ENTITY ControlRom IS
   PORT( 
      id_controls_out : OUT    CONTROL_WORD;
      RESET_L         : IN     STD_LOGIC;
      id_IR_in        : IN     LC3B_WORD
   );

-- Declarations

END ControlRom ;

--
ARCHITECTURE Untitled OF ControlRom IS
BEGIN
    PROCESS (id_IR_in)
    VARIABLE newControl : CONTROL_WORD;
    BEGIN
		newControl.fetch.PCMUXSel := "00";
    newControl.fetch.IAddrMuxSel := '0';
    newControl.fetch.IROutMuxSel := '0';

		newControl.id.PCAddMUXSel := '0';
		newControl.id.IDPCMUXSel := '0';
		newControl.id.DRMUXSel := '0';
		newControl.id.SRAMUXSel := '0';
		newControl.id.SRBMUXSel := '0';
			
		newControl.ex.aluop := ALU_PASS;
		newControl.ex.ALUMUXSel := "00";
		newControl.ex.LoadNZP := '0';
	  newControl.ex.GenCCMuxSel := '0';
	
		newControl.mem.MARMUXSel := '0';
		newControl.mem.LoadMAR := '0';
		newControl.mem.DRead_L := '1';
		newControl.mem.DWriteL_L := '1';
		newControl.mem.DWriteH_L := '1';
		newControl.mem.ldi := '0';
		newControl.mem.sti := '0';

	  newControl.wb.ByteMUXSel := '0';
		newControl.wb.RegDataMuxSel := "00";
		newControl.wb.Write := '0';
		
		newControl.RegWrite := '0';
		
		IF (RESET_L= '1') THEN

        CASE id_IR_in(15 downto 12) IS
            WHEN OP_ADD =>
                newControl.RegWrite := '1';
              		
                newControl.name := add_op;
                newControl.ex.aluop := ALU_ADD;
				        if (id_IR_in(5) = '0') then
				         	newControl.ex.ALUMUXSel := "00";
				        else
				          newControl.ex.ALUMUXSel := "10";
			       	  end if;
			         	newControl.ex.LoadNZP := '1';
			         	newControl.wb.RegDataMuxSel := "01";
			         	newControl.wb.Write := '1';
		    		
            WHEN OP_AND =>
                newControl.RegWrite := '1';
                newControl.name := and_op;
                		
	           			newControl.ex.aluop := ALU_AND;
            				if (id_IR_in(5) = '0') then
            					newControl.ex.ALUMUXSel := "00";
            				else
            					newControl.ex.ALUMUXSel := "10";
            				end if;
            				newControl.ex.LoadNZP := '1';
            				newControl.wb.RegDataMuxSel := "01";
            				newControl.wb.Write := '1';
           
           
            WHEN OP_NOT =>
                newControl.RegWrite := '1';
                newControl.name := not_op;
                		
	           			newControl.ex.aluop := ALU_NOT;
            				newControl.ex.LoadNZP := '1';
            				newControl.wb.RegDataMuxSel := "01";
            				newControl.wb.Write := '1';
            				
      				  WHEN OP_SHF =>
      				      newControl.name := shf_op;
      				      newControl.RegWrite := '1';
      				      
            				if (id_IR_in(4) = '0') then
            					 newControl.ex.aluop := ALU_SLL;
            				else
           					  if(id_IR_in(5) = '0') then
           					    newControl.ex.aluop := ALU_SRL;
       					      else
       					        newControl.ex.aluop := ALU_SRA;
     					        end if;
            				end if;
            				
            				newControl.ex.LoadNZP := '1';
            				newControl.ex.ALUMUXSel := "10";
            				
            				newControl.wb.RegDataMuxSel := "01";
            				newControl.wb.Write := '1';      				      
                        
                         
            WHEN OP_LDR =>
                newControl.RegWrite := '1';
                newControl.name := ldr_op;
                    		
            				newControl.ex.aluop := ALU_ADD;
            				newControl.ex.ALUMUXSel := "01";
            				newControl.ex.LoadNZP := '1';
            				newControl.mem.LoadMAR := '1';
            				newControl.mem.DRead_L := '0';
            				newControl.wb.Write := '1';			
            
            WHEN OP_LDB =>
                newControl.RegWrite := '1';
                newControl.name := ldb_op;
                    		
            				newControl.ex.aluop := ALU_ADD;
            				newControl.ex.ALUMUXSel := "01";
            				newControl.ex.LoadNZP := '1';
            				newControl.mem.LoadMAR := '1';
            				newControl.mem.DRead_L := '0';
            				
            				newControl.wb.ByteMuxSel := '1';
            				newControl.wb.Write := '1';  
            				
        				WHEN OP_LDI =>
                newControl.name := str_op;
                newControl.mem.ldi := '1';
                newControl.RegWrite :='1';
                            		
            				newControl.ex.aluop := ALU_ADD;
            				newControl.ex.ALUMUXSel := "01";
            				newControl.ex.LoadNZP := '1';
            				newControl.mem.LoadMAR := '1';
            				newControl.mem.DRead_L := '0';
            				newControl.wb.Write := '1';	           				          
            
            WHEN OP_STR =>
                newControl.name := str_op;
                            		
            				newControl.id.SRAMUXSel := '0';
            				newControl.id.SRBMUXSel := '1';	
            				newControl.ex.aluop := ALU_ADD;
            				newControl.ex.ALUMUXSel := "01";
            				newControl.ex.LoadNZP := '1';
            				newControl.mem.LoadMAR := '1';
            				newControl.mem.DWriteL_L := '0';
            				newControl.mem.DWriteH_L := '0';
            				
            WHEN OP_STB =>
                newControl.name := stb_op;
                            		
            				newControl.id.SRAMUXSel := '0';
            				newControl.id.SRBMUXSel := '1';	
            				newControl.ex.aluop := ALU_ADD;
            				newControl.ex.ALUMUXSel := "01";
            				newControl.ex.LoadNZP := '1';
            				newControl.mem.LoadMAR := '1';
            				newControl.mem.DWriteL_L := '0';
            				
        				WHEN OP_STI =>
                newControl.name := str_op;
                newControl.mem.sti := '1';
                            		
            				newControl.id.SRAMUXSel := '0';
            				newControl.id.SRBMUXSel := '1';	
            				newControl.ex.aluop := ALU_ADD;
            				newControl.ex.ALUMUXSel := "01";
            				newControl.ex.LoadNZP := '1';
            				newControl.mem.LoadMAR := '1';
            				newControl.mem.DRead_L := '0';
                      
            WHEN OP_BR =>
                newControl.name := br_op;
				        newControl.fetch.PCMUXSel := "10";
				        
				    WHEN OP_JMP =>
				        newControl.name := jmp_op;
				        newControl.fetch.PCMUXSel := "11";
                newControl.id.IDPCMUXSel := '1';
                
            WHEN OP_JSR =>
                newControl.name := jsr_op;
                
                newControl.fetch.PCMUXSel := "11";
                
                newControl.id.DRMUXSel := '1';
            				if (id_IR_in(11) = '0') then
            					newControl.id.IDPCMUXSel := '1';
            				else
            					newControl.id.IDPCMUXSel := '0';
            					newControl.id.PCAddMUXSel := '1';
            				end if;
                
                newControl.wb.Write := '1';
                newControl.wb.RegDataMuxSel := "11";
                
            WHEN OP_LEA =>
                newControl.name := lea_op;
                newControl.RegWrite := '1';
                
                newControl.ex.GenCCMuxSel := '1';
                newControl.ex.LoadNZP := '1';
                newControl.ex.aluop := ALU_PASS;
                
             			newControl.wb.Write := '1';
             			newControl.wb.RegDataMuxSel := "10";
             			
         			WHEN	OP_TRAP =>
         			    		newControl.fetch.PCMUXSel := "01";
                  newControl.fetch.IAddrMuxSel := '1';
                  newControl.fetch.IROutMuxSel := '1';
                  
                  newControl.id.DRMUXSel := '1';
                  newControl.wb.Write := '1';
                  newControl.wb.RegDataMuxSel := "11";            
            
            WHEN OTHERS =>
                newControl.name := bad_op;
                newControl.fetch.PCMUXSel := "00";
				        newControl.ex.aluop := ALU_PASS;	        
				        
        END CASE;
        
    END IF;
        
      id_controls_out <= newControl AFTER DELAY_ROM;
    END PROCESS;
END ARCHITECTURE Untitled;
