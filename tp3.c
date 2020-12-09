#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tcv.h"
#include "malib.h"
int main (int argc, char *argv[]) {
	cmd(argc, argv);
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
		if (!checkTime(atoi(getInfo(copy,1)), past)) continue;
		strcpy(copy,trans);
		switch (atoi(getInfo(copy,2))) {
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
			default :
				past->nonReconnue++;
				break;
		}
	}
	if (!paramT) transaction21(past);
	if (!paramT) transaction22(past);
	if (!paramT) transaction23(past);
	if (paramI) printf("information invalide\n  trx non reconnue : %d\n  trx avec ts non sequentiel : %d\n", past->nonReconnue, past->badTime);
	free(version);
	free(past);
	free(decompte);
	return 0;
}
