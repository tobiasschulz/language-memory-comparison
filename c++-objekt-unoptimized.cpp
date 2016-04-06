#include <list>
#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <malloc.h>

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

long allocated_memory = 0;

char *mystrdup(const char *s) {
	char *result = (char*)malloc(strlen(s) + 1);
	allocated_memory += strlen(s) + 1;
	if (result == (char*)0){return (char*)0;}
	strcpy(result, s);
	return result;
}

int main () {
	long memoryStart = 0;

	Model** array = new Model*[1000000];
	for (int i = 0; i < 1000000; i++) {
		Model* m = new Model();
		m->id = i;
		m->spalte_a = mystrdup("abcdefghijklmnopqrstuvwxyz");
		m->spalte_b = mystrdup("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
		m->spalte_c = mystrdup("aabbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzz");
		m->spalte_d = mystrdup("0123456789");
		m->spalte_e = mystrdup("0123456789012345678901234567890123456789012345678901234567890123456789");
		m->spalte_f = mystrdup("abcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabcabc");
		allocated_memory += sizeof(Model);
		array[i] = m;
	}
	long memoryEnd = allocated_memory + memoryStart;
	cout << "  c++ obj (manual malloc): memory diff: " << ((memoryEnd - memoryStart) / 1024) << " KB" << endl;
	cout << "  c++ obj (manual malloc): memory per row: " << ((memoryEnd - memoryStart) / 1000000) << " bytes" << endl;
}

