#include <list>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <proc/readproc.h>

using namespace std;

long get_rss() {
        proc_t proc;
        look_up_our_self(&proc);
        return proc.rss * 1024;
}

int main () {
	long memoryStart = get_rss();

	map<string,char*>** array = new map<string,char*>*[1000000];
	for (int i = 0; i < 1000000; i++) {
		map<string,char*>* m = new map<string,char*>();
		(*m)["id"] = (char*)(void*)(i); // of course, i is not a valid pointer, but this is the most efficient way to store i
		(*m)["spalte_a"] = strdup("abcdefghijklmnopqrstuvwxyz");
		(*m)["spalte_b"] = strdup("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
		(*m)["spalte_c"] = strdup("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz");
		(*m)["spalte_d"] = strdup("0123456789");
		(*m)["spalte_e"] = strdup("0123456789012345678901234567890123456789012345678901234567890123456789");
		(*m)["spalte_f"] = strdup("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
		array[i] = m;
	}
	long memoryEnd = get_rss();
	cout << " c++ hashmap: memory start: " << (memoryStart / 1024) << " KB" << endl;
	cout << " c++ hashmap: memory end: " << (memoryEnd / 1024) << " KB" << endl;
	cout << " c++ hashmap: memory diff: " << ((memoryEnd - memoryStart) / 1024) << " KB" << endl;
	cout << " c++ hashmap: memory per row: " << ((memoryEnd - memoryStart) / 1000000.0) << " bytes" << endl;
}

