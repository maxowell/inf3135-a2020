#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tcv.h"
#include "malib.h"

int main () {

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
				strcpy(copy, trans);
				char *temp = getTemp(copy);
				if (strcmp(temp, "ERREUR\n") != 0 && validerTH_1(getTempShort(temp))) {
					past->sommeTH += (float) atof(temp);
					past->nombreTH++;
				} else if (strcmp(temp, "ERREUR\n") == 0) {
					past->erreurTH++;
				} else if (!validerTH_1(getTempShort(temp))) {
					past->invalideTH++;
				}
				break;
			case 2 :
				strcpy(copy, trans);
				temp = getTemp(copy);
				bool validerTA;
				if (version->build > 1004) {
					validerTA = validerTA_1(atoi(getTemp(temp)));
				} else {
					validerTA = validerTA_3(getTempShort(temp));
				}
				if (strcmp(temp, "ERREUR\n") != 0 && validerTA) {
					past->sommeTA += (float) atof(temp);
					past->nombreTA++;
				} else if (strcmp(temp, "ERREUR\n") == 0) {
					past->erreurTA++;
				} else if (!validerTA) {
					past->invalideTA++;
				}
				break;
			case 3 :
				strcpy(copy, trans);
				char *puls = getTemp(copy);
				bool validerPuls;
				if (version->build > 1004) {
					validerPuls = validerPulsation_1(atoi(puls));
				} else {
					validerPuls = validerPulsation_3((short)atoi(temp));
				}
				if (strcmp(puls, "ERREUR\n") != 0 && validerPuls) {
					past->sommePuls += (size_t) atoi(puls);
					past->nombrePuls++;
				} else if (strcmp(puls, "ERREUR\n") == 0) {
					past->erreurPuls++;
				} else if (!validerPuls) {
					past->invalidePuls++;
				}
				break;
			case 4 :
				strcpy(copy, trans);
				bool validerSignal;
				if (version->build > 1004) {
					validerSignal = validerSignal_3(getSignal(copy));
				} else {
					validerSignal = validerSignal_2(getSignal(copy));
				}
				if (validerSignal) {
					qualiteSignal(trans, past);
				}
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
