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
	char* spalte_a;
	char* spalte_b;
	char* spalte_c;
	char* spalte_d;
	char* spalte_e;
	char* spalte_f;
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
		m->spalte_a = strdup("abcdefghijklmnopqrstuvwxyz");
		m->spalte_b = strdup("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
		m->spalte_c = strdup("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz");
		m->spalte_d = strdup("0123456789");
		m->spalte_e = strdup("0123456789012345678901234567890123456789012345678901234567890123456789");
		m->spalte_f = strdup("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
		array[i] = m;
	}
	long memoryEnd = get_rss();
	cout << "  c++ objekt (with char*): memory start: " << (memoryStart / 1024) << " KB" << endl;
	cout << "  c++ objekt (with char*): memory end: " << (memoryEnd / 1024) << " KB" << endl;
	cout << "  c++ objekt (with char*): memory diff: " << ((memoryEnd - memoryStart) / 1024) << " KB" << endl;
	cout << "  c++ objekt (with char*): memory per row: " << ((memoryEnd - memoryStart) / 1000000) << " bytes" << endl;
}

