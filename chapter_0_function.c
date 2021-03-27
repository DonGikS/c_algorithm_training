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
static int top_stack=0;

void push_stack(int n){
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

#define ADVENCE_QUEUE_CAPACITY 8
static void* advenceQueue[ADVENCE_QUEUE_CAPACITY];
static int advence_head_queue = 0;
static int advence_tail_queue = -1;
static int advence_queue_size = 0;


void addQueue(void* value){
	if(advence_queue_size == ADVENCE_QUEUE_CAPACITY){
		printf("The Queue is fulled\n");
		return;
	}
	advence_tail_queue = (advence_tail_queue + 1) % ADVENCE_QUEUE_CAPACITY;
	advenceQueue[advence_tail_queue] = value;
	advence_queue_size++;
}
void* deleteQueue(){
	void* r;
	if(advence_queue_size == 0){
		printf("The Queus is emptied\n");
		return NULL;
	}
	r = advenceQueue[advence_head_queue];
	advence_head_queue = (advence_head_queue + 1) % ADVENCE_QUEUE_CAPACITY;
	advence_queue_size--;
	
	return r;
}

//###################################################################################-0.5 list

struct _node{
	int key;
	struct _node *next;
};

typedef struct _node node_t;

node_t *head = NULL, *tail = NULL;

void insert_node(int n){
	node_t *new_node = (node_t *) malloc(sizeof(node_t));
	new_node -> key = n;
	new_node -> next =NULL;
	if(head == NULL){
		head = new_node;
		tail = new_node;
	} else{
		tail -> next = new_node;
		tail = new_node;
	}
}

int delete_node(){
	node_t *node;
	int r;
	
	if(head == NULL) return -1;
	
	node = head;
	head = head -> next;
	if (head == NULL) tail = NULL;
	
	r = node -> key;
	free(node);
	return r;
}
//############################################# extra problem 0.5
// 0.a problem
void print_arr(int arr[], int lenght_arr){

	for(int i = 0; i < lenght_arr; i++){
		if(i != lenght_arr - 1) printf("%d ", arr[i]);
		else printf("%d\n", arr[i]); 
	}
}
//0.b problem
int all_is(int arr[], int lenght_arr, int k){
	for(int i = 0; i < lenght_arr; i++){
		if(arr[i] == k) continue;
		else if(arr[i] != k) return 0;
	}
	return 1;
}

//0.c problem
int trans_binary(int k){
	int count=0;
	int num_one=0;
	int bi_arr[32]={0,};
	while(1){
		bi_arr[count] = k%2;
		k = k/2;
		count++;
		if(k == 0) break;
	};
	for(int i = count; i > 0; i--){
		if(bi_arr[i-1] == 1) num_one+=1;
		if(i-1 != 0)printf("%d", bi_arr[i-1]);
		else printf("%d\n", bi_arr[i-1]);
	}
	return num_one;
	
}
