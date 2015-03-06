onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/CLK
add wave -noupdate -radix hexadecimal -childformat {{/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(7) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(6) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(5) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(4) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(3) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(2) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(1) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(0) -radix hexadecimal}} -expand -subitemconfig {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(7) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(6) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(5) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(4) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(3) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(2) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(1) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(0) {-height 16 -radix hexadecimal}} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/if_PC_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/if_IR_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/id_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/id_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/RESET_L
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/Output
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/PRE_OUT
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/I_MREAD_L
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/I_MRESP_H
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_MREAD_L
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/I_DATAIN
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/Input
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/RESET
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/clk
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/load
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/Output
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCReg/PRE_OUT
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sIF/PCMUX/Sel
add wave -noupdate /mp3_cpu/aPipelineDP/LOAD_EXMEM
add wave -noupdate /mp3_cpu/aPipelineDP/LOAD_IDEX
add wave -noupdate /mp3_cpu/aPipelineDP/LOAD_IF
add wave -noupdate /mp3_cpu/aPipelineDP/LOAD_IFID
add wave -noupdate /mp3_cpu/aPipelineDP/LOAD_MEMWB
add wave -noupdate /mp3_cpu/I_MREAD_L
add wave -noupdate /mp3_cpu/D_MREAD_L
add wave -noupdate /mp3_cpu/D_MWRITEH_L
add wave -noupdate /mp3_cpu/D_MWRITEL_L
add wave -noupdate /mp3_cpu/PipeMem/mdCache/hit
add wave -noupdate /mp3_cpu/PipeMem/miCache/hit
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {4651 ns} 0} {{Cursor 2} {3104 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 506
configure wave -valuecolwidth 252
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {4313 ns} {5453 ns}
