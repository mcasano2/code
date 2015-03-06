echo "--- Executing initialization force file for ../testcode/mp2test.asm ---"

echo "Resetting processor for 5 ns."
force /reset_l 0 @0
force /reset_l 1 @5
echo "Initializing the processor."
force /start_h 0 @0
force /start_h 1 @10

-- Test case: lowering start_h should not impact the function of the processor
force /start_h 0 @ 100

echo "Done initializing processor, loading ../testcode/mp2test.asm program code."
run 5
change mp3_cpu/magicalMem/vhdl_memory/mem(0) X"28"
change mp3_cpu/magicalMem/vhdl_memory/mem(1) X"10"
change mp3_cpu/magicalMem/vhdl_memory/mem(2) X"40"
change mp3_cpu/magicalMem/vhdl_memory/mem(3) X"12"
change mp3_cpu/magicalMem/vhdl_memory/mem(4) X"64"
change mp3_cpu/magicalMem/vhdl_memory/mem(5) X"54"
change mp3_cpu/magicalMem/vhdl_memory/mem(6) X"42"
change mp3_cpu/magicalMem/vhdl_memory/mem(7) X"52"
change mp3_cpu/magicalMem/vhdl_memory/mem(8) X"03"
change mp3_cpu/magicalMem/vhdl_memory/mem(9) X"E6"
change mp3_cpu/magicalMem/vhdl_memory/mem(10) X"C0"
change mp3_cpu/magicalMem/vhdl_memory/mem(11) X"C0"
change mp3_cpu/magicalMem/vhdl_memory/mem(12) X"3F"
change mp3_cpu/magicalMem/vhdl_memory/mem(13) X"10"
change mp3_cpu/magicalMem/vhdl_memory/mem(14) X"C0"
change mp3_cpu/magicalMem/vhdl_memory/mem(15) X"C1"
change mp3_cpu/magicalMem/vhdl_memory/mem(16) X"00"
change mp3_cpu/magicalMem/vhdl_memory/mem(17) X"50"
change mp3_cpu/magicalMem/vhdl_memory/mem(18) X"03"
change mp3_cpu/magicalMem/vhdl_memory/mem(19) X"0C"
change mp3_cpu/magicalMem/vhdl_memory/mem(20) X"FD"
change mp3_cpu/magicalMem/vhdl_memory/mem(21) X"EF"
change mp3_cpu/magicalMem/vhdl_memory/mem(22) X"FA"
change mp3_cpu/magicalMem/vhdl_memory/mem(23) X"E9"
change mp3_cpu/magicalMem/vhdl_memory/mem(24) X"00"
change mp3_cpu/magicalMem/vhdl_memory/mem(25) X"C1"
change mp3_cpu/magicalMem/vhdl_memory/mem(26) X"FF"
change mp3_cpu/magicalMem/vhdl_memory/mem(27) X"0F"
run 5
echo "Done loading ../testcode/mp2test.asm program code."
