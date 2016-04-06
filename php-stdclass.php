<?php

$memoryStart = memory_get_usage(false);
$list = [];
for ($i = 0; $i < 1000000; $i++) {
	$list[] = (object)[
		"id" => $i,
		"spalte_a" => "abcdefghijklmnopqrstuvwxyz",
		"spalte_b" => "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
		"spalte_c" => "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz",
		"spalte_d" => "0123456789",
		"spalte_e" => "0123456789012345678901234567890123456789012345678901234567890123456789",
		"spalte_f" => "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc",
	];
}
$memoryEnd = memory_get_usage(false);
echo "php ".$argv[1]." object (stdclass): memory start: " . (int)($memoryStart / 1024) . " KB\n";
echo "php ".$argv[1]." object (stdclass): memory end: " . (int)($memoryEnd / 1024) . " KB\n";
echo "php ".$argv[1]." object (stdclass): memory diff: " . (int)(($memoryEnd - $memoryStart) / 1024) . " KB\n";
echo "php ".$argv[1]." object (stdclass): memory per row: " . (($memoryEnd - $memoryStart) / 1000000) . " bytes\n";
