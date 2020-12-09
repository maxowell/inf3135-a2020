#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "tcv.h"
#include "malib.h"
#include "outil3.h"
bool paramT = false;
bool paramD = false;
bool paramS = false;
bool paramI = false;

int cmd (int _argc, char *_argv[]) {
	for (int i = 0; i < _argc; i++) {
		if (strcmp(_argv[i], "-s") == 0) paramS = true;
		else if (strcmp(_argv[i], "-d") == 0) paramD = true;
		else if (strcmp(_argv[i], "-t") == 0) paramT = true;
		else if (strcmp(_argv[i], "-i") == 0) paramI = true;
	}
	return 0;
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