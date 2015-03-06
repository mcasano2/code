onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/CLK
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_controls_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_ALU_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/mem_DATAIN_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_ADDRESS
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_DATAOUT
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_MWRITEH_L
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_MWRITEL_L
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/d_MREAD_L
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_MRESP_H
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/D_DATAIN
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sMEM/LoadMAR
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sMEM/MARMUXSel
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {219 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 289
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
WaveRestoreZoom {0 ns} {384 ns}
