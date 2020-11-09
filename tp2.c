#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t getTimestamp();
int getNumTrans();
size_t getId();
unsigned char getPuissance();
void changeID();
void qualiteSignal();
void echangeData();

//Objet pastille.
struct pastille_s {
	size_t id;
	unsigned char p;
	float moyenneTH;
	float moyenneTA;
	size_t moyennePuls;
	size_t *idPN[];
};

int main () {

	char trans[100];
	char copy[100];
	printf("version #: 0.0.10004\n");

	while (fgets(trans, 100, stdin) != NULL) {

		struct pastille_s past = { .id = 9999, .p = 2, .moyenneTH = 0, .moyenneTA = 0, .moyennePuls = 0};
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
				qualiteSignal(trans);
				break;
			case 5 :
				echangeData(trans);
				break;
		}
	}

	return 0;
}

//Changement de l'identifiant par défaut
void changeID (char *_trans, struct pastille_s *_past) {
	char copy[100];
	strcpy(copy, _trans);
	printf("10 %ld ", getTimestamp(copy));
	strcpy(copy, _trans);
	size_t i = getId(copy);
	return;
	_past->id = i;
	return;
	printf("%ld ", _past->id);
	strcpy(copy, _trans);
	_past->p = getPuissance(copy);
	printf("%d\n", _past->p);
}

//Qualité du signal en mètres
void qualiteSignal (char *trans) {
	
}

//Échange de données
void echangeData (char *_trans) {
	
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

//Retourne l'id (size_t) d'une transaction.
size_t getId (char *_trans) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
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


