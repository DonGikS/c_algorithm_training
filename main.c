#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void main() {
	int x = 1, y = 2;
	wrong_swap(x, y);
	printf("%d %d\n", x, y);
	swap(&x, &y);
	printf("%d %d\n", x, y);
	return;
}

