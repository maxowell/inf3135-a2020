#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

size_t getTimestamp();
int getNumTrans();
size_t getId();
unsigned char getPuissance();
void changeID();
void qualiteSignal();
void echangeData();
signed short getSignal();
float getDistance();

//Objet pastille.
typedef struct {
	size_t id;
	unsigned char p;
	float moyenneTH;
	float moyenneTA;
	size_t moyennePuls;
	size_t idPN[];
} pastille_s;

int main () {

	char trans[100];
	char copy[100];
	printf("version #: 0.0.10004\n");

	pastille_s *past = NULL;
	past = malloc(sizeof(pastille_s));
	past->id = 9999;
	past->p = 2;
	past->moyenneTH = 0;
	past->moyenneTA = 0;
	past->moyennePuls = 0;

	while (fgets(trans, 100, stdin) != NULL) {

		strcpy(copy, trans);

		switch (getNumTrans(copy)) {
			case 0 :
				changeID(trans, past);
				break;
			case 1 :
				break;
			case 2 :
				break;
			case 3 :
				break;
			case 4 :
				qualiteSignal(trans, past);
				break;
			case 5 :
				echangeData(trans, past);
				break;
		}
	}

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
	printf("%ld ", getId(copy, 0));
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
	strcpy(copy, _trans);
	int oldSize = sizeof((size_t)_past->idPN)/sizeof(_past->idPN[0]);
	size_t newId = getId(copy, 1);
	_past->idPN[oldSize - 1] = newId;
	for (int i = 0; i < oldSize; i++) {
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
	float m = (float) (-69 - (int) _signal);
	float n = (float) (10 * (int) _p);
	float distance = (float) pow(10, m/n);
	return distance;
}
