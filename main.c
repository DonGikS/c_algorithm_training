#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void main() {
	int arr[10];
	for(int i = 0; i<10; i++){
		arr[i] = i;
	}
	swap_arr(arr, 3, 9);
	for(int i = 0; i<10; i++){
		printf("%d ", arr[i]);
	}
	return;
}

