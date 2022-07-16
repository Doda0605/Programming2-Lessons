#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

i = 0;

okrenuti(const char* string, FILE* fp) {

	if (i != strlen(string)) {

		printf("%c", string[strlen(string) - i - 1]);
		i++;
		fprintf(fp, "%c", string[strlen(string) - i - 1]);
		okrenuti(string, fp);


	}
}