onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /mp2_cpu/ControlUnit/clk
add wave -noupdate /mp2_cpu/theDatapath/PCout
add wave -noupdate /mp2_cpu/ControlUnit/IRout
add wave -noupdate /mp2_cpu/theDatapath/aRegFile/RAM
add wave -noupdate /mp2_cpu/theDatapath/ADDRESS
add wave -noupdate /mp2_cpu/theDatapath/DATAIN
add wave -noupdate /mp2_cpu/theDatapath/DATAOUT
add wave -noupdate /mp2_cpu/DRAM/MREAD_L
add wave -noupdate /mp2_cpu/DRAM/MRESP_H
add wave -noupdate /mp2_cpu/DRAM/PMDATAIN
add wave -noupdate /mp2_cpu/DRAM/PMDATAOUT
add wave -noupdate /mp2_cpu/DRAM/PMRESP_H
add wave -noupdate /mp2_cpu/DRAM/LRUout
add wave -noupdate /mp2_cpu/DRAM/CacheWrite
add wave -noupdate /mp2_cpu/DRAM/HIT
add wave -noupdate -expand /mp2_cpu/DRAM/Cache_DP/aDataArray0/Data
add wave -noupdate -expand /mp2_cpu/DRAM/Cache_DP/aDataArray1/Data
add wave -noupdate -expand /mp2_cpu/DRAM/Cache_DP/LRUBit/Bit
add wave -noupdate /mp2_cpu/DRAM/Cache_DP/LRUBit/Index
add wave -noupdate /mp2_cpu/DRAM/Cache_DP/LRUBit/BitWrite
add wave -noupdate /mp2_cpu/DRAM/Cache_DP/LRUBit/BitIn
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {1005 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 153
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
WaveRestoreZoom {356 ns} {2294 ns}
