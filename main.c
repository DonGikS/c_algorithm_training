#include <stdio.h>
#include <stdlib.h>
#include "function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	int number, r;
	do{
		printf("input number: ");
		scanf("%d", &number);
		
		if(number > 0){
			//enqueue(number);
			push_stack(number);
		}else if(number == 0){
			//r = dequeue();
			r = pop_stack();
			printf("[%d]\n", r);
		}
	} while(number >= 0);
	return 0;
}

