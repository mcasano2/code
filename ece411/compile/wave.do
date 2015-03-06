onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /mp2_cpu/theDatapath/clk
add wave -noupdate /mp2_cpu/theDatapath/PCout
add wave -noupdate /mp2_cpu/theDatapath/IRout
add wave -noupdate /mp2_cpu/theDatapath/DATAIN
add wave -noupdate /mp2_cpu/theDatapath/DATAOUT
add wave -noupdate /mp2_cpu/theDatapath/ADDRESS
add wave -noupdate /mp2_cpu/theDatapath/aRegFile/RAM
add wave -noupdate /mp2_cpu/DRAM/Cache_Cont/current_state
add wave -noupdate /mp2_cpu/DRAM/Cache_Cont/CacheWrite
add wave -noupdate /mp2_cpu/DRAM/Cache_Cont/HIT
add wave -noupdate /mp2_cpu/DRAM/Cache_Cont/LRUout
add wave -noupdate /mp2_cpu/DRAM/MREAD_L
add wave -noupdate /mp2_cpu/DRAM/MRESP_H
add wave -noupdate /mp2_cpu/DRAM/PMDATAIN
add wave -noupdate /mp2_cpu/DRAM/PMDATAOUT
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {5975 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
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
WaveRestoreZoom {5895 ns} {6079 ns}
