#!/usr/bin/python
import os
import psutil
process = psutil.Process(os.getpid())

class Model:
	id = 0
	spalte_a = ""
	spalte_b = ""
	spalte_c = ""
	spalte_d = ""
	spalte_e = ""
	spalte_f = ""

memoryStart = process.memory_info().rss
list = []
for i in xrange(1000000):
	m = Model()
	m.id = i
	m.spalte_a = "abcdefghijklmnopqrstuvwxyz"
	m.spalte_b = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
	m.spalte_c = "aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz"
	m.spalte_d = "0123456789"
	m.spalte_e = "0123456789012345678901234567890123456789012345678901234567890123456789"
	m.spalte_f = "abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc"
	list.append(m)
memoryEnd = process.memory_info().rss
print "python objek: memory start: " + str(int(memoryStart / 1024)) + " KB"
print "python objek: memory end: " + str(int(memoryEnd / 1024)) + " KB"
print "python objek: memory diff: " + str(int((memoryEnd - memoryStart) / 1024)) + " KB"
print "python objek: memory per row: " + str((memoryEnd - memoryStart) / 1000000) + " bytes"
