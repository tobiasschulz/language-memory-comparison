#!/usr/bin/perl

use strict;
use warnings;

open my $f, "<", "./speichereffizienz.txt";
my @lines = <$f>;
map { chomp } @lines;
close $f;

sub formatbytes {
	my $v = $_[0];
	$v =~ s/\..*//gm;
	$v =~ s/[^0-9]//gm;
	return int($v);
}

my @languages = sort keys %{{ map { $_ => 1 } map { my $l=$_; $l =~ s/:.*//gm; $l =~ s/^\s+//gm; $l } @lines }};
my @columns = ("memory start", "memory end", "memory diff", "memory per row");
#print join(", ", @columns)."\n";
#print join(", ", @languages)."\n";

my $lc = $columns[$#columns];
@languages = sort { formatbytes(join(",", map { my $v=$_; $v =~ s/^.*://gm; $v } grep { /\Q$a\E.*?$lc/ } @lines)) <=> formatbytes(join(",", map { my $v=$_; $v =~ s/^.*://gm; $v } grep { /\Q$b\E.*?$lc/ } @lines)) } @languages;

open my $md, ">", "./speichereffizienz.md";

print $md "| Sprache | ";
foreach my $c (@columns) {
	print $md "$c | ";
}
print $md "\n";
print $md "| ----- | ";
foreach my $c (@columns) {
	print $md "----- | ";
}
print $md "\n";
foreach my $l (@languages) {
	print $md "| $l | ";
	foreach my $c (@columns) {
		my $v = join(",", map { my $v=$_; $v =~ s/^.*://gm; $v } grep { /\Q$l\E.*?$c/ } @lines);
		if ($v =~ /byte/) {
			$v =~ s/\..*//gm;
			$v =~ s/[^0-9]//gm;
			$v = int($v) . " bytes";
		}
		print $md "$v | ";
	}
	print $md "\n";
}

print $md "\n";
print $md "\n";

print $md "| Sprache | ";
foreach my $c (@columns) {
	print $md "$c | ";
}
print $md "\n";
print $md "| ----- | ";
foreach my $c (@columns) {
	print $md "----- | ";
}
print $md "\n";
foreach my $l (@languages) {
	print $md "| $l | ";
	foreach my $c (@columns) {
		my $v = join(",", map { my $v=$_; $v =~ s/^.*://gm; $v } grep { /\Q$l\E.*?$c/ } @lines);
		if ($v =~ /KB/) {
			$v =~ s/\..*//gm;
			$v =~ s/[^0-9]//gm;
			$v = int(int($v) / 1024) . " MB";
		}
		if ($v =~ /byte/) {
			$v =~ s/\..*//gm;
			$v =~ s/[^0-9]//gm;
			$v = int($v) . " bytes";
		}
		print $md "$v | ";
	}
	print $md "\n";
}

close $md;

system("mv speichereffizienz.md README.md");
