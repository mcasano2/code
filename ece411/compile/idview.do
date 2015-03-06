onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_RegIn
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_DR
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/wb_regWrite
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_PCadj_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_REGa_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_REGb_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_SEXT5_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_SEXT6_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_ZEXT8_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/id_controls_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/SrcB
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/SRAMUXSel
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sID/SRBMuxSel
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {499 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 309
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
WaveRestoreZoom {1655 ns} {2019 ns}
