#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"

maks = -50, i = 0;

void popunjavanje(int * polje, int n) {
	for (int i = 0; i < n; i++) {
		polje[i] = -50 + (float)rand() / RAND_MAX * (100 - (-50));
	}
}

int najvecielem(int* polje, const int n) {

	if (i < n) {
		if (polje[i] > maks) {
			maks = polje[i];
			i++;
			najvecielem(polje, n);
		}
		if (polje[i] <= maks) {
			i++;
			najvecielem(polje, n);
		}
	}
	
	return maks;

}