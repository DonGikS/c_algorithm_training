#include <stdio.h>
#include <stdlib.h>
//int min(int x, int y);
//int max(int x, int y);
int min_advence(int x, int y, int z);
int max_advence(int x, int y, int z);

int max_arr(int arr[], int arr_len);
int max_arr2(int arr[], int arr_len);

void wrong_swap(int a, int b);
void swap(int *a, int *b);
void swap_arr(int arr[], int i, int j);

void right_rotate(int arr[], int s, int t);
void left_rotate(int arr[], int s, int t);
void right_rotate_advance(int arr[], int s, int t, int k);
void right_rotate_compare(int arr[], int s, int t, int k);

void enqueue(int n);
int dequeue();
void push_stack(int n);
int pop_stack();

void addQueue(void*);
void* deleteQueue();

void insert_node(int);
int delete_node();

void print_arr(int arr[], int lenght_arr);
int all_is(int arr[], int lenght_arr, int k);
