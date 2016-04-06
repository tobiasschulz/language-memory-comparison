<?php

$memoryStart = memory_get_usage(false);
$list = [];
for ($i = 0; $i < 1000000; $i++) {
	$m = new Model();
	$m->id = $i;
	$m->spalte_a = "abcdefghijklmnopqrstuvwxyz";
	$m->spalte_b = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	$m->spalte_c = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz";
	$m->spalte_d = "0123456789";
	$m->spalte_e = "0123456789012345678901234567890123456789012345678901234567890123456789";
	$m->spalte_f = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc";
	$list[] = $m;
}
$memoryEnd = memory_get_usage(false);
echo "  php ".$argv[1]." objekt (deklarierte attribute): memory start: " . (int)($memoryStart / 1024) . " KB\n";
echo "  php ".$argv[1]." objekt (deklarierte attribute): memory end: " . (int)($memoryEnd / 1024) . " KB\n";
echo "  php ".$argv[1]." objekt (deklarierte attribute): memory diff: " . (int)(($memoryEnd - $memoryStart) / 1024) . " KB\n";
echo "  php ".$argv[1]." objekt (deklarierte attribute): memory per row: " . (($memoryEnd - $memoryStart) / 1000000) . " bytes\n";

class Model {
	public $id;
	public $spalte_a;
	public $spalte_b;
	public $spalte_c;
	public $spalte_d;
	public $spalte_e;
	public $spalte_f;
}
