#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "tcv.h"
#include "malib.h"

int cmd () {

}

bool checkTime (size_t time, pastille_s *_past) {
	if (time < _past->time) {
		return false;
	}
	_past->time = time;
	return true;
}

void changeID (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	printf("10 %ld ", getTimestamp(copy));
	strcpy(copy, _trans);
	_past->id = getId(copy, 1);
	printf("%ld ", _past->id);
	strcpy(copy, _trans);
	_past->p = getPuissance(copy);
	printf("%d\n", _past->p);
}

void qualiteSignal (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	printf("14 %ld ", getTimestamp(copy));
	strcpy(copy, _trans);
	size_t newId = getId(copy, 0);
	_past->idPN[_past->sizePN] = newId;
	_past->sizePN++;
	printf("%ld ", newId);
	strcpy(copy, _trans);
	signed short signal = getSignal(copy);
	printf("%.1f\n", getDistance(signal, _past->p));
}

void echangeData (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	printf("15 %ld ", getTimestamp(copy));
	strcpy(copy, _trans);
	printf("%ld ", _past->id);
	for (int i = 0; i < _past->sizePN; i++) {
		printf("%ld ", _past->idPN[i]);
	}
	printf("\n");
}

size_t getTimestamp (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	return atoi(elem);
}

int getNumTrans(char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	return atoi(elem);
}

size_t getId (char *_trans, int *_v) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	if (_v == 0) {
		elem = strtok(NULL, " ");
	}
	return atoi(elem);
}

unsigned char getPuissance (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return (unsigned char) atoi(elem);
}

signed short getSignal (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return (signed short) atoi(elem);
}

float getDistance (signed short *_signal, unsigned char *_p) {
	float m = (float) (-69 - (signed short)(signed long)_signal);
	float n = (float) (10 * (size_t) _p);
	float distance = (float) pow(10, m/n);
	return distance;
}

char* getTemp (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return elem;
}

signed short getTempShort (char *_temp) {
	return (signed short)((float) atof(_temp) * 10);
}

void transaction21 (pastille_s *_past) {
	printf("21 ");
	if (_past->nombreTH != 0) {
		printf("%.1f ", _past->sommeTH/_past->nombreTH);
	} else {
		printf("%.1f ", _past->sommeTH);
	}
	if (_past->nombreTA != 0) {
		printf("%.1f ", _past->sommeTA/_past->nombreTA);
	} else {
		printf("%.1f ", _past->sommeTA);
	}
	if (_past->nombrePuls != 0) {
		printf("%ld\n", _past->sommePuls/_past->nombrePuls);
	} else {
		printf("%ld\n", _past->sommePuls);
	}
}

void transaction01 (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	char *temp = getTemp(copy);
	if (strcmp(temp, "ERREUR\n") != 0 && validerTH_1(getTempShort(temp))) {
		_past->sommeTH += (float) atof(temp);
		_past->nombreTH++;
	} else if (strcmp(temp, "ERREUR\n") == 0) {
		_past->erreurTH++;
	} else if (!validerTH_1(getTempShort(temp))) {
		_past->invalideTH++;
	}
}

void transaction02 (char *_trans, pastille_s *_past, version_t *_version) {
	char copy[100];
	strcpy(copy, _trans);
	char *temp = getTemp(copy);
	bool validerTA;
	if (_version->build > 1004) {
		validerTA = validerTA_1(atoi(getTemp(temp)));
	} else {
		validerTA = validerTA_3(getTempShort(temp));
	}
	if (strcmp(temp, "ERREUR\n") != 0 && validerTA) {
		_past->sommeTA += (float) atof(temp);
		_past->nombreTA++;
	} else if (strcmp(temp, "ERREUR\n") == 0) {
		_past->erreurTA++;
	} else if (!validerTA) {
		_past->invalideTA++;
	}
}

void transaction03 (char *_trans, pastille_s *_past, version_t *_version) {
	char copy[100];
	strcpy(copy, _trans);
	char *puls = getTemp(copy);
	bool validerPuls;
	if (_version->build > 1004) {
		validerPuls = validerPulsation_1(atoi(puls));
	} else {
		validerPuls = validerPulsation_3((short)atoi(puls));
	}
	if (strcmp(puls, "ERREUR\n") != 0 && validerPuls) {
		_past->sommePuls += (size_t) atoi(puls);
		_past->nombrePuls++;
	} else if (strcmp(puls, "ERREUR\n") == 0) {
		_past->erreurPuls++;
	} else if (!validerPuls) {
		_past->invalidePuls++;
	}
}

void transaction04 (char *_trans, pastille_s *_past, version_t *_version) {
	char copy[100];
	strcpy(copy, _trans);
	bool validerSignal;
	if (_version->build > 1004) {
		validerSignal = validerSignal_3(getSignal(copy));
	} else {
		validerSignal = validerSignal_2(getSignal(copy));
	}
	if (validerSignal) {
		qualiteSignal(_trans, _past);
	}
}

void transaction22 (pastille_s *_past) {
	printf("22 %d %d %d\n", _past->invalideTH, _past->invalideTA, _past->invalidePuls);
}

void transaction23(pastille_s *_past) {
	printf("23 %ld %ld %ld\n", _past->erreurTH/3, _past->erreurTA/3, _past->erreurPuls/3);
}

void getPastille (pastille_s *_past) {
	_past->id = 9999;
	_past->p = 2;
	_past->sommeTH = 0;
	_past->nombreTH = 0;
	_past->erreurTH = 0;
	_past->invalideTH = 0;
	_past->sommeTA = 0;
	_past->nombreTA = 0;
	_past->erreurTA = 0;
	_past->invalideTA = 0;
	_past->sommePuls = 0;
	_past->nombrePuls = 0;
	_past->erreurPuls = 0;
	_past->invalidePuls = 0;
	_past->sizePN = 0;
	_past->time = 0;
}

void getDecompte (decompte_s *_decompte) {
	_decompte->nbTransInconnues = 0;
	_decompte->nbTransDecroissantes = 0;
	_decompte->nbTransTrans01 = 0;
	_decompte->nbTransTrans02 = 0;
	_decompte->nbTransTrans03 = 0;
	_decompte->nbTransTrans04 = 0;
	_decompte->nbTransTrans05 = 0;
}
