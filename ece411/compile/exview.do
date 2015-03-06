onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /mp3_cpu/aPipelineDP/CLK
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_controls_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_PC_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_IR_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_REGa_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_ADJ6_in
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/ex_ALU_out
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sEX/aluop
add wave -noupdate -radix hexadecimal /mp3_cpu/aPipelineDP/sEX/ALUMUXSel
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {130 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 302
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
WaveRestoreZoom {1670 ns} {2018 ns}
