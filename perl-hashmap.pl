#!/usr/bin/perl

sub get_rss {
	$rss = qx{ grep VmRSS /proc/$$/status };
	$rss =~ s/[^0-9]//gm;
	return $rss * 1024;
}

my $memoryStart = get_rss;
my $list = [];
for ($i = 0; $i < 1000000; $i++) {
	push @$list, {
		id => $i,
		spalte_a => "abcdefghijklmnopqrstuvwxyz",
		spalte_b => "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz",
		spalte_c => "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz",
		spalte_d => "0123456789",
		spalte_e => "0123456789012345678901234567890123456789012345678901234567890123456789",
		spalte_f => "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc",
	};
}
my $memoryEnd = get_rss;
print "  perl array: memory start: " . int($memoryStart / 1024) . " KB\n";
print "  perl array: memory end: " . int($memoryEnd / 1024) . " KB\n";
print "  perl array: memory diff: " . int(($memoryEnd - $memoryStart) / 1024) . " KB\n";
print "  perl array: memory per row: " . (($memoryEnd - $memoryStart) / 1000000) . " bytes\n";
