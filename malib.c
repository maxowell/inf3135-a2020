#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "tcv.h"
#include "malib.h"

int cmd () {}

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

void transaction22 (pastille_s *_past) {
	printf("22 %d %d %d\n", _past->invalideTH, _past->invalideTA, _past->invalidePuls);
}

void transaction23(pastille_s *_past) {
	printf("23 %ld %ld %ld\n", _past->erreurTH/3, _past->erreurTA/3, _past->erreurPuls/3);
}
