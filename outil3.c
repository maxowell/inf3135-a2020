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
float getDistance (signed short *_signal, unsigned char *_p) {
	float m = (float) (-69 - (signed short)(signed long)_signal);
	float n = (float) (10 * (size_t) _p);
	float distance = (float) pow(10, m/n);
	return distance;
}