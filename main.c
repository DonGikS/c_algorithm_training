#include <stdio.h>
#include <stdlib.h>
#include "chapter_0_function.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main() {
	int number, r;
	//void* number;
	//void* r;
	do{
		printf("input number: ");
		scanf("%d", &number);
		if(number > 0){
			//enqueue(number);
			//push_stack(number);
			//addQueue(number);
			insert_node(number);
		}else if(number == 0){
			//r = dequeue();
			//r = pop_stack();
			//r = deleteQueue();
			r = delete_node();
			printf("[%d]\n", r);
		}
	} while(number >= 0);
	return 0;
}

