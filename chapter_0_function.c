#include "chapter_0_function.h"
//#define max(x, y) ((x)>(y) ? (x) : (y)) //define은 호출도 빠르고 쓰이는데 좋지만 특수한 상황이 아니라면 함수자체를 만들어서 쓰자(재귀함수에 매우 취약) 
//#define min(x, y) ((x)<(y) ? (x) : (y))
//###################################################################################-0.1
//서로 비교하는 함수(숫자 2개, 숫자 3개) 

int min(int x, int y){
	if(x < y) return x;
	else return y;
}
int max(int x,int y){
	if(x > y) return x;
	else return y;
}
int min_advence(int x, int y, int z){
	if(x < y){
		if(x < z) return x;
		else return z;
	}
	else{
		if(y < z) return y;
		else return z;
	}
}
int max_advence(int x, int y, int z){
	if(x > y){
		if(x > z) return x;
		else return z;
	}
	else{
		if(y > z) return y;
		else return z;
	}
}

//배열의 최대 값을 구하는 함수 
int max_arr(int arr[], int arr_len){
	int maxa, i;
	
	maxa = arr[0];
	for (i = 1; i < arr_len; i++){
		if (arr[i] > maxa) maxa = arr[i];
	}
	
	return maxa;
}
int max_arr2(int arr[], int arr_len){
	if (arr_len == 1) return arr[0];
	else return max(arr[arr_len-1], max_arr2(arr, arr_len -1));
}

//###################################################################################-0.2

void wrong_swap(int a, int b){//포인터로 받지 않아서 동작하지 않는 swap함수 
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}
void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap_arr(int arr[], int i, int j){
	int temp;
	
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//###################################################################################-0.3
void right_rotate(int arr[], int s, int t){
	int i, last;
	
	last = arr[t];
	for(i = t; i > s; i--){
		arr[i] = arr[i-1];
	}
	arr[s] = last;
}
void left_rotate(int arr[], int s, int t){
	int i, leftmost;
	
	leftmost = arr[s];
	for(i = s; i < t; i++){
		arr[i] = arr[i+1];
	}
	arr[t] = leftmost;
}
void right_rotate_advance(int arr[], int s, int t, int k){
	int pure_move = k % (t - s + 1);
	
	int temp_arr[pure_move];
	
	for(int i = 0; i < pure_move; i++){
		temp_arr[i] = arr[t - pure_move + 1 + i];
	}
	for(int i = t; s < i; i--){
		arr[i] = arr[i - pure_move];
	}
	for(int i = 0; i < pure_move; i++){
		arr[s + i] = temp_arr[i];
	}
}
void right_rotate_compare(int arr[], int s, int t, int k){
	int loop_val = 0;
	while(loop_val < k){
		int i, last;
		last = arr[t];
		for(i = t; s < i; i--){
			arr[i] = arr[i-1];
		}
		arr[s] = last;
		loop_val++;
	}
}
//###################################################################################-0.4
#define QUEUE_CAPACITY 8

static int queue[QUEUE_CAPACITY];
static int head_queue = 0;
static int tail_queue = -1;
static int queue_size = 0;

void enqueue(int n){
	if (queue_size == QUEUE_CAPACITY){
		printf("queue full\n");
		return;
	}
	tail_queue = (tail_queue + 1) % QUEUE_CAPACITY;
	queue_size++;
	queue[tail_queue]=n;
}

int dequeue(){
	int r;
	if(queue_size == 0){
		printf("queue empty!\n");
		return 0;
	}
	
	r = queue[head_queue];
	head_queue = (head_queue + 1) % QUEUE_CAPACITY;
	queue_size--;
	return r;
}
#define STACK_CAPACITY 8

static int stack[STACK_CAPACITY];
static int top_stack=-1;

void push_stack(int n){
	if(n <= 0){
		printf("please, input value is positive int\n");
		return;
	}
	if(top_stack<0) top_stack = 0;
	if (top_stack == STACK_CAPACITY){
		printf("stack is fulled\n");
		return;
	}
	stack[top_stack] = n;
	top_stack++;
}

int pop_stack(){
	int r;
	if(top_stack <= 0){
		printf("stack is empty\n");
		return 0;
	}
	r = stack[--top_stack];
	return r;
}

