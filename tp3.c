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
				past->nbTransInconnues++;
				break;
		}
	}
	if (!paramT) transaction21(past);
	if (!paramT) transaction22(past);
	if (!paramT) transaction23(past);
	if (paramI) printf("information invalide\n  trx non reconnue : %d\n  trx avec ts non sequentiel : %d\n", past->nbTransInconnues, past->nbTransDecroissantes);
	if (paramD) printf("information detaillee\n  trx 01 : %d\n  trx 02 : %d\n  trx 03 : %d\n  trx 04 : %d\n  trx 05 : %d\n  le dernier ts lu : %ld\n", past->nbTrans01, past->nbTrans02, past->nbTrans03, past->nbTrans04, past->nbTrans05, past->time);
	if (paramS) printf("information sommaire\n  nbr trx valides : %d\n  nbr trx (total) : %d\n", past->nbTrans01 + past->nbTrans02 + past->nbTrans03 + past->nbTrans04 + past->nbTrans05, past->nbTrans01 + past->nbTrans02 + past->nbTrans03 + past->nbTrans04 + past->nbTrans05 + past->nbTransDecroissantes + past->nbTransInconnues);
	free(version);
	free(past);
	return 0;
}
