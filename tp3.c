#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
	past->id = 9999;
	past->p = 2;
	past->sommeTH = 0;
	past->nombreTH = 0;
	past->erreurTH = 0;
	past->invalideTH = 0;
	past->sommeTA = 0;
	past->nombreTA = 0;
	past->erreurTA = 0;
	past->invalideTA = 0;
	past->sommePuls = 0;
	past->nombrePuls = 0;
	past->erreurPuls = 0;
	past->invalidePuls = 0;
	past->sizePN = 0;
	past->time = 0;

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
				transaction04();
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
	return 0;
}
