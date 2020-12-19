#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void main() {
	int a=32;
	int arr[a];
	int i;
	for(int i = 0; i < a; i++){
		arr[i] = a - i;
	}
	max_arr2(arr, a);
	
	for(i = 0; i < a; i++) printf("%d ", arr[i]);
	return;
}

