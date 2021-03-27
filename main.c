#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "chapter_0_function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	int arr[100];
	srand(time(NULL));
	for(int i=0; i<(sizeof(arr)/sizeof(int)); i++){
		arr[i] = rand()%9;
	}
	print_arr(arr, sizeof(arr)/sizeof(int));
	printf("%d\n",all_is(arr, sizeof(arr)/sizeof(int), 4));
	
	
	
	return 0;
}

