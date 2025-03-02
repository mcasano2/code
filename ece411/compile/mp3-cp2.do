echo "--- Executing initialization force file for ../testcode/mp3-cp2.asm ---"

echo "Resetting processor for 5 ns."
force /reset_l 0 @0
force /reset_l 1 @5

echo "Done initializing processor, loading ../testcode/mp3-cp2.asm program code."
run 5
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(0) X"07"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(1) X"0E"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(2) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(3) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(4) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(5) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(6) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(7) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(8) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(9) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(10) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(11) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(12) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(13) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(14) X"80"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(15) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(16) X"07"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(17) X"60"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(18) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(19) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(20) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(21) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(22) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(23) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(24) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(25) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(26) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(27) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(28) X"06"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(29) X"62"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(30) X"08"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(31) X"66"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(32) X"07"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(33) X"64"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(34) X"09"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(35) X"68"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(36) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(37) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(38) X"09"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(39) X"72"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(40) X"08"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(41) X"74"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(42) X"07"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(43) X"76"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(44) X"06"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(45) X"78"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(46) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(47) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(48) X"06"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(49) X"62"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(50) X"07"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(51) X"64"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(52) X"08"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(53) X"66"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(54) X"09"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(55) X"68"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(56) X"12"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(57) X"0E"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(58) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(59) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(60) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(61) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(62) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(63) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(64) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(65) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(66) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(67) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(68) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(69) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(70) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(71) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(72) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(73) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(74) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(75) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(76) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(77) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(78) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(79) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(80) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(81) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(82) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(83) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(84) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(85) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(86) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(87) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(88) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(89) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(90) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(91) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(92) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(93) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(94) X"42"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(95) X"1A"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(96) X"C4"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(97) X"1C"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(98) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(99) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(100) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(101) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(102) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(103) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(104) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(105) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(106) X"18"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(107) X"7A"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(108) X"46"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(109) X"1F"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(110) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(111) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(112) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(113) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(114) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(115) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(116) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(117) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(118) X"10"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(119) X"7E"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(120) X"10"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(121) X"62"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(122) X"FF"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(123) X"0F"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(124) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(125) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(126) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(127) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(128) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(129) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(130) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(131) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(132) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(133) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(134) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(135) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(136) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(137) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(138) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(139) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(140) X"09"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(141) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(142) X"02"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(143) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(144) X"01"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(145) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(146) X"03"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(147) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(148) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(149) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(150) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(151) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(152) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(153) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(154) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(155) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(156) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(157) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(158) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(159) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(160) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(161) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(162) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(163) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(164) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(165) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(166) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(167) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(168) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(169) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(170) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(171) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(172) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(173) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(174) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(175) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(176) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(177) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(178) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(179) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(180) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(181) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(182) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(183) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(184) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(185) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(186) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(187) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(188) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(189) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(190) X"00"
change mp3_cpu/PipeMem/mPhyDRAM/vhdl_memory/mem(191) X"00"
run 5
echo "Done loading ../testcode/mp3-cp2.asm program code."
