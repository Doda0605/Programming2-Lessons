#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"


int suma(int n) {

	int t = 0, zbroj = 0;

	if (n > 0)
	{
		t = n % 10;
		n = n / 10;
		zbroj = zbroj + t + suma(n);
	}
	
	return zbroj;
	
}