#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcv.h"
#include "malib.h"
int main (int argc, char *argv[]) {
	char trans[100];
	char copy[100];
	version_t *version = NULL;
	version = malloc(sizeof(version_t));
	getVersion(version);
	printf("version #: %d.%d.%d\n", version->major, version->minor, version->build);
	pastille_s *past = NULL;
	past = malloc(sizeof(pastille_s));
	getPastille(past);
	decompte_s *decompte = NULL;
	decompte = malloc(sizeof(decompte_s));
	getDecompte(decompte);
	while (fgets(trans, 100, stdin) != NULL) {
		strcpy(copy, trans);
		if (!checkTime(getTimestamp(copy), past)) continue;
		strcpy(copy,trans);
		switch (getNumTrans(copy)) {
			case 0 :
				changeID(trans, past);
				break;
			case 1 :
				transaction01(trans, past);
				break;
			case 2 :
				transaction02(trans, past, version);
				break;
			case 3 :
				transaction03(trans, past, version);
				break;
			case 4 :
				transaction04(trans, past, version);
				break;
			case 5 :
				echangeData(trans, past);
				break;
		}
	}
	transaction21(past);
	transaction22(past);
	transaction23(past);
	free(version);
	free(past);
	free(decompte);
	return 0;
}
