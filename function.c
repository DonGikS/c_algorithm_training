#include "function.h"
//#define max(x, y) ((x)>(y) ? (x) : (y)) //define�� ȣ�⵵ ������ ���̴µ� ������ Ư���� ��Ȳ�� �ƴ϶�� �Լ���ü�� ���� ����(����Լ��� �ſ� ���) 
//#define min(x, y) ((x)<(y) ? (x) : (y))
//###################################################################################-0.1
//���� ���ϴ� �Լ�(���� 2��, ���� 3��) 

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

//�迭�� �ִ� ���� ���ϴ� �Լ� 
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
