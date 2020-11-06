#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t getTimestamp();
int getNumTrans();
size_t getId();
char* getThirdElem();

int main () {

	char trans[100];

	while (fgets(trans, 100, stdin) != NULL) {
		printf("%s\n", getThirdElem(trans));
	}

	return 0;
}

//Retourne le timestamp (size_t) d'une transaction.
size_t getTimestamp (char *_trans[]) {
	char *elem = strtok((char *)_trans, " ");
	return atoi(elem);
}

//Retourne le numéro (int) d'une transaction.
int getNumTrans(char *_trans[]) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	return atoi(elem);
}

//Retourne l'id (size_t) d'une transaction.
size_t getId (char *_trans[]) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return atoi(elem);
}

//Retourne le troisième élément d'une transaction.
char* getThirdElem (char *_trans[]) {
	char *elem = strtok((char *)_trans, " ");
	elem = strtok(NULL, " ");
	elem = strtok(NULL, " ");
	return elem;
}
