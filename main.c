#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void main() {
	int arr[10000];
	for(int i = 0; i<10000; i++){
		arr[i] = i;
	}
	//right_rotate_advance(arr, 24, 8500, 15050);
	right_rotate_compare(arr, 24, 8500, 15050);
	for(int i = 0; i<10000; i++){
		printf("%d ", arr[i]);
	}
	return;
}

