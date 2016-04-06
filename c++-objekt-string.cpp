#include <list>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <proc/readproc.h>

using namespace std;

class Model {
public:
	int id;
	string spalte_a;
	string spalte_b;
	string spalte_c;
	string spalte_d;
	string spalte_e;
	string spalte_f;
};

long get_rss() {
        proc_t proc;
        look_up_our_self(&proc);
        return proc.rss * 1024;
}

int main () {
	long memoryStart = get_rss();

	Model** array = new Model*[1000000];
	for (int i = 0; i < 1000000; i++) {
		Model* m = new Model();
		m->id = i;
		m->spalte_a = string("abcdefghijklmnopqrstuvwxyz");
		m->spalte_b = string("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
		m->spalte_c = string("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz");
		m->spalte_d = string("0123456789");
		m->spalte_e = string("0123456789012345678901234567890123456789012345678901234567890123456789");
		m->spalte_f = string("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
		array[i] = m;
	}
	long memoryEnd = get_rss();
	cout << "  c++ objekt (with string): memory start: " << (memoryStart / 1024) << " KB" << endl;
	cout << "  c++ objekt (with string): memory end: " << (memoryEnd / 1024) << " KB" << endl;
	cout << "  c++ objekt (with string): memory diff: " << ((memoryEnd - memoryStart) / 1024) << " KB" << endl;
	cout << "  c++ objekt (with string): memory per row: " << ((memoryEnd - memoryStart) / 1000000) << " bytes" << endl;
}

