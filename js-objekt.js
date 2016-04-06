var util = require('util');

memoryStart = process.memoryUsage().rss
var list = []
for (i = 0; i < 1000000; i++) {
	m = {}
	m.id = i
	m.spalte_a = new String("abcdefghijklmnopqrstuvwxyz")
	m.spalte_b = new String("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz")
	m.spalte_c = new String("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz")
	m.spalte_d = new String("0123456789")
	m.spalte_e = new String("0123456789012345678901234567890123456789012345678901234567890123456789")
	m.spalte_f = new String("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc")
	list.push(m)
}
memoryEnd = process.memoryUsage().rss
console.log("node.js objekt: memory start: " + (parseInt(memoryStart / 1024)) + " KB")
console.log("node.js objekt: memory end: " + (parseInt(memoryEnd / 1024)) + " KB")
console.log("node.js objekt: memory diff: " + (parseInt((memoryEnd - memoryStart) / 1024)) + " KB")
console.log("node.js objekt: memory per row: " + ((memoryEnd - memoryStart) / 1000000) + " bytes")
