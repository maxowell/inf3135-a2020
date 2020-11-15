
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "tcv.h"

size_t getTimestamp();
int getNumTrans();
size_t getId();
unsigned char getPuissance();
void changeID();
void qualiteSignal();
void echangeData();
signed short getSignal();
float getDistance();
char* getTemp();
signed short getTempShort();
void transaction21();
void transaction22();
void transaction23();

//Objet pastille.
typedef struct {
	size_t id;
	unsigned char p;
	float sommeTH;
	int nombreTH;
	size_t erreurTH;
	int invalideTH;
	float sommeTA;
	int nombreTA;
	size_t erreurTA;
	int invalideTA;
	size_t sommePuls;
	int nombrePuls;
	size_t erreurPuls;
	int invalidePuls;
	int sizePN;
	size_t idPN[];
} pastille_s;

int main () {

	char trans[100];
	char copy[100];
	printf("version #: 0.1.10005\n");

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

	while (fgets(trans, 100, stdin) != NULL) {

		strcpy(copy, trans);

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
				if (strcmp(temp, "ERREUR\n") != 0 && validerTA_3(getTempShort(temp))) {
					past->sommeTA += (float) atof(temp);
					past->nombreTA++;
				} else if (strcmp(temp, "ERREUR\n") == 0) {
					past->erreurTA++;
				} else if (!validerTA_3(getTempShort(temp))) {
					past->invalideTA++;
				}
				break;
			case 3 :
				strcpy(copy, trans);
				char *puls = getTemp(copy);
				if (strcmp(puls, "ERREUR\n") != 0 && validerPulsation_1(atof(puls))) {
					past->sommePuls += (size_t) atof(puls);
					past->nombrePuls++;
				} else if (strcmp(puls, "ERREUR\n") == 0) {
					past->erreurPuls++;
				} else if (!validerPulsation_3(getTempShort(puls))) {
					past->invalidePuls++;
				}
				break;
			case 4 :
				strcpy(copy, trans);
				if (validerSignal_2(getSignal(copy))) {
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
	return 0;
}

//Changement de l'identifiant par défaut
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

//Qualité du signal en mètres
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

//échange de données
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

//Retourne le timestamp (size_t) d'une transaction.
size_t getTimestamp (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	return atoi(elem);
}

//Retourne le numéro (int) d'une transaction.
int getNumTrans(char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	return atoi(elem);
}

//Retourne l'id (size_t) d'une transaction. Position 3 si v != 0, 4 si v == 0.
size_t getId (char *_trans, int *_v) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	if (_v == 0) {
		elem = strtok(NULL, " ");
	}
	return atoi(elem);
}

//Retourne la puissance de l'émetteur.
unsigned char getPuissance (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return (unsigned char) atoi(elem);
}

//Retourne le signal RSSI d'une transaction.
signed short getSignal (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return (signed short) atoi(elem);
}

//Calcule la distance en mètres
float getDistance (signed short *_signal, unsigned char *_p) {
	float m = (float) (-69 - (signed short)(signed long)_signal);
	float n = (float) (10 * (size_t) _p);
	float distance = (float) pow(10, m/n);
	return distance;
}

//Retourne la température d'une transaction
char* getTemp (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return elem;
}

//Retourne une température sous forme signed short
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

//Effectue la transaction pour le cumul des 
void transaction22 (pastille_s *_past) {
	printf("22 %d %d %d\n", _past->invalideTH, _past->invalideTA, _past->invalidePuls);
}

void transaction23(pastille_s *_past) {
	printf("23 %ld %ld %ld\n", _past->erreurTH/3, _past->erreurTA/3, _past->erreurPuls/3);
}
