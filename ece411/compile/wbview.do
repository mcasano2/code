onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/CLK
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_DATAIN_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_ALU_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_PCadj_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_RegIn
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_DR
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_regWrite
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sWB/RegDataMuxSel
add wave -noupdate -radix hexadecimal -childformat {{/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(7) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(6) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(5) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(4) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(3) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(2) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(1) -radix hexadecimal} {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(0) -radix hexadecimal}} -expand -subitemconfig {/mp3_cpu/aPipelineDP/sID/aRegFile/RAM(7) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(6) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(5) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(4) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(3) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(2) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(1) {-height 16 -radix hexadecimal} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM(0) {-height 16 -radix hexadecimal}} /mp3_cpu/aPipelineDP/sID/aRegFile/RAM
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/WrIn
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/DRIn
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {486 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 286
configure wave -valuecolwidth 100
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
WaveRestoreZoom {1818 ns} {2010 ns}
