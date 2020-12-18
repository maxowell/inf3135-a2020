#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "tcv.h"
#include "malib.h"
#include "outil3.h"
char* getInfo (char *_trans, int _i) {
	char *elem = strtok((char *)_trans, " ");
	for (int j = 1; j < _i; j++) elem = strtok(NULL, " ");
	return elem;
}
void changeID (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	if (!paramT) printf("10 %ld ", atol(getInfo(copy,1)));
	strcpy(copy, _trans);
	_past->id = atoi(getInfo(copy,3));
	if (!paramT) printf("%ld ", _past->id);
	strcpy(copy, _trans);
	_past->p = (unsigned char) atoi(getInfo(copy,4));
	if (!paramT) printf("%d\n", _past->p);
}
void qualiteSignal (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	if (!paramT) printf("14 %ld ", atol(getInfo(copy,1)));
	strcpy(copy, _trans);
	size_t newId = atoi(getInfo(copy, 4));
	_past->idPN[_past->sizePN] = newId;
	_past->sizePN++;
	if (!paramT) printf("%ld ", newId);
	strcpy(copy, _trans);
	signed short signal = atoi(getInfo(copy,3));
	if (!paramT) printf("%.1f\n", getDistance(signal, _past->p));
}
void echangeData (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	if (!paramT) printf("15 %ld ", atol(getInfo(copy,1)));
	strcpy(copy, _trans);
	if (!paramT) {
		printf("%ld ", _past->id);
		for (int i = 0; i < _past->sizePN; i++) printf("%ld ", _past->idPN[i]);
		printf("\n");
	}
	_past->nbTrans05++;
}
void transaction01 (char *_trans, pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	char *temp = getInfo(copy,3);
	if (strstr(temp, ".") != NULL && validerTH_1((signed short)((float) atof(temp) * 10))) {
		_past->sommeTH += (float) atof(temp);
		_past->nombreTH++;
	} else if (strstr(temp, ".") == NULL) {
		_past->erreurTH++;
	} else if (!validerTH_1((signed short)((float) atof(temp) * 10))) {
		_past->invalideTH++;
	}
	_past->nbTrans01++;
}
void transaction02 (char *_trans, pastille_s *_past, version_t *_version) {
	char copy[100];
	strcpy(copy, _trans);
	char *temp = getInfo(copy,3);
	bool validerTA;
	if (_version->build > 1004) {
		validerTA = validerTA_1(atoi(temp));
	} else {
		validerTA = validerTA_3((signed short)((float) atof(temp) * 10));
	}
	if (strstr(temp, ".") != NULL && validerTA) {
		_past->sommeTA += (float) atof(temp);
		_past->nombreTA++;
	} else if (strstr(temp, ".") == NULL) {
		_past->erreurTA++;
	} else if (!validerTA) {
		_past->invalideTA++;
	}
	_past->nbTrans02++;
}
void transaction03 (char *_trans, pastille_s *_past, version_t *_version) {
	char copy[100];
	strcpy(copy, _trans);
	char *puls = getInfo(copy,3);
	bool validerPuls;
	if (_version->build > 1004) validerPuls = validerPulsation_1(atoi(puls));
	else validerPuls = validerPulsation_3((short)atoi(puls));
	if (validerPuls) {
		_past->sommePuls += (size_t) atoi(puls);
		_past->nombrePuls++;
	} else if (atoi(puls) == 0) _past->erreurPuls++;
	else _past->invalidePuls++;
	_past->nbTrans03++;
}
void transaction04 (char *_trans, pastille_s *_past, version_t *_version) {
	char copy[100];
	strcpy(copy, _trans);
	bool validerSignal;
	if (_version->build > 1004) validerSignal = validerSignal_3(atoi(getInfo(copy,3)));
	else validerSignal = validerSignal_2(atoi(getInfo(copy,3)));
	if (validerSignal) qualiteSignal(_trans, _past);
	_past->nbTrans04++;
}
bool checkTime (size_t _time, pastille_s *_past) {
	if (_time != 0 && _time <= _past->time) {
		_past->nbTransDecroissantes++;
		return false;
	}
	_past->time = _time;
	return true;
}
void transaction21 (pastille_s *_past) {
	printf("21 ");
	if (_past->nombreTH != 0) printf("%.1f ", _past->sommeTH/_past->nombreTH);
	else printf("%.1f ", _past->sommeTH);
	if (_past->nombreTA != 0) printf("%.1f ", _past->sommeTA/_past->nombreTA);
	else printf("%.1f ", _past->sommeTA);
	if (_past->nombrePuls != 0) printf("%ld\n", _past->sommePuls/_past->nombrePuls);
	else printf("%ld\n", _past->sommePuls);
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
	_past->nbTransInconnues = 0;
	_past->nbTransDecroissantes = 0;
	_past->nbTrans01 = 0;
	_past->nbTrans02 = 0;
	_past->nbTrans03 = 0;
	_past->nbTrans04 = 0;
	_past->nbTrans05 = 0;
}
